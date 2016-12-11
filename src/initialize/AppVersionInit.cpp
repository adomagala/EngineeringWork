//
// Created by Aleksander Domagała on 11/12/2016.
//

#include "AppVersionInit.h"

const int AppVersionInit::projectVersionMajor = PROJECT_VERSION_MAJOR;
const int AppVersionInit::projectVersionMinor = PROJECT_VERSION_MINOR;
const int AppVersionInit::projectVersionPatch = PROJECT_VERSION_PATCH;

void AppVersionInit::init() {
    addAppVersionToAppProperties();
}

void AppVersionInit::addAppVersionToAppProperties() {
    std::shared_ptr<AppVersion> appVersionProperty(new AppVersion(projectVersionMajor,
                                                                  projectVersionMinor,
                                                                  projectVersionPatch));

    AppProperties &appProperties = AppProperties::getInstance();

    appProperties.addProperty(PROPERTY_TYPES::APP_VERSION, appVersionProperty);
}