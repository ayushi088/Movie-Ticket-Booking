#include <iostream>
using namespace std;

// TicketPrinter only prints the ticket.
// It does not handle booking or payment.
class TicketPrinter
{
public:

    void printTicket(Booking* booking)
    {
        Show* show = booking->getShow();

        cout << "\n";
        cout << "====================================\n";
        cout << "             TICKET\n";
        cout << "====================================\n";

        cout << "Booking ID : BK"
             << booking->getBookingId() << endl;

        cout << "Customer   : "
             << booking->getCustomer()->getName() << endl;

        cout << "Movie      : "
             << show->getMovie()->getTitle() << endl;

        cout << "Screen     : Screen-"
             << show->getScreen()->getScreenNumber() << endl;

        cout << "Time       : "
             << show->getStartTime() << endl;

        cout << "Seats      : ";

        vector<ShowSeat*>& seats =
            booking->getSeats();

        for (size_t i = 0; i < seats.size(); i++)
        {
            cout << seats[i]->getSeat()->getNumber();

            if (i != seats.size() - 1)
                cout << ", ";
        }

        cout << endl;

        cout << "Amount     : Rs."
             << booking->getAmount() << endl;

        cout << "Status     : "
             << booking->getStatusName() << endl;

        cout << "====================================\n";
    }
};