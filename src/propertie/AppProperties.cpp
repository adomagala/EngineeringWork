//
// Created by Aleksander Domagała on 08.11.2016.
//

#include "AppProperties.h"

AppProperties *AppProperties::instance = nullptr;

void AppProperties::addProperty(PROPERTY_TYPES propertyName, const std::shared_ptr<Property> &property) {
    if (isContainsPropertyName(propertyName)) {
        //TODO: dodać wyjątek
    }

    std::pair<int, std::shared_ptr<Property>> newPropertyElement(1, property);

    properties.insert(newPropertyElement);

    int qw = 0;
}

AppProperties &AppProperties::getInstance() {
    if (instance == nullptr) {
        instance = new AppProperties();
    }

    return *instance;
}

Property  *AppProperties::getPropertyByName(PROPERTY_TYPES propertyName) {
    if (!isContainsPropertyName(propertyName)) {
        //TODO: dodać wyjątek
    }

    return properties[1].get();
}

bool AppProperties::isContainsPropertyName(const PROPERTY_TYPES &propertyName) {
    return properties.find(propertyName) != properties.end();
}
