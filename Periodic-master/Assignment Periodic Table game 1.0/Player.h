#pragma once
#include <string>
class Player
{
	int lives;

public:
	Player();
	~Player();

	bool IsAlive();
	void DecreaseLives();
	int getLives();
	virtual std::string getAnswer();

};

