//
// Created by Aleksander Domagała on 08.11.2016.
//

#ifndef ENGINEERINGWORK_CAMDEVICE_H
#define ENGINEERINGWORK_CAMDEVICE_H

#include <string>

class CamDevice {
    const std::string deviceName;
    const std::string devicePath;

public:
    explicit CamDevice(const std::string &deviceName, const std::string &devicePath);

    const std::string &getCamerName() const;

    const std::string &getCamerDevicePath() const;
};

#endif //ENGINEERINGWORK_CAMDEVICE_H
