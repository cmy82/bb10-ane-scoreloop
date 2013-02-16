/*
 * SLVersion.h
 *
 *  Created on: Feb 12, 2013
 *      Author: CHRIS
 */


#include <FlashRuntimeExtensions.h>


#ifndef SL_ANE_SLVERSION_H_
#define SL_ANE_SLVERSION_H_

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Returns version information about the linked to Scoreloop library.
 *
 * This method returns version information of the Scoreloop library you linked to. The contents of the returned
 * string is not further specified and can change without any notice. This method is primarily intended to be used
 * when communicating with the Scoreloop support team. Do not use it to guess enabled library features.
 *
 * @param pInitData     Currently ignored.
 * @param buffer        A non-null character buffer which will be filled up to bufferSize.
 * @param bufferSize    The length of the buffer. Choose a big enough buffer to get all data.
 * @return SC_Bool_t    SC_TRUE if bufferSize was big enough, SC_FALSE if return was truncated because of too small buffer.
 */
//SC_Bool_t SC_GetVersionInfo(const SC_InitData_t *pInitData, char *buffer, unsigned int bufferSize);
FREObject sl_ane_SC_GetVersionInfo(FREContext ctx, void* functionData, uint32_t argc, FREObject argv[]);



#ifdef __cplusplus
}
#endif



#endif /* SLVERSION_H_ */
