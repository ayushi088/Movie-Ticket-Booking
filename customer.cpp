#include <iostream>
#include <string>
using namespace std;

// Customer represents a person booking movie tickets.
class Customer
{
private:
    string name;
    string phone;

public:
    // Constructor
    Customer(string name, string phone)
    {
        this->name = name;
        this->phone = phone;
    }

    // Get customer name
    string getName()
    {
        return name;
    }

    // Get customer phone number
    string getPhone()
    {
        return phone;
    }
};