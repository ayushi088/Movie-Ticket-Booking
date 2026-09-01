#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Show represents one movie playing on one screen at one time.
class Show
{
private:
    // Aggregation: Show uses existing Movie and Screen objects.
    Movie* movie;
    Screen* screen;

    string startTime;

    // Composition: Show creates/owns ShowSeat objects.
    vector<ShowSeat> showSeats;

public:
    // Constructor
    Show(Movie* movie, Screen* screen, string startTime)
    {
        this->movie = movie;
        this->screen = screen;
        this->startTime = startTime;

        // Create ShowSeat for every physical seat
        for (size_t i = 0; i < screen->getSeats().size(); i++)
        {
            showSeats.push_back(
                ShowSeat(&screen->getSeats()[i])
            );
        }
    }

    // Get movie
    Movie* getMovie()
    {
        return movie;
    }

    // Get screen
    Screen* getScreen()
    {
        return screen;
    }

    // Get show time
    string getStartTime()
    {
        return startTime;
    }

    // Display all seats
    void displaySeats()
    {
        cout << "\n===== SEAT LAYOUT =====\n";

        cout << "Screen: "
             << screen->getScreenNumber()
             << "   Time: "
             << startTime << "\n\n";

        for (size_t i = 0; i < showSeats.size(); i++)
        {
            cout << showSeats[i].getSeat()->getNumber()
                 << "  "
                 << showSeats[i].getSeat()->getTypeName()
                 << "  ";

            if (showSeats[i].isAvailable())
                cout << "[ AVAILABLE ]";
            else
                cout << "[ BOOKED ]";

            cout << endl;
        }
    }

    // Find a seat using seat number
    ShowSeat* getShowSeat(string seatNumber)
    {
        for (size_t i = 0; i < showSeats.size(); i++)
        {
            if (showSeats[i].getSeat()->getNumber() == seatNumber)
            {
                return &showSeats[i];
            }
        }

        return nullptr;
    }
};