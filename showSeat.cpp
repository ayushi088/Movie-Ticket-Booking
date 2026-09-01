#include <iostream>
using namespace std;

// Status of a seat for a particular show
enum SeatStatus
{
    AVAILABLE,
    BOOKED
};
// ShowSeat stores the status of one seat for one show.
class ShowSeat
{
private:
    Seat* seat;
    SeatStatus status;

public:
    // Constructor
    ShowSeat(Seat* seat)
    {
        this->seat = seat;
        status = AVAILABLE;
    }

    // Check whether seat is available
    bool isAvailable()
    {
        return status == AVAILABLE;
    }

    // Book the seat
    bool bookSeat()
    {
        if (status == BOOKED)
            return false;

        status = BOOKED;
        return true;
    }

    // Release the seat
    void releaseSeat()
    {
        status = AVAILABLE;
    }

    // Get seat
    Seat* getSeat()
    {
        return seat;
    }

    // Get status
    SeatStatus getStatus()
    {
        return status;
    }
};