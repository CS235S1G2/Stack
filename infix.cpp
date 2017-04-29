/***********************************************************************
* Source:
*    Infix.cpp
* Summary:
*    This will contain just the prototype for the convertInfixToPostfix()
*    function
* Author
*    Justin Chandler, Jeremy Chandler, Nathan Bench, Jed Billman
************************************************************************/

#include "infix.h"
#include "stack.h"
#include <string>
#include <iostream>

using namespace std;

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
	// The Infix expression which the user inputs
	string infixExression;

	char token, topToken;
	Stack<char> operatorStack;
	const string SPACE = " ";

	// The postFix expressoin
	string postfixExpression;
	// Recieving input from the user for infix expression
	cout << "Enter an infix equation.  Type \"quit\" when done.";
	while (infixExression != "quit")
	{
		cout << "\ninfix > ";
		getline(cin, infixExression);

		// To convert infix to postfix
		for (int i = 0; i < infixExression.length(); i++)
		{
			token = infixExression[i];
			switch (token)
			{
			case ' ': break; // do nothing with blanks
			case '(': operatorStack.push(token);
				break;
			case ')': for (;;)
			{
				assert(!operatorStack.empty());  // an open parenthesis needs to be placed before a closed parenthesis
				topToken = operatorStack.top();
				operatorStack.pop();
				if (topToken == '(') break;
				postfixExpression.append(SPACE + topToken);
			}
            break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				for (;;)
				{
					if (operatorStack.empty() ||
						operatorStack.top() == '(' ||
						(token == '^') &&
						(operatorStack.top() == '+' || operatorStack.top() == '-' ||
							operatorStack.top() == '*' || operatorStack.top() == '/' || operatorStack.top() == '%'))
					{
						operatorStack.push(token);
						break;
					}
					else if (operatorStack.empty() ||
						operatorStack.top() == '(' ||
						(token == '*' || token == '/' || token == '%') &&
						(operatorStack.top() == '+' || operatorStack.top() == '-'))
					{
						operatorStack.push(token);
						break;
					}
					else
					{
						topToken = operatorStack.top();
						operatorStack.pop();
						postfixExpression.append(SPACE + topToken);
					}
				}
				break;
			default:
				if (token == '.')
				{
               if (isalnum(infixExression[i - 1]))
                  postfixExpression.append(1, token);
               else
                  postfixExpression.append(SPACE + token);
				}
				else
					postfixExpression.append(SPACE + token);
				for (;;)
				{
					if (!isalnum(infixExression[i + 1])) break; // end of identifier
					i++;
					token = infixExression[i];
					postfixExpression.append(1, token);

				}
				break;

			}

		}
		// pop remaining operators on the stack
		for (;;)
		{
			if (operatorStack.empty()) break;
			topToken = operatorStack.top();
			operatorStack.pop();
			if (topToken != '(')
			{
				postfixExpression.append(SPACE + topToken);
			}
			else
			{
				cout << " Error in infix expression!\n";
				break;
			}
		}

		// display results
		if (infixExression != "quit")
		{
			cout << "\tpostfix: " << postfixExpression << "\n";
		}
			// reset variables
			token, topToken = '\n';
			operatorStack.clear();
			postfixExpression = "";
		}
	}

/*****************************************************
* TEST INFIX TO ASSEMBLY
* Prompt the user for infix text and display the
* resulting assembly instructions
*****************************************************/
void testInfixToAssembly()
{

}
