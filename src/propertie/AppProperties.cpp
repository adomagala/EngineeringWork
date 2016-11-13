//
// Created by Aleksander Domagała on 08.11.2016.
//

#include "AppProperties.h"

AppProperties *AppProperties::instance = nullptr;

void AppProperties::addProperty(const PROPERTY_TYPES &propertyName, const std::shared_ptr<Property> &property) {
    if (isContainsPropertyName(propertyName)) {
        //TODO: dodać wyjątek
    }

    const std::pair<PROPERTY_TYPES, std::shared_ptr<Property>> newPropertyElement(propertyName, property);

    properties.insert(newPropertyElement);
}

AppProperties &AppProperties::getInstance() {
    if (instance == nullptr) {
        instance = new AppProperties();
    }

    return *instance;
}

const Property &AppProperties::getPropertyByName(const PROPERTY_TYPES &propertyName) {
    if (!isContainsPropertyName(propertyName)) {
        //TODO: dodać wyjątek
    }

    return *(properties[propertyName]);
}

bool AppProperties::isContainsPropertyName(const PROPERTY_TYPES &propertyName) {
    return properties.find(propertyName) != properties.end();
}
