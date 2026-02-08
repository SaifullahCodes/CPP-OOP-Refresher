#include <iostream>
using namespace std;
class BankAccount
{
private:
    double balance;
    int accountNumber;
    string accountHolderName;
    int pin;

public:
    BankAccount(int accountNumber, string accountHolderName, double balance, int pin)
    {
        this->balance = balance;
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->pin = pin;
    }
    ~BankAccount()
    {
        cout << "Account for " << accountHolderName << " is closed." << endl;
    }
    void deposit(double a)
    {
        balance = balance + a;
        cout << "You hace successfully deposit this amount in your account" << endl;
    }
    void withdraw(double a, int b)
    {
        if (b == pin)
        {
            if (a <= balance && a > 500)
            {
                balance = balance - a;
                cout << "You hace successfully withdraw this amount from your account" << endl;
            }
            else
            {
                cout << "Enter correct amount" << endl;
            }
        }
        else
        {
            cout << "Enter correct pin code" << endl;
        }
    }
    void changePin(int old)
    {
        if (old == pin)
        {
            cout << "Enter your new pin :";
            cin >> pin;
        }
        else
            cout << "Enter correct pin";
    }
    void check_balance()
    {
        cout << "Your current balance is :" << balance << endl;
    }
    void displayDetails()
    {
        cout << "Account holder name is :" << accountHolderName << endl;
        cout << "Account Number is :" << accountNumber << endl;
        cout << "Your current balance is :" << balance << endl;
    }
};
int main()
{
    BankAccount saifAccount(1, "saif", 10000, 123);
    BankAccount adilAccount(2, "adil", 20000, 1234);
    bool a = true;
    int b;
    while (a)
    {
        cout << "Press 1: Details Dekhein" << endl;
        cout << "Press 2: Deposit Karein" << endl;
        cout << "Press 3: Withdraw Karein" << endl;
        cout << "Press 4: PIN Change Karein" << endl;
        cout << "Press 5: Exit" << endl;
        cin >> b;
        switch (b)
        {
        case 1:
            saifAccount.displayDetails();
            break;
        case 2:
            double d;
            cout << "Enter Amount you want to deposit in account :";
            cin >> d;
            saifAccount.deposit(d);
            break;
        case 3:
            double w;
            int p;
            cout << "Enter pin of your Account :";
            cin >> p;
            cout << endl;
            cout << "Enter Amount you want to withdraw from your account :";
            cin >> w;
            cout << endl;
            saifAccount.withdraw(w, p);
            break;
        case 4:
            int pi, ol;
            cout << "Enter your old pin :";
            cin >> pi;
            saifAccount.changePin(pi);
            break;
        case 5:
            a = false;
            break;
        default:
            cout << "Invalid number" << endl;
        }
    }
}