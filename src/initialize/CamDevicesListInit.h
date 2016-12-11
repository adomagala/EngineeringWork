//
// Created by Aleksander Domagała on 13.11.2016.
//

#ifndef ENGINEERING_WORK_CAM_DEVICES_LIST_INIT_H
#define ENGINEERING_WORK_CAM_DEVICES_LIST_INIT_H

#include <windows.h>
#include <dshow.h>
#include <uuids.h>
#include <string>
#include <vector>
#include <iostream>
#include "../propertie/CamDeviceList.h"
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

    CamDevicesListInit(const CamDevicesListInit &) = delete;

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


#endif //ENGINEERING_WORK_CAM_DEVICES_LIST_INIT_H
