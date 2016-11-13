//
// Created by Aleksander Domagała on 11.11.2016.
//

#include "AppInit.h"

const std::vector<std::function<void()>>
        AppInit::listInitFunction({
                                          CamDevicesListInit::addCamDeviceListToAppProperties
                                  });

AppInit *AppInit::instance = nullptr;

AppInit &AppInit::getInstance() {
    if (instance == nullptr) {
        instance = new AppInit();
    }

    return *instance;
}

void AppInit::initialization() const {
    std::for_each(listInitFunction.begin(), listInitFunction.end(),
                  [](std::function<void()> functor) { functor(); });
}
