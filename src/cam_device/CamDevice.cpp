//
// Created by Aleksander Domagała on 08.11.2016.
//

#include "CamDevice.h"

CamDevice::CamDevice(const std::string &deviceName, const std::string &devicePath) :
        deviceName(deviceName), devicePath(devicePath) {
}

const std::string &CamDevice::getCamerName() const {
    return deviceName;
}

const std::string &CamDevice::getCamerDevicePath() const {
    return devicePath;
}