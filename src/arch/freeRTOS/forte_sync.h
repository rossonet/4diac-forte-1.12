/************************************************************************************
 * Copyright (c) 2016 fortiss GmbH
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 * Milan Vathoopan, Guru Chandrasekhara - initial API and implementation and/or initial documentation
 ************************************************************************************/
#ifndef _SYNC_H_
#define _SYNC_H_

#include <FreeRTOS_Source/include/FreeRTOS.h>
#include <FreeRTOS_Source/include/semphr.h>

#define CSyncObject CFreeRTOSSyncObject //allows that doxygen can generate better documenation

/*! \ingroup FREERTOS-HAL
 * \brief The sync object implementation for FreeRTOS.
 *
 * In the FreeRTOS version we use a binary semaphore for the sync object
 * 
 * Note: For Mutex implementation,  uncomment the xSemaphoreCreateMutex() function in sync.cpp
 */

class CFreeRTOSSyncObject{
  private:
  protected:
  //! The posix thread mutex handle of the operating system.
  SemaphoreHandle_t mMutexHandle;
  public:
    CFreeRTOSSyncObject();
    ~CFreeRTOSSyncObject();
  /*!\brief Lock the resource coming after the lock command  
   * 
   * This function blocks until it will get the lock for the coming critical section.
   */  
    void lock(void){
      xSemaphoreTake(mMutexHandle, portMAX_DELAY);
    };

  //!Free the resource coming after the lock command
    void unlock(void){
       xSemaphoreGive( mMutexHandle );
    };
};

#endif /*SYNC_H_*/
