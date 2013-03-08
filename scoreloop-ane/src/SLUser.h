/*
 * SLUser.h
 *
 *  Created on: Mar 1, 2013
 *      Author: hu77
 */

/**
 * @file        sc_user.h
 * @brief       Models the game user.
 *
 * @addtogroup  SC_User
 * @{
 *
 * Instances of \ref SC_User model the game user.
 * Scoreloop considers users to be unique players tied to unique devices.
 * Instances of \ref SC_Session maintain an instance of the local user, referred to
 * as the session user.
 *
 * Instances of \ref SC_User that are not the session user may not have all
 * properties available.
 *
 * However, the following properties are always available:
 * - Identifier
 * - Login
 * - Display name
 *
 * Instances of \ref SC_User are available from:
 * -# The Scoreloop session - SC_Session_GetUser()
 * -# An instance of \ref SC_Score - SC_Score_GetUser()
 * -# An instance of \ref SC_UserController - SC_UserController_GetUser()
 * -# An instance of \ref SC_UsersController - SC_UsersController_GetUsers()
 * -# An instance of \ref SC_Challenge :
 *  - SC_Challenge_GetContender()
 *  - SC_Challenge_GetContestant()
 *  - SC_Challenge_GetLoser()
 *  - SC_Challenge_GetWinner()
 *
 * \ref SC_User objects are managed by two controllers:
 * -# The \ref SC_UserController is used to retrieve information for an arbitrary user from the server. It is also used to update the attributes of the session user.
 * -# The \ref SC_UsersController, retrieves lists of \ref SC_User objects from the server.
 */


#include <FlashRuntimeExtensions.h>
#include <map>


#ifndef _SLANE_SLUSER_H_
#define _SLANE_SLUSER_H_


#ifdef __cplusplus
extern "C" {
#endif


//==============================================================================================
//                         Variables
//==============================================================================================

extern SC_User_h sl_sessionUser;
extern std::map<SC_User_h,int> sl_userMap;

//==============================================================================================
//                         Custom Functions
//==============================================================================================


//==============================================================================================
//                         ScoreLoop sc_user.h Function Stubs
//==============================================================================================

/**
 * @brief Returns a handle to the user object.
 *
 * This method returns a unique handle of the user.
 * It plays a role of a wrapper around globally unique identifier on Scoreloop network.
 * The value hidden behind this handle will never change.
 *
 * @param self An opaque handle for the SC_User instance.
 * @return SC_UserHandle_h The handle of the user.
 */
SC_PUBLISHED SC_UserHandle_h SC_User_GetHandle(SC_User_h self);

/**
 * @brief Sets the user's login.
 *
 * This method is used to set the login of the user. The login is the preferred "display name" for the user. This method is available only to the session user.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @param login The preferred login name, UTF-8 encoded.
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 *
 */
//SC_PUBLISHED SC_Error_t SC_User_SetLogin(SC_User_h self, const char *login);
FREObject sl_ane_SC_User_SetLogin(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Returns the user's login.
 *
 * This method returns the login for the user.
 * This property is distinct from the user identifier. The login for the user can be changed.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @return SC_String_h The login of the user.
 */
//SC_PUBLISHED SC_String_h SC_User_GetLogin(SC_User_h self);
FREObject sl_ane_SC_User_GetLogin(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Sets the user's email address.
 *
 * This method is used to set the email address of the user.
 * This method is available only to the session user.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @param email The email address to be set, UTF-8 encoded.
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_User_SetEmail(SC_User_h self, const char *email);
FREObject sl_ane_SC_User_SetEmail(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Returns the user's email address.
 *
 * This method returns the session user's email address.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @return SC_String_h The email address of the user.
 */
//SC_PUBLISHED SC_String_h SC_User_GetEmail(SC_User_h self);
FREObject sl_ane_SC_User_GetEmail(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Returns the number of Scoreloop-enabled games that the user has played.
 *
 * This method returns the number of Scoreloop-enabled games that the user has played.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @return int The number of games that the user has played.
 */
//SC_PUBLISHED int SC_User_GetGamesCount(SC_User_h self);
FREObject sl_ane_SC_User_GetGamesCount(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Returns the number of achievements of the user across all games that they have played until now.
 *
 * This methid returns the number of achievements of the user across all games that they have played until now.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @return int The number of achievements
 */
//SC_PUBLISHED int SC_User_GetGlobalAchievementsCount(SC_User_h self);
FREObject sl_ane_SC_User_GetGlobalAchievementsCount(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Returns the number of buddies the user has.
 *
 * This methid returns the number of buddies the user has.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @return int The number of buddies for the user.
 */
//SC_PUBLISHED int SC_User_GetBuddiesCount(SC_User_h self);
FREObject sl_ane_SC_User_GetBuddiesCount(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Returns the URL of the user's image.
 *
 * This method returns the URL of the user's image.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @return SC_String String representing the URL with user's image or NULL if it's unavailable.
 */
//SC_PUBLISHED SC_String_h SC_User_GetImageUrl(SC_User_h self);
FREObject sl_ane_SC_User_GetImageUrl(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Returns the source of the image URL.
 *
 * This method returns the source of the image URL.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @return SC_UserImageSource_t enum value representing source of the image.
 */
//SC_PUBLISHED SC_UserImageSource_t SC_User_GetImageSource(SC_User_h self);
FREObject sl_ane_SC_User_GetImageSource(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Sets the user's image from an external source.
 *
 * After calling this method, the previous image becomes outdated, and
 * GetImageUrl returns NULL.
 * The request is sent to the server after a UserController calls UpdateUser.
 * The image is updated on the server side asynchronously.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @param source Correct external source value
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_User_SetImageFromExternalService(SC_User_h self,SC_UserImageSource_t source);
FREObject sl_ane_SC_User_SetImageFromExternalService(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Sets the user's image.
 *
 * This method is used to set the image of the user.
 *
 * After calling this method, the previous image becomes outdated, and
 * GetImageUrl returns NULL.
 * The image is sent to the server after a UserController calls UpdateUser, and
 * then the image URL containing the new image will become available.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @param imageData    Binary data containing new user's image in JPG or PNG format.
 * @param imageDataLen The length of binary data
 * @param imageMime    Mime type of the image. Currently "image/png" and "image/jpeg" are supported.
 * @return SC_Error_t  A return code (a value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_User_SetImageFromData(SC_User_h self,
//        const unsigned char *imageData, unsigned int imageDataLen,
//        const char *imageMime);
FREObject sl_ane_SC_User_SetImageFromData(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Removes the user's image.
 *
 * This method is used to remove the image of the user.
 *
 * After calling this method, the previous image becomes outdated, and
 * GetImageUrl returns NULL.
 * The image is removed from the server after a UserController calls UpdateUser.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_User_ResetImage(SC_User_h self);
FREObject sl_ane_SC_User_ResetImage(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Sets the user's nationality.
 *
 * This method sets the nationality of the user.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @param nationality The nationality of the user.
 * @return SC_Error_t A return code (a value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_User_SetNationality(SC_User_h self, const char *nationality);
FREObject sl_ane_SC_User_SetNationality(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Returns the user's nationality.
 *
 * This method returns the nationality of the user.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @return SC_String_h The nationality of the user.
 */
//SC_PUBLISHED SC_String_h SC_User_GetNationality(SC_User_h self);
FREObject sl_ane_SC_User_GetNationality(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief An accessor method that returns the game-specific context associated with user.
 *
 * This property becomes valid after a successful user context request. See
 * SC_UserController_LoadUserContext().
 * If the server doesn't return the context, the method returns NULL.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @return SC_Context_h Context of the user.
 */
//SC_PUBLISHED SC_Context_h SC_User_GetContext(SC_User_h self);

/**
 * @brief Sets the context for the user.
 *
 * This method is used to set the context of a user. The context is updated on the server with a call to
 * SC_UserController_UpdateUserContext.
 *
 * @param self     An opaque handle for the current SC_User instance.
 * @param context  New user's context
 * @return SC_Error_t   A return code (a value of SC_OK indicates success, any other value indicates an error).
 */
//SC_PUBLISHED SC_Error_t SC_User_SetContext(SC_User_h self, SC_Context_h context);

/**
 * @brief Examines the state of the user to see if they can be challenged or not.
 *
 * This method examines the state of the user to see if they can be challenged or not.
 *
 * @param self     An opaque handle for the SC_User instance.
 * @return SC_Bool_t SC_TRUE if the user can be challenged, otherwise SC_FALSE
 */
//SC_PUBLISHED SC_Bool_t SC_User_IsChallengable(SC_User_h self);
FREObject sl_ane_SC_User_IsChallengeable(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Returns the context sent to the server.
 *
 * This property is valid when SC_UserController_UpdateUserContext's callback is called with
 * SC_CONTEXT_VERSION_MISMATCH. In this case, SC_User_GetOutdatedContext contains the old context
 * that was sent to the server and which caused an error, SC_User_GetContext returns a new context that was
 * returned by the server.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @return SC_Context_h Old context
 */
//SC_PUBLISHED SC_Context_h SC_User_GetOutdatedContext(SC_User_h self);

/**
 * @brief Compares two user objects.
 *
 * This method returns true if both objects are equal, otherwise it returns false.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @param other An opaque handle for the another SC_User instance.
 * @return SC_Bool_t The result of the comparison, true/false.
 */
//SC_PUBLISHED SC_Bool_t SC_User_Equals(SC_User_h self, SC_User_h other);
FREObject sl_ane_SC_User_Equals(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Examines the state of the user.
 *
 * This method returns the current state of the user. The following states
 * are possible:
 * - SC_USER_STATE_ANONYMOUS
 * - SC_USER_STATE_ACTIVE
 * - SC_USER_STATE_DELETED
 * - SC_USER_STATE_PASSIVE
 * - SC_USER_STATE_PENDING
 * - SC_USER_STATE_SUSPENDED
 *
 * @param self An opaque handle for the current SC_User instance.
 * @return SC_UserState_t The state of the user.
 */
//SC_PUBLISHED SC_UserState_t SC_User_GetState(SC_User_h self);
FREObject sl_ane_SC_User_GetState(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Examines the state of the user and checks if specified game belongs to favorite ones.
 *
 * This method returns true if given game appears on the list of favorite games, otherwise it returns false.
 *
 * @param self An opaque handle for the current SC_User instance.
 * @param game An opaque handle for game instance to find on the list of favorites.
 * @return SC_Bool_t The result of the check, true/false.
 */
//SC_PUBLISHED SC_Bool_t SC_User_IsFavoriteGame(SC_User_h self, SC_Game_h game);
FREObject sl_ane_SC_User_IsFavoriteGame(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);


#ifdef __cplusplus
}
#endif


#endif /* SLUSER_H_ */
