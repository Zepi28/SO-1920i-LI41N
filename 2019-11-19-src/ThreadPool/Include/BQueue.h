#pragma once

#ifdef THREADPOOL_EXPORTS
#define UTILS_API __declspec(dllexport)
#else
#define UTILS_API __declspec(dllimport)
#endif

#include "List.h"

typedef struct {
	LIST_ENTRY list; // the list sentinel
	HANDLE mutex;	 // to implement critical sections on queue code	
	HANDLE hasItems; // In this version this a semaphore!
	HANDLE hasSpace; // a new semaphore for blocking "putters"!
	INT size;		 // the queue current size (not used)
	INT maxSize;	 // Queue max capacity
} BQUEUE, *PBQUEUE;


UTILS_API VOID BQ_Init(PBQUEUE q, INT capacity);
UTILS_API VOID BQ_Put(PBQUEUE q, LPVOID item);
UTILS_API LPVOID BQ_Get(PBQUEUE q);
UTILS_API BOOL BQ_IsEmpty(PBQUEUE q);