
#include "Globals.h"


using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

//======================================================================================//
//           VARIABLES
//======================================================================================//

SL_AppData_s *appData = NULL;
FREContext   currentContext;

//======================================================================================//
//           FUNCTION STUBS
//======================================================================================//


void SLANEExtensionInitializer(void** extDataToSet,
		                         FREContextInitializer* ctxInitializerToSet,
		                         FREContextFinalizer* ctxFinalizerToSet);
void SLANEExtensionFinalizer();

void SLANEContextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx,
		                       uint32_t* numFunctionsToSet, const FRENamedFunction** functionsToSet);
void SLANEContextFinalizer(FREContext ctx);

static void bpsEventComplete(bps_event_t *event);

//======================================================================================//
//          CUSTOM FUNCTIONS
//======================================================================================//


//======================================================================================//
//          NATIVE FUNCTIONS
//======================================================================================//


/**
 * The runtime calls this method once when it loads an ActionScript extension.
 * Implement this function to do any initializations that your extension requires.
 * Then set the output parameters.
 *
 * @param extDataToSet
 *             A pointer to a pointer to the extension data of the ActionScript extension.
 *             Create a data structure to hold extension-specific data. For example, allocate
 *             the data from the heap, or provide global data. Set extDataToSet to a pointer
 *             to the allocated data.
 * @param ctxInitializerToSet
 *             A pointer to the pointer to the FREContextInitializer() function. Set
 *             ctxInitializerToSet to the FREContextInitializer() function you defined.
 * @param ctxFinalizerToSet
 *             A pointer to the pointer to the FREContextFinalizer() function. Set
 *             ctxFinalizerToSet to the FREContextFinalizer() function you defined. You can
 *             set this pointer to NULL.
 */
void SLANEExtensionInitializer(void** extDataToSet,
		FREContextInitializer* ctxInitializerToSet,
		FREContextFinalizer* ctxFinalizerToSet) {
	*extDataToSet = NULL;
	*ctxInitializerToSet = &SLANEContextInitializer;
	*ctxFinalizerToSet = &SLANEContextFinalizer;

	cout << "Initializing struct to hold SL Controllers and data" << endl;
	appData = (SL_AppData_s*)malloc(sizeof(SL_AppData_s));
	cout << "Starting SL thread" << endl;
	pthread_create(NULL, NULL, initScoreLoopThread, NULL);
}

/**
 * The runtime calls this function when it disposes of the ExtensionContext instance
 * for this extension context.
 */
void SLANEExtensionFinalizer() { }

/**
 * The runtime calls this method when the ActionScript side calls ExtensionContext.createExtensionContext().
 *
 * @param extData
 *             A pointer to the extension data of the ActionScript extension.
 * @param ctxType
 *             A string identifying the type of the context. You define this string as
 *             required by your extension. The context type can indicate any agreed-to meaning
 *             between the ActionScript side and native side of the extension. If your extension
 *             has no use for context types, this value can be Null. This value is a UTF-8
 *             encoded string, terminated with the null character.
 * @param ctx
 *             An FREContext variable. The runtime creates this value and passes it to FREContextInitializer().
 * @param numFunctionsToSet
 *             A pointer to a unint32_t. Set numFunctionsToSet to a unint32_t variable containing
 *             the number of functions in the functionsToSet parameter.
 * @param functionsToSet
 *             A pointer to an array of FRNamedFunction elements. Each element contains a pointer
 *             to a native function, and the string the ActionScript side uses in the ExtensionContext
 *             instance's call() method.
 */
void SLANEContextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx,
		                        uint32_t* numFunctionsToSet, const FRENamedFunction** functionsToSet) {
	char *temp = NULL;
	int i;

	// define an array of functions
	const char *functionNames[] = { //SLInit.h
	                                "sl_ane_setMinimumVersion",
	                                "sl_ane_SC_GetBPSEventDomain",
	                                //SLClient.h
	                                "sl_ane_SC_Client_New",
	                                NULL };

	FREFunction functionPtrs[] = { sl_ane_setMinimumVersion,
	                               sl_ane_SC_GetBPSEventDomain,
	                               sl_ane_SC_Client_New,
	                               NULL };

	// count number of functions
	*numFunctionsToSet = 0;
	while (functionPtrs[*numFunctionsToSet] != NULL) {
		(*numFunctionsToSet)++;
	}

	FRENamedFunction *functionSet = (FRENamedFunction *)calloc(*numFunctionsToSet,
		                                                        sizeof(FRENamedFunction));

	for (uint32_t i = 0; i < *numFunctionsToSet; i++) {
		int bufferSize = sizeof(char) * (strlen(functionNames[i]) + 1);
		temp = (char*) malloc(bufferSize);
		strncpy(temp, functionNames[i], bufferSize);
		temp[strlen(functionNames[i])] = '\0';
		functionSet[i].name = (uint8_t*) temp;
		functionSet[i].functionData = NULL;
		functionSet[i].function = functionPtrs[i];
	}

	*functionsToSet = functionSet;
	currentContext = ctx;
}

/**
 * The runtime calls this function when it disposes of the ExtensionContext instance for this extension context.
 *
 * @param ctx
 *             The FREContext variable that represents this extension context.
 */
void SLANEContextFinalizer(FREContext ctx) { }



#ifdef __cplusplus
}
#endif

