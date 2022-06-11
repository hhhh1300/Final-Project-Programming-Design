#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#define defaultVolume 20
enum ScreenType {
	menu, members, guide, setting, game, after
};
class Screen
{
private :
	sf::Music music;
public :
	bool setMusic(std::string str, float volume);
	void setVolume(float volume);
	void playMusic(sf::RenderWindow& App);
	void stopMusic(sf::RenderWindow& App);
	virtual float getVolume();
	virtual int run(sf::RenderWindow &App) = 0;
};

