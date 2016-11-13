//
// Created by Aleksander Domagała on 13.11.2016.
//

#ifndef ENGINEERINGWORK_CAMDEVICESLISTINIT_H
#define ENGINEERINGWORK_CAMDEVICESLISTINIT_H

#include <windows.h>
#include <dshow.h>
#include <uuids.h>
#include "../propertie/Property.h"

class CamDevicesListInit {
    static HRESULT handleResults;
    static IEnumMoniker *enumMoniker;

    CamDevicesListInit() = delete;

    static void checkHandlerResultsIsCorrect();

    static void createCamDeviceList();

    static void enumerateDevices(const GUID category);

    static void checkCategoryIsNotEmpty();

    static void getInformationAboutCamDevice();

    static void releaseEnumMoniker();
public:
    static void addCamDeviceListToAppProperties();
};


#endif //ENGINEERINGWORK_CAMDEVICESLISTINIT_H
