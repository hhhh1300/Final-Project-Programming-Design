#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
using namespace std;

class MyWindow {
private:
	sf::RenderWindow *window;
	sf::Event event;
	sf::VideoMode vm;
	sf::RectangleShape button[4];
	sf::Text messenge[4];
	int messengeCnt;
	int buttonCnt;
public:
	MyWindow();
	void createWindow(int height, int width, string windowName);
	bool isWindowOpen();
	void createButton(float x, float y, string text);
	void MyWindow_draw();
	void MyWindow_clear();
	void MyWindow_display();
};

MyWindow::MyWindow()
{
	this->window = nullptr;
	buttonCnt = 0;
	messengeCnt;
}

void MyWindow::createWindow(int height, int width, string windowName)
{
	this->vm.width = width;
	this->vm.height = height;
	this->window = new sf::RenderWindow(vm, windowName, sf::Style::Close | sf::Style::Titlebar);
}

bool MyWindow::isWindowOpen()
{
	if ((* this->window).isOpen())
		return true;
	else
		return false;
}

void MyWindow::createButton(float x, float y, string text)
{
	sf::Font font;
	font.loadFromFile("Lato-Black.ttf");
	this->messenge[messengeCnt].setFont(font);
	this->messenge[messengeCnt].setString(text);
	this->messenge[messengeCnt].setPosition(sf::Vector2f(x, y));
	this->button[buttonCnt].setPosition(sf::Vector2f(x, y));
	this->button[buttonCnt].setSize(sf::Vector2f(100.f, 200.f));
	this->buttonCnt++;
	this->messengeCnt++;
}

void MyWindow::MyWindow_draw()
{
	for(int i = 0; i < messengeCnt; i++)
		this->window->draw(messenge[i]);
}
void MyWindow::MyWindow_clear()
{
	this->window->clear();
}
void MyWindow::MyWindow_display()
{
	this->window->display();
}