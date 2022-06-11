#include "AfterGame.h"

int AfterGame::run(sf::RenderWindow& App)
{
	sf::Texture background;
	sf::Sprite sBackground;
	if (!background.loadFromFile("image/celebratesPink.png"))
		return -1;
	sBackground.setTexture(background);
	sBackground.setPosition(sf::Vector2f(0.f, 0.f));
	sBackground.setScale(sf::Vector2f(1.f, 1.f));

	sf::Event e;
	Button cont, leave;
	cont.window = &App;
	leave.window = &App;
	cont.setTexture("image/buttonOfBack.png");
	leave.setTexture("image/buttonOfGameOver.png");
	cont.setPosition(App.getSize().x / 2 - 300.f, App.getSize().y / 2 + 50);
	leave.setPosition(App.getSize().x / 2 + 100.f, App.getSize().y / 2 + 50);
	cont.setScale(0.2f, 0.2f);
	leave.setScale(0.2f, 0.2f);

	sf::Font font;
	if (!font.loadFromFile("font/NotoSansCJKtc-Black.otf"))
		return -1;

	while (App.isOpen())
	{
		sf::Text t;
		t.setFont(font);
		t.setScale(2.0, 2.0);
		t.setFillColor(sf::Color::Blue);
		t.setPosition(App.getSize().x / 2 - 350.f, App.getSize().y / 2 - 50);
		if (point == 15 || point > point2)
		{
			t.setString("Congratulation to Player 1 !");
		}
		else if (point2 == 15 || point2 > point)
		{
			t.setString("Congratulation to Player 2 !");
		}
		else if (point == point2)
		{
			t.setString("\t\t\t\t\t\tDraw !");
		}
		while (App.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				return -1;
			}

			if (e.type == sf::Event::KeyPressed)
			{
				switch (e.key.code)
				{
				case sf::Keyboard::Escape:
					return ScreenType::menu;
				default:
					break;
				}
			}

			if (cont.onClick(e))
			{
				return ScreenType::menu;
			}
			if (leave.onClick(e))
			{
				return -1;
			}
		}

		App.clear();

		App.draw(sBackground);
		App.draw(t);
		cont.show();
		leave.show();

		App.display();
	}
}