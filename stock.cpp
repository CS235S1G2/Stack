/***********************************************************************
* Implementation:
*    STOCK
* Summary:
*    This will contain the implementation for stocksBuySell() as well
*    as any other function or class implementation you need
* Author
*    <your names here>
**********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <sstream>
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "dollars.h"   // used to handle currency
//TODO add back in queue #include "queue.h"     // for QUEUE
#include <queue>
using namespace std;

queue <int> qShares;
queue <Dollars> qDollars;
queue <string> qTransactionHistory;

void buyStock(int shares, Dollars dollars)
{
	qShares.push(shares);
	qDollars.push(dollars);
}

Dollars sellStock(int sharesToBeSold, Dollars dollars)
{
	int soldShares = 0;
	Dollars proceeds = 0;
	// While we haven't sold enough shares
	while (soldShares < sharesToBeSold)
	{
		// while adding one transaction still won't be enough keep 
		// adding transactions
		while ((soldShares + qShares.front()) < sharesToBeSold)
		{
			// add shares of one transaction
			soldShares += qShares.front();
			// figure out the proceeds 
			proceeds += (dollars - qDollars.front()) * qShares.front();
			// remove that transaction
			qShares.pop();
			qDollars.pop();
			// update the count of the shares we still need to sell
			sharesToBeSold -= soldShares;
		}
		// adding one is more than enough so add part of a transaction
		// get rid of some of the shares in the front transaction of the queue
		qShares.front() -= (sharesToBeSold);
		soldShares += sharesToBeSold;
		// proceeds = buying price * the rest of the shares we need to sell
		proceeds += (dollars - qDollars.front()) * (sharesToBeSold);
	}
		// We sold all the shares we needed to sell, update the record
		sharesToBeSold = 0;
		string s1 = "Sold ";
		string s2 = " shares at ";
		string s3 = " for a profit of ";
		cout << s1 << soldShares << s2 << dollars << s3 << proceeds;
}

void display(Dollars proceeds)
{
	cout << proceeds;
}

/************************************************
* STOCKS BUY SELL
* The interactive function allowing the user to
* buy and sell stocks
***********************************************/
void stocksBuySell()
{
	// instructions
	cout << "This program will allow you to buy and sell stocks. "
		<< "The actions are:\n";
	cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
	cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
	cout << "  display         - Display your current stock portfolio\n";
	cout << "  quit            - Display a final report and quit the program\n";

	Dollars proceeds;
	stringstream ss;
	string instruction;
	int shares = 0;
	string command;
	Dollars dollars;
	while (instruction != "quit")
	{
		getline(cin, instruction);
		istringstream ss(instruction);
		ss >> command >> shares >> dollars;
		cout << "command:" << command << " shares:" << shares << " dollars:" << dollars;
		if (command == "buy")
		{
			buyStock(shares, dollars);
		}
		else if (command == "sell")
		{
			proceeds = sellStock(shares, dollars);
		}
		else if (command == "display")
		{
			display(proceeds);
		}
	}
}

// TODO delete main
int main()
{
	stocksBuySell();
	return 0;
};

