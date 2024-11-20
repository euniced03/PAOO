#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>
#include "Scene.h"

class Movie {
private:
    std::string title;
    std::string director;
    int releaseYear;
    std::string genre;
    int currentSceneIndex;
    std::vector<Scene> scenes; // Vector de scene

public:
    // Constructor
    Movie(const std::string& title, const std::string& director, int releaseYear, const std::string& genre, const std::vector<std::string>& sceneDescriptions);

    // Copy constructor
    Movie(const Movie& other);

    // Move constructor
    Movie(Movie&& other) noexcept;

    // Destructor
    ~Movie();

    // Metode publice
    void play();
    void nextScene();
    void displayCurrentScene() const;
    void displayInfo() const;

    // Suprascrierea operatorului de atribuire
    Movie& operator=(const Movie& other);
};

#endif // MOVIE_H
