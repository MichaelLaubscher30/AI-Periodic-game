#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include <string>



Player::Player():lives(3)
{
}


Player::~Player()
{
}

bool Player::IsAlive()
{
	return lives > 0;
}

void Player::DecreaseLives()
{
	lives--;
}

int Player::getLives()
{
	return lives;
}

std::string Player::getAnswer()
{
	std::string answer;
	getline(std::cin, answer);
	for (int i = 0; i < answer.length(); i++)
	{
		answer[0] = toupper(answer[0]);
	}
	return answer;


}
