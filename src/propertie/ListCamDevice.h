//
// Created by Aleksander Domagała on 11.11.2016.
//

#ifndef ENGINEERINGWORK_LISTCAMDEVICE_H
#define ENGINEERINGWORK_LISTCAMDEVICE_H

#include <vector>

#include "Property.h"
#include "../cam_device/CamDevice.h"

class ListCamDevice : public Property {
    const std::vector<CamDevice> devicesList;

public:
    ListCamDevice(const std::vector<CamDevice> &devicesList);

    const std::vector<CamDevice> &getDevicesList() const;

};


#endif //ENGINEERINGWORK_LISTCAMDEVICE_H
