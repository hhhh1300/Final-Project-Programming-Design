#include "Guide.h"

int Guide::run(sf::RenderWindow& App)
{
	sf::Event event;

	//setting background
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

	//setting messenges
	sf::Font font;
	if (!font.loadFromFile("font/NotoSansCJKtc-Black.otf"))
		return -1;
	sf::Text pres;
	pres.setFont(font);
	pres.setString("For player1 (on the left), use W, A, S, D to control the movement of\nthe left icon. For player2 (on the right), use arrow keys (Up, Right,\nLeft, Down) to control the movement of the right icon. If you are \nplayer1, use F to spike, as for player2, use 1 to spike. Game duration\nis 5 minutes, the one who scores 15 early wins!!If nobody gets 15,\nthe one scores more wins.");
	pres.setPosition(sf::Vector2f(150.f, 150.f));
	pres.setScale(sf::Vector2f(1.f, 1.f));
	pres.setFillColor(sf::Color::Black);

	while (App.isOpen())
	{
		while (App.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return -1;
			}
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
			if (esc.onClick(event))
			{
				return ScreenType::menu;
			}
		}

		App.clear();

		App.draw(sBackground);
		esc.show();
		App.draw(pres);

		App.display();
	}


}