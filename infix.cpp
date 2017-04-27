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
using namespace std;

/*****************************************************
 * ITERATE STRING
 * Accepts a Stack and a String to assist in converting
 * infix equations to postfix
 *****************************************************/
 void iterateString(Stack <char> &ops, string input, int i)
 {
      string inParen;
      
      // iterate through string
   for (; i < input.length(); i++)
   {
      switch(input[i])
      {
         // standard ops
         case '+':
            ops.push(input[i]);
            break;
         case '-':
            ops.push(input[i]);
            break;         
         case '*':
            ops.push(input[i]);
            break;         
         case '/':
            ops.push(input[i]);
            break;
         // exponent
         case '^':
            ops.push(input[i]);
            break;
         // parenthesis - repeat this process until ')' update i
         case '(':
            // continue until ')'
            for (; input[i] == ')'; i++)
            {
               inParen += input[i];
            }
            iterateString(ops, inParen, i);
         // space
         case ' ':
            break;
         default:
            cout << input[i] << " ";
      }
   }

   while (!ops.empty())
   {
      cout << ops.top();
      ops.pop();
   }
 }

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
   string input;
   int i = 0;
   Stack <char> ops;

   cout << "Enter an infix equation.  Type \"quit\" when done.\n";
        
   
   do
   {
      cout << "infix > ";
      getline(cin, input);
      if (input == "quit")
         break;
      cout << "\tpostfix:  ";

      // iterate through string
      iterateString(ops, input, i);

      cout << endl << endl;
      ops.clear();
      i = 0;
   } while (input != "quit");

}

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly()
{

}
