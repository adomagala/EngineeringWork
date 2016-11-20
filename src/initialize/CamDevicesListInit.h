//
// Created by Aleksander Domagała on 13.11.2016.
//

#ifndef ENGINEERINGWORK_CAMDEVICESLISTINIT_H
#define ENGINEERINGWORK_CAMDEVICESLISTINIT_H

#include <windows.h>
#include <dshow.h>
#include <uuids.h>
#include <string>
#include <vector>
#include <iostream>
#include "../propertie/ListCamDevice.h"
#include "../propertie/AppProperties.h"
#include "../propertie/PropertyTypes.h"
#include "../cam_device/CamDevice.h"

class CamDevicesListInit {
    static HRESULT handleResults;
    static IEnumMoniker *enumMoniker;
    static IMoniker *moniker;
    static IPropertyBag *propertyBag;
    static VARIANT variant;

    static std::string deviceName;
    static std::string devicePath;

    static std::vector<CamDevice> camDeviceList;

    CamDevicesListInit() = delete;

    static void checkHandlerResultsIsCorrect();

    static void createCamDeviceList();

    static void enumerateDevices();

    static void checkCategoryIsNotEmpty();

    static void completeInformationAboutDevice();

    static void extractDisplayDeviceInformation();

    static void releaseEnumMoniker();

    static bool isNextDevice();

    static void initHandleResults();

    static void releaseMoniker();

    static void initVariant();

    static void setCamDeviceName();

    static void setCamDevicePath();

    static bool initBindToStorage();

    static void releasePropertyBag();

    static void getDeviceName();

    static void variantClear();

    static void getDevicePath();

    static std::string extractProperty();

    static void addNewCamDeviceToList();

    static void addCamDeviceListToAppProperties();

public:
    static void init();
};


#endif //ENGINEERINGWORK_CAMDEVICESLISTINIT_H
