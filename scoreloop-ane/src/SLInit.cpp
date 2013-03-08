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

int sl_ANEDomain    = -1;
int sl_ANEChannelID = -1;

sl_ANEThreadState_e sl_threadState = SL_INIT;
SC_InitData_t       *sl_initData   = NULL;

bool clientCreated          = false;
bool userControllersCreated = false;

//==============================================================================================
//                         Custom Functions
//==============================================================================================

void* initScoreLoopThread(void* data){
   cout << "Initializing BPS" << endl;
   bps_initialize();
   cout << "Registering domain and getting channel" << endl;
   sl_ANEDomain = bps_register_domain();
   sl_ANEChannelID = bps_channel_get_active();

   cout << "Initializing SC_InitData struct" << endl;
   sl_initData = (SC_InitData_t*)malloc(sizeof(SC_InitData_t));
   memset(sl_initData,0,sizeof(SC_InitData_t));
   SC_InitData_Init(sl_initData);
   cout << "Setting domain" << endl;
   sl_initData->eventDomain = sl_ANEDomain;

   cout << "Zeroing appData memory" << endl;
   memset(appData, 0, sizeof(SL_AppData_s));

   //cout << "Initializing child threads" <<endl;
   //pthread_create(NULL, NULL, initUserControllerThread, NULL);

   for(;;){
      switch( sl_threadState ){
         case SL_INIT: {
            bps_event_t *event;
            bps_get_event(&event, -1);
            if (!event) return NULL;

            int eventDomain;
            int eventCode;

            eventDomain = bps_event_get_domain(event);
            if( eventDomain == sl_ANEDomain ){
               eventCode = bps_event_get_code(event);
               switch( eventCode ){
                  case CREATE_CLIENT: {
                     SC_Error_t code = SC_Client_New(&(appData->client),sl_initData,
                                                     sl_gameID,sl_gameSecret,sl_gameVersion,
                                                     sl_currency,sl_langs);
                     if( code == SC_OK ) clientCreated = true;
                     else cout << "Client creation failed !!!!!!!!!! [" << code <<"]" << endl;
                     break;
                  }
               }
            }

            cout << "Attempting to create current user controller" << endl;
            SC_Error_t code = SC_Client_CreateUserController(appData->client, &(appData->currentUserController),
                                                             &currentUserRequestCompleted, NULL);
            if( code == SC_OK ) userControllersCreated = true;
            else cout << "UserController creation failed !!!!!!!!!! [" << code << "]" << endl;

            //Get the current user
            if( clientCreated && userControllersCreated ) sl_threadState = SL_LOADING;
            break;
         }
         case SL_LOADING: {
            cout << "Attempting to load user data" << endl;
            SC_Error_t code = SC_UserController_LoadUser(appData->currentUserController);
            cout << "Result: " << code << endl;

            sl_threadState = SL_RUNNING;
            break;
         }
         case SL_RUNNING: {
            cout << "Entering run state for SL Main Thread" << endl;
            bps_event_t *event;
            bps_get_event(&event, -1);
            if (!event) return NULL;

            if (bps_event_get_domain(event) == sl_ANEDomain) SC_HandleBPSEvent(sl_initData, event);


            break;
         }
         case SL_STOPPING:
            break;

         case SL_STOPPED:
            break;
      }

      if( sl_threadState == SL_STOPPED ) break;
   }

   SC_Client_Release(appData->client);
   bps_shutdown();

   return NULL;
}

static void bpsEventComplete(bps_event_t *event){
   bps_event_destroy(event);
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
   //FRENewObjectFromInt32(sl_initData->eventDomain,&result);
   FRENewObjectFromInt32(SC_GetBPSEventDomain(sl_initData),&result);
   return result;
}


#ifdef __cplusplus
}
#endif



