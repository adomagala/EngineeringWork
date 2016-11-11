//
// Created by Aleksander Domagała on 08.11.2016.
//

#include "AppProperties.h"

AppProperties *AppProperties::instance = nullptr;

AppProperties &AppProperties::getInstance() {
    if (instance == nullptr) {
        instance = new AppProperties();
    }

    return *instance;
}

const Property &AppProperties::getPropertyByName(const PROPERTY_TYPES &propertyTypes) {
    if (!isContainsPropertyName(propertyTypes)) {
        //TODO: dodać wyjątek
    }

    return *(properties[propertyTypes]);
}

bool AppProperties::isContainsPropertyName(const PROPERTY_TYPES &propertyTypes) {
    return properties.find(propertyTypes) != properties.end();
}


