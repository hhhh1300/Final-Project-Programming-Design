#pragma once
#include "Screen.h"
#include "Button.h"
#include "Game.h"
class AfterGame : public Screen
{
public :
	int point;
	int point2;
	int run(sf::RenderWindow& App);
};

