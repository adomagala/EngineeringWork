//
// Created by Aleksander Domagała on 11.11.2016.
//

#ifndef ENGINEERING_WORK_CAM_DEVICE_LIST_H
#define ENGINEERING_WORK_CAM_DEVICE_LIST_H

#include <vector>

#include "Property.h"
#include "../cam_device/CamDevice.h"

class CamDeviceList : public Property {
    const std::vector<CamDevice> devicesList;

public:
    CamDeviceList(const std::vector<CamDevice> &devicesList);

    CamDeviceList(const CamDeviceList &listCamDevice);

    const std::vector<CamDevice> &getDevicesList() const;

};


#endif //ENGINEERING_WORK_CAM_DEVICE_LIST_H
