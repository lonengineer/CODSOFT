// movie_ticket_booking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<ostream>
#include<vector>


using namespace std;

class Movie {
    vector <int> booked_seatnums;
public:
    string name;
    vector <int> available_seatnums;
    void book_seat(int seat_num) {
        booked_seatnums.push_back(seat_num);
        std::cout << std::endl << "Booking Confirmed!\t Your seat number for " << name << " is " << seat_num << ".\nThanks for your purchase.\n";
        available_seatnums.erase(available_seatnums.begin() + seat_num - 1);
    }
    bool seat_available() {
        return (bool)available_seatnums.size();
    }
    bool seat_available(int num) {
        for (auto i : available_seatnums) { if (i == num) return true; }
        return false;
    }
    Movie(void) { name = ""; vector <int> temp = { 1,2,3,4,5,6,7,8,9,10 }; available_seatnums = temp; };
    Movie(string s) { name = s; vector <int> temp = { 1,2,3,4,5,6,7,8,9,10 }; available_seatnums = temp; };
};
ostream& operator << (ostream& out, const Movie m)
{
    out << "Movie name:\t" << m.name << std::endl;
    out << "Seats available:";
    for (auto i : m.available_seatnums)
        out << "\t" << i;
    out << endl << endl;
    return out;
}

void moviesname(vector<Movie>& temp);
int main(){
    bool exit_status = false;
    vector<Movie> list = { Movie("Thor"), Movie("Darkest Hour"), Movie("The Drill"), Movie("Captian America") };
    int choice = 0;
    cout << ":::::::::::::::::::::::::::::::::: Welcome to Movies World :::::::::::::::::::::::::::::";
    while (!exit_status) {
        cout << "\n\nChoose how we can help you:\n";
        cout << "1. I want to know the movies name\n2. I want to buy a ticket \n3. I want to check seat availability" << endl;
        cout << "Your choice:\t";
        cin >> choice;
        cout << endl;
        unsigned counter = 1; int name_choice = 0, seat_choice = 0;
        try {
            switch (choice) {
            case 1:
                moviesname(list); break;
            case 2:
                cout << "Please choose only available seats\n" << endl;

                for (auto i : list) {
                    cout << counter++ << ". " << i;
                }

                cout << endl << "Enter movie choice:\t";
                cin >> name_choice;
                if (name_choice > 10 || name_choice < 1) throw "Exception caught. No such movie available.";

                cout << "Enter your preffered seat: \t";
                cin >> seat_choice;
                if (seat_choice > 10 || seat_choice < 1) throw "Exception caught. No such seat available.";
                list[name_choice-1].book_seat(seat_choice);
                break;
            case 3:
                moviesname(list);
                cout << "\nPlease select the movie number: ";
                cin >> name_choice;
                cout << "Please enter seat number: ";
                cin >> seat_choice;
                cout << endl;
                list[name_choice - 1].seat_available(seat_choice) ? cout << "Your desired seat is available!\n" : cout << "Unfortunately the seat is already booked\n";
                break;
            default:
                throw "Exception caught. No such option available.";
            }
        }
        catch (const char* exception) {
            cout << exception << endl;
        }
        cout << "\nTo continue press 1.\nTo exit press 0.\n";
        cin >> choice;
        choice == 1 ? exit_status = false : exit_status = true;
    }

}

void moviesname(vector<Movie> &temp) {
    unsigned counter = 1;
    for (auto i : temp) {
        cout << counter++ << ". " << i.name << "\t\t";
    }
    cout << endl;
}
