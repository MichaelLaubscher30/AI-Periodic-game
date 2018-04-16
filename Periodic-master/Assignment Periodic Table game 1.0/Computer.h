#pragma once
#include <string>
#include "Player.h"
#include <list>

class Computer:public Player
{
private:
	std::list<std::string>& words;
	std::string &lastAnswer;
	std::string diffLevel;
	
public:
	Computer::Computer(std::list<std::string> &words, std::string &lastAnswer, std::string diffLevel);
	~Computer();
	std::string getAnswer()override;

};

