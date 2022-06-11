#include "Ball.h"

Ball::Ball()
{
	this->initVariable();
	this->initTexture();
	this->initSprite();
}

void Ball::initVariable()
{
	speedx = -5;
	speedy = 5;
	gravity = 0.05;
	direct = true;
}


void Ball::initTexture()
{
	if (!this->texture.loadFromFile("texture/ball.png"))
		std::cout << "ERROR::NOT SUCH FILE" << "\n";
}

void Ball::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(sf::Vector2f(0.1f, 0.1f));
}

void Ball::move()
{
	speedy -= -1 * gravity;
	sprite.move(speedx, speedy);
}

void Ball::windowBoundCollision(sf::RenderTarget* target)
{
	if (this->sprite.getGlobalBounds().left <= 0)
	{
		speedx *= -1;
		float y = sprite.getGlobalBounds().top;
		sprite.setPosition(sprite.getGlobalBounds().width, y + speedy);
	}
	if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= target->getSize().x)
	{
		speedx *= -1;
		float y = sprite.getGlobalBounds().top;
		sprite.setPosition(target->getSize().x - sprite.getGlobalBounds().width, y + speedy);
	}
	if (this->sprite.getGlobalBounds().top <= 0)
	{
		speedy *= -1;
		float x = sprite.getGlobalBounds().left;
		sprite.setPosition(x + speedx, sprite.getGlobalBounds().height);
	}
	if (this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height >= target->getSize().y)
	{
		speedy *= -1;
		float x = sprite.getGlobalBounds().left;
		sprite.setPosition(x + speedx, target->getSize().y - sprite.getGlobalBounds().height);
	}
}


Ball::~Ball()
{
}

void Ball::update()
{
	move();
}

void Ball::initPosition(sf::RenderTarget* target)
{
	float x = target->getSize().x / 2 - sprite.getGlobalBounds().width / 2;
	float y = 0;
	sprite.setPosition(x, y);
	if (direct)
	{
		speedx = -5;
		speedy = 5;
	}
	else
	{
		speedx = 5;
		speedy = 5;
	}

}

void Ball::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
