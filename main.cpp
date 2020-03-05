#include"Game.h"
#include<iostream>
int main()
{
    std::cout << "Enter player:(1/2):  ";
    int Player;
    std::cin >> Player;
    std::cout << "Enter other player's ip address: ";
    std::string ipaddress;
    std::cin >> ipaddress;
	Game game(800,600,ipaddress,Player==1);
	game.running();
	return 0;
}