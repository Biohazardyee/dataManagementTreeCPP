#ifndef TREE_HPP
#define TREE_HPP

#include "videogame.hpp"
#include <iostream>
#include <algorithm>
#include <fstream> // For file handling

struct TreeNode
{
    VideoGame game;  // The video game object
    TreeNode *left;  // Pointer to the left child
    TreeNode *right; // Pointer to the right child
    int height;      // Height of the node in the AVL tree

    // Constructor to initialize a node with a video game
    TreeNode(const VideoGame &game) : game(game), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
public:
    void remove(int id)
    {
        root = deleteNode(root, id);
    }
private:
    TreeNode *root;

    // Utility function to get the height of a node
    int getHeight(TreeNode *node)
    {
        return (node == nullptr) ? 0 : node->height;
    }

    // Utility function to get the balance factor of a node
    int getBalanceFactor(TreeNode *node)
    {
        return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    // Right rotation to balance the tree
    TreeNode *rightRotate(TreeNode *y)
    {
        TreeNode *x = y->left;
        TreeNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // Left rotation to balance the tree
    TreeNode *leftRotate(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // Function to find the node with the minimum value in the tree
    TreeNode *findMin(TreeNode *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    // Recursive function to delete a node
    TreeNode *deleteNode(TreeNode *node, int id)
    {
        if (node == nullptr)
        {
            std::cout << "Game with ID " << id << " not found!\n";
            return node;
        }

        // Search for the node to delete
        if (id < node->game.getId())
        {
            node->left = deleteNode(node->left, id);
        }
        else if (id > node->game.getId())
        {
            node->right = deleteNode(node->right, id);
        }
        else
        {
            // Node found
            if (node->left == nullptr || node->right == nullptr)
            {
                // One or zero child case
                TreeNode *temp = node->left ? node->left : node->right;

                if (temp == nullptr)
                {
                    // No child case
                    temp = node;
                    node = nullptr;
                }
                else
                {
                    // One child case
                    *node = *temp;
                }
                delete temp;
            }
            else
            {
                // Node with two children
                TreeNode *temp = findMin(node->right);
                node->game = temp->game;
                node->right = deleteNode(node->right, temp->game.getId());
            }
        }

        if (node == nullptr)
        {
            return node;
        }

        // Update height
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        // Rebalance the tree
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && getBalanceFactor(node->left) >= 0)
        {
            return rightRotate(node);
        }

        // Left Right Case
        if (balance > 1 && getBalanceFactor(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && getBalanceFactor(node->right) <= 0)
        {
            return leftRotate(node);
        }

        // Right Left Case
        if (balance < -1 && getBalanceFactor(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    

    // Recursive function to insert a new video game into the tree
    TreeNode *insert(TreeNode *node, const VideoGame &game)
    {
        if (node == nullptr)
        {
            return new TreeNode(game);
        }

        if (game.getId() < node->game.getId())
        {
            node->left = insert(node->left, game);
        }
        else if (game.getId() > node->game.getId())
        {
            node->right = insert(node->right, game);
        }
        else
        {
            std::cout << "Game with ID " << game.getId() << " already exists!\n";
            return node;
        }

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceFactor(node);

        if (balance > 1 && game.getId() < node->left->game.getId())
        {
            return rightRotate(node);
        }

        if (balance < -1 && game.getId() > node->right->game.getId())
        {
            return leftRotate(node);
        }

        if (balance > 1 && game.getId() > node->left->game.getId())
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && game.getId() < node->right->game.getId())
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Recursive function to search for a game by ID
    TreeNode *search(TreeNode *node, int id)
    {
        if (node == nullptr || node->game.getId() == id)
        {
            return node;
        }

        if (id < node->game.getId())
        {
            return search(node->left, id);
        }
        else
        {
            return search(node->right, id);
        }
    }

    // Recursive in-order traversal to display all games
    void inOrder(TreeNode *node)
    {
        if (node != nullptr)
        {
            inOrder(node->left);
            node->game.display();
            std::cout << "----------------------\n";
            inOrder(node->right);
        }
    }

    // Helper function to save games to a file
    void saveToFile(TreeNode *node, std::ofstream &file)
    {
        if (node != nullptr)
        {
            saveToFile(node->left, file); // Traverse the left subtree
            file << node->game.getId() << "\t"
                 << node->game.getName() << "\t"
                 << node->game.getYear() << "\t"
                 << node->game.getGenre() << "\t"
                 << node->game.getPrice() << "\t"
                 << node->game.getAgeRating() << "\n";
            saveToFile(node->right, file); // Traverse the right subtree
        }
    }

public:
    // Constructor
    AVLTree() : root(nullptr) {}

    // Public function to insert a game
    void insert(const VideoGame &game)
    {
        root = insert(root, game);
    }

    void remove(const VideoGame &game)
    {
        root = deleteNode(root, game.getId());
    }



    // Public function to search for a game by ID
    void search(int id)
    {
        TreeNode *result = search(root, id);
        if (result != nullptr)
        {
            std::cout << "Game found:\n";
            result->game.display();
        }
        else
        {
            std::cout << "Game with ID " << id << " not found!\n";
        }
    }

    // Public function to display all games
    void displayAll()
    {
        if (root == nullptr)
        {
            std::cout << "No games in the database.\n";
        }
        else
        {
            std::cout << "All Video Games:\n";
            inOrder(root);
        }
    }

    // Public function to save all games to a file
    void saveToFile(std::ofstream &file)
    {
        saveToFile(root, file); // Start the traversal from the root
    }

    // Helper function to load games from file into the tree
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        int id, year;
        float price;
        std::string name, genre, ageRating;
        int count = 0;  // To track number of games loaded

        while (file >> id) {
            std::getline(file >> std::ws, name, '\t');   // Read name until tab
            file >> year >> genre >> price >> ageRating;  // Read other values
            VideoGame game(name, year, genre, price, ageRating, id);
            insert(game);
            count++;
        }

        if (count == 0) {
            std::cout << "No games were loaded. Check if the file is empty or incorrectly formatted.\n";
        } else {
            std::cout << "Games loaded from file successfully! Total games loaded: " << count << "\n";
        }
    }


};

#endif
