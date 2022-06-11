#include "Members.h"

void dele(std::vector<sf::Text*> &messenges)
{
	for (vector<sf::Text*>::iterator it_i = messenges.begin(); it_i != messenges.end(); it_i++)
		delete *it_i;
}

int Members::run(sf::RenderWindow& App)
{
	sf::Event event;
	bool running = true;
	
	//setting the messenge
	sf::Font font;
	if (!font.loadFromFile("font/NotoSansCJKtc-Black.otf"))
		return -1;
	std::vector<sf::Text*> messenges;
	for (int i = 0; i < 7; i++)
	{
		messenges.push_back(new sf::Text());
		messenges[i]->setFont(font);
		messenges[i]->setScale(sf::Vector2f(2.0f, 2.0f));
		messenges[i]->setPosition(sf::Vector2f(500.f, 100.f + 75 * i));
		messenges[i]->setFillColor(sf::Color::Blue);
	}
	messenges[0]->setString("Group list :");
	messenges[1]->setString("Yang Chung");
	messenges[2]->setString("Chen Yen Ting");
	messenges[3]->setString("Peng Chun Tao");
	messenges[4]->setString("Tsai Yu Chen");
	messenges[5]->setString("Kao I Ming");
	messenges[6]->setString("Yu You Zheng");

	//setting the background
	sf::Texture background;
	sf::Sprite sBackground;
	if (!background.loadFromFile("image/background.jpg"))
		return -1;
	sBackground.setTexture(background);
	sBackground.setPosition(sf::Vector2f(0.f, 0.f));
	sBackground.setScale(sf::Vector2f(1.f, 1.f));

	//setting buttons
	Button esc;
	esc.window = &App;
	esc.setTexture("image/esc.jfif");
	esc.setPosition(10.f, 10.f);
	esc.setScale(0.5, 0.5);

	while (App.isOpen())
	{
		while (App.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				dele(messenges);
				return -1;
			}
			
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape :
					dele(messenges);
					return ScreenType::menu;
				default:
					break;
				}
			}
			if (esc.onClick(event))
			{
				dele(messenges);
				return ScreenType::menu;
			}
		}

		App.clear();

		App.draw(sBackground);
		for(int i = 0; i < messenges.size(); i++)
			App.draw(*messenges[i]);
		esc.show();

		App.display();

	}
	dele(messenges);
	return -1;
}