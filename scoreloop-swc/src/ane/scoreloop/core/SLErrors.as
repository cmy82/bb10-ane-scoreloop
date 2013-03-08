package ane.scoreloop.core {   
   public class SLErrors {
      /** ScoreloopCore error codes. */
      public static const SC_OK:Number            = 0;                   /**< No error occurred. */
      public static const SC_OUT_OF_MEMORY:Number = 1;                   /**< Failed to allocate memory. */
      public static const SC_NOT_IMPLEMENTED_YET:Number = 2;             /**< Particular interface was not yet implemented. */
      public static const SC_NOT_SUPPORTED:Number = 3;                   /**< Particular functionality is not supported on this platform. */
      public static const SC_PAL_INITIALIZATION_FAILED:Number = 4;       /**< Pal context cannot be created with init data. */
      public static const SC_INVALID_STATE:Number = 5;                   /**< Invalid state of object. */
      public static const SC_UNKNOWN_AWARD:Number = 6;                   /**< Given award's identifier was unknown. */
      public static const SC_NOT_FOUND:Number = 7;                       /**< Requested object has not been found. */
      public static const SC_AWARDS_BUNDLE_NOT_FOUND:Number = 8;         /**< SLAwards.bundle directory has not been found. */
      public static const SC_INVALID_ARGUMENT:Number = 9;                       /**< Invalid argument has been passed to method. */
      public static const SC_SESSION_NOT_AUTHENTICATED:Number = 10;             /**< Session is not authenticated. */
      public static const SC_INVALID_AWARDS_BUNDLE:Number = 11;                 /**< Awards bundle is invalid. */
      public static const SC_SYNCHRONIZATION_IN_PROGRESS:Number = 12;           /**< Achievements synchronization already in progress. */
      public static const SC_SCORE_FORMATTER_CFG_NOT_FOUND:Number = 13;         /**< Score formatter configuration file is missing. */
      public static const SC_SCORE_FORMATTER_CFG_INVALID:Number = 14;           /**< Score formatter configuration file is invalid. */
      public static const SC_STRING_INVALID_UTF8:Number = 15;                   /**< The UTF8 sequence for an string is invalid */
      public static const SC_DEV_PERMISSION_DENIED:Number = 16;                 /**< Code failed to retrieve device ID due to permission restrictions. */
      public static const SC_DISABLED_DUE_TO_CORPORATE_LIABLE_MODE:Number = 17; /**< The device is in corporate liable mode which forbids the usage of scoreloop */
      
      /** Request-processing related codes */
      public static const SC_HTTP_SERVER_ERROR:Number = 100;       /**< Server returned non-200 response code. */
      public static const SC_INVALID_RANGE:Number = 101;           /**< User tried to load next/previous range when there is none available. */
      public static const SC_INVALID_SERVER_RESPONSE:Number = 102; /**< Invalid response received from server. */
      public static const SC_HANDSHAKE_FAILED:Number = 103;        /**< Handshake request wasn't successful. */
      public static const SC_REQUEST_FAILED:Number = 104;          /**< Request failed for other reason (server-side). */
      public static const SC_REQUEST_CANCELLED:Number = 105;       /**< Request has been cancelled by the submitter. */
      public static const SC_TOO_MANY_REQUETS_QUEUED:Number = 106; /**< There are too many requests in the queue now. */
      public static const SC_INVALID_GAME_ID:Number = 107;         /**< Invalid game id was used in handshake */
      public static const SC_USER_NOT_FOUND:Number = 108;          /**< Specified user doesn't exist */
      public static const SC_INACCESSIBLE_USER:Number = 109;       /**< Request in context of invalid user, e.g. asking for activities of a user that is not a friend of the session user */
      public static const SC_NO_NETWORK:Number = 110;              /**< Request failed due to no network connectivity */
      
      /** Challenge related codes */
      public static const SC_CHALLENGE_NOT_ENOUGH_MONEY:Number = 200; /**< There is not enough money to play the challenge. */
      public static const SC_CANNOT_ACCEPT_CHALLENGE:Number = 201;    /**< Challenge is not playable for user. */
      public static const SC_CANNOT_REJECT_CHALLENGE:Number = 202;    /**< User cannot reject challenge. */
      public static const SC_CHALLENGE_NOT_SET:Number = 203;          /**< Challenge is not set. */
      public static const SC_SCORE_MODE_DOES_NOT_MATCH:Number = 204;  /**< Score's mode does not match with challenge's mode. */
      public static const SC_CHALLENGE_WRONG_CURRENCY:Number = 205;   /**< Challenge submitted with currency different than the game defined on server. */
      
      /** User related error codes */
      public static const SC_INVALID_USER_DATA:Number = 300;         /**< User data validation failed when updating */
      public static const SC_CONTEXT_VERSION_MISMATCH:Number = 301;  /**< Could not update old user context. */
      public static const SC_INVALID_USER_IMAGE_FORMAT:Number = 302; /**< Provided image isn't proper JPEG nor PNG file */
      
      public static const SC_FILE_ERROR:Number = 400;           /**< Filesystem operation failed. */
      
      public static const SC_BUDDYHOOD_FAILED:Number = 450;             /**< Generic adding buddy failure */
      public static const SC_BUDDYHOOD_SELF_FAILED:Number = 451;        /**< Trying to add yourself as a buddy? */
      public static const SC_BUDDYHOOD_INVITATION_INVALID:Number = 452; /**< Buddyhood invitation invalid or expired */
      public static const SC_BUDDYHOOD_ALREADY_BUDDY:Number = 453;      /**< User is already a buddy */
      public static const SC_BUDDYHOOD_NOT_BUDDY:Number = 454;          /**< User is not a buddy */
      
      /* Social related error codes */
      public static const SC_AUTHORIZATION_FAILED:Number = 500;   /**< Authorization failed. */
      public static const SC_AUTHORIZATION_DENIED:Number = 501;   /**< Authorization denied by user. */
      public static const SC_AUTHORIZATION_CANCELED:Number = 502; /**< Authorization canceled by user. */
      
      /* Game-items related codes */
      public static const SC_GAMEITEM_NOT_PURCHASED:Number = 550; /**< Ownership validation check failed. */
      
      /* UI related codes */
      public static const SC_UI_ALREADY_DISPLAYED:Number = 2000; /**< UI already displayed a view and can't show another one until dismissed. */
      public static const SC_UI_SHOW_FAILED:Number = 2001;       /**< UI view displaying failed */
      public static const SC_UI_CLOSE_FAILED:Number = 2002;      /**< UI view closing failed */
      public static const SC_UI_MISSING_FIELD:Number = 2003;     /**< UI missed a field set, when invoking a view */
      public static const SC_UI_MISSING_VALUE:Number = 2004;     /**< UI missed a value set for a field, when invoking a view */
      
      /** Possible user profile validation errors (see SC_UserController_GetValidationErrors). */      
      public static const SC_EMAIL_ALREADY_TAKEN:Number = 0x1;               //(1 << 0),  /**< The E-mail is already registed */
      public static const SC_EMAIL_FORMAT_INVALID:Number = 0x10;             //(1 << 1),  /**< The format of the E-mail address id invalid  */
      public static const SC_USERNAME_ALREADY_TAKEN:Number = 0x100;          //(1 << 2),  /**< The username is already registered */
      public static const SC_USERNAME_FORMAT_INVALID:Number = 0x1000;        //(1 << 3),  /**< The format of the username is invalid */
      public static const SC_USERNAME_TOO_SHORT:Number = 0x10000;            //(1 << 4),  /**< The given username is too short */
      public static const SC_IMAGE_TOO_LARGE:Number = 0x100000;              //(1 << 5),  /**< The image is too large */
      public static const SC_IMAGE_UNSUPPORTED_MIME_TYPE:Number = 0x1000000; //(1 << 6),  /**< The image is of an unsupported type */
      public static const SC_USERNAME_TOO_LONG:Number = 0x10000000;          //(1 << 7),  /**< The given username is too long */
      public static const SC_USERNAME_INAPPROPRIATE:Number = 0x100000000;    //(1 << 8)   /**< The given username is inappropriate */
      
      public function SLErrors() {}
      
      public static function MapErrorToString(errorCode:Number):String {
         switch(errorCode){
            /** ScoreloopCore error codes. */
            case SC_OK:                                    return "No error occurred.";
            case SC_OUT_OF_MEMORY:                         return "Failed to allocate memory.";
            case SC_NOT_IMPLEMENTED_YET:                   return "Particular interface was not yet implemented.";
            case SC_NOT_SUPPORTED:                         return "Particular functionality is not supported on this platform.";
            case SC_PAL_INITIALIZATION_FAILED:             return "Pal context cannot be created with init data.";
            case SC_INVALID_STATE:                         return "Invalid state of object.";
            case SC_UNKNOWN_AWARD:                         return "Given award's identifier was unknown.";
            case SC_NOT_FOUND:                             return "Requested object has not been found.";
            case SC_AWARDS_BUNDLE_NOT_FOUND:               return "SLAwards.bundle directory has not been found.";
            case SC_INVALID_ARGUMENT:                      return "Invalid argument has been passed to method.";
            case SC_SESSION_NOT_AUTHENTICATED:             return "Session is not authenticated.";
            case SC_INVALID_AWARDS_BUNDLE:                 return "Awards bundle is invalid.";
            case SC_SYNCHRONIZATION_IN_PROGRESS:           return "Achievements synchronization already in progress.";
            case SC_SCORE_FORMATTER_CFG_NOT_FOUND:         return "Score formatter configuration file is missing.";
            case SC_SCORE_FORMATTER_CFG_INVALID:           return "Score formatter configuration file is invalid.";
            case SC_STRING_INVALID_UTF8:                   return "The UTF8 sequence for an string is invalid";
            case SC_DEV_PERMISSION_DENIED:                 return "Code failed to retrieve device ID due to permission restrictions.";
            case SC_DISABLED_DUE_TO_CORPORATE_LIABLE_MODE: return "The device is in corporate liable mode which forbids the usage of scoreloop";
            
            /** Request-processing related codes */
            case SC_HTTP_SERVER_ERROR:       return "Server returned non-200 response code.";
            case SC_INVALID_RANGE:           return "User tried to load next/previous range when there is none available.";
            case SC_INVALID_SERVER_RESPONSE: return "Invalid response received from server.";
            case SC_HANDSHAKE_FAILED:        return "Handshake request wasn't successful.";
            case SC_REQUEST_FAILED:          return "Request failed for other reason (server-side).";
            case SC_REQUEST_CANCELLED:       return "Request has been cancelled by the submitter.";
            case SC_TOO_MANY_REQUETS_QUEUED: return "There are too many requests in the queue now.";
            case SC_INVALID_GAME_ID:         return "Invalid game id was used in handshake";
            case SC_USER_NOT_FOUND:          return "Specified user doesn't exist";
            case SC_INACCESSIBLE_USER:       return "Request in context of invalid user, e.g. asking for activities of a user that is not a friend of the session user";
            case SC_NO_NETWORK:              return "Request failed due to no network connectivity";
            
            /** Challenge related codes */
            case SC_CHALLENGE_NOT_ENOUGH_MONEY: return "There is not enough money to play the challenge.";
            case SC_CANNOT_ACCEPT_CHALLENGE:    return "Challenge is not playable for user.";
            case SC_CANNOT_REJECT_CHALLENGE:    return "User cannot reject challenge.";
            case SC_CHALLENGE_NOT_SET:          return "Challenge is not set.";
            case SC_SCORE_MODE_DOES_NOT_MATCH:  return "Score's mode does not match with challenge's mode.";
            case SC_CHALLENGE_WRONG_CURRENCY:   return "Challenge submitted with currency different than the game defined on server.";
            
            /** User related error codes */
            case SC_INVALID_USER_DATA:         return "User data validation failed when updating";
            case SC_CONTEXT_VERSION_MISMATCH:  return "Could not update old user context.";
            case SC_INVALID_USER_IMAGE_FORMAT: return "Provided image isn't proper JPEG nor PNG file";
            
            case SC_FILE_ERROR:                return "Filesystem operation failed.";
            
            case SC_BUDDYHOOD_FAILED:             return "Generic adding buddy failure";
            case SC_BUDDYHOOD_SELF_FAILED:        return "Trying to add yourself as a buddy?";
            case SC_BUDDYHOOD_INVITATION_INVALID: return "Buddyhood invitation invalid or expired";
            case SC_BUDDYHOOD_ALREADY_BUDDY:      return "User is already a buddy";
            case SC_BUDDYHOOD_NOT_BUDDY:          return "User is not a buddy";
            
            /* Social related error codes */
            case SC_AUTHORIZATION_FAILED:   return "Authorization failed.";
            case SC_AUTHORIZATION_DENIED:   return "Authorization denied by user.";
            case SC_AUTHORIZATION_CANCELED: return "Authorization canceled by user.";
            
            /* Game-items related codes */
            case SC_GAMEITEM_NOT_PURCHASED: return "Ownership validation check failed.";
            
            /* UI related codes */
            case SC_UI_ALREADY_DISPLAYED: return "UI already displayed a view and can't show another one until dismissed.";
            case SC_UI_SHOW_FAILED:       return "UI view displaying failed";
            case SC_UI_CLOSE_FAILED:      return "UI view closing failed";
            case SC_UI_MISSING_FIELD:     return "UI missed a field set, when invoking a view";
            case SC_UI_MISSING_VALUE:     return "UI missed a value set for a field, when invoking a view";            
         }
         return "Unknown Error ["+errorCode+"]";
      }
   }
}






//SC_PUBLISHED const char * SC_MapErrorToStr(SC_Error_t error);

