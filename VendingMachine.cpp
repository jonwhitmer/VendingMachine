//============================================================================
// Name        : Vending Machine
// Author      : Jon Whitmer
// Copyright   : 2022
// Description : A functioning vending machine that keeps track of a variety of variables using pass by value and pass by reference.
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

const int PotatoChipPrice = 100, ChewingGumPrice = 55, CheeseCurlsPrice = 80, PretzelsPrice = 75, ChocolateChipCookiesPrice = 150, CandyBarsPrice = 100;
const double InitQtrAmt = 40, InitDimeAmt = 50, InitNickelAmt = 40;

// [CoinName]Amt is a constantly changing value used to calculate the change, while [CoinName]Qnty is the actual inventory of the coins.

void displayMenu();
void getOption(int & opt, double & total, int & PotatoChipQnty, int & ChewingGumQnty, int & CheeseCurlsQnty, int & PretzelsQnty, int & ChocolateChipCookiesQnty, int & CandyBarsQnty, int & Quit);
void collectCoins(double total, int & qtramt, int & dimeamt, int & nickelamt, double & deposit, int & qtrqnty, int & dimeqnty, int & nickelqnty);
void checkChange(double total, double deposit, int qtramt, int dimeamt, int nickelamt, int & qtrqnty, int & dimeqnty, int & nickelqnty);
int EndofDay(double & total, int anothercustomer, int qtrqnty, int dimeqnty, int nickelqnty, double & deposit, int & qtramt, int & dimeamt, int & nickelamt, double & profit);
void displayStats(int qtrqnty, int dimeqnty, int nickelqnty, int PotatoChipQnty, int ChewingGumQnty, int CheeseCurlsQnty, int PretzelsQnty, int ChocolateChipCookiesQnty, int CandyBarsQnty, double total, double deposit, double profit);

int main()
{
	int opt = 0, qtramt, dimeamt, nickelamt, qtrqnty, dimeqnty, nickelqnty, anothercustomer = 1, Quit = 0;
	int PotatoChipQnty = 5, ChewingGumQnty = 5, PretzelsQnty = 5, CheeseCurlsQnty = 5, ChocolateChipCookiesQnty = 5, CandyBarsQnty = 5;
	double total = 0, deposit = 0, profit = 0;
	qtrqnty = InitQtrAmt;
	dimeqnty = InitDimeAmt;
	nickelqnty = InitNickelAmt;

	do
	{
		do
		{
			displayMenu();
			getOption(opt, total, PotatoChipQnty, ChewingGumQnty, PretzelsQnty, CheeseCurlsQnty, ChocolateChipCookiesQnty, CandyBarsQnty, Quit);
		} while(opt != 7);
		if (opt == 7 && Quit != 2)
		{
			collectCoins(total, qtramt, dimeamt, nickelamt, deposit, qtrqnty, dimeqnty, nickelqnty);
			checkChange(total, deposit, qtramt, nickelamt, dimeamt, qtrqnty, dimeqnty, nickelqnty);
			Quit = EndofDay(total, anothercustomer, qtrqnty, dimeqnty, nickelqnty, deposit, qtramt, dimeamt, nickelamt, profit);
		}
	} while (Quit != 2);

	if (Quit == 2)
	{
	displayStats(qtrqnty, dimeqnty, nickelqnty, PotatoChipQnty, ChewingGumQnty, PretzelsQnty, CheeseCurlsQnty, ChocolateChipCookiesQnty, CandyBarsQnty, total, deposit, profit);
	}
	return 0;
}

void displayMenu()
{
	cout << "Select an option." << endl;
	cout << "1] Potato Chips - $1.00" << endl;
	cout << "2] Chewing Gum - $0.55" << endl;
	cout << "3] Cheese Curls - $0.80" << endl;
	cout << "4] Pretzels - $0.75" << endl;
	cout << "5] Chocolate Chip Cookies - $1.50" << endl;
	cout << "6] Candy Bar - $1.00" << endl;
	cout << "7] Quit" << endl;
}

void getOption(int & opt, double & total, int & PotatoChipQnty, int & ChewingGumQnty, int & CheeseCurlsQnty, int & PretzelsQnty, int & ChocolateChipCookiesQnty, int & CandyBarsQnty, int & Quit)
{
	string foodname;
	double cost;
	cin >> opt;
	if (opt < 1 || opt > 7)
	{
		cout << "Invalid Option.  Try Again." << endl;
	}
	else if (opt >= 1 && opt <= 6)
	{
		if (opt == 1)
		{
			if (PotatoChipQnty >= 1)
			{
				foodname = "Potato Chips";
				cost = PotatoChipPrice;
				total = total + cost;
				PotatoChipQnty = PotatoChipQnty - 1;
			}
			else
			{
				cout << "Out of Stock.  Try Another Item." << endl;
				foodname = "Potato Chips";
			}
		}
		else if (opt == 2)
		{
			if (ChewingGumQnty >= 1)
			{
				foodname = "Chewing Gum";
				cost = ChewingGumPrice;
				total = total + cost;
				ChewingGumQnty = ChewingGumQnty - 1;
			}
			else
			{
				cout << "Out of Stock.  Try Another Item." << endl;
				foodname = "Chewing Gum";
			}
		}
		else if (opt == 3)
		{
			if (CheeseCurlsQnty >= 1)
			{
				foodname = "Cheese Curls";
				cost = CheeseCurlsPrice;
				total = total + cost;
				CheeseCurlsQnty = CheeseCurlsQnty - 1;
			}
			else
			{
				cout << "Out of Stock.  Try Another Item." << endl;
				foodname = "Cheese Curls";
			}
		}
		else if (opt == 4)
		{
			if (PretzelsQnty >= 1)
			{
				foodname = "Pretzels";
				cost = PretzelsPrice;
				total = total + cost;
				PretzelsQnty = PretzelsQnty - 1;
			}
			else
			{
				cout << "Out of Stock.  Try Another Item." << endl;
				foodname = "Pretzels";
			}
		}
		else if (opt == 5)
		{
			if (ChocolateChipCookiesQnty >= 1)
			{
				foodname = "Chocolate Chip Cookies";
				cost = ChocolateChipCookiesPrice;
				total = total + cost;
				ChocolateChipCookiesQnty = ChocolateChipCookiesQnty - 1;
			}
			else
			{
				cout << "Out of Stock.  Try Another Item." << endl;
				foodname = "Chocolate Chip Cookies";
			}
		}
		else if (opt == 6)
		{
			if (CandyBarsQnty >= 1)
			{
				foodname = "Candy Bar";
				cost = CandyBarsPrice;
				total = total + cost;
				CandyBarsQnty = CandyBarsQnty - 1;
			}
			else
			{
				cout << "Out of Stock.  Try Another Item." << endl;
				foodname = "Candy Bar";
			}
		}
		cout << "You chose Option " << opt << ": " << foodname << endl;
		cout << "Current Total: $" << fixed << setprecision(2) << total / 100 << endl;
	}
	else
	{
		cout << "You chose Option 7." << endl;
		if (total == 0)
		{
			cout << "You haven't bought anything.  Quitting." << endl;
			Quit = 2;
		}
		else if (total != 0)
		{
			cout << "Proceeding to checkout..." << endl;
			cout << "Total Cost: $" << fixed << setprecision(2) << total / 100 << endl;
		}
	}
}

void collectCoins(double total, int & qtramt, int & dimeamt, int & nickelamt, double & deposit, int & qtrqnty, int & dimeqnty, int & nickelqnty)
{
	int cointype, stopinserting = 2;
	do
	{
		cout << "Choose a coin, and enter how many you would like to insert." << endl;
		cout << "1] Quarters 2] Dimes 3] Nickels" << endl;
		cin >> cointype;
		while (cointype < 1 || cointype > 3)
		{
			cout << "Invalid Option.  Try Again." << endl;
			cout << "1] Quarters 2] Dimes 3] Nickels" << endl;
			cin >> cointype;
		}
		switch(cointype)
		{
			case 1:
				do
				{
				cout << "How many quarters do you want to insert?" << endl;
				cin >> qtramt;
				} while (qtramt < 0);
				deposit = deposit + (qtramt * 25);
				cout << "You deposited $" << deposit / 100 << endl;
				if (deposit < total)
				{

					cout << "You still need $" << (total / 100) - (deposit / 100) << endl;
				}
				qtrqnty = qtrqnty + qtramt;
				break;
			case 2:
				do
				{
					cout << "How many dimes do you want to insert?" << endl;
					cin >> dimeamt;
				} while (dimeamt < 0);
				deposit = deposit + (dimeamt * 10);
				cout << "You deposited $" << deposit / 100 << endl;
				if (deposit < total)
				{
					cout << "You still need $" << (total / 100) - (deposit / 100) << endl;
				}
				dimeqnty = dimeqnty + dimeamt;
				break;
			case 3:
				do
				{
					cout << "How many nickels do you want to insert?" << endl;
					cin >> nickelamt;
				} while (nickelamt < 0);
				deposit = deposit + (nickelamt * 5);
				cout << "You deposited $" << deposit / 100 << endl;
				if (deposit < total)
				{
					cout << "You still need $" << (total / 100) - (deposit / 100) << endl;
				}
				nickelqnty = nickelqnty + nickelamt;
				break;
		}
		if (deposit >= total)
		{
			cout << "Total has been met." << endl;
			stopinserting = 1;
		}
	} while (stopinserting != 1);
}

void checkChange(double total, double deposit, int qtramt, int dimeamt, int nickelamt, int & qtrqnty, int & dimeqnty, int & nickelqnty)
{
	int difference;

	if (deposit > total)
	{
		difference = deposit - total;
		cout << "Change Back: $" << (deposit - total) / 100 << endl;

		qtramt = difference / 25;

		if (qtrqnty < qtramt)
		{
			if (qtrqnty == 0)
			{
				cout << "[Out of Quarters]" << endl;
			}
			else if (qtrqnty > 0)
			{
				cout << "[QTR Test Failed -- CASE 2 -- ABOVE 0]" << endl;
				qtramt = qtrqnty;
				qtrqnty = qtrqnty - qtramt;
				cout << "Quarters: " << qtramt << endl; // Quarters
				difference = difference - (25 * qtramt);
			}
		}
		else
		{
			cout << "Quarters: " << qtramt << endl; // Quarters
			difference = difference % 25;
			qtrqnty = qtrqnty - qtramt;
		}

	dimeamt = difference / 10;

		if (dimeqnty < dimeamt)
		{
			if (dimeqnty == 0)
			{
				cout << "[Out of Dimes]" << endl;
			}
			else if (dimeqnty > 0)
			{
				cout << "[DIME Test Failed -- CASE 2 -- ABOVE 0]" << endl;
				dimeamt = dimeqnty;
				dimeqnty = dimeqnty - dimeamt;
				cout << "Dimes: " << dimeamt << endl; // Dimes
				difference = difference - (10 * dimeamt);
			}
		}
		else
		{
			cout << "Dimes: " << dimeamt << endl; // Dimes
			difference = difference % 10;
			dimeqnty = dimeqnty - dimeamt;
		}

	nickelamt = difference / 5;

		if (nickelqnty < nickelamt)
		{
			cout << "NICKEL Test Failed." << endl;
		}
		else
		{
			cout << "Nickels: " << nickelamt << endl; // Nickels
			difference = difference % 5;
			nickelqnty = nickelqnty - nickelamt;
		}

		if (difference != 0)
		{
			cout << "Remainder: " << difference << endl; // For Testing
			cout << "There are not enough coins to give change." << endl;
		}
	}
	else if (total == deposit)
	{
		cout << "No change." << endl;
	}
}

int EndofDay(double & total, int anothercustomer, int qtrqnty, int dimeqnty, int nickelqnty, double & deposit, int & qtramt, int & dimeamt, int & nickelamt, double & profit)
{
	cout << "Is there another customer?" << endl;
	cout << "1] Yes 2] No" << endl;
	cin >> anothercustomer;
	while (anothercustomer < 1 || anothercustomer > 2)
	{
		cout << "Invalid Response.  Try Again." << endl;
		cout << "Is there another customer?" << endl;
		cout << "1] Yes 2] No" << endl;
		cin >> anothercustomer;
	}

	profit = profit + total;
	total = 0, deposit = 0, qtramt = 0, dimeamt = 0, nickelamt = 0; // resetting of all calculating values
	return anothercustomer;
}

void displayStats(int qtrqnty, int dimeqnty, int nickelqnty, int PotatoChipQnty, int ChewingGumQnty, int CheeseCurlsQnty, int PretzelsQnty, int ChocolateChipCookiesQnty, int CandyBarsQnty, double total, double deposit, double profit)
{
	cout << endl; // space for effect
	cout << "Vending Machine Statistics" << endl;
	cout << "COIN TOTALS" << endl;
	cout << "Quarters: " << qtrqnty << ", ";
	cout << "Dimes: " << dimeqnty << ", ";
	cout << "Nickels: " << nickelqnty << ", " << endl;
	cout << "INVENTORY REMAINING" << endl;
	cout << "Potato Chips: " << PotatoChipQnty << endl;
	cout << "Chewing Gum: " << ChewingGumQnty << endl;
	cout << "Cheese Curls: " << CheeseCurlsQnty << endl;
	cout << "Pretzels: " << PretzelsQnty << endl;
	cout << "Chocolate Chip Cookies: " << ChocolateChipCookiesQnty << endl;
	cout << "Candy Bars: " << CandyBarsQnty << endl;
	cout << "ACCOUNTING" << endl;
	cout << "Total Profit: $" << profit / 100 << endl;
}
