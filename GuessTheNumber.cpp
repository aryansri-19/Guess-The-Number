#include <iostream>
#include <cstdlib>
using namespace std;
class Betting
{
    public:
    int total_money;
    int rounds;
    int guess(int n)
    {
        return rand()%10;
    }
    void over()
    {
        cout << "\nYou have won " << rounds << " rounds and are taking $" << total_money 
            << " with you.\n" << endl;
            cout << "Thank you for playing with us.";
            exit(1);
    }
    void correct(int round_money, int number)
    {
        cout << "And the drawn number is " << number << endl;
        cout << "Congratulations, you won this round." << endl;
        total_money += 2*round_money;
    }
    void wrong(int round_money, int n)
    {
        cout << "And the drawn number is " << n << endl;
        cout << "Oops, looks like you lost this round." << endl;
        total_money -= round_money;
    }
};
int main()
{
    Betting bet;
    cout << "Welcome to the Betting Grounds!!" << endl;
    cout << "Let's play the number guessing game!!\n" << endl;
    cout << "Rules: First you need to set a betting amount\nThen, you will get a chance to guess the number and "
    << "put some money on it.\nIf your guessed"
    << " number matches with the drawn number, you'll win and receive the double amount\n\n";
    cout << "If the number does not match, you lose and the money you put will be lost. " << endl;
    cout << "\nYou can play as many rounds you can or untill you lose all your money!!\n" << endl;
    cout << "Enter the total money for betting ($) ";
    cin >> bet.total_money;
    int round_money, number;
    bet.rounds = 0;
    while(1)
    {
        char c;
        if(bet.total_money<=0)
        {
            cout << "It seems you have lost all your money. Do you wish to add funds? (Y/N): ";
            cin >> c;
            if(c=='Y'||c=='y')
            {
                cout << "Enter the amount to be added: ";
                cin >> bet.total_money;
                continue;
            }
            else if(c=='N'||c=='n')
            bet.over();
            else
            {
                cout << "Invalid input" << endl;
                continue;
            }
        }
        cout << "Do you wish to play? (Y/N): ";
        cin >> c;
        if(c=='N'||c=='n')
        {
            bet.over();
        }
        else if(c=='Y'||c=='y')
        {
            cout << "Enter the money you want to bet for this round ($): ";
            cin >> round_money;
            if(round_money>bet.total_money)
            {
                cout << "Entered amount is exceeding playing limit. Proceed correctly." << endl;
                continue;
            }
            cout << "Guess the number between 0 to 9: ";
            cin >> number;
            int n = bet.guess(number);
            if(number==n)
            {
                bet.correct(round_money, number);
            }
            else
            {
                bet.wrong(round_money,n);
            }
        }
        else
        {
            cout << "Invalid input" << endl;
            continue;
        }
    }
}
