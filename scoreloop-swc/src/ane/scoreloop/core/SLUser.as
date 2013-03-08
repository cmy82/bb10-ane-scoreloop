package ane.scoreloop.core {
   import flash.external.ExtensionContext;
   
   public class SLUser {
      private var _context:ExtensionContext;
      
      public function SLUser(context:ExtensionContext) {
         _context = context;
      }
      
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
      public function sl_ane_SC_User_SetLogin(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);
      
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
      public function sl_ane_SC_User_GetLogin(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);
      
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
      public function sl_ane_SC_User_SetEmail(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);
      
      /**
       * @brief Returns the user's email address.
       *
       * This method returns the session user's email address.
       *
       * @param self An opaque handle for the current SC_User instance.
       * @return SC_String_h The email address of the user.
       */
      //SC_PUBLISHED SC_String_h SC_User_GetEmail(SC_User_h self);
      public function sl_ane_SC_User_GetEmail(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);
      
      /**
       * @brief Returns the number of Scoreloop-enabled games that the user has played.
       *
       * This method returns the number of Scoreloop-enabled games that the user has played.
       *
       * @param self An opaque handle for the current SC_User instance.
       * @return int The number of games that the user has played.
       */
      //SC_PUBLISHED int SC_User_GetGamesCount(SC_User_h self);
      public function sl_ane_SC_User_GetGamesCount(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);
      
      /**
       * @brief Returns the number of achievements of the user across all games that they have played until now.
       *
       * This methid returns the number of achievements of the user across all games that they have played until now.
       *
       * @param self An opaque handle for the current SC_User instance.
       * @return int The number of achievements
       */
      //SC_PUBLISHED int SC_User_GetGlobalAchievementsCount(SC_User_h self);
      public function sl_ane_SC_User_GetGlobalAchievementsCount(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);
      
      /**
       * @brief Returns the number of buddies the user has.
       *
       * This methid returns the number of buddies the user has.
       *
       * @param self An opaque handle for the current SC_User instance.
       * @return int The number of buddies for the user.
       */
      //SC_PUBLISHED int SC_User_GetBuddiesCount(SC_User_h self);
      public function sl_ane_SC_User_GetBuddiesCount(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);
      
      /**
       * @brief Returns the URL of the user's image.
       *
       * This method returns the URL of the user's image.
       *
       * @param self An opaque handle for the current SC_User instance.
       * @return SC_String String representing the URL with user's image or NULL if it's unavailable.
       */
      //SC_PUBLISHED SC_String_h SC_User_GetImageUrl(SC_User_h self);
      public function sl_ane_SC_User_GetImageUrl(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);
      
      /**
       * @brief Returns the source of the image URL.
       *
       * This method returns the source of the image URL.
       *
       * @param self An opaque handle for the current SC_User instance.
       * @return SC_UserImageSource_t enum value representing source of the image.
       */
      //SC_PUBLISHED SC_UserImageSource_t SC_User_GetImageSource(SC_User_h self);
      public function sl_ane_SC_User_GetImageSource(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);
      
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
      public function sl_ane_SC_User_SetImageFromExternalService(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);
      
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
      public function sl_ane_SC_User_SetImageFromData(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);
      
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
      public function sl_ane_SC_User_ResetImage(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);
      
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
      public function sl_ane_SC_User_SetNationality(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);
      
      /**
       * @brief Returns the user's nationality.
       *
       * This method returns the nationality of the user.
       *
       * @param self An opaque handle for the current SC_User instance.
       * @return SC_String_h The nationality of the user.
       */
      //SC_PUBLISHED SC_String_h SC_User_GetNationality(SC_User_h self);
      public function sl_ane_SC_User_GetNationality(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);
      
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
      public function User_IsChallengeable(id:Number):Boolean {
         return _context.call( "sl_ane_SC_User_IsChallengeable", id ) as Boolean;
      }
      
      /**
       * @brief Compares two user objects.
       *
       * This method returns true if both objects are equal, otherwise it returns false.
       *
       * @param self An opaque handle for the current SC_User instance.
       * @param other An opaque handle for the another SC_User instance.
       * @return SC_Bool_t The result of the comparison, true/false.
       */
      public function User_Equals(id1:Number,id2:Number){
         return _context.call("sl_ane_SC_User_Equals", id1, id2 ) as Boolean;
      }
      
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
      public function User_GetState(id:Number):String {
         var rslt:Number = _context.call( "sl_ane_SC_User_GetState",id ) as Number;
         switch(rslt){
            case 0: return "SC_USER_STATE_ANONYMOUS";
            case 1: return "SC_USER_STATE_ACTIVE";
            case 2: return "SC_USER_STATE_DELETED";
            case 3: return "SC_USER_STATE_PASSIVE";
            case 4: return "SC_USER_STATE_PENDING";
            case 5: return "SC_USER_STATE_SUSPENDED";
         }
         return "SC_USER_STATE_UNKNOWN";
      }
      
      /**
       * @brief Examines the state of the user and checks if specified game belongs to favorite ones.
       *
       * This method returns true if given game appears on the list of favorite games, otherwise it returns false.
       *
       * @param self An opaque handle for the current SC_User instance.
       * @param game An opaque handle for game instance to find on the list of favorites.
       * @return SC_Bool_t The result of the check, true/false.
       */
      public function SC_User_IsFavoriteGame():Boolean {
         return _context.call("sl_ane_SC_User_IsFavoriteGame", null) as Boolean;
      }

   }
}