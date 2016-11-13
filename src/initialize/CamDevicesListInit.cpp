//
// Created by Aleksander Domagała on 13.11.2016.
//

#include "CamDevicesListInit.h"

HRESULT CamDevicesListInit::handleResults = CoInitializeEx(nullptr, COINIT_MULTITHREADED);

void CamDevicesListInit::addCamDeviceListToAppProperties() {
    checkHandlerResultsIsCorrect();

    createCamDeviceList();
}

void CamDevicesListInit::createCamDeviceList() {
    enumerateDevices(CLSID_VideoInputDeviceCategory);

    checkHandlerResultsIsCorrect();

    CoUninitialize();
}

void CamDevicesListInit::enumerateDevices(const GUID category) {
    ICreateDevEnum *devEnum;

    handleResults = CoCreateInstance(CLSID_SystemDeviceEnum, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&devEnum));

    checkHandlerResultsIsCorrect();

    handleResults = devEnum->CreateClassEnumerator(category, &enumMoniker, 0);
    checkCategoryIsNotEmpty();
    devEnum->Release();
}

void CamDevicesListInit::checkHandlerResultsIsCorrect() {
    if (FAILED(handleResults)) {
        //TODO: dodac wyjątek
    }
}

void CamDevicesListInit::checkCategoryIsNotEmpty() {
    if (handleResults == S_FALSE) {
        handleResults = VFW_E_NOT_FOUND;
    }
}

void CamDevicesListInit::getInformationAboutCamDevice() {
    DisplayDeviceInformation(enumMoniker);



    releaseEnumMoniker();
}

void CamDevicesListInit::releaseEnumMoniker() {
    enumMoniker->Release();
}
