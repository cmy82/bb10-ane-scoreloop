/*
 * SLInit.h
 *
 *  Created on: Feb 12, 2013
 *      Author: CHRIS
 */


#include <FlashRuntimeExtensions.h>


#ifndef SL_ANE_SLINIT_H_
#define SL_ANE_SLINIT_H_


#ifdef __cplusplus
extern "C" {
#endif


//==============================================================================================
//                         Variables
//==============================================================================================

typedef enum {
   SL_INIT = 0,
   SL_RUNNING,
   SL_STOPPING,
   SL_STOPPED
} sl_ANEThreadState_e;

extern sl_ANEThreadState_e slThreadState;
extern SC_InitData_t       *sl_initData;

extern int sl_ANEDomain;
extern int sl_channelID;

//==============================================================================================
//                         Custom Functions
//==============================================================================================

void* initScoreLoopThread(void *data);

/**
 * @brief Allows you to set the minimum required version of the ScoreLoop Library
 *
 * Use this to assign the minimum required version of the ScoreLoop Library. Must be set before the
 * ANE enters the SL_RUNNING state
 *
 * @param version char pointer to a string that holds the version number
 * @return
 */
FREObject sl_ane_setMinimumVersion(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

//==============================================================================================
//                         ScoreLoop sc_init.h Function Stubs
//==============================================================================================

/**
 * @brief Returns the event domain used by ScoreLoop
 *
 * Use this method to query the event domain used by ScoreLoop in order to correctly dispatch BPS events.
 * The event domain will only be correctly set after a SC_Client instance was created.
 *
 * @param initData      A pointer to the init data
 * @return The BPS event domain used by ScoreLoop
 * @sa SC_InitData_t.eventDomain
 */
//SC_PUBLISHED int SC_GetBPSEventDomain(SC_InitData_t *initData);
FREObject sl_ane_SC_GetBPSEventDomain(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);



#ifdef __cplusplus
}
#endif


#endif /* SLINIT_H_ */
