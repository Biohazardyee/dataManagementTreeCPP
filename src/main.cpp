#include <iostream>
#include <fstream>
#include <limits>
#include "tree.hpp"
#include "videogame.hpp"

// Function to load games from the file into the tree
void loadGamesFromFile(AVLTree &tree) {
    tree.loadFromFile("VideoGames.txt");
}

// Function to add a new video game
void addVideoGame(AVLTree &tree) {
    std::string name, genre, ageRating;
    int year;
    float price;

    std::cout << "Enter game name: ";
    std::cin >> name;
    std::cout << "Enter game year: ";
    std::cin >> year;
    std::cout << "Enter game genre: ";
    std::cin >> genre;
    std::cout << "Enter game price: ";
    std::cin >> price;
    std::cout << "Enter game age rating: ";
    std::cin >> ageRating;

    VideoGame newGame(name, year, genre, price, ageRating);
    tree.insert(newGame);

    std::cout << "\033[1;32mNew game added successfully!\033[0m\n";
}

// Function to search for a game by ID
void searchById(AVLTree &tree) {
    int id;
    std::cout << "Enter the game ID to search: ";
    std::cin >> id;

    tree.search(id);  // Search for the game in the tree
}

// Function to display all games
void displayAllGames(AVLTree &tree) {
    tree.displayAll();  // Display all games in the AVL tree
}

// Function to save all games to the file
void saveAllGamesToFile(AVLTree &tree) {
    std::ofstream file("VideoGames.txt");

    if (!file) {
        std::cerr << "Error opening file for saving!\n";
        return;
    }

    // You need to implement an in-order traversal to save all games
    // You can use a helper function in the AVLTree class for this purpose
    tree.saveToFile(file);

    file.close();
    std::cout << "\033[1;32mGames have been successfully saved to the file!\033[0m\n";
}

int main() {
    AVLTree tree;

    // Load games from the file into the AVL tree
    loadGamesFromFile(tree);

    // Display message after loading from file
    std::cout << "\033[1;32mGames loaded from file successfully!\033[0m\n";

    int choice;
    bool exitProgram = false;

    do {
        // Display menu
        std::cout << "                  _._______  \n";  
        std::cout << "                 | _______ | \n";
        std::cout << "                 ||,-----.|| \n";
        std::cout << "                 |||     ||| \n";
        std::cout << "                 |||_____||| \n";
        std::cout << "                 |`-------'| \n";
        std::cout << "                 | +     O | \n";
        std::cout << "                 |      O  | \n";
        std::cout << "                 | / /  ##/ \n";
        std::cout << "                  `-------   \n";
        std::cout << "\n\033[36m========================================\033[0m\n";
        std::cout << "\033[1;36m   VIDEO GAME MANAGEMENT SYSTEM   \033[0m\n";
        std::cout << "\033[36m========================================\033[0m\n";
        std::cout << "\033[33m1. Add Video Game\n";
        std::cout << "2. Search Video Game by ID\n";
        std::cout << "3. Delete Video Game by ID\n";
        std::cout << "4. Display All Video Games\n";
        std::cout << "5. Save Games to File\n";
        std::cout << "6. Exit\033[0m\n";
        std::cout << "\033[36m========================================\033[0m\n";
        std::cout << "\033[34mEnter your choice: \033[0m";

        // Get user input and validate
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "\033[1;31mInvalid input. Please enter a number between 1 and 6.\033[0m\n";
            continue;
        }

        std::cout << "\n";  // Add a blank line for better spacing

        switch (choice) {
            case 1:
                addVideoGame(tree);
                break;
            case 2:
                searchById(tree);
                break;
            case 3:
                int idToRemove;
                std::cout << "Enter the game ID to delete: ";
                std::cin >> idToRemove;
                tree.remove(idToRemove);
                std::cout << "\033[1;32mGame with ID " << idToRemove << " removed successfully!\033[0m\n";
                break;
            case 4:
                displayAllGames(tree);
                break;
            case 5:
                saveAllGamesToFile(tree);
                break;
            case 6:
                std::cout << "\033[1;32mExiting the program. Goodbye!\033[0m\n";
                exitProgram = true;
                break;
            default:
                std::cout << "\033[1;31mInvalid choice. Please enter a number between 1 and 6.\033[0m\n";
        }

    } while (!exitProgram);

    return 0;
}
