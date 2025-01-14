#include <iostream>
#include <fstream>
#include "tree.hpp"
#include "videogame.hpp"

// Function to load games from the file into the tree
void loadGamesFromFile(AVLTree &tree) {
    tree.loadFromFile("videogames.txt");
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

    // Display all games after loading from the file
    std::cout << "Games loaded from file:\n";
    tree.displayAll();

    int choice;
    bool valid_input;

    do {
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
        std::cout << "3. Display All Video Games\n";
        std::cout << "4. Save Games to File\n";
        std::cout << "5. Exit\033[0m\n";
        std::cout << "\033[36m========================================\033[0m\n";
        std::cout << "\033[34mEnter your choice: \033[0m";

        // Validate user input for menu choice
        valid_input = false;
        while (!valid_input) {
            std::cin >> choice;

            if (std::cin.fail()) {
                std::cin.clear(); // Clear the error flag
                std::cout << "\033[1;31mInvalid input. Please enter a valid number.\033[0m\n";
                std::cout << "\033[34mEnter your choice: \033[0m";
            } else {
                valid_input = true;
            }
        }

        std::cout << "\n";  // Add a blank line for better spacing

        switch (choice) {
            case 1:
                addVideoGame(tree);  // Add a new video game
                break;
            case 2:
                searchById(tree);    // Search video game by ID
                break;
            case 3:
                displayAllGames(tree);  // Display all video games
                break;
            case 4:
                saveAllGamesToFile(tree);  // Save all video games to file
                break;
            case 5:
                std::cout << "\033[1;32mExiting the program. Goodbye!\033[0m\n";
                break;
            default:
                std::cout << "\033[1;31mInvalid choice. Please try again.\033[0m\n";
        }

    } while (choice != 5);

    return 0;
}
