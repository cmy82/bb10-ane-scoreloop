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


//==============================================================================================
//                         Custom Functions
//==============================================================================================


//==============================================================================================
//                         ScoreLoop sc_init.h Function Stubs
//==============================================================================================

//SC_PUBLISHED SC_Error_t SC_Client_New(SC_Client_h* pSelf, SC_InitData_t* initData,
//        const char* gameIdentifier, const char* gameSecret, const char* gameVersion, const char *currency,
//        const char* languages);
FREObject sl_ane_SC_Client_New(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   const uint8_t *gameID,    *gameSecret,    *gameVersion,    *currency,    *languages;
   uint32_t       gameID_len, gameSecret_len, gameVersion_len, currency_len, languages_len;

   cout << "Loading data for SC Client struct" << endl;
   FREGetObjectAsUint32(argv[1],&gameID_len);
   FREGetObjectAsUint32(argv[3],&gameSecret_len);
   FREGetObjectAsUint32(argv[5],&gameVersion_len);
   FREGetObjectAsUint32(argv[7],&currency_len);
   FREGetObjectAsUint32(argv[9],&languages_len);

   char *gameid = (char*)malloc(gameID_len+1);
   FREGetObjectAsUTF8(argv[0], &gameID_len, &gameID );
   strncpy(gameid,(char*)gameID,gameID_len);
   gameid[gameID_len] = '\0';

   char *gamesecret = (char*)malloc(gameSecret_len+1);
   FREGetObjectAsUTF8(argv[2], &gameSecret_len, &gameSecret );
   strncpy(gamesecret,(char*)gameSecret,gameSecret_len);
   gamesecret[gameSecret_len] = '\0';

   char *gameversion = (char*)malloc(gameVersion_len+1);
   FREGetObjectAsUTF8(argv[4], &gameVersion_len, &gameVersion );
   strncpy(gameversion,(char*)gameVersion,gameVersion_len);
   gameversion[gameVersion_len] = '\0';

   char *currncy = (char*)malloc(currency_len+1);
   FREGetObjectAsUTF8(argv[6], &currency_len, &currency );
   strncpy(currncy,(char*)currency,currency_len);
   currncy[currency_len] = '\0';

   char *langs = (char*)malloc(languages_len+1);
   FREGetObjectAsUTF8(argv[8], &languages_len, &languages );
   strncpy(langs,(char*)languages,languages_len);
   langs[languages_len] = '\0';

   cout << "About to create SC Client struct" << endl;
   SC_Error_t code = SC_Client_New(&(appData->client),sl_initData,gameid,gamesecret,gameversion,currncy,langs);
   FREObject result;
   FRENewObjectFromInt32(code,&result);
   return result;
}



#ifdef __cplusplus
}
#endif


