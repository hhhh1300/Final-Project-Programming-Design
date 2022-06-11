#include "Screen.h"

bool Screen::setMusic(std::string str, float volume)
{
	if (!this->music.openFromFile(str))
		return false;
	this->music.setVolume(volume);
	return true;
}

void Screen::playMusic(sf::RenderWindow& App)
{
	this->music.setLoop(true);
	this->music.play();
}

void Screen::stopMusic(sf::RenderWindow& App)
{
	this->music.stop();
}

void Screen::setVolume(float volume)
{
	this->music.setVolume(volume);
}

float Screen::getVolume()
{
	return defaultVolume;
}