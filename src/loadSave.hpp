#include <fstream>
#include "class.hpp"

void saveGamesToFile(videoGame videoGames[], int videoGamesCount)
{
    // Create an output file stream
    ofstream file("VideoGames.txt");

    if (!file) {
        std::cerr << "Error opening file for saving!" << std::endl;
        return;
    }

    for (int i = 0; i < videoGamesCount; i++) {
        videoGames[i].writeToFile(file);
    }

     // Close the file
    file.close();

    cout << "\033[1;32mGames have been successfully saved to the file!\033[0m\n";

}