/*
 * SLClient.h
 *
 *  Created on: Feb 13, 2013
 *      Author: CHRIS
 */


#include <FlashRuntimeExtensions.h>


#ifndef SL_ANE_SLCLIENT_H_
#define SL_ANE_SLCLIENT_H_


#ifdef __cplusplus
extern "C" {
#endif

//==============================================================================================
//                         Variables
//==============================================================================================

extern char *sl_gameID;
extern char *sl_gameSecret;
extern char *sl_gameVersion;
extern char *sl_currency;
extern char *sl_langs;

extern bool clientCreationSuccessful;

//==============================================================================================
//                         Custom Functions
//==============================================================================================

void clientCreationComplete(bps_event_t *event);

//==============================================================================================
//                         ScoreLoop sc_init.h Function Stubs
//==============================================================================================

/**
 * @brief Creates a new instance of SC_Client.
 *
 * This method creates the SC_Client instance and initializes it.
 * It initializes the PAL Context and creates a session (with the new game object created).
 * The game object is created with the ID, secret and currency passed as input parameters to this method.
 *
 * @param pSelf A pointer to the SC_Client struct.
 * @param initData A pointer to the SC_InitData struct. The initData variable has to have the same lifetime as the client variable.
 * @param gameIdentifier The unique game identifier assigned by Scoreloop when
 *  the game was registered on
 *  <a href="https://developer.scoreloop.com">https://developer.scoreloop.com</a>.
 * @param gameSecret The unique game secret assigned by Scoreloop
 * when the game was registered on
 * <a href="https://developer.scoreloop.com">https://developer.scoreloop.com</a>.
 * @param gameVersion The version of the game in the format "<MajorVersion>.<MinorVersion>", e.g. "1.0".
 * In the case of a  wrong format SC_INVALID_ARGUMENT is returned.
 * @param currency The unique game specific currency code assigned by Scoreloop when the game was registered on
 *  <a href="https://developer.scoreloop.com">https://developer.scoreloop.com</a>.
 * @param languages A comma-separated list of languages the game supports. e.g., for English, pass "en". This parameter is mandatory if the game supports localization of Awards.
 * The current language on the device is intersected with the given list and all Scoreloop supported languages. If an intersection is found, the intersected language will be used.
 * If there is no intersection the first language from the given list is used. English ("en") will be used if NULL is passed.
 * \n Example:\n
 * List of languages supported by game: ['en', 'en_US', 'de', 'pl']
 * <table>
 * <tr><td>Current Language of OS</td><td>Language used</td></tr>
 * <tr><td> 'en_US' </td><td>'en_US'</td></tr>
 * <tr><td> 'en_UK' </td><td>'en'</td></tr>
 * <tr><td> 'pl_PL' </td><td>'pl'</td></tr>
 * <tr><td> 'de' </td><td>'de'</td></tr>
 * <tr><td> 'it' </td><td>'en'</td></tr>
 * </table>
 * Note that the awards bundle needs to be localized to all given languages.
 * @return SC_Error_t A return code (A value of SC_OK indicates success, any other value indicates an error).
 *
 * @note
 * - The object is created with a reference count equal to 1.
 * - On BlackBerry,
 *      - this call will prompt for BBID credentials.
 *      - only local game play is possible in CORPORATE LIABLE MODE. Here, the device forbids the use of Scoreloop. A connection request returns error code SC_DISABLED_DUE_TO_CORPORATE_LIABLE_MODE which needs to be handled.
 *      - This is a synchronous call and might take sometime to return, blocking your thread in the meantime. To avoid your game from being slayed by the system, call SC_Client_New only after a window is open in the game.
 */
//SC_PUBLISHED SC_Error_t SC_Client_New(SC_Client_h* pSelf, SC_InitData_t* initData,
//        const char* gameIdentifier, const char* gameSecret, const char* gameVersion, const char *currency,
//        const char* languages);
FREObject sl_ane_SC_Client_New(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);


#ifdef __cplusplus
}
#endif


#endif /* SLCLIENT_H_ */
