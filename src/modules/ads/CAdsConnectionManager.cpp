/*******************************************************************************
 * Copyright (c) 2018 TU Wien/ACIN
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *    Martin Melik-Merkumians - initial contribution
 *******************************************************************************/

#include "CAdsConnectionManager.h"

namespace forte {
  namespace ads {
    DEFINE_SINGLETON (CAdsConnectionManager)

    CAdsConnectionManager::CAdsConnectionManager(){
    }

    CAdsConnectionManager::~CAdsConnectionManager(){
      // TODO Auto-generated destructor stub
    }

    bool CAdsConnectionManager::addConnection(const std::string& paFriendlyServerName, const std::string& paAddr, const std::string& paRemoteIpOrHostName){
      return addConnection(paFriendlyServerName, paAddr, AMSPORT_R0_PLC_TC3, paRemoteIpOrHostName);
    }

    bool CAdsConnectionManager::addConnection(const std::string& paFriendlyServerName, const std::string& paAddr, uint16_t paPort, const std::string& paRemoteIpOrHostName){
      CAdsConnection *connection = new CAdsConnection(paAddr, paPort, paRemoteIpOrHostName);
      if(connection->connect()){
        mConnectionRegistry[paFriendlyServerName] = connection;
        return true;
      }
      delete connection;
      return false;
    }

    void CAdsConnectionManager::removeConnection(const std::string& paFriendlyServerName){
      CAdsConnection *connection = mConnectionRegistry[paFriendlyServerName];
      delete connection;
      mConnectionRegistry.erase(paFriendlyServerName);
    }

    CAdsConnection* CAdsConnectionManager::getConnection(const std::string& paFriendlyServerName){
      return mConnectionRegistry[paFriendlyServerName];
    }
  }
}

