#include "Player2.h"



void Player2::initTexture()
{
	if (!this->texture.loadFromFile("texture/star.png"))
		std::cout << "ERROR::NOT SUCH FILE" << "\n";
}

void Player2::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(sf::Vector2f(0.28f, 0.28f));
}

void Player2::initPosition(sf::RenderTarget* target)
{
	float x = target->getSize().x - sprite.getGlobalBounds().width;
	float y = target->getSize().y - sprite.getGlobalBounds().height;
	sprite.setPosition(sf::Vector2f(x, y));
}

void Player2::initVariables()
{
	this->speedMax = 4;
	this->jumpSpeedMax = 6.3;
	this->gravity = 4.2;
	this->jumping = false;
	this->acceleration = 7;
}

void Player2::initSound()
{
	if (!buffer.loadFromFile("audio/jumpsound.wav"))
	{
		std::cout << "ERROR::NOT SUCH FILE" << "\n";
	}
	jumpSound.setBuffer(buffer);
	jumpSound.setVolume(9);
}

Player2::Player2()
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
	this->initSound();
}

Player2::~Player2()
{
}

void Player2::windowBoundCollision(sf::RenderTarget* target)
{
	if (this->sprite.getGlobalBounds().left <= target->getSize().x / 2)
	{
		this->sprite.setPosition(target->getSize().x / 2, this->sprite.getGlobalBounds().top);
	}
	if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= target->getSize().x)
	{
		this->sprite.setPosition(target->getSize().x - this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().top);
	}
	if (this->sprite.getGlobalBounds().top <= 0)
	{
		this->sprite.setPosition(this->sprite.getGlobalBounds().left, 0);
	}
	if (this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height >= target->getSize().y)
	{
		if (jumping)
		{
			this->jumping = false;
			this->acceleration = 70;
		}
		this->sprite.setPosition(this->sprite.getGlobalBounds().left, target->getSize().y - this->sprite.getGlobalBounds().height);
	}
}

void Player2::updatePosition(sf::RenderTarget* target)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		sprite.move(-1 * speedMax, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		sprite.move(speedMax, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (sprite.getGlobalBounds().top == target->getSize().y - sprite.getGlobalBounds().height)
		{
			this->jumping = true;
			jumpSound.play();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		sprite.move(0, speedMax);
}

void Player2::jump()
{
	if (jumping)
	{
		acceleration -= gravity;
		sprite.move(0, -1 * acceleration);
	}
}

void Player2::update(sf::RenderTarget* target)
{
	this->updatePosition(target);
	this->jump();
}

void Player2::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
