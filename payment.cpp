#include <iostream>
#include <string>
using namespace std;

// Abstract Payment class.
// Abstraction: only the payment contract is defined here.
class Payment
{
public:

    // Pure virtual function
    virtual bool pay(double amount) = 0;

    // Return payment method
    virtual string getMethod() = 0;

    // Virtual destructor
    virtual ~Payment()
    {
    }
};