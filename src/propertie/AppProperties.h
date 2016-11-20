//
// Created by Aleksander Domagała on 08.11.2016.
//

#ifndef ENGINEERINGWORK_APPPROPERTIES_H
#define ENGINEERINGWORK_APPPROPERTIES_H

#include <map>
#include <string>
#include <memory>

#include "Property.h"
#include "PropertyTypes.h"

class AppProperties {
    static AppProperties* instance;

    std::map<int, std::shared_ptr<Property>> properties;

    AppProperties() = default;

    void addProperty(PROPERTY_TYPES propertyName, const std::shared_ptr<Property> &property);

    friend class CamDevicesListInit;

public:
    static AppProperties &getInstance();

    Property *getPropertyByName(PROPERTY_TYPES propertyName);

    bool isContainsPropertyName(const PROPERTY_TYPES &propertyName);

};

#endif //ENGINEERINGWORK_APPPROPERTIES_H
