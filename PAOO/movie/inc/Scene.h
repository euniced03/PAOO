#ifndef SCENE_H
#define SCENE_H

#include <string>

class Scene {
private:
    std::string description;

public:
    // Constructor
    Scene(const std::string& description);

    // Destructor
    ~Scene();

    // Getter
    std::string getDescription() const;
};

#endif // SCENE_H
