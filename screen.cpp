#include <iostream>
#include <vector>
using namespace std;

// Screen represents one auditorium.
// Composition: Screen owns its seats.
class Screen
{
private:
    int screenNumber;
    vector<Seat> seats;

public:
    // Constructor
    Screen(int screenNumber)
    {
        this->screenNumber = screenNumber;
    }
    // Add a seat to the screen
    void addSeat(Seat seat)
    {
        seats.push_back(seat);
    }
    // Get screen number
    int getScreenNumber()
    {
        return screenNumber;
    }

    // Get all seats
    vector<Seat>& getSeats()
    {
        return seats;
    }
};