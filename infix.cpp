/***********************************************************************
* Source:
*    Infix.cpp
* Summary:
*    This will contain just the prototype for the convertInfixToPostfix()
*    function
* Author
*    Justin Chandler, Jeremy Chandler, Nathan Bench
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
	string infixExp;

	char token, topToken;
	Stack<char> opStack;
	const string BLANK = " ";

	// The postFix expressoin
	string postFixExp;
	// Recieving input from the user for infix expression
	cout << "Enter an infix equation.  Type \"quit\" when done.";
	while (infixExp != "quit")
	{
		cout << "\ninfix > ";
		getline(cin, infixExp);

		// To convert infix to postfix
		for (int i = 0; i < infixExp.length(); i++)
		{
			token = infixExp[i];
			switch (token)
			{
			case ' ': break; // do nothing with blanks
			case '(': opStack.push(token);
				break;
			case ')': for (;;)
			{
				assert(!opStack.empty());  // an open parenthesis is necessary
				topToken = opStack.top();
				opStack.pop();
				if (topToken == '(') break;
				postFixExp.append(BLANK + topToken);
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
					if (opStack.empty() ||
						opStack.top() == '(' ||
						(token == '^') &&
						(opStack.top() == '+' || opStack.top() == '-' ||
							opStack.top() == '*' || opStack.top() == '/' || opStack.top() == '%'))
					{
						opStack.push(token);
						break;
					}
					else if (opStack.empty() ||
						opStack.top() == '(' ||
						(token == '*' || token == '/' || token == '%') &&
						(opStack.top() == '+' || opStack.top() == '-'))
					{
						opStack.push(token);
						break;
					}
					else
					{
						topToken = opStack.top();
						opStack.pop();
						postFixExp.append(BLANK + topToken);
					}
				}
				break;
			default:
				if (token == '.')
				{
               if (isalnum(infixExp[i - 1]))
                  postFixExp.append(1, token);
               else
                  postFixExp.append(BLANK + token);
				}
				else
					postFixExp.append(BLANK + token);
				for (;;)
				{
					if (!isalnum(infixExp[i + 1])) break; // end of identifier
					i++;
					token = infixExp[i];
					postFixExp.append(1, token);

				}
				break;

			}

		}
		// pop remaining operators on the stack
		for (;;)
		{
			if (opStack.empty()) break;
			topToken = opStack.top();
			opStack.pop();
			if (topToken != '(')
			{
				postFixExp.append(BLANK + topToken);
			}
			else
			{
				cout << " Error in infix expression!\n";
				break;
			}
		}

		// display results
		if (infixExp != "quit")
		{
			cout << "\tpostfix: " << postFixExp << "\n";
		}
			// reset variables
			token, topToken = '\n';
			opStack.clear();
			postFixExp = "";
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
