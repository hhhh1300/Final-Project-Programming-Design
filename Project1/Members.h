#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include "Screen.h"
#include "Button.h"
class Members : public Screen
{
private:

public:
	Members() {}
	virtual int run(sf::RenderWindow& App);
};

