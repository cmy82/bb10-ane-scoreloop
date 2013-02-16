/*
 * SCUserList.cpp
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

extern SC_UserList_h userList;

//==============================================================================================
//                         Custom Functions
//==============================================================================================


//==============================================================================================
//                         ScoreLoop sc_users_controller.h Function Stubs
//==============================================================================================

/**
 * @brief Returns the number of users on the list.
 *
 * This method returns the total number of users on the list.
 *
 * @param self An opaque handle for the current SC_UserList instance.
 * @return unsigned int The number of users on the list.
 */
//SC_PUBLISHED unsigned int SC_UserList_GetCount(SC_UserList_h self);
FREObject sl_ane_SC_UserList_GetCount(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]){
   FREObject result;
   FRENewObjectFromUint32(SC_UserList_GetCount(userList),&result);
   return result;
}



#ifdef __cplusplus
}
#endif



