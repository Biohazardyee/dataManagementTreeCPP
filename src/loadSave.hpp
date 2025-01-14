#include <fstream>
#include <iostream>
#include "videogame.hpp"

void saveGamesToFile(VideoGame videoGames[], int videoGamesCount) {
    if (videoGamesCount == 0) {
        std::cerr << "No games to save!" << std::endl;
        return;
    }

    // Create an output file stream (overwrite mode)
    std::ofstream file("VideoGames.txt");
    
    if (!file) {
        std::cerr << "Error opening file for saving!" << std::endl;
        return;
    }

    // Write each video game's details to the file
    for (int i = 0; i < videoGamesCount; i++) {
        file << videoGames[i].getId() << "\t" << videoGames[i].getName() << "\t" << videoGames[i].getYear() << "\t"<< videoGames[i].getGenre() << "\t"<< videoGames[i].getPrice() << "\t"<< videoGames[i].getAgeRating() << "\n";
    }

    // Close the file
    file.close();

    std::cout << "\033[1;32mGames have been successfully saved to the file!\033[0m\n";
}
