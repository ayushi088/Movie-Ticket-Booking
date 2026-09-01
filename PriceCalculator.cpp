#include <iostream>
#include <vector>
using namespace std;

// PriceCalculator only calculates the total price.
// It does not book or release seats.
class PriceCalculator
{
public:

    double calculateTotal(vector<ShowSeat*> seats)
    {
        double total = 0;

        for (size_t i = 0; i < seats.size(); i++)
        {
            total = total +
                    seats[i]->getSeat()->getPrice();
        }

        return total;
    }
};