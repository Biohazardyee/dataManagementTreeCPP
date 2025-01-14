#include <iostream>
#include <string>

using namespace std;

class videoGames{
    public:
        string name;
        int year;
        string genre;
        int price;
        string ageRating;
        int id;


        videoGames(string name, int year, string genre, int price, string ageRating, int id){
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
}

