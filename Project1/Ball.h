#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Ball
{
private:
	float speedx;
	float speedy;
	float gravity;
	sf::Texture texture;
	sf::Sprite sprite;

	void initVariable();
	void initTexture();
	void initSprite();
	void move();
public:
	Ball();
	~Ball();
	bool direct;

	void initPosition(sf::RenderTarget* target);
	void windowBoundCollision(sf::RenderTarget* target);
	void update();
	void render(sf::RenderTarget* target);
	friend class Game;
};

