//
// Created by Aleksander Domagała on 13.11.2016.
//

#include "CamDevicesListInit.h"

HRESULT CamDevicesListInit::handleResults;
IEnumMoniker *CamDevicesListInit::enumMoniker;
IMoniker *CamDevicesListInit::moniker = nullptr;
IPropertyBag *CamDevicesListInit::propertyBag;
VARIANT CamDevicesListInit::variant;

std::string CamDevicesListInit::deviceName;
std::string CamDevicesListInit::devicePath;

std::vector<CamDevice> CamDevicesListInit::camDeviceList;

void CamDevicesListInit::init() {
    initHandleResults();
    checkHandlerResultsIsCorrect();

    createCamDeviceList();

    addCamDeviceListToAppProperties();
}

void CamDevicesListInit::initHandleResults() {
    handleResults = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
}

void CamDevicesListInit::createCamDeviceList() {
    enumerateDevices();

    checkHandlerResultsIsCorrect();

    completeInformationAboutDevice();

    CoUninitialize();
}

void CamDevicesListInit::enumerateDevices() {
    ICreateDevEnum *devEnum;

    handleResults = CoCreateInstance(CLSID_SystemDeviceEnum, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&devEnum));

    checkHandlerResultsIsCorrect();

    handleResults = devEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &enumMoniker, 0);

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

void CamDevicesListInit::completeInformationAboutDevice() {
    extractDisplayDeviceInformation();

    releaseEnumMoniker();
}

void CamDevicesListInit::extractDisplayDeviceInformation() {
    while (isNextDevice()) {
        if (initBindToStorage()) {
            initVariant();

            setCamDeviceName();

            setCamDevicePath();

            releasePropertyBag();
            releaseMoniker();

            addNewCamDeviceToList();
        }
    }
}

void CamDevicesListInit::addNewCamDeviceToList() {
    const CamDevice camDevice(deviceName, devicePath);

    camDeviceList.push_back(camDevice);
}

bool CamDevicesListInit::initBindToStorage() {
    handleResults = moniker->BindToStorage(0, 0, IID_PPV_ARGS(&propertyBag));

    if (FAILED(handleResults)) {
        releaseMoniker();
        return false;
    }

    return true;
}

void CamDevicesListInit::releasePropertyBag() {
    propertyBag->Release();
}

void CamDevicesListInit::releaseMoniker() {
    moniker->Release();
}

void CamDevicesListInit::initVariant() {
    VariantInit(&variant);
}

void CamDevicesListInit::setCamDeviceName() {
    getDeviceName();

    checkHandlerResultsIsCorrect();

    deviceName = extractProperty();

    variantClear();
}

void CamDevicesListInit::getDeviceName() {
    handleResults = propertyBag->Read(L"Description", &variant, 0);

    if (FAILED(handleResults)) {
        handleResults = propertyBag->Read(L"FriendlyName", &variant, 0);
    }
}

void CamDevicesListInit::setCamDevicePath() {
    getDevicePath();

    checkHandlerResultsIsCorrect();

    devicePath = extractProperty();

    variantClear();
}

std::string CamDevicesListInit::extractProperty() {
    std::wstring ws(variant.bstrVal, SysStringLen(variant.bstrVal));

    std::string property(ws.begin(), ws.end());

    return property;
}

void CamDevicesListInit::getDevicePath() { handleResults = propertyBag->Read(L"DevicePath", &variant, 0); }

void CamDevicesListInit::variantClear() {
    VariantClear(&variant);
}

bool CamDevicesListInit::isNextDevice() {
    return enumMoniker->Next(1, &moniker, nullptr) == S_OK;
}

void CamDevicesListInit::releaseEnumMoniker() {
    enumMoniker->Release();
}

void CamDevicesListInit::addCamDeviceListToAppProperties() {
    std::shared_ptr<ListCamDevice> listCamDeviceProperty(new ListCamDevice(camDeviceList));

    AppProperties appProperties = AppProperties::getInstance();

    appProperties.addProperty(PROPERTY_TYPES::CAM_DEVICE_LIST, listCamDeviceProperty);
}