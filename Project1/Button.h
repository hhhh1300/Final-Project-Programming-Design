#pragma once
#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
using namespace std;
class Button
{
	friend class Menu;
	friend class Members;
	friend class Guide;
	friend class Setting;
	friend class Game;
	friend class AfterGame;
private :
	sf::Texture t;
	sf::RenderWindow *window;

public :
	bool isActive;
	bool pressedBeforeRealese;
	Button() : window(nullptr), isActive(false), pressedBeforeRealese(false) {};
	void setTexture(string str);
	void setPosition(float x, float y);
	void setScale(float x, float y);
	void show();
	bool onClick(sf::Event &e);
	sf::Sprite s;
};

