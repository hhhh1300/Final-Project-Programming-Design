#include "Button.h"

void Button::setTexture(string str)
{
	if (!this->t.loadFromFile(str))
	{
		std::cerr << "imageLoadingError\n";
	}
	this->s.setTexture(t);
}

void Button::setPosition(float x, float y)
{
	this->s.setPosition(sf::Vector2f(x, y));
}

void Button::setScale(float x, float y)
{
	this->s.setScale(sf::Vector2f(x, y));
}

bool Button::onClick(sf::Event& e)
{
	if (!this->isActive)
		return false;
	bool isOnClick = false;
	sf::FloatRect box = s.getGlobalBounds();
	//cout << box.left << " " << box.width << " " << box.top << " " << box.height << endl;
	//cout << "x : " << sf::Mouse::getPosition(*window).x << " y : " << sf::Mouse::getPosition(*window).y << endl;
	if (sf::Mouse::getPosition(*window).x >= box.left && sf::Mouse::getPosition(*window).x <= box.left + box.width && sf::Mouse::getPosition(*window).y >= box.top && sf::Mouse::getPosition(*window).y <= box.top + box.height)
	{
		if (e.type == sf::Event::MouseButtonReleased && e.key.code == sf::Mouse::Left && this->pressedBeforeRealese)
		{
			this->pressedBeforeRealese = false;
			isOnClick = true;
		}
		else
			isOnClick = false;
		if (e.type == sf::Event::MouseButtonPressed && e.key.code == sf::Mouse::Left)
		{
			this->s.setColor(sf::Color(125, 125, 0, 255));
			this->pressedBeforeRealese = true;
		}
		else
			this->s.setColor(sf::Color(125, 125, 0, 100));
	}
	else
	{
		this->s.setColor(sf::Color(255, 255, 255, 255));
	}
	return isOnClick;
}

void Button::show()
{
	this->isActive = true;
	(*this->window).draw(s);
}