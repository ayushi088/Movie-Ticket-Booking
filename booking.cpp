#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Booking status
enum BookingStatus
{
    PENDING,
    CONFIRMED,
    FAILED,
    CANCELLED
};

// Booking represents one booking.
class Booking
{
private:
    // Static variable creates unique booking IDs.
    static int nextBookingId;

    int bookingId;

    Customer* customer;
    Show* show;

    vector<ShowSeat*> seats;

    double amount;

    BookingStatus status;

public:

    // Constructor
    Booking(Customer* customer, Show* show)
    {
        this->bookingId = nextBookingId++;

        this->customer = customer;
        this->show = show;

        amount = 0;
        status = PENDING;
    }

    // Add selected seat
    void addSeat(ShowSeat* seat)
    {
        seats.push_back(seat);
    }

    // Set total amount
    void setAmount(double amount)
    {
        this->amount = amount;
    }

    // Get amount
    double getAmount()
    {
        return amount;
    }

    // Set booking status
    void setStatus(BookingStatus status)
    {
        this->status = status;
    }

    // Get booking status
    BookingStatus getStatus()
    {
        return status;
    }

    // Get booking ID
    int getBookingId()
    {
        return bookingId;
    }

    // Get customer
    Customer* getCustomer()
    {
        return customer;
    }

    // Get show
    Show* getShow()
    {
        return show;
    }

    // Get selected seats
    vector<ShowSeat*>& getSeats()
    {
        return seats;
    }

    // Return status as text
    string getStatusName()
    {
        if (status == PENDING)
            return "PENDING";

        if (status == CONFIRMED)
            return "CONFIRMED";

        if (status == FAILED)
            return "FAILED";

        return "CANCELLED";
    }
};

// Starting booking ID
int Booking::nextBookingId = 1001;