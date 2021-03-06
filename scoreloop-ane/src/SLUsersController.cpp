/*
 * SLUsersController.cpp
 *
 *  Created on: Feb 16, 2013
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


//==============================================================================================
//                         ScoreLoop sc_users_controller.h Function Stubs
//==============================================================================================

/**
 * @brief Sets the maximum number of user objects to be matched per server request.
 *
 * Sets the upper limit for the total number of matched users to be returned. User searches where positive matches
 * exceed this limit will not return the array of users.
 * This means that calling SC_UsersController_GetUsers() in these cases will return an empty list. However, the count of
 * positive matches will still be accessible using SC_UsersController_GetUsersCount().
 *
 * Note that Scoreloop includes an automatic upper limit of 999 on search matches.
 *
 * @param   self        SC_UsersController instance handle
 * @param   limit       The maximum number of users to be matched per server request.
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_UsersController_SetSearchLimit(SC_UsersController_h self, unsigned int limit);
FREObject sl_ane_SC_UsersController_SetSearchLimit(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   uint32_t limit;
   FREGetObjectAsUint32(argv[0],&limit);

   SC_Error_t code = SC_UsersController_SetSearchLimit(appData->usersController,limit);

   FREObject result;
   FRENewObjectFromInt32(code,&result);
   return result;
}

/**
 * @brief Returns the maximum number of user objects to be matched per server request.
 *
 * The search request will stop once this limit has been reached. If the number of positive matches
 * on the server exceeds this limit then the matched user objects will not be accessible.
 * This means that calling SC_UsersController_GetUsers() in these cases will return an empty list. However, the count of
 * positive matches will still be accessible using SC_UsersController_GetUsersCount().
 *
 * Note that Scoreloop includes an automatic upper limit of 999 on search matches.
 *
 * @param   self        SC_UsersController instance handle
 * @return unsigned int Integer corresponding to this limit
 * \sa SC_UsersController_GetUsersCount(), SC_UsersController_IsOverLimit()
 */
//SC_PUBLISHED unsigned int SC_UsersController_GetSearchLimit(SC_UsersController_h self);
FREObject sl_ane_SC_UsersController_GetSearchLimit(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   uint32_t limit = SC_UsersController_GetSearchLimit(appData->usersController);

   FREObject result;
   FRENewObjectFromInt32(limit,&result);
   return result;
}

/**
 * @brief Returns the list of user objects that have been successfully retrieved from the server after calling one of the search methods.
 *
 * After a successful server request, the user objects that are retrieved will normally be accessible using this accessor.
 *
 * In cases where the number of positive matches found on the server exceeds the value set by calling SC_UsersController_SetSearchLimit(), then
 * this method will return an empty list.
 *
 * @param   self        SC_UsersController instance handle
 * @return SC_UserList_h The list of user objects retrieved from the server.
 */
//SC_PUBLISHED SC_UserList_h SC_UsersController_GetUsers(SC_UsersController_h self);
FREObject sl_ane_SC_UsersController_GetUsers(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   userList = SC_UsersController_GetUsers(appData->usersController);

   FREObject result;
   FRENewObjectFromUint32(SC_UserList_GetCount(userList),&result);
   return result;
}

/**
 * @brief Returns the value for the flag that indicates whether the search request should extend beyond the current game.
 *
 * This method can be used to check if the search request extends beyond the current game.
 * This method returns SC_TRUE when the search request extends beyond the current game otherwise SC_FALSE.
 *
 * @param   self        SC_UsersController instance handle
 * @return SC_Bool_t SC_FALSE, if the search is restricted to the current game only. SC_TRUE, if the search is set to users of any Scoreloop game.
 */
//SC_PUBLISHED SC_Bool_t SC_UsersController_GetSearchesGlobal(SC_UsersController_h self);
FREObject sl_ane_SC_UsersController_GetSearchesGlobal(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   SC_Bool_t enabled = SC_UsersController_GetSearchesGlobal(appData->usersController);

   FREObject result;
   FRENewObjectFromUint32(enabled,&result);
   return result;
}

/**
 * @brief Sets the flag extending the search request beyond the current game.
 *
 * This method sets the flag to extend the search request beyond the current game.
 * Set the searchesGlobal parameter to SC_TRUE to retrieve users of any Scoreloop game.
 * Set the searchesGlobal parameter to SC_FALSE to retrieve users of the current game only.
 *
 * @param self          SC_UsersController instance handle
 * @param searchesGlobal   Set this flag to @c SC_TRUE to retrieve users of any Scoreloop game.
 *                   Set this flag to @c SC_FALSE to retrieve users of the current game only.
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_UsersController_SetSearchesGlobal(SC_UsersController_h self, SC_Bool_t searchesGlobal);
FREObject sl_ane_SC_UsersController_SetSearchesGlobal(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   uint32_t enabled;
   FREGetObjectAsUint32(argv[0],&enabled);

   SC_Error_t code = SC_UsersController_SetSearchesGlobal(appData->usersController,(SC_Bool_t)enabled);

   FREObject result;
   FRENewObjectFromInt32(code,&result);
   return result;
}

/**
 * @brief Requests user objects from the server for the user whose login matches the supplied string.
 *
 * Note that this is an asynchronous call and a callback will be triggered. After a successful server request, the
 * user objects that are retrieved can be accessed by calling SC_UsersController_GetUsers().
 * The total count of positive matches found on the server can be accessed by calling SC_UsersController_GetUsersCount().
 *
 * If the number of matched user objects exceeds the limit set by the developer, then the matched users will not be accessible.
 * This means that calling SC_UsersController_GetUsers() in this case will return an empty list. However, the count of
 * positive matches will still be accessible by using SC_UsersController_GetUsersCount().
 *
 * @param   self        SC_UsersController instance handle
 * @param   login       The search string.
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_UsersController_SearchByLogin(SC_UsersController_h self, const char *login);
FREObject sl_ane_SC_UsersController_SearchByLogin(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   const uint8_t *login;
   uint32_t      login_len;

   FREGetObjectAsUint32(argv[1],&login_len);

   char *login_name = (char*)malloc(login_len+1);
   FREGetObjectAsUTF8(argv[0], &login_len, &login );
   strncpy(login_name,(char*)login,login_len);
   login_name[login_len] = '\0';

   SC_Error_t code = SC_UsersController_SearchByLogin(appData->usersController,login_name);

   FREObject result;
   FRENewObjectFromInt32(code,&result);
   return result;
}

/**
 * @brief Requests user objects from the server for the user whose email address matches the supplied string.
 *
 *  Note that this is an asynchronous call and a callback will be triggered. After a successful server request, the
 *  user objects that are retrieved can be accessed by calling SC_UsersController_GetUsers().
 *  The total count of positive matches found on the server can be accessed by
 *  calling SC_UsersController_GetUsersCount().
 *
 *  If the number of matched user objects exceeds the
 *  limit set by the developer, then the matched users
 *  will not be accessible.
 * This means that calling SC_UsersController_GetUsers() in this case will return an empty list. However, the count of
 * positive matches will still be accessible by using SC_UsersController_GetUsersCount().
 *
 * @param   self        SC_UsersController instance handle
 * @param   email       The search string.
 * @return SC_Error_t   A return code (A value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_UsersController_SearchByEmail(SC_UsersController_h self, const char *email);
FREObject sl_ane_SC_UsersController_SearchByEmail(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   const uint8_t *email;
   uint32_t      email_len;

   FREGetObjectAsUint32(argv[1],&email_len);

   char *email_addy = (char*)malloc(email_len+1);
   FREGetObjectAsUTF8(argv[0], &email_len, &email );
   strncpy(email_addy,(char*)email,email_len);
   email_addy[email_len] = '\0';

   SC_Error_t code = SC_UsersController_SearchByEmail(appData->usersController,email_addy);

   FREObject result;
   FRENewObjectFromInt32(code,&result);
   return result;
}

/**
 * @brief Requests the buddy list of the user that is returned by SC_UsersController_GetUsers().
 *
 * If no user has been explicitly set, the buddy list of the session
 * user is requested instead.
 *
 * Note that this is an asynchronous call and a callback will be triggered. After a successful request, you can access the buddy list by calling
 * SC_UsersController_GetUsers().
 *
 * @param  self         SC_UserController instance handle
 * @param  user         The user whose buddy list is requested.
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 * @sa User
  */
//SC_PUBLISHED SC_Error_t SC_UsersController_LoadBuddies(SC_UsersController_h self, SC_User_h user);
FREObject sl_ane_SC_UsersController_LoadBuddies(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   SC_Error_t code = 0; //SC_UsersController_LoadBuddies(appData->usersController,limit);

   FREObject result;
   FRENewObjectFromInt32(code,&result);
   return result;
}

/**
 * @brief Reports whether the search limit was exceeded or not.
 *
 * This method will return the value SC_TRUE if the number of
 * positive matches found on the server exceeds the value
 * set by SC_UsersController_SetSearchLimit(). Otherwise, it will have the value SC_FALSE.
 *
 * @param   self        SC_UsersController instance handle
 * @return SC_Bool_t True, when more search results were found than defined by using SC_UsersController_SetSearchLimit().
 */
//SC_PUBLISHED SC_Bool_t SC_UsersController_IsOverLimit(SC_UsersController_h self);
FREObject sl_ane_SC_UsersController_IsOverLimit(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   SC_Bool_t over = SC_UsersController_IsOverLimit(appData->usersController);

   FREObject result;
   FRENewObjectFromUint32(over,&result);
   return result;
}

/**
 * @brief Returns the total number of users matched on the server.
 *
 * After a successful server request, this
 * property will store the total count of
 * positive user matches found on the server.
 *
 * @param   self        SC_UsersController instance handle
 * @return unsigned int, An int corresponding to the number of users matched. Has an upper limit of 999.
 */
//SC_PUBLISHED unsigned int SC_UsersController_GetUsersCount(SC_UsersController_h self);
FREObject sl_ane_SC_UsersController_GetUsersCount(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   uint32_t count = SC_UsersController_GetUsersCount(appData->usersController);

   FREObject result;
   FRENewObjectFromUint32(count,&result);
   return result;
}


#ifdef __cplusplus
}
#endif


