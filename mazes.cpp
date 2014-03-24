/*
	LAB 5: Mazes
	AUTHOR: Alex Patel

	In short, your job is to discover if there is a way to 
	successfully solve a rectangular maze (see example below): 

		########
		#.##..*#
		#.##.###
		#.#..###
		#.##...#
		#o...#.#
		########


	In the maze, the start and end points are notated as 'o' 
	and '*'. The '#' character represents a wall. Movement is 
	up, right, down, or left; no diagonal moves allowed! The 
	above maze is solvable; here is one which is not solvable:
		...#.*
		.#..##
		.#...#
		o#....

	Note that the only legal routes are those within the maze
	boundaries - even if there are no walls around the maze. 
	Create a function has_solution, which takes a vector of 
	strings maze and returns true if the maze has a solution,
	and false otherwise. 

	example:

		{"#####",
		 "#o.*#",
		 "#####"}

		return true
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

queue <string> store;


// FUNCTION PROTOTYPE
bool has_solution(vector<string>);

int main()
{

	vector <string> maze;
	maze.push_back("#####");
	maze.push_back("#o.*#");
	maze.push_back("#####");
	/*string mazes[] =
	{"#####",
	 "#o.*#",
	 "#####"};*/

	has_solution(maze);

	

	system("pause");

	return 0;
}



bool has_solution(vector<string> maze) 
{
	// ENQUEUE EACH ROW TO THE QUEUE
	for( int i = 0; i < maze.size(); i++ )
	{
		store.push(maze[i]); // enqueue each element of maze to the queue
		cout << "enque: " << maze[i] << endl;
	}
	cout << endl;

	int start_row;
	int finish;
	int col = 0;
	int i;
	string row;

	// LOOP THROUGH THE ROWS IN THE QUEUE
	for( i = 0; i < maze.size(); i++ )
	{
		row = maze[i];

		if( row[i] == 'o' )
		{
			start_row = i;
			cout << "start row: " << start_row << endl;
			cout << "start col: " << col << endl;
		}
		
		col++; // increment the number of the column
	}


	if( row[i] == '*' )
	{
		finish = i;
		cout << finish << endl;
	}
	else if( row[i] == '.' )
	{
		row[i] = 'X'; // Mark a trail
		cout << row[i] << endl;
	}


	return true; 
}
