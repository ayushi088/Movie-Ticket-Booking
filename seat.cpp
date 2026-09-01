#include <iostream>
#include <string>
using namespace std;

// Different types of seats
enum SeatType{
    SILVER,
    GOLD,
    PLATINUM
};
// Seat class represents one physical seat.
class Seat{
private:
    string number;
    SeatType type;

public:
    Seat(string number, SeatType type)
    {
        this->number = number;
        this->type = type;
    }

    // Get seat number
    string getNumber()
    {
        return number;
    }

    // Get seat type
    SeatType getType(){
        return type;
}
        // Return price according to seat type
    double getPrice()
    {
        const double SILVER_PRICE = 150;
        const double GOLD_PRICE = 250;
        const double PLATINUM_PRICE = 400;

        if (type == SILVER)
            return SILVER_PRICE;

        if (type == GOLD)
            return GOLD_PRICE;

        return PLATINUM_PRICE;
    }

    // Return seat type as text
    string getTypeName()
    {
        if (type == SILVER)
            return "SILVER";

        if (type == GOLD)
            return "GOLD";

        return "PLATINUM";
    }
};