#ifndef VIDEOGAME_HPP
#define VIDEOGAME_HPP

#include <iostream>
#include <string>
#include <fstream>

class VideoGame {
private:
    std::string name;
    int year;
    std::string genre;
    int price;
    std::string ageRating;
    int id;
    static int videoGameCount;  // Static member to generate unique IDs

public:
    // Default constructor
    VideoGame() : name(""), year(0), genre(""), price(0), ageRating(""), id(0) {}

    // Parameterized constructor with auto-generated ID
    VideoGame(std::string name, int year, std::string genre, int price, std::string ageRating)
        : name(name), year(year), genre(genre), price(price), ageRating(ageRating) {
        id = ++videoGameCount;  // Increment and assign unique ID
    }

    // Parameterized constructor with user-defined ID (optional)
    VideoGame(std::string name, int year, std::string genre, int price, std::string ageRating, int id)
        : name(name), year(year), genre(genre), price(price), ageRating(ageRating), id(id) {}

    // Getters
    std::string getName() const { return name; }
    int getYear() const { return year; }
    std::string getGenre() const { return genre; }
    float getPrice() const { return price; }
    std::string getAgeRating() const { return ageRating; }
    int getId() const { return id; }

    // Setters
    void setName(const std::string& newName) { name = newName; }
    void setYear(int newYear) { year = newYear; }
    void setGenre(const std::string& newGenre) { genre = newGenre; }
    void setPrice(int newPrice) { price = newPrice; }
    void setAgeRating(const std::string& newAgeRating) { ageRating = newAgeRating; }
    static void setVideoGameCount(int count) { videoGameCount = count; }

    // Method to display video game details
    void display() const {
        std::cout << "ID: " << id << "\n" << "Name: " << name << "\n" << "Year: " << year << "\n" << "Genre: " << genre << "\n" << "Price: $" << price << "\n" << "Age Rating: " << ageRating << "\n" << "-------------------------\n";
    }

    // Method to write game details to a file
    void writeToFile(std::ofstream& file) const {
        file << "ID: " << id << "\n" << "Name: " << name << "\n" << "Year: " << year << "\n" << "Genre: " << genre << "\n" << "Price: $" << price << "\n" << "Age Rating: " << ageRating << "\n" << "-------------------------\n";
    }
};

// Initialize static member
int VideoGame::videoGameCount = 0;

#endif // VIDEOGAME_HPP
