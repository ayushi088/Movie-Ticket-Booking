#include <iostream>
#include <string>
using namespace std;

// UPI Payment
// Inheritance: UpiPayment inherits Payment.
class UpiPayment : public Payment
{
public:

    bool pay(double amount)
    {
        int choice;

        cout << "\nUPI Payment: Rs." << amount << endl;
        cout << "Enter 1 for successful payment" << endl;
        cout << "Enter 0 for failed payment" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "UPI payment successful.\n";
            return true;
        }

        cout << "UPI payment failed.\n";
        return false;
    }

    string getMethod()
    {
        return "UPI";
    }
};


// Card Payment
class CardPayment : public Payment
{
public:

    bool pay(double amount)
    {
        int choice;

        cout << "\nCard Payment: Rs." << amount << endl;
        cout << "Enter 1 for successful payment" << endl;
        cout << "Enter 0 for failed payment" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Card payment successful.\n";
            return true;
        }

        cout << "Card payment failed.\n";
        return false;
    }

    string getMethod()
    {
        return "Card";
    }
};


// Cash Payment
class CashPayment : public Payment
{
public:

    bool pay(double amount)
    {
        int choice;

        cout << "\nCash Payment: Rs." << amount << endl;
        cout << "Enter 1 if cash is received" << endl;
        cout << "Enter 0 if payment failed" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Cash payment successful.\n";
            return true;
        }

        cout << "Cash payment failed.\n";
        return false;
    }

    string getMethod()
    {
        return "Cash";
    }
};