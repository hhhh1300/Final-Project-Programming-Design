#include "Player.h"



void Player::initTexture()
{
	if (!this->texture.loadFromFile("texture/myimage.png"))
		std::cout << "ERROR::NOT SUCH FILE" << "\n";
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(sf::Vector2f(0.1f, 0.1f));
}

void Player::initPosition(sf::RenderTarget* target)
{
	float x = 0;
	float y = target->getSize().y - sprite.getGlobalBounds().height;
	sprite.setPosition(sf::Vector2f(x, y));
}

void Player::initVariables()
{
	this->speedMax = 4;
	this->jumpSpeedMax = 6.3;
	this->gravity = 4.2;
	this->jumping = false;
	this->acceleration = 7;
}

void Player::initSound()
{
	if (!buffer.loadFromFile("audio/jumpsound.wav"))
	{
		std::cout << "ERROR::NOT SUCH FILE" << "\n";
	}
	jumpSound.setBuffer(buffer);
	jumpSound.setVolume(9);
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
	this->initSound();
}

Player::~Player()
{
}

void Player::windowBoundCollision(sf::RenderTarget* target)
{
	if (this->sprite.getGlobalBounds().left <= 0.f)
	{
		this->sprite.setPosition(0.f, this->sprite.getGlobalBounds().top);
	}
	if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= target->getSize().x / 2)
	{
		this->sprite.setPosition(target->getSize().x / 2 - this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().top);
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

void Player::updatePosition(sf::RenderTarget* target)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		sprite.move(-1 * speedMax, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		sprite.move(speedMax, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (sprite.getGlobalBounds().top == target->getSize().y - sprite.getGlobalBounds().height)
		{
			this->jumping = true;
			jumpSound.play();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		sprite.move(0, speedMax);
}

void Player::jump()
{
	if (jumping)
	{
		acceleration -= gravity;
		sprite.move(0, -1 * acceleration);
	}
}

void Player::update(sf::RenderTarget* target)
{
	this->updatePosition(target);
	this->jump();
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
