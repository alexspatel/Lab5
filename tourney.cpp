/*
	LAB 5: Tourney
	AUTHOR: Alex Patel

	The number of teams in the tournament should be a power of
	2 -- if it isn't, byes are added to the bracket. Byes are 
	never placed so that they will "play" each other. When a team's
	opponent is "bye", there is no game played and the team 
	automatically advances as if it had won a game. Here is an 
	example with a bracket of length 4 containing one bye (see
	Example 0). 
             ROUND 1       ROUND 2
      DUKE
          |--------- DUKE
      UCLA              |
                        |-------- MIT
      bye               |
          |---------- MIT
      MIT


	We have the tournament bracket (including any byes) from a 
	previous year's tournament. We also have a list of the results 
	of the games in the order in which they were played. We want 
	to figure out who won the tournament. Create a function winner
	that is given a vector of strings bracket and a string results
	and that returns the name of the winning team as a string. The
	bracket is given in order from top to bottom, and the results 
	are given as a string of 'H' or 'L' indicating for each game 
	(in the order in which the games were played) whether the Higher
	or Lower team from the bracket won that game. The string results
	contains a character for each real game, but not for byes. 

	example:
	bracket = {"DUKE","UCLA","bye","MIT"}

	results = "HL"

	Returns:  "MIT"

*/

#include <iostream>
#include <queue>

using namespace std;

string winner(vector<string> bracket, string results);

int main()
{

	std::string bracket = {"DUKE","UCLA","bye","MIT"};

	cout << bracket[1];
	system("pause");

	return 0;
}

string winner(vector<string> bracket, string results)
{
	return "CSM";
}
