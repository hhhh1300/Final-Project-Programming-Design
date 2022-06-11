#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include "Screen.h"
using namespace std;
class Menu : public Screen 
{
private :

public :
	Menu() {}
	int run(sf::RenderWindow &App);
};

