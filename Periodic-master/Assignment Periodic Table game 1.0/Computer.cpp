#include "stdafx.h"
#include "Computer.h"
#include <list>
#include <string>
#include <iostream>

Computer::Computer(std::list<std::string> &words, std::string &lastAnswer, std::string diffLevel) : words(words), lastAnswer(lastAnswer), diffLevel(diffLevel)
{

}


Computer::~Computer()
{
}


std::string Computer::getAnswer()
{
	//holds the letter m
	char m = 'm';
	char M = 'M';
	//AI answer if there is a option to use a word that ends in m
	std::string AIanswer;
	//Answer that gets sent to the periodic.cpp main as the Computers answer
	std::string ComputerAnswer;
	std::cout << diffLevel << std::endl;
	//where Last letter of the last played answer will be held
	char lastLetter;


	std::string hardAnswer;
	std::string mediumAnswer;
	std::string easyAnswer;
	//for loop to itterate through the list
	for (auto& i : words) {
		//gets the last letter of the last anser played
		lastLetter = lastAnswer[lastAnswer.length() - 1];
		//changes the casing of the last letter to uppercase
		lastLetter = toupper(lastLetter);
		//check to see if the last letter is = to the first letter of the list word being checked.

		if (lastLetter != i[0])
		{
			continue;
		}

		//----------------------------------------------------------------------------------------
//Hard difficulty
	//If lastLetter = Mit will ensure AI victory

		/*checks for star m and end m*/
		if (diffLevel == "3") {
			if (lastLetter == M) {
				if (i[i.length() - 1] == m) {
					hardAnswer = i;
					break;
				}
				else {
					continue;
				}
			}
			
			if (lastLetter != M) {
				if (i[i.length() - 1] != m) {
					hardAnswer = i;
					break;
				}
				else {
					continue;
				}

			}

			}
		





		//----------------------------------------------------------------------------------------
	////Medium difficulty
		if (diffLevel == "2") {
			if (lastLetter == M) {
				if (i[i.length() - 1] != m) {
					mediumAnswer = i;
					break;
				}
				else {
					continue;
				}
			}

			if (lastLetter != m) {
				if (i[i.length() - 1] != m) {
					mediumAnswer = i;
					break;
				}
				else {
					continue;
				}

			}

		}

	//	//-----------------------------------------------------------------------------------------
	//	//easy difficulty
		if (diffLevel == "1") {
			easyAnswer = i;
			break;
}
}

	if (!hardAnswer.empty())
	{
		std::cout << "hard" << std::endl;

		return hardAnswer;
		words.remove(hardAnswer);
	}
	if (!mediumAnswer.empty())
	{
		std::cout << "Medium" << std::endl;

		return mediumAnswer;
		words.remove(mediumAnswer);
	}
	std::cout << "easy" << std::endl;

	return easyAnswer;
	words.remove(easyAnswer);
}
