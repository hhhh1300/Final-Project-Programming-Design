#pragma once
#include "Screen.h"
#include "Button.h"
class Setting : public Screen
{
private :
	float volume;
public :
	Setting() { volume = defaultVolume; };
	float getVolume();
	int run(sf::RenderWindow& App);
};

