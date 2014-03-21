/*
	Lab 5: Nesting
	
	AUTHOR: Alex Patel

	Create a function is_valid, which takes three strings, expr,
	left, and right, and returns true if expr represents a valid 
	expression as regards the proper nesting of the left and right
	delimiters contained in left and right. Here the delimiters 
	are all single characters, so each index in left and right
	corresponds to one delimiter pair. 
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// FUNCTION PROTOTYPE
bool is_valid(string expr, string left, string right);

int main()
{

	is_valid("(awesome{sauce})","{(", "})" );
	system("pause");

	return 0;
}

bool is_valid(string expr, string left, string right)
{
	stack<char> store;		// stack to store the left delimiter
	string::size_type i;	// An index into the string 
	char next;				// The next character from the string

	cout << "expression: " << expr << endl;
	cout << "left delimiter: " << left << endl;
	cout << "right delimiter: " << right << endl;
	
	// Loop through the left delimiters
	cout << "left delimiters" << endl;
	for( i = 0; i < left.length(); ++i )
	{
		next = left[i];
		store.push(next);		// push next onto the stack	
		cout << "pushed: " << next << endl;
	}

	// Loop through the expression, evaluate left delimiters
	for( i = 0; i < expr.length(); i++ )
	{
		next = expr[i];
		if( next == store.top() ) // if the top of the stack contains the same character as expr
		{
			cout << "pop off : " << store.top() << endl;
			store.pop(); // pop off the top item in the stack
		}
		else
		{
			cout << "invalid delimiter: " << next << endl;
			return false;
		}
	}

	
	// Loop through the expression, evaluate right delimiters
	cout << "right delimiters" << endl;
	int sizeR = expr.length() - right.length();
	for( int j = expr.length() - 1; j >= sizeR; j-- )
	{
		next = expr[j];
		store.push(next);
		cout << "pushed: " << next << endl;
	}

	// Loop through the right delimiters
	for( int i = 0; i < right.length(); i++ )
	{
		next = right[i];
		if( next == store.top() ) // if the top of the stack contains the same character as right
		{
			cout << "pop off: " << store.top() << endl;
			store.pop(); // pop off the top item in the stack
		}
		else
		{
			cout << "invalid delimiter: " << next << endl;
			return false;
		}
	}


	cout << "valid!" << endl;
	return true;
}
