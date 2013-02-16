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
#include "SLUsersController.h"
#include "SLUserList.h"

//HEADER ONLY - NO NEED TO CONVERT
//sc_platform.h
//sc_types.h
//sc_range.h
//


#ifndef SL_ANE_GLOBALS_H_
#define SL_ANE_GLOBALS_H_


#ifdef __cplusplus
extern "C" {
#endif


typedef struct AppData_tag {
    SC_Client_h                      client;
    //SC_Score_h                       score;
    SC_UsersController_h              userController;
    //SC_UserController_h              userController;  //Original - possible typo
    //SC_ScoreController_h             scoreController;
    //SC_ScoresController_h            scoresController;
    //SC_LocalAchievementsController_h achievementsController;
    //SC_ChallengeController_h         challengeController;
    //SC_ChallengesController_h        challengesController;
    //screen_context_t                 screenContext;
    //screen_window_t                  screenWindow;
    //dialog_instance_t                dialog;
} SL_AppData_s;

extern SL_AppData_s *appData;

extern FREContext currentContext;



#ifdef __cplusplus
}
#endif

#endif /* GLOBALS_H_ */


