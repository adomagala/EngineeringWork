//
// Created by Aleksander Domagała on 04/12/2016.
//

#include "AppVersion.h"

AppVersion::AppVersion(const int &projectVersionMajor, const int &projectVersionMinor, const int &projectVersionPatch) :
        projectVersionMajor(projectVersionMajor),
        projectVersionMinor(projectVersionMinor),
        projectVersionPatch(projectVersionPatch) {
}

const int AppVersion::getProjectVersionMajor() const {
    return projectVersionMajor;
}

const int AppVersion::getProjectVersionMinor() const {
    return projectVersionMinor;
}

const int AppVersion::getProjectVersionPatch() const {
    return projectVersionPatch;
}
