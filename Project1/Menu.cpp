#include "Menu.h"
#include "Button.h"
#define buttonWidth 1280
#define buttonHeight 640
int Menu::run(sf::RenderWindow &App)
{
	sf::Event event;
	bool running = true;
	//settting buttons
	Button bStartGame;
	Button bLeaveGame;
	Button bGuide;
	Button bMembers;
	Button bSetting;
	bStartGame.window = &App;
	bLeaveGame.window = &App;
	bGuide.window = &App;
	bMembers.window = &App;
	bSetting.window = &App;


	//the size of buttons following is 1280 X 640(256 X 128)
	float xPos = 1280 / 2 - buttonWidth * 0.2 / 2;
	float yPos = 720 / 6;
	bStartGame.setTexture("image/buttonOfStartGame.png");
	bStartGame.setScale(0.2, 0.2);
	bStartGame.setPosition(xPos, yPos - buttonHeight * 0.2 / 2);

	bGuide.setTexture("image/buttonOfGuide.png");
	bGuide.setScale(0.2, 0.2);
	bGuide.setPosition(xPos, yPos * 2 - buttonHeight * 0.2 / 2);

	bMembers.setTexture("image/buttonOfMembers.png");
	bMembers.setScale(0.2, 0.2);
	bMembers.setPosition(xPos, yPos * 3 - buttonHeight * 0.2 / 2);

	bSetting.setTexture("image/buttonOfSetting.png");
	bSetting.setScale(0.2, 0.2);
	bSetting.setPosition(xPos, yPos * 4 - buttonHeight * 0.2 / 2);

	bLeaveGame.setTexture("image/buttonOfGameOver.png");
	bLeaveGame.setScale(0.2, 0.2);
	bLeaveGame.setPosition(xPos, yPos * 5- buttonHeight * 0.2 / 2);

	//setting background
	sf::Texture background;
	sf::Sprite sBackground;
	if (!background.loadFromFile("image/background.jpg"))
		return -1;
	sBackground.setTexture(background);
	sBackground.setPosition(sf::Vector2f(0.f, 0.f));
	sBackground.setScale(sf::Vector2f(1.f, 1.f));

	while (running)
	{
		while (App.pollEvent(event))
		{
			//click the X
			if (event.type == sf::Event::Closed)
			{
				return -1;
			}

			//press keyboard
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape :
					return -1;
				default:
					break;
				}
			}


			//press buttons
			if (bStartGame.onClick(event))
			{
				return ScreenType::game;
			}
			if (bLeaveGame.onClick(event))
			{
				return -1;
			}
			if (bGuide.onClick(event))
			{
				return ScreenType::guide;
			}
			if (bMembers.onClick(event))
			{
				return ScreenType::members;
			}
			if (bSetting.onClick(event))
			{
				return ScreenType::setting;
			}
		}

		//display
		App.clear();

		App.draw(sBackground);

		bStartGame.show();
		bLeaveGame.show();
		bGuide.show();
		bMembers.show();
		bSetting.show();

		App.display();
	}
	return -1;
}