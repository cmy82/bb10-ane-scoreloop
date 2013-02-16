/*
 * SCUserList.h
 *
 *  Created on: Feb 16, 2013
 *      Author: hu77
 */


#include <FlashRuntimeExtensions.h>


#ifndef SLANE_SCUSERLIST_H_
#define SLANE_SCUSERLIST_H_



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
//                         ScoreLoop sc_user_list.h Function Stubs
//==============================================================================================

/**
 * @brief Increments the object's reference count.
 *
 * This method increments the reference count for the current SC_UserList instance.
 *
 * @param self An opaque handle for the current SC_UserList instance.
 */
//SC_PUBLISHED void SC_UserList_Retain(SC_UserList_h self);

/**
 * @brief Decrements the object's reference count, and deletes the object if the counter reaches 0
 *
 * This method decrements the reference count for the current SC_UserList instance.
 * The current instance will be automatically deleted when the reference count reaches 0.
 *
 * Please note that this method is NULL pointer safe. That is, NULL as an argument will
 * not cause an exception.
 *
 * @param self An opaque handle for the current SC_UserList instance.
 */
//SC_PUBLISHED void SC_UserList_Release(SC_UserList_h self);

/**
 * @brief Retrieves a specific user from the list.
 *
 * This method returns the user at the given index in the list.
 *
 * @param self An opaque handle for the current SC_UserList instance.
 * @param index The index of the score to be retrieved.
 * @return SC_User_h The user at the given index.
 */
//SC_PUBLISHED SC_User_h SC_UserList_GetAt(SC_UserList_h self, unsigned int index);
//FREObject sl_ane_SC_UserList_GetAt(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);

/**
 * @brief Returns the number of users on the list.
 *
 * This method returns the total number of users on the list.
 *
 * @param self An opaque handle for the current SC_UserList instance.
 * @return unsigned int The number of users on the list.
 */
//SC_PUBLISHED unsigned int SC_UserList_GetCount(SC_UserList_h self);
FREObject sl_ane_SC_UserList_GetCount(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);



#ifdef __cplusplus
}
#endif




#endif /* SCUSERLIST_H_ */
