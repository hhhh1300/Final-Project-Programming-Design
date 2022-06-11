#include "Setting.h"

float Setting::getVolume()
{
	return this->volume;
}

int Setting::run(sf::RenderWindow& App)
{
	sf::Event event;
	bool running = true; 
	
	sf::Font font;
	if (!font.loadFromFile("font/NotoSansCJKtc-Black.otf"))
		return -1;
	sf::Text text;
	std::string str;
	
	char buffer[10] = { 0 };
	int v = volume;
	itoa(v, buffer, 10);
	str.append(buffer);
	text.setFont(font);

	text.setFillColor(sf::Color::Blue);
	text.setScale(2.f, 2.f);
	text.setPosition(600.f, 225.f);

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

	Button plus;
	plus.window = &App;
	plus.setTexture("image/squareButtonPlus.png");
	plus.setPosition(800.f, 200.f);
	plus.setScale(0.5, 0.5);

	Button minus;
	minus.window = &App;
	minus.setTexture("image/squareButtonMinus.jpg");
	minus.setPosition(300.f, 200.f);
	minus.setScale(0.5, 0.5);

	while (App.isOpen())
	{
		while (App.pollEvent(event))
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
			if (esc.onClick(event))
			{
				return ScreenType::menu;
			}
			if (plus.onClick(event))
			{
				volume += 5;
				if (volume > 100)
					volume = 100;
				setVolume(volume);
				str.clear();
				char buffer[10] = { 0 };
				int v = volume;
				itoa(v, buffer, 10);
				str.append(buffer);
			}
			if (minus.onClick(event))
			{
				volume -= 5;
				if (volume < 0)
					volume = 0;
				setVolume(volume);
				str.clear();
				char buffer[10] = { 0 };
				int v = volume;
				itoa(v, buffer, 10);
				str.append(buffer);
			}
		}
		text.setString(str);

		App.clear();

		App.draw(sBackground);
		esc.show(); 
		plus.show();
		minus.show();
		App.draw(text);

		App.display();
	}

	return -1;
}

