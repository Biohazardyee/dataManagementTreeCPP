#include <iostream>
#include <string>


using namespace std;

class videoGame{
    public:
        string name;
        int year;
        string genre;
        int price;
        string ageRating;
        int id;

        static int videoGameCount;


        videoGame(string name, int year, string genre, int price, string ageRating, int id){
            this->name = name;
            this->year = year;
            this->genre = genre;
            this->price = price;
            this->ageRating = ageRating;
            this->id = id;
        }

        void display(){
            cout << "Name: " << name << endl;
            cout << "Year: " << year << endl;
            cout << "Genre: " << genre << endl;
            cout << "Price: " << price << endl;
            cout << "Age Rating: " << ageRating << endl;
            cout << "ID: " << id << endl;
        }

         // Method to write game details to a file
        void writeToFile(ofstream &file) {
            file << "Name: " << name << endl;
            file << "Year: " << year << endl;
            file << "Genre: " << genre << endl;
            file << "Price: $" << price << endl;
            file << "Age Rating: " << ageRating << endl;
            file << "ID: " << id << endl;
            file << "-------------------------" << endl;
        }
};


int videoGame::videoGameCount = 0;