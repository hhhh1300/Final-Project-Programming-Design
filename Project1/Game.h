#pragma once
#include "Screen.h"
#include "Player.h"
#include "Player2.h"
#include "Ball.h"
#include "Button.h"
#include<sstream>

class Game : public Screen
{
protected:
	
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videomode;
	sf::Texture backgroundTex, netTex;
	sf::Sprite background, net;
	sf::SoundBuffer buffer, startBuffer;
	sf::Sound sound, startSound;

	unsigned int point,point2;
	sf::Font font;
	sf::Text text;
	sf::Text time;
	sf::Music music;
	Player player;
	Player2 player2;
	Ball ball;

	

	void initTexture();
	void initSprite();
	void initFont();
	void initText();
	void initMusic();
	void initSound();
public:
	Game();
	~Game();

	void initVariables();
	void initWindow(sf::RenderWindow &App);
	void caculatePoint();
	void collision();
	void netCollision();
	void playerPosition();
	void player2Position();
	void ballPosition();
	const bool running() const;
	void pollEvents();
	void renderBackground();
	void update();
	void updateText();
	void renderText();
	void render();
	int getPoint();
	int getPoint2();

	bool timer(float remainSecond);
	int run(sf::RenderWindow& App);
};
