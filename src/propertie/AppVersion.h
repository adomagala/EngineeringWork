//
// Created by Aleksander Domagała on 04/12/2016.
//

#ifndef ENGINEERING_WORK_APP_VERSION_H
#define ENGINEERING_WORK_APP_VERSION_H

#include "Property.h"

class AppVersion : public Property {
    const int projectVersionMajor;
    const int projectVersionMinor;
    const int projectVersionPatch;

public:
    AppVersion(const int &projectVersionMajor, const int &projectVersionMinor, const int &projectVersionPatch);

    const int getProjectVersionMajor() const;

    const int getProjectVersionMinor() const;

    const int getProjectVersionPatch() const;
};


#endif //ENGINEERING_WORK_APP_VERSION_H
