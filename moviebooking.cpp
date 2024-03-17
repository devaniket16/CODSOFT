#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 5;

class Movie {
private:
    string title;
    double price;
public:
    Movie(string _title, double _price) : title(_title), price(_price) {}

    string getTitle() const {
        return title;
    }

    double getPrice() const {
        return price;
    }
};

class Theater {
private:
    vector<vector<char>> seats;
public:
    Theater() {
        seats = vector<vector<char>>(NUM_ROWS, vector<char>(NUM_COLS, 'O'));
    }

    pair<int, int> bookSeat(int row, int col) {
        if (row < 1 || row > NUM_ROWS || col < 1 || col > NUM_COLS) {
            cout << "Invalid seat selection." << endl;
            return make_pair(-1, -1);
        }

        if (seats[row - 1][col - 1] == 'X') {
            cout << "Seat already booked. Please select another seat." << endl;
            return make_pair(-1, -1);
        }

        seats[row - 1][col - 1] = 'X';
        return make_pair(row, col);
    }

    void displaySeats() {
        cout << "  ";
        for (int i = 1; i <= NUM_COLS; ++i)
            cout << setw(3) << i;
        cout << endl;

        for (int i = 0; i < NUM_ROWS; ++i) {
            cout << setw(2) << (i + 1);
            for (int j = 0; j < NUM_COLS; ++j) {
                cout << setw(3) << seats[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    // Create movies
    Movie movie1("Shaitaan", 240.50);
    Movie movie2("Artile 370", 220.0);
    Movie movie3("Oppenheimer", 180.0);

    // Create theater
    Theater theater;

    // Display movie listings
    cout << "Movie Listings:" << endl;
    cout << "1. " << movie1.getTitle() << " (Rs " << movie1.getPrice() << ")" << endl;
    cout << "2. " << movie2.getTitle() << " (Rs " << movie2.getPrice() << ")" << endl;
    cout << "3. " << movie3.getTitle() << " (Rs " << movie3.getPrice() << ")" << endl;

    char choice;
    do {
        // Display available seats and make booking
        cout << "Available Seats:" << endl;
        theater.displaySeats();

        int row, col;
        cout << "Enter row and column number to book a seat: ";
        cin >> row >> col;

        pair<int, int> bookedSeat = theater.bookSeat(row, col);
        if (bookedSeat.first != -1 && bookedSeat.second != -1) {
            cout << "Seat " << bookedSeat.first << "-" << bookedSeat.second << " booked successfully!" << endl;
            cout << "Total Cost: Rs " << fixed << setprecision(2) << movie1.getPrice() << endl;
        } else {
            cout << "Seat booking failed. Please try again." << endl;
        }

        cout << "Do you want to book another ticket? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
