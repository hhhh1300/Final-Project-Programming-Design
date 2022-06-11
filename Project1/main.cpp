#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include "Screen.h"
#include "Menu.h"
#include "Members.h"
#include "Guide.h"
#include "setting.h"
#include "Game.h"
#include "AfterGame.h"
using namespace std;

int main()
{
	//build a vector to store different scenes which we may use
	//screen is a variable which help us store screens's index
	std::vector<Screen*> screens;
	int screen = 0;

	//create the only window and scenes
	sf::RenderWindow App(sf::VideoMode(1280, 720), "Game", sf::Style::Close | sf::Style::Titlebar);
	App.setFramerateLimit(144);
	Menu menu;
	screens.push_back(&menu);
	Members mem;
	screens.push_back(&mem);
	Guide guide;
	screens.push_back(&guide); 
	Setting setting;
	screens.push_back(&setting);
	Game g;
	g.initVariables();
	g.initWindow(App);
	screens.push_back(&g);
	AfterGame af;


	//setting music
	bool isChange = false;
	int changeCnt = 0;
	string music[2] = { {"music/summer.ogg"} , {"audio/audio1.ogg"} };
	screens[ScreenType::setting]->setMusic(music[changeCnt % 2], screens[ScreenType::setting]->getVolume());
	screens[ScreenType::setting]->playMusic(App);

	//the loop stop when "run" return -1
	while (screen >= 0)
	{
		//The function "run" will return the page's index(the page we want to get into)
		//The function "run" is a virtual function which is inherited from every scene's mutual parent class "Screen"
		screen = screens[screen]->run(App);

		if (screen == ScreenType::game)
			isChange = true;
		
		if (screen == ScreenType::after)
		{
			af.point = g.getPoint();
			af.point2 = g.getPoint2();
			screen = af.run(App);
		}
		std::cout << screen << std::endl;

		if (isChange && (screen == ScreenType::game || screen == ScreenType::menu))
		{
			changeCnt++;
			screens[ScreenType::setting]->stopMusic(App);
			screens[ScreenType::setting]->setMusic(music[changeCnt % 2], screens[ScreenType::setting]->getVolume());
			screens[ScreenType::setting]->playMusic(App);
			if(screen == ScreenType::menu)
				isChange = false;
		}
	}
	 
	screens[ScreenType::setting]->stopMusic(App);
	return 0;
}