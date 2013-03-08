/*
 * SLUserController.h
 *
 *  Created on: Feb 23, 2013
 *      Author: hu77
 */


#include <FlashRuntimeExtensions.h>


#ifndef _SLANE_SLUSERCONTROLLER_H_
#define _SLANE_SLUSERCONTROLLER_H_


#ifdef __cplusplus
extern "C" {
#endif


//==============================================================================================
//                         Variables
//==============================================================================================


//==============================================================================================
//                         Custom Functions
//==============================================================================================

void currentUserRequestCompleted(void* userData, SC_Error_t completionStatus);

//==============================================================================================
//                         ScoreLoop sc_user_controller.h Function Stubs
//==============================================================================================

/**
 * @brief Returns the user currently set for the controller.
 *
 * If the user is not explicitly set,
 * the controller will
 * deal with the current session user instead.
 *
 * @param   self        SC_UserController instance handle
 * @return SC_User_h     The user currently set for the controller.
 */
//SC_PUBLISHED SC_User_h SC_UserController_GetUser(SC_UserController_h self);
//FREObject sl_ane_SC_GetBPSEventDomain(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Sets the user object that the controller should deal with.
 *
 * If the user is not explicitly set,the controller will
 * deal with the current session user instead.
 *
 * @param   self        SC_UserController instance handle
 * @param   user        The SC_User object that the controller will deal with.
 * @return SC_Error_t A return code (a value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_UserController_SetUser(SC_UserController_h self, SC_User_h user);

/**
 * @brief Requests attribute information for the user. User is given as handle.
 *
 * If no user has been provided, attributes for the current
 * session user will be requested instead. Note that this is an asynchronous call and a callback will be
 * triggered, after which you can access the retrieved user by calling SC_UserController_GetUser().
 *
 * @param  self       SC_UserController instance handle
 * @param  userHandle User handle to load info for.
 * @return SC_Error_t A return code (a value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_UserController_LoadUserFromHandle(SC_UserController_h self, SC_UserHandle_h userHandle);

/**
 * @brief Requests attribute information for the user.
 *
 * If no user has been explicitly set, attributes for the current
 * session user will be requested instead. Note that this is an asynchronous call and a callback will be
 * triggered, after which you can access the retrieved user by calling SC_UserController_GetUser().
 *
 * @param   self        SC_UserController instance handle
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_UserController_LoadUser(SC_UserController_h self);

/**
 * @brief Pushes updates of the current session user's attributes to the server.
 *
 * This method updates a user's attributes on the Scoreloop server. Only the session user can be updated in thisc way.
 * Note that this is an asynchronous call and a callback will be triggered upon success or failure.
 *
 * @param   self        SC_UserController instance handle
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 *
 * If the error code returned indicates SC_INVALID_USER_DATA, you must call SC_UserController_GetValidationErrors()
 * to figure out the exact causes of the failure, for example, SC_EMAIL_ALREADY_TAKEN, SC_EMAIL_FORMAT_INVALID, SC_USERNAME_ALREADY_TAKEN,
 * or SC_USERNAME_FORMAT_INVALID. It may also return SC_EMAIL_ALREADY_TAKEN + SC_USERNAME_FORMAT_INVALID.
 * In case of SC_EMAIL_ALREADY_TAKEN, an E-mail is sent to the given E-mail address with a link to manage the accounts(merge/transfer device).
 * Please see SC_UserController_GetValidationErrors() for more details.
 */
//SC_PUBLISHED SC_Error_t SC_UserController_UpdateUser(SC_UserController_h self);

/**
 * @brief Adds the user returned by SC_UserController_GetUser() to the buddy list of the session user.
 *
 * This method adds the user that is returned by SC_UserController_GetUser()
 * to the buddy list of the current session user.
 * It also verifies, if current session user, tries to become a buddy of himself.
 *
 * Note that this is an asynchronous call and a callback will be triggered upon success or failure.
 *
 * @param   self        SC_UserController instance handle
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 * @sa removeAsBuddy
 */
//SC_PUBLISHED SC_Error_t SC_UserController_AddAsBuddy(SC_UserController_h self);

/**
 * @brief Removes the user that is returned by SC_UserController_GetUser()
 * from the buddy list of the current session user.
 * It also verifies, if current session user, tries to remove itself from the buddylist.
 *
 * Note that this is an asynchronous call and a callback will be triggered upon success or failure.
 *
 * @param   self        SC_UserController instance handle
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_UserController_RemoveAsBuddy(SC_UserController_h self);

/**
 * @brief Returns the bitmask of validation errors that occurred while updating the user data.
 *
 * This method returns the bitmask of validation errors that occurred while updating the user data. The errors
 * that could occur include SC_EMAIL_ALREADY_TAKEN, SC_EMAIL_FORMAT_INVALID, SC_USERNAME_ALREADY_TAKEN,
 * or SC_USERNAME_FORMAT_INVALID
 *
 * @param   self        SC_UserController instance handle
 * @return SC_UserValidationError_t Lists all possible reasons for user update failure.
 */
//SC_PUBLISHED SC_UserValidationError_t SC_UserController_GetValidationErrors(SC_UserController_h self);

/**
 * @brief Returns the proposed available user logins.
 *
 * This method returns the list of available user names the user can chose from. This method should
 * be called if a call to SC_UserController_GetValidationErrors() indicates SC_USERNAME_ALREADY_TAKEN.
 *
 * @param   self        SC_UserController instance handle
 * @return SC_StringList_h  Lists off proposed user names.
 */
//SC_PUBLISHED SC_StringList_h SC_UserController_GetProposedUserNames(SC_UserController_h self);

/**
 * @brief Cancels any ongoing request or operation initiated by this particular controller instance.
 *
 * This method cancels any ongoing request or operation that is initiated by this particular controller instance.
 *
 * @param self An opaque handle of the user controller instance.
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_UserController_Cancel(SC_UserController_h self);

/**
 * @brief Requests the context of the user.
 *
 * If no user has been explicitly set, the context for the session user will be requested instead.
 * After a successful request, you can access the context by calling SC_User's SC_User_GetContext().
 *
 * @param  self        SC_UserController instance handle
 * @return SC_Error_t  A return code (a value of SC_OK indicates success, any other value indicates an error).
 * @sa SC_User
 */
//SC_PUBLISHED SC_Error_t SC_UserController_LoadUserContext(SC_UserController_h self);

/**
 * @brief Pushes the updated user's context to the server.
 *
 * Any user can be updated in this way.
 *
 * Note: Only the most recent context, requested by SC_UserController_LoadUserContext, can be updated.
 * If the context was updated in the meantime by some other client, a delegate callback will be called with
 * SC_CONTEXT_VERSION_MISMATCH. SC_User_GetContext will then contain the most recent server context and
 * SC_User_GetOldContext will contain the context that was sent with the last SC_UserController_UpdateUserContext.
 *
 * Note that this is an asynchronous call and a callback will be triggered upon success or failure.
 *
 * @param   self        SC_UserController instance handle
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 * @sa SC_User
 */
//SC_PUBLISHED SC_Error_t SC_UserController_UpdateUserContext(SC_UserController_h self);


#ifdef __cplusplus
}
#endif



#endif /* SLUSERCONTROLLER_H_ */
