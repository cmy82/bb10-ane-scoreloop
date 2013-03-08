/*
 * SLUserController.cpp
 *
 *  Created on: Feb 23, 2013
 *      Author: hu77
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

void currentUserRequestCompleted(void* userData, SC_Error_t completionStatus){
   cout << "User request callback initiated" << endl;
   /* Check completion status */
   if (completionStatus != SC_OK) {
      SC_UserController_Release(appData->currentUserController); /* Cleanup Controller */
      cout << SC_MapErrorToStr(completionStatus) << endl;
      return;
   }

   /* Get the session from the client. */
   SC_Session_h session = SC_Client_GetSession(appData->client);

   /* Get the session user from the session. */
   SC_User_h user = SC_Session_GetUser(session);

   /* Write out some user data */
   SC_String_h login = SC_User_GetLogin(user);
   LOG(" User's login: %s", login ? SC_String_GetData(login) : "<unknown>");
   //LOG("Scoreloop login name: %s", login ? SC_String_GetData(login) : "<unknown>");
   SC_String_h email = SC_User_GetEmail(user);
   LOG(" User's email: %s", email ? SC_String_GetData(email) : "<unknown>");
}

//==============================================================================================
//                         ScoreLoop sc_user_controller.h Function Stubs
//==============================================================================================




#ifdef __cplusplus
}
#endif


