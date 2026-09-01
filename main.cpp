#include <iostream>
#include <vector>
#include <string>
using namespace std;


// ======================================================
// Include all class files
// No header files are used as required.
// ======================================================

#include "movie.cpp"
#include "seat.cpp"
#include "screen.cpp"
#include "cinema.cpp"
#include "showSeat.cpp"
#include "show.cpp"
#include "customer.cpp"
#include "payment.cpp"
#include "paymentType.cpp"
#include "booking.cpp"
#include "PriceCalculator.cpp"
#include "ticketPrinter.cpp"
#include "bookingService.cpp"


// ======================================================
// Display all movies
// ======================================================

void displayMovies(vector<Movie>& movies)
{
    cout << "\n========== MOVIES ==========\n";

    for (size_t i = 0; i < movies.size(); i++)
    {
        cout << i + 1 << ". "
             << movies[i].getTitle()
             << " | "
             << movies[i].getLanguage()
             << " | "
             << movies[i].getDuration()
             << " min\n";
    }
}


// ======================================================
// Display shows for selected movie
// ======================================================

void displayShows(
    vector<Show>& shows,
    Movie* movie)
{
    cout << "\n========== SHOWS ==========\n";

    int count = 1;

    for (size_t i = 0; i < shows.size(); i++)
    {
        if (shows[i].getMovie() == movie)
        {
            cout << count << ". Screen-"
                 << shows[i].getScreen()->getScreenNumber()
                 << " | "
                 << shows[i].getStartTime()
                 << endl;

            count++;
        }
    }
}


// ======================================================
// Select payment method
// ======================================================

Payment* choosePayment()
{
    int choice;

    cout << "\n========== PAYMENT ==========\n";
    cout << "1. UPI\n";
    cout << "2. Card\n";
    cout << "3. Cash\n";

    cout << "Choose payment method: ";
    cin >> choice;


    if (choice == 1)
    {
        return new UpiPayment();
    }

    if (choice == 2)
    {
        return new CardPayment();
    }

    if (choice == 3)
    {
        return new CashPayment();
    }


    cout << "Invalid payment choice.\n";

    return nullptr;
}


// ======================================================
// Main Function
// ======================================================

int main()
{
    // ==================================================
    // Create Movies
    // ==================================================

    Movie movie1(
        "3 Idiots",
        "Hindi",
        170
    );

    Movie movie2(
        "Interstellar",
        "English",
        169
    );

    vector<Movie> movies;

    movies.push_back(movie1);
    movies.push_back(movie2);


    // ==================================================
    // Create Screen 1
    // ==================================================

    Screen screen1(1);

    screen1.addSeat(
        Seat("A1", SILVER)
    );

    screen1.addSeat(
        Seat("A2", SILVER)
    );

    screen1.addSeat(
        Seat("A3", SILVER)
    );

    screen1.addSeat(
        Seat("A4", SILVER)
    );

    screen1.addSeat(
        Seat("B1", GOLD)
    );

    screen1.addSeat(
        Seat("B2", GOLD)
    );

    screen1.addSeat(
        Seat("B3", GOLD)
    );

    screen1.addSeat(
        Seat("C1", PLATINUM)
    );

    screen1.addSeat(
        Seat("C2", PLATINUM)
    );


    // ==================================================
    // Create Screen 2
    // ==================================================

    Screen screen2(2);

    screen2.addSeat(
        Seat("A1", SILVER)
    );

    screen2.addSeat(
        Seat("A2", SILVER)
    );

    screen2.addSeat(
        Seat("A3", SILVER)
    );

    screen2.addSeat(
        Seat("A4", SILVER)
    );

    screen2.addSeat(
        Seat("B1", GOLD)
    );

    screen2.addSeat(
        Seat("B2", GOLD)
    );

    screen2.addSeat(
        Seat("B3", GOLD)
    );

    screen2.addSeat(
        Seat("C1", PLATINUM)
    );

    screen2.addSeat(
        Seat("C2", PLATINUM)
    );


    // ==================================================
    // Create Cinema
    // ==================================================

    Cinema cinema("PVR Cinema");

    cinema.addScreen(screen1);
    cinema.addScreen(screen2);


    // Get screens from Cinema
    vector<Screen>& screens =
        cinema.getScreens();


    // ==================================================
    // Create Shows
    // ==================================================

    vector<Show> shows;


    // 3 Idiots - Screen 1
    shows.push_back(
        Show(
            &movies[0],
            &screens[0],
            "06:00 PM"
        )
    );


    // 3 Idiots - Screen 2
    shows.push_back(
        Show(
            &movies[0],
            &screens[1],
            "09:00 PM"
        )
    );


    // Interstellar - Screen 1
    shows.push_back(
        Show(
            &movies[1],
            &screens[0],
            "07:00 PM"
        )
    );


    // ==================================================
    // Customer
    // ==================================================

    Customer customer(
        "Ayushi Saini",
        "9876543210"
    );


    // ==================================================
    // Create services
    // ==================================================

    PriceCalculator priceCalculator;

    TicketPrinter ticketPrinter;

    BookingService bookingService(
        &priceCalculator,
        &ticketPrinter
    );


    // ==================================================
    // Main Menu
    // ==================================================

    while (true)
    {
        cout << "\n";
        cout << "====================================\n";
        cout << "       MOVIE TICKET BOOKING\n";
        cout << "====================================\n";

        cout << "1. Movies\n";
        cout << "2. Book Ticket\n";
        cout << "3. Cancel Booking\n";
        cout << "4. My Tickets\n";
        cout << "0. Exit\n";

        cout << "Choose: ";

        int choice;
        cin >> choice;


        // ==============================================
        // Exit
        // ==============================================

        if (choice == 0)
        {
            cout << "Thank you!\n";
            break;
        }


        // ==============================================
        // Show Movies
        // ==============================================

        else if (choice == 1)
        {
            displayMovies(movies);
        }


        // ==============================================
        // Book Ticket
        // ==============================================

        else if (choice == 2)
        {
            displayMovies(movies);

            int movieChoice;

            cout << "\nChoose movie: ";
            cin >> movieChoice;


            // Validate movie choice
            if (
                movieChoice < 1 ||
                static_cast<size_t>(movieChoice) > movies.size()
            )
            {
                cout << "Invalid movie choice.\n";
                continue;
            }


            Movie* selectedMovie =
                &movies[movieChoice - 1];


            // Show available shows
            displayShows(
                shows,
                selectedMovie
            );


            int showChoice;

            cout << "\nChoose show: ";
            cin >> showChoice;


            // Find selected show
            vector<Show*> availableShows;

            for (size_t i = 0; i < shows.size(); i++)
            {
                if (shows[i].getMovie() ==
                    selectedMovie)
                {
                    availableShows.push_back(
                        &shows[i]
                    );
                }
            }


            // Validate show choice
            if (
                showChoice < 1 ||
                static_cast<size_t>(showChoice) > availableShows.size()
            )
            {
                cout << "Invalid show choice.\n";
                continue;
            }


            Show* selectedShow =
                availableShows[showChoice - 1];


            // Display seats
            selectedShow->displaySeats();


            // ==========================================
            // Select seats
            // ==========================================

            int numberOfSeats;

            cout << "\nHow many seats do you want? ";
            cin >> numberOfSeats;


            if (numberOfSeats <= 0)
            {
                cout << "Invalid number of seats.\n";
                continue;
            }


            vector<string> seatNumbers;


            for (int i = 0; i < numberOfSeats; i++)
            {
                string seatNumber;

                cout << "Enter seat "
                     << i + 1
                     << ": ";

                cin >> seatNumber;

                seatNumbers.push_back(
                    seatNumber
                );
            }


            // ==========================================
            // Select payment
            // ==========================================

            Payment* payment =
                choosePayment();


            if (payment == nullptr)
            {
                continue;
            }


            // ==========================================
            // Book ticket
            // ==========================================

            bookingService.bookTicket(
                selectedShow,
                &customer,
                seatNumbers,
                payment
            );


            // Delete payment object
            delete payment;
        }


        // ==============================================
        // Cancel Booking
        // ==============================================

        else if (choice == 3)
        {
            int bookingId;

            cout << "Enter Booking ID: ";
            cin >> bookingId;


            bookingService.cancelBooking(
                bookingId
            );
        }


        // ==============================================
        // My Tickets
        // ==============================================

        else if (choice == 4)
        {
            bookingService.showTickets();
        }


        // ==============================================
        // Invalid menu
        // ==============================================

        else
        {
            cout << "Invalid menu choice.\n";
        }
    }


    return 0;
}
