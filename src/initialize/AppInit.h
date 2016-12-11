//
// Created by Aleksander Domagała on 11.11.2016.
//

#ifndef ENGINEERING_WORK_APP_INIT_H
#define ENGINEERING_WORK_APP_INIT_H

#include <functional>
#include <vector>
#include <algorithm>

#include "CamDevicesListInit.h"
#include "AppVersionInit.h"

class AppInit {
    static const std::vector<std::function<void()>> listInitFunction;
    static AppInit *instance;

    AppInit() = default;

    AppInit(const AppInit &) = delete;

public:
    static AppInit &getInstance();

    void initialization() const;
};


#endif //ENGINEERING_WORK_APP_INIT_H
