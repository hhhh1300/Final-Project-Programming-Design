
#include "Game.h"
#include<windows.h>


void Game::initVariables()
{
	this->window = nullptr;
	point = 0;
	point2 = 0;
}



void Game::initWindow(sf::RenderWindow &App)
{
	this->window = &App;
}

void Game::initTexture()
{
	if (!this->backgroundTex.loadFromFile("texture/library.jpg"))
	{
		std::cout << "ERROR::NOT SUCH FILE" << "\n";
	}
	if (!this->netTex.loadFromFile("texture/bush.png"))
	{
		std::cout << "ERROR::NOT SUCH FILE" << "\n";
	}
}

void Game::initSprite()
{
	this->background.setTexture(this->backgroundTex);
	this->background.setScale(1.25f, 1.25f);
	this->net.setTexture(this->netTex);
	this->net.setScale(0.6f, 0.5f);

	float x = (this->window->getSize().x / 2) - (this->net.getGlobalBounds().width / 2);
	float y = (this->window->getSize().y) - (this->net.getGlobalBounds().height);
	this->net.setPosition(sf::Vector2f(x, y));

}

void Game::initFont()
{
	if (!this->font.loadFromFile("font/font1.ttf"))
	{
		std::cout << "ERROR::NOT SUCH FILE" << "\n";
	}
}

void Game::initText()
{
	this->text.setFont(font);
	this->text.setFillColor(sf::Color::Cyan);
	this->text.setCharacterSize(72);
	this->text.setString("test");

	this->time.setFont(font);
	this->time.setFillColor(sf::Color::Cyan);
	this->time.setCharacterSize(72);
	this->time.setString("test");
}

void Game::initMusic()
{
	this->music.openFromFile("audio/audio1.ogg");
	this->music.setVolume(15.0);
	this->music.setLoop(true);
	this->music.play();
}

void Game::initSound()
{
	if (!buffer.loadFromFile("audio/cheersound.wav"))
	{
		std::cout << "ERROR::NOT SUCH FILE" << "\n";
	}
	sound.setBuffer(buffer);
	sound.setVolume(10.f);
	if (!startBuffer.loadFromFile("audio/startsound.wav"))
	{
		std::cout << "ERROR::NOT SUCH FILE" << "\n";
	}
	startSound.setBuffer(startBuffer);
	startSound.setVolume(8.f);
	startSound.play();
}

Game::Game()
{

}

Game::~Game()
{
	
}

void Game::caculatePoint()
{
	if (ball.sprite.getGlobalBounds().top + ball.sprite.getGlobalBounds().height >= this->window->getSize().y)
	{
		if (ball.sprite.getGlobalBounds().left + ball.sprite.getGlobalBounds().width >= net.getGlobalBounds().left + net.getGlobalBounds().width)
		{
			point++;
			ball.direct = false;
		}
		else
		{
			point2++;
			ball.direct = true;
		}
		if ((point + point2) % 3 == 0)
			sound.play();
		ballPosition();
		Sleep(900);
	}
}

void Game::collision()
{
	if (ball.sprite.getGlobalBounds().top + ball.sprite.getGlobalBounds().height >= player.sprite.getGlobalBounds().top
		&& ball.sprite.getGlobalBounds().top + ball.sprite.getGlobalBounds().height * 3 / 4 <= player.sprite.getGlobalBounds().top
		&& ball.speedy > 0)
	{
		if (ball.sprite.getGlobalBounds().left <= player.sprite.getGlobalBounds().left + player.sprite.getGlobalBounds().width
			&& ball.sprite.getGlobalBounds().left > player.sprite.getGlobalBounds().left - ball.sprite.getGlobalBounds().width)
		{
			ball.speedy *= -1;
		}
	}

	else if (ball.sprite.getGlobalBounds().left <= player.sprite.getGlobalBounds().left + player.sprite.getGlobalBounds().width
		&& ball.sprite.getGlobalBounds().left >= player.sprite.getGlobalBounds().left - ball.sprite.getGlobalBounds().width)
	{
		if (ball.sprite.getGlobalBounds().top + ball.sprite.getGlobalBounds().height >= player.sprite.getGlobalBounds().top)
		{
			if (ball.speedy > 0)
				ball.speedy *= -1;
			float y = ball.sprite.getPosition().y;
			if (ball.speedx > 0)
				ball.sprite.setPosition(player.sprite.getGlobalBounds().left - ball.sprite.getGlobalBounds().width, y + ball.speedy / 2);
			if (ball.speedx < 0)
				ball.sprite.setPosition(player.sprite.getGlobalBounds().left + player.sprite.getGlobalBounds().width + ball.sprite.getGlobalBounds().width, y + ball.speedy / 2);
			ball.speedx *= -1;
		}
	}

	if (ball.sprite.getGlobalBounds().top + ball.sprite.getGlobalBounds().height >= player2.sprite.getGlobalBounds().top
		&& ball.sprite.getGlobalBounds().top + ball.sprite.getGlobalBounds().height * 3 / 4 <= player2.sprite.getGlobalBounds().top
		&& ball.speedy > 0)
	{
		if (ball.sprite.getGlobalBounds().left < player2.sprite.getGlobalBounds().left + player2.sprite.getGlobalBounds().width
			&& ball.sprite.getGlobalBounds().left > player2.sprite.getGlobalBounds().left - ball.sprite.getGlobalBounds().width)
		{
			ball.speedy *= -1;
		}
	}
	else if (ball.sprite.getGlobalBounds().left <= player2.sprite.getGlobalBounds().left + player2.sprite.getGlobalBounds().width
		&& ball.sprite.getGlobalBounds().left >= player2.sprite.getGlobalBounds().left - ball.sprite.getGlobalBounds().width)
	{
		if (ball.sprite.getGlobalBounds().top + ball.sprite.getGlobalBounds().height >= player2.sprite.getGlobalBounds().top)
		{
			if (ball.speedy > 0)
				ball.speedy *= -1;
			float y = ball.sprite.getPosition().y;
			if (ball.speedx > 0)
				ball.sprite.setPosition(player2.sprite.getGlobalBounds().left - ball.sprite.getGlobalBounds().width, y + ball.speedy / 2);
			if (ball.speedx < 0)
				ball.sprite.setPosition(player2.sprite.getGlobalBounds().left + player2.sprite.getGlobalBounds().width + ball.sprite.getGlobalBounds().width, y + ball.speedy / 2);
			ball.speedx *= -1;
		}
	}
}

void Game::netCollision()
{
	if (ball.sprite.getGlobalBounds().left + ball.sprite.getGlobalBounds().width < net.getGlobalBounds().left + net.getGlobalBounds().width / 2
		&& ball.sprite.getGlobalBounds().left > net.getGlobalBounds().left - net.getGlobalBounds().width / 2
		&& ball.sprite.getGlobalBounds().top > net.getGlobalBounds().top)
	{
		ball.speedx *= -1;
		//float y = ball.sprite.getGlobalBounds().top;
		//ball.sprite.setPosition(net.getGlobalBounds().left + net.getGlobalBounds().width + ball.speedx,y);
	}
	else if (ball.sprite.getGlobalBounds().left + ball.sprite.getGlobalBounds().width > net.getGlobalBounds().left + net.getGlobalBounds().width / 2
		&& ball.sprite.getGlobalBounds().left + ball.sprite.getGlobalBounds().width < net.getGlobalBounds().left + net.getGlobalBounds().width * 3/2
		&& ball.sprite.getGlobalBounds().top > net.getGlobalBounds().top)
	{
		ball.speedx *= -1;
		//float y = ball.sprite.getGlobalBounds().top;
		//ball.sprite.setPosition(net.getGlobalBounds().left - ball.sprite.getGlobalBounds().width + ball.speedx, y);
	}
	if (ball.sprite.getGlobalBounds().left == net.getGlobalBounds().left
		&& ball.sprite.getGlobalBounds().top + ball.sprite.getGlobalBounds().height >= net.getGlobalBounds().top)
	{
		ball.speedy *= -1;
		//float x = ball.sprite.getGlobalBounds().left;
		//ball.sprite.setPosition(x, net.getGlobalBounds().top - ball.sprite.getGlobalBounds().height);
	}
	if (player.sprite.getGlobalBounds().left + player.sprite.getGlobalBounds().width > net.getGlobalBounds().left - 50)
	{
		float y = player.sprite.getPosition().y;
		player.sprite.setPosition(net.getGlobalBounds().left - player.sprite.getGlobalBounds().width - 50, y);
	}
	if (player2.sprite.getGlobalBounds().left <= net.getGlobalBounds().left + net.getGlobalBounds().width + 50)
	{
		float y = player2.sprite.getPosition().y;
		player2.sprite.setPosition(net.getGlobalBounds().left + net.getGlobalBounds().width + 50, y);
	}
}

void Game::playerPosition()
{
	player.initPosition(this->window);
}

void Game::player2Position()
{
	player2.initPosition(this->window);
}

void Game::ballPosition()
{
	ball.initPosition(this->window);
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}

void Game::renderBackground()
{
	this->window->draw(background);
}

void Game::update()
{
	this->pollEvents();
	player.update(this->window);
	player.windowBoundCollision(this->window);
	player2.update(this->window);
	player2.windowBoundCollision(this->window);
	this->collision();
	ball.update();
	caculatePoint();
	ball.windowBoundCollision(this->window);
	this->netCollision();
	this->updateText();
}

void Game::updateText()
{
	std::stringstream ss;
	if(point < 10)
		ss << "\n    " << point <<"\t\t\t\t\t\t   :\t\t\t\t\t\t " << point2;
	else
		ss << "\n   " << point << "\t\t\t\t\t\t   :\t\t\t\t\t\t" << point2;
	text.setString(ss.str());
}

bool Game::timer(float remainSecond)
{
	if (remainSecond <= 0)
		return false;
	int minute = 0;
	int second = remainSecond;
	while (second >= 60)
	{
		second -= 60;
		minute++;
	}
	second = remainSecond - minute * 60;
	std::stringstream ss;
	if(second >= 10)
		ss << "\t\t\t\t\t\t\t0" << minute << " : " << second;
	else
		ss << "\t\t\t\t\t\t\t0" << minute << " : 0" << second;
	time.setString(ss.str());

	return true;
}

void Game::renderText()
{
	
	this->window->draw(time);
	this->window->draw(text);
}

void Game::render()
{
	this->renderBackground();
	this->window->draw(net);
	player.render(this->window);
	player2.render(this->window);
	ball.render(this->window);
	this->renderText();
}

int Game::getPoint()
{
	return point;
}
int Game::getPoint2()
{
	return point2;
}

int Game::run(sf::RenderWindow& App)
{
	sf::Event event;
	this->point = 0;
	this->point2 = 0;
	this->initTexture();
	this->initSprite();
	this->initFont();
	this->initText();
	this->initSound();
	//game.initMusic();

	this->playerPosition();
	this->player2Position();
	this->ballPosition();

	Button esc;
	esc.window = this->window;
	esc.setTexture("image/esc.jfif");
	esc.setPosition(10.f, 10.f);
	esc.setScale(0.4, 0.4);

	std::clock_t initSecond = clock();
	while (this->window->isOpen())
	{
		while (this->window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return -1;
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape :
					return ScreenType::menu;
				default:
					break;
				}
			}
		}
		if (esc.onClick(event))
		{
			return ScreenType::menu;
		}
		if (point == 15)
			return ScreenType::after;
		else if (point2 == 15)
			return ScreenType::after;

		std::clock_t second = 360 - (clock() - initSecond) / CLOCKS_PER_SEC;
		if (!this->timer(second))
			return ScreenType::after;
		
		this->update();
		this->window->clear();
		this->render();
		esc.show();
		this->window->display();
	}

	return ScreenType::menu;
}
