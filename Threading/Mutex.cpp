/*
 * Mutex.cpp
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */

#include "Mutex.h"

/*#ifdef LINUX

Mutex::Mutex()
{
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_ERRORCHECK);
	pthread_mutex_init(&(_mutex),&attr);
}

Mutex::~Mutex()
{
	pthread_mutex_destroy(&(_mutex));
}

void Mutex::Lock()
{
	pthread_mutex_lock(&(_mutex));
}

void Mutex::Unlock()
{
	pthread_mutex_unlock(&(_mutex));
}
#elif WINDOWS*/

Mutex::Mutex()
{
	_mutex = CreateMutex(0, FALSE, 0);
}

Mutex::~Mutex()
{
	//if(WaitForSingleObject(_mutex, (DWORD)0) != WAIT_TIMEOUT )
	//{
		CloseHandle(_mutex);
	//}
}

void Mutex::Lock()
{
	WaitForSingleObject(_mutex,INFINITE);
}

void Mutex::Unlock()
{
	ReleaseMutex(_mutex);
}

/*
#endif
*/