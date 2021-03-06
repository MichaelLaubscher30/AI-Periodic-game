#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <set>
#include "Player.h"
#include "Computer.h"
#include <memory>
//#include <boost\asio.hpp>

using namespace std;

// FOR ALL THE FUNCTION DECLARATIONS BELOW, YOU MAY USE VECTORS INSTEAD OF LISTS BUT BEAR IN MIND THE DIFFERENCE IN EFFICIENCY MAY REQUIRE YOU TO ALTER THE IMPLEMENTATION A BIT

std::set<std::string> setOfStrs;

/*
This function reads a file and stores each line in a list of strings, you should use <fstream> to achieve this
@param  l: the list of strings
@param  s: the filename*/
void readFile(list<string>& l, string Elements1) {
	std::ifstream ifs(Elements1);
	string v;
	while (getline(ifs, v)) {
		l.push_back(v);
	}
}

string toLowerCase(string moo) {
	string mooLower;
	for (int o = 0; o < moo.length(); o++) {
		mooLower += tolower(moo[o]);

	}
	return mooLower;
}

bool equalsIgnoreCase(string l, string s) {
	return toLowerCase(l) == toLowerCase(s);
}

/*
This function returns true if a specified string is contained in a list
@param  l: the list of strings
@param  s: the string to be checked
@return true if s is a member of l, false otherwise
*/
//function that cycles through the list and ignores the case

bool isin(list<string> l, string s) {
	for (auto i : l) {
		if (equalsIgnoreCase(i, s)) {
			return true;
		}

	}
	cout << "Your word does not match the criteria" << endl;
	return false;
}
//Life check

void lives(int P1, int P2) {
	if (P1 == 0) {
		cout << "Player 2 Wins" << endl;

	}
	if (P2 == 0) {
		cout << "Player 1 Wins" << endl;
	}
}

/*
This function returns true if the last letter of one string matches the first letter of another
@param  first:  the string whose first character is to be checked
@param  last:   the string whose last character to be checked
@return true if first and last characters are equal, regardless of case
*/

//Checks to see if the two answers are matching

bool match(string answer, string lastAnswer) {
	//    stops error at the start of the game where lastAnswer was empty
	if (lastAnswer.empty()) {
		return true;
	}
	//    specifies the location of the characters I want to focus on
	char f = answer[0];
	char end = lastAnswer[lastAnswer.length() - 1];
	//    converts them to lowercase
	if (tolower(f) == tolower(end)) {
		cout << "Next move" << "\n\n\n\n\n" << endl;
		return true;
	}
	else {
		cout << "Your word does not fulfilled the objective" << endl;

		return false;
	}
}
bool insertInSet(std::set<std::string> & setOfStrs, std::string str)
{
	std::pair<std::set<std::string>::iterator, bool> result;

	result = setOfStrs.insert(str);

	// Check if word is added sucessfuly
	if (result.second) {
		std::cout << "Correct Answer" << std::endl << "---------------------------------" << std::endl;
		return true;
	}
	std::cout << "Wrong Answer" << std::endl << "---------------------------------" << std::endl;

	return false;

}
//Checks the answer given

bool checkAnswer(list<string> playerWords, string &lastAnswer, string answer) {

	//    Checks to see if the word is found in the external file
	if (!isin(playerWords, answer)) {
		return false;
	}

	//    Checks to see if there is a match between the first and last letters
	if (!match(answer, lastAnswer)) {
		return false;
	}
	/*Check for duplicate words using set*/
	// Try to insert the element.
	bool result = insertInSet(setOfStrs, answer);
	if (!result) {
		for (auto elem : setOfStrs)
			std::cout << "Words that have already been used" << endl << elem << endl << "***************************************" << std::endl;
		return false;
	}
	//    last Answer takes the value of answer
	lastAnswer = answer;

	return true;
}
inline std::string toupper(std::string answer){
	for (int i = 0; i < answer.length(); i++)
	{
		answer[i] = toupper(answer[i]);
	}
	return answer;
}
string diffLevel = "3";


//insert program here....

int main() {
	list<string> playerWords;
	readFile(playerWords, "Elements1.txt");
	string lastAnswer;
	std::unique_ptr<Player> player1;
	std::unique_ptr<Player> player2;
	std::cout << "Welcome to the Periodic table game" << endl;
	std::cout << "Players will each take turns typing in names of the elements" << endl;
	std::cout << "on the periodic table" << endl;
	std::cout << "You will need to match the first letter of your word to the last" << endl;
	std::cout << "letter played by the other player" << endl;
	std::cout << "Good luck" << "\n\n\n\n" << endl;


	//Game type
	std::cout << "Choose game type" << "\n\n" << endl;
	std::cout << "Type in a number to select a gamemode" << endl;
	std::cout << "Player vs Player = 1" << endl;
	std::cout << "Player vs Computer = 2" << endl;
	std::cout << "Player vs PLayer over a network = 3" << endl;
	std::cout << "Exit Game = 4" << endl;

	string option;
	std::getline(std::cin, option);
	if (option == "1") {
		player1 = std::make_unique<Player>();
		player2 = std::make_unique<Player>();

	}
	else if (option == "2")
	{
		player1 = std::make_unique<Player>();

		//Game difficulty 

		string diffOption;


		std::cout << "Choose game difficulty" << "\n\n" << endl;
		std::cout << "Easy = 1" << endl;
		std::cout << "Medium = 2" << endl;
		std::cout << "Hard = 3" << endl;
		std::cout << "Exit Game = 4" << endl;

		std::getline(std::cin, diffOption);

		if (diffOption == "1") {
			diffLevel = diffOption;

		}
		else if (diffOption == "2") {
			diffLevel = diffOption;

		}
		else if (diffOption == "3") {
			diffLevel = diffOption;

		}

		else if (option == "4")
		{
			exit(0);
		}
		player2 = std::make_unique<Computer>(playerWords, lastAnswer, diffLevel);

	


	}
	else if (option == "3")
	{
		player1 = std::make_unique<Player>();

	}
	else if (option == "4")
	{
		exit(0);

	}
	std::cout << "\n\n\n" << "Round START" << "\n\n" << endl;
	bool player1Turn = true;

	while (true) {
		bool success;
		for (auto elem : setOfStrs)
			std::cout << "Words that have already been used" << endl << elem << endl << "***************************************" << std::endl;
		if (player1Turn) {
			std::cout << "-------------------------------------------------------------------------------" << endl << "Player 1 lives remaining" << endl;
			std::cout << player1->getLives() << endl;
			std::cout << "player One please enter your word" << endl;


			string answer = player1->getAnswer();

			success = checkAnswer(playerWords, lastAnswer, answer);
			playerWords.remove(answer);
			if (!success) {
				player1->DecreaseLives();
			}
			/*Checks to make sure player 1 has lives*/
			if (!player1->IsAlive()) {
				std::cout << "Player 2 Wins" << endl;
				system("PAUSE");
				break;
			}

		}
		else {
			std::cout << "-------------------------------------------------------------------------------" << endl << "Player 2 lives remaining" << endl;
			std::cout << player2->getLives() << endl;

			std::cout << "player Two please enter your word" << endl;
	
			
			string answer = player2->getAnswer();

			success = checkAnswer(playerWords, lastAnswer, answer);
			playerWords.remove(answer);
			if (!success) {
				player2->DecreaseLives();
			}
			/*Checks to make sure player 2 has lives*/
			if (!player2->IsAlive()) {
				std::cout << "Player 1 Wins" << endl;
				system("PAUSE");
				break;
			}
		}

		if (success)
		{

			player1Turn = !player1Turn;
		}
		std::cout << "\n\n\n\n";
	}
}