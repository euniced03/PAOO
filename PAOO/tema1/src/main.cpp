#include "Movie.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> sceneDescriptions = {
        "Opening scene: Introduction of the main character.",
        "Scene 2: The character faces their first challenge.",
        "Scene 3: The turning point in the plot.",
        "Final scene: The conclusion and resolution."
    };

    Movie movie1("The Hero's Journey", "John Smith", 2024, "Adventure", sceneDescriptions);

    movie1.displayInfo();
    movie1.play();
    movie1.displayCurrentScene();
    movie1.nextScene();
    movie1.displayCurrentScene();

    Movie movie2 = movie1; // Copy constructor demonstration
    movie2.nextScene();
    movie2.displayCurrentScene();

    return 0;
}
