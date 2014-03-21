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

	is_valid( "{x * [y * (z + <a,b>*<c,d>) - (e^k)] - phi}(_m_)", "([{<", ")]}>" );

	system("pause");

	return 0;
}

bool is_valid(string expr, string left, string right)
{
	stack<char> store;			// stack to store the left delimiter
	int size = expr.length();	// length of expr

	// INITIAL CONDITION CHECK
	// if either the left and right delimiters are NULL, or expr is NULL, return true.
	if( ( left == "" && right == "" ) || expr == "" )
	{
		return true;
	}
	
	// LEFT DELIMITER
	// Loop through the left delimiters, push each char to the stack
	for( int i = 0; i < left.length(); i++ )
	{
		store.push(left[i]); // push each character in the string left to the stack
		cout << "pushed: " << left[i] << endl;
	}

	// Loop through the expression, pop off a char if the char matches the top char in the stack
	for( int i = size - 1; i >= 0; i-- )
	{
		if( store.empty() )
		{
			cout << "failed" << endl;
			return false;
		}
		else if( expr[i] == store.top() )
		{
			store.pop(); // pop off the top value
			cout << "popped: " << expr[i] << endl;
		}
	}

	if( !store.empty() ) // if the stack is not empty, return false
	{
		cout << "stack not empty" << endl;
		return false;
	}

	cout << "end left, start right" << endl;

	// RIGHT DELIMITERS
	// Loop through the right delimiters, push each char to the stack
	for( int i = 0; i < right.length(); i++ )
	{
		store.push(right[i]); // push each char in right onto the stack
		cout << "pushed: " << right[i] << endl;
	}

	// Loop through expr, look for right delimiters
	for( int i = 0; i < expr.length(); i++ )
	{
		if( store.empty() )
		{
			cout << "failed" << endl;
			return false;
		}
		else if( expr[i] == store.top() )
		{
			store.pop(); // pop off the top value
			cout << "popped: " << expr[i] << endl;
		}
	}

	if( !store.empty() ) // if the stack is not empty, return false
	{
		cout << "stack not empty" << endl;
		return false;
	}

	cout << "passed" << endl;
	return true;
}
