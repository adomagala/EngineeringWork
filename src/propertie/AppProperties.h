//
// Created by Aleksander Domagała on 08.11.2016.
//

#ifndef ENGINEERING_WORK_APP_PROPERTIES_H
#define ENGINEERING_WORK_APP_PROPERTIES_H

#include <map>
#include <string>
#include <memory>

#include "Property.h"
#include "PropertyTypes.h"

class AppProperties {
    static AppProperties* instance;

    std::map<int, std::shared_ptr<const Property>> properties;

    AppProperties() = default;

    AppProperties(const AppProperties &) = delete;

    void addProperty(const PROPERTY_TYPES &propertyName, const std::shared_ptr<Property> &property);

    friend class CamDevicesListInit;
    friend class AppVersionInit;

public:
    static AppProperties &getInstance();

    std::shared_ptr<const Property> getPropertyByName(const PROPERTY_TYPES &propertyName);

    //template std::shared_ptr<T> getPropertyByName<T>(const PROPERTY_TYPES &propertyName, T a);

    bool isContainsPropertyName(const PROPERTY_TYPES &propertyName);

};

#endif //ENGINEERING_WORK_APP_PROPERTIES_H
