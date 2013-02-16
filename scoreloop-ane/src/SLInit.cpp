/*
 * SLinit.cpp
 *
 *  Created on: Feb 12, 2013
 *      Author: CHRIS
 */



#include "Globals.h"


using namespace std;


#ifdef __cplusplus
extern "C" {
#endif


//==============================================================================================
//                         Variables
//==============================================================================================

int sl_ANEDomain = -1;
int sl_channelID = -1;

sl_ANEThreadState_e slThreadState = SL_INIT;
SC_InitData_t       *sl_initData  = NULL;

//==============================================================================================
//                         Custom Functions
//==============================================================================================

void* initScoreLoopThread(void *data){
   cout << "Initializing BPS" << endl;
   bps_initialize();
   cout << "Registering domain and getting channel" << endl;
   sl_ANEDomain = bps_register_domain();
   sl_channelID = bps_channel_get_active();

   cout << "Initializing SC_InitData struct" << endl;
   sl_initData = (SC_InitData_t*)malloc(sizeof(SC_InitData_t));
   memset(sl_initData,0,sizeof(SC_InitData_t));
   SC_InitData_Init(sl_initData);
   cout << "Setting domain" << endl;
   sl_initData->eventDomain = sl_ANEDomain;

   cout << "Zeroing appData memory" << endl;
   memset(appData, 0, sizeof(SL_AppData_s));

   for(;;){
      switch( slThreadState ){
         case SL_INIT:
            sleep(15);
            break;

         case SL_RUNNING:
            bps_event_t *event;
            bps_get_event(&event, -1);
            if (!event) return NULL;

            if (bps_event_get_domain(event) == sl_ANEDomain) SC_HandleBPSEvent(sl_initData, event);

            //Need to decide if need to wait for all a custom event before next scoreloop
            //or just process custom events as they are received
            SC_HandleCustomEvent(sl_initData, SC_FALSE);

            break;

         case SL_STOPPING:
            break;

         case SL_STOPPED:
            break;
      }

      if( slThreadState == SL_STOPPED ) break;
   }

   bps_shutdown();

   return NULL;
}

FREObject sl_ane_setMinimumVersion(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   return NULL;
}

//==============================================================================================
//                         ScoreLoop sc_init.h Function Stubs
//==============================================================================================

//SC_PUBLISHED int SC_GetBPSEventDomain(SC_InitData_t *initData);
FREObject sl_ane_SC_GetBPSEventDomain(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   FREObject result;
   FRENewObjectFromInt32(sl_initData->eventDomain,&result);
   return result;
}


#ifdef __cplusplus
}
#endif



