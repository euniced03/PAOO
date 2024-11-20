#include "Movie.h"
#include <iostream>
#include <utility>

// Constructor
Movie::Movie(const std::string& title, const std::string& director, int releaseYear, const std::string& genre, const std::vector<std::string>& sceneDescriptions)
    : title(title), director(director), releaseYear(releaseYear), genre(genre), currentSceneIndex(0) {
    for (const std::string& description : sceneDescriptions) {
        scenes.emplace_back(description);
    }
    std::cout << "Movie created: " << title << " with " << scenes.size() << " scenes." << std::endl;
}

// Copy constructor
Movie::Movie(const Movie& other)
    : title(other.title), director(other.director), releaseYear(other.releaseYear), genre(other.genre), currentSceneIndex(other.currentSceneIndex), scenes(other.scenes) {
    std::cout << "Copy constructor called for movie: " << title << std::endl;
}

// Move constructor
Movie::Movie(Movie&& other) noexcept
    : title(std::move(other.title)), director(std::move(other.director)), releaseYear(other.releaseYear), genre(std::move(other.genre)), currentSceneIndex(other.currentSceneIndex), scenes(std::move(other.scenes)) {
    other.currentSceneIndex = 0;
    std::cout << "Move constructor called for movie: " << title << std::endl;
}

// Destructor
Movie::~Movie() {
    std::cout << "Movie destroyed: " << title << std::endl;
}

void Movie::play() {
    std::cout << "Playing movie: " << title << std::endl;
}

void Movie::nextScene() {
    if (currentSceneIndex < scenes.size() - 1) {
        ++currentSceneIndex;
        std::cout << "Moving to next scene..." << std::endl;
    } else {
        std::cout << "End of movie reached." << std::endl;
    }
}

void Movie::displayCurrentScene() const {
    std::cout << "Current scene: " << scenes[currentSceneIndex].getDescription() << std::endl;
}

void Movie::displayInfo() const {
    std::cout << "Movie Info: " << title << " directed by " << director << " (" << releaseYear << ") - Genre: " << genre << std::endl;
}

// Operator de atribuire
Movie& Movie::operator=(const Movie& other) {
    if (this != &other) {
        title = other.title;
        director = other.director;
        releaseYear = other.releaseYear;
        genre = other.genre;
        currentSceneIndex = other.currentSceneIndex;
        scenes = other.scenes;
    }
    std::cout << "Movie assigned: " << title << std::endl;
    return *this;
}
