/*
 * Globals.h
 *
 *  Created on: Feb 12, 2013
 *      Author: CHRIS
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include <pthread.h>
#include <unistd.h>

#include <bps/bps.h>
#include <scoreloopcore.h>
#include <FlashRuntimeExtensions.h>

#include "SLVersion.h"
#include "SLInit.h"
#include "SLClient.h"
#include "SLSession.h"
#include "SLUser.h"
#include "SLUserController.h"
#include "SLUserList.h"
#include "SLUsersController.h"

//HEADER ONLY - NO NEED TO CONVERT
//sc_platform.h
//sc_types.h
//sc_range.h
//
//No Needed functions - NO NEED TO CONVERT
//sc_user_handle.h
//



#ifndef SL_ANE_GLOBALS_H_
#define SL_ANE_GLOBALS_H_


#ifdef __cplusplus
extern "C" {
#endif

/* Some simple logging */
#define LOG(fmt, args...) do { fprintf(stdout, "[Scoreloop ANE] " fmt "\n", ##args); fflush(stdout); } while (0);


typedef struct AppData_tag {
    SC_Client_h                      client;
    //SC_Score_h                       score;
    SC_UserController_h              currentUserController;
    SC_UserController_h              userController;
    SC_UsersController_h             usersController;
    //SC_ScoreController_h             scoreController;
    //SC_ScoresController_h            scoresController;
    //SC_LocalAchievementsController_h achievementsController;
    //SC_ChallengeController_h         challengeController;
    //SC_ChallengesController_h        challengesController;
} SL_AppData_s;
extern SL_AppData_s *appData;

extern FREContext currentContext;



#ifdef __cplusplus
}
#endif

#endif /* GLOBALS_H_ */


