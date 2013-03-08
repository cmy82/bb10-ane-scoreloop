/*
 * SLClient.cpp
 *
 *  Created on: Feb 13, 2013
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

char *sl_gameID      = NULL;
char *sl_gameSecret  = NULL;
char *sl_gameVersion = NULL;
char *sl_currency    = NULL;
char *sl_langs       = NULL;

bool clientCreationSuccessful = false;

//==============================================================================================
//                         Custom Functions
//==============================================================================================

void clientCreationComplete(bps_event_t *event){
   bps_event_destroy(event);
}

//==============================================================================================
//                         ScoreLoop sc_init.h Function Stubs
//==============================================================================================

//SC_PUBLISHED SC_Error_t SC_Client_New(SC_Client_h* pSelf, SC_InitData_t* initData,
//        const char* gameIdentifier, const char* gameSecret, const char* gameVersion, const char *currency,
//        const char* languages);
FREObject sl_ane_SC_Client_New(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   if( !clientCreationSuccessful ) clientCreationSuccessful = true;
   else return NULL;

   const uint8_t *gameID,    *gameSecret,    *gameVersion,    *currency,    *languages;
   uint32_t       gameID_len, gameSecret_len, gameVersion_len, currency_len, languages_len;

   cout << "Loading data for SC Client struct" << endl;
   FREGetObjectAsUint32(argv[1],&gameID_len);
   FREGetObjectAsUint32(argv[3],&gameSecret_len);
   FREGetObjectAsUint32(argv[5],&gameVersion_len);
   FREGetObjectAsUint32(argv[7],&currency_len);
   FREGetObjectAsUint32(argv[9],&languages_len);

   sl_gameID = (char*)malloc(gameID_len+1);
   FREGetObjectAsUTF8(argv[0], &gameID_len, &gameID );
   strncpy(sl_gameID,(char*)gameID,gameID_len);
   sl_gameID[gameID_len] = '\0';

   sl_gameSecret = (char*)malloc(gameSecret_len+1);
   FREGetObjectAsUTF8(argv[2], &gameSecret_len, &gameSecret );
   strncpy(sl_gameSecret,(char*)gameSecret,gameSecret_len);
   sl_gameSecret[gameSecret_len] = '\0';

   sl_gameVersion = (char*)malloc(gameVersion_len+1);
   FREGetObjectAsUTF8(argv[4], &gameVersion_len, &gameVersion );
   strncpy(sl_gameVersion,(char*)gameVersion,gameVersion_len);
   sl_gameVersion[gameVersion_len] = '\0';

   sl_currency = (char*)malloc(currency_len+1);
   FREGetObjectAsUTF8(argv[6], &currency_len, &currency );
   strncpy(sl_currency,(char*)currency,currency_len);
   sl_currency[currency_len] = '\0';

   sl_langs = (char*)malloc(languages_len+1);
   FREGetObjectAsUTF8(argv[8], &languages_len, &languages );
   strncpy(sl_langs,(char*)languages,languages_len);
   sl_langs[languages_len] = '\0';

   bps_initialize();
   bps_event_t *event;
   bps_event_create(&event, sl_ANEDomain, CREATE_CLIENT, NULL, &clientCreationComplete);
   int code = bps_channel_push_event(sl_ANEChannelID, event);
   bps_shutdown();

   FREObject result;
   FRENewObjectFromInt32(code,&result);
   return result;
}


#ifdef __cplusplus
}
#endif


