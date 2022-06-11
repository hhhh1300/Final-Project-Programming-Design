#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::SoundBuffer buffer;
	sf::Sound jumpSound;
	float speedMax;
	float jumpSpeedMax;
	float gravity;
	float acceleration;
	bool jumping;

	void initTexture();
	void initSprite();
	void initVariables();
	void initSound();

public:
	Player();
	~Player();

	void initPosition(sf::RenderTarget* target);
	void windowBoundCollision(sf::RenderTarget* target);
	void updatePosition(sf::RenderTarget* target);
	void jump();
	void update(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);

	friend class Game;
};

