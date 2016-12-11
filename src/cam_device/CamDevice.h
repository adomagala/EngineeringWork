//
// Created by Aleksander Domagała on 08.11.2016.
//

#ifndef ENGINEERING_WORK_CAM_DEVICE_H
#define ENGINEERING_WORK_CAM_DEVICE_H

#include <string>

class CamDevice {
    const std::string deviceName;
    const std::string devicePath;

public:
    explicit CamDevice(const std::string &deviceName, const std::string &devicePath);

    const std::string &getCamerName() const;

    const std::string &getCamerDevicePath() const;
};

#endif //ENGINEERING_WORK_CAM_DEVICE_H
