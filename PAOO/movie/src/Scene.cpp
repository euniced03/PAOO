#include "Scene.h"
#include <iostream>

// Constructor
Scene::Scene(const std::string& description) : description(description) {}

// Destructor
Scene::~Scene() {
    std::cout << "Scene destroyed" << std::endl;
}

// Getter
std::string Scene::getDescription() const {
    return description;
}
