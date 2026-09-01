#include <iostream>
#include <vector>
#include <string>
using namespace std;

// BookingService controls the complete booking process.
class BookingService
{
private:
    PriceCalculator* priceCalculator;
    TicketPrinter* ticketPrinter;

    // Store all bookings
    vector<Booking*> bookings;

public:

    // Constructor
    BookingService(
        PriceCalculator* priceCalculator,
        TicketPrinter* ticketPrinter)
    {
        this->priceCalculator = priceCalculator;
        this->ticketPrinter = ticketPrinter;
    }


    // Book ticket
    Booking* bookTicket(
        Show* show,
        Customer* customer,
        vector<string> seatNumbers,
        Payment* payment)
    {
        vector<ShowSeat*> selectedSeats;


        // --------------------------------
        // STEP 1: Validate all seats
        // --------------------------------

        for (size_t i = 0; i < seatNumbers.size(); i++)
        {
            ShowSeat* showSeat =
                show->getShowSeat(seatNumbers[i]);

            // Invalid seat
            if (showSeat == nullptr)
            {
                cout << "Invalid seat: "
                     << seatNumbers[i] << endl;

                return nullptr;
            }

            // Already booked
            if (!showSeat->isAvailable())
            {
                cout << "Seat "
                     << seatNumbers[i]
                     << " is already BOOKED.\n";

                cout << "Booking rejected.\n";

                return nullptr;
            }

            selectedSeats.push_back(showSeat);
        }


        // --------------------------------
        // STEP 2: Calculate price
        // --------------------------------

        double total =
            priceCalculator->calculateTotal(selectedSeats);

        cout << "\nTotal Amount: Rs."
             << total << endl;


        // --------------------------------
        // STEP 3: Create booking
        // --------------------------------

        Booking* booking =
            new Booking(customer, show);

        booking->setAmount(total);


        // --------------------------------
        // STEP 4: Book selected seats
        // --------------------------------

        for (size_t i = 0; i < selectedSeats.size(); i++)
        {
            selectedSeats[i]->bookSeat();
            booking->addSeat(selectedSeats[i]);
        }


        // --------------------------------
        // STEP 5: Payment
        // --------------------------------

        bool paymentSuccessful =
            payment->pay(total);


        // --------------------------------
        // STEP 6: Payment failed
        // --------------------------------

        if (!paymentSuccessful)
        {
            // Release all seats
            for (size_t i = 0; i < selectedSeats.size(); i++)
            {
                selectedSeats[i]->releaseSeat();
            }

            booking->setStatus(FAILED);

            bookings.push_back(booking);

            cout << "\nPayment failed.\n";
            cout << "Seats have been released.\n";
            cout << "Booking status: FAILED\n";

            return booking;
        }


        // --------------------------------
        // STEP 7: Payment successful
        // --------------------------------

        booking->setStatus(CONFIRMED);

        bookings.push_back(booking);

        cout << "\nBooking confirmed successfully!\n";

        // Print ticket
        ticketPrinter->printTicket(booking);

        return booking;
    }


    // Cancel booking
    bool cancelBooking(int bookingId)
    {
        for (size_t i = 0; i < bookings.size(); i++)
        {
            Booking* booking = bookings[i];

            if (booking->getBookingId() == bookingId)
            {
                // Only confirmed booking can be cancelled
                if (booking->getStatus() != CONFIRMED)
                {
                    cout << "Booking cannot be cancelled.\n";
                    return false;
                }


                // Release all seats
                vector<ShowSeat*>& seats =
                    booking->getSeats();

                for (size_t j = 0; j < seats.size(); j++)
                {
                    seats[j]->releaseSeat();
                }


                booking->setStatus(CANCELLED);

                cout << "Booking cancelled successfully.\n";
                cout << "All seats are AVAILABLE again.\n";

                return true;
            }
        }

        cout << "Booking not found.\n";
        return false;
    }


    // Display all confirmed tickets
    void showTickets()
    {
        bool found = false;

        for (size_t i = 0; i < bookings.size(); i++)
        {
            if (bookings[i]->getStatus() == CONFIRMED)
            {
                ticketPrinter->printTicket(bookings[i]);
                found = true;
            }
        }

        if (!found)
        {
            cout << "No confirmed bookings found.\n";
        }
    }
};