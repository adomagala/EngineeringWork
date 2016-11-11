//
// Created by Aleksander Domagała on 11.11.2016.
//

#include "ListCamDevice.h"

ListCamDevice::ListCamDevice(const std::vector<CamDevice> &devicesList) :
        devicesList(devicesList) {
}

const std::vector<CamDevice> &ListCamDevice::getDevicesList() const {
    return devicesList;
}
