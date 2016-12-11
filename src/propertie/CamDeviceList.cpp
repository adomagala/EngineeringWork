//
// Created by Aleksander Domagała on 11.11.2016.
//

#include "CamDeviceList.h"

CamDeviceList::CamDeviceList(const std::vector<CamDevice> &devicesList) :
        devicesList(devicesList) {
}

CamDeviceList::CamDeviceList(const CamDeviceList &listCamDevice) :
        devicesList(listCamDevice.devicesList) {

}

const std::vector<CamDevice> &CamDeviceList::getDevicesList() const {
    return devicesList;
}