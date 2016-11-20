//
// Created by Aleksander Domagała on 11.11.2016.
//

#ifndef ENGINEERINGWORK_APPINIT_H
#define ENGINEERINGWORK_APPINIT_H

#include <functional>
#include <vector>
#include <algorithm>

#include "CamDevicesListInit.h"

class AppInit {
    static const std::vector<std::function<void()>> listInitFunction;
    static AppInit *instance;

    AppInit() = default;

public:
    static AppInit &getInstance();

    void initialization() const;
};


#endif //ENGINEERINGWORK_APPINIT_H
