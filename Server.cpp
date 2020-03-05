#include "Server.h"

 Server::Server(unsigned short port)
{
	connected = true;
	listenPort(port);
}

void Server::listenPort(unsigned short port)
{
	if (listener.listen(port) == sf::Socket::Done)
	{
		std::cout << "Server is all set to go:" << port << "Waiting for clients: \n";
		selector.add(listener);
		noofplayers = 0;
		dataWaiting = false;
		Threadu = std::thread(&Server::recieve, this);
		Threadu.detach();
	}

	else
	{
		listenPort(++port);

	}
}

void Server::recieve()
{
	while (connected) {
		while (noofplayers == 0) {
			if (listener.accept(this->socket) == sf::Socket::Done) {
				++noofplayers;
				std::cout << "Client is connected" << std::endl;
			}
		}
		if (this->dataWaiting) {
			std::cout << "Sending data" << std::endl;
			if (socket.send(this->pack) != sf::Socket::Done)
				std::cout << "Error occured" << std::endl;
			Mutex.lock();
			this->dataWaiting = false;
			Mutex.unlock();

		}
		
	}
}

test Server::convertPacketToinfo(sf::Packet packet)
{
	test player;
	char h=player.getName();
	packet<< &h<< player.getScore() << player.getPosition().x
		<< player.getPosition().y << player.getBulletcount();
	return player;
}

void Server::update(char name, int score, sf::Vector2f position, int bulletcount)
{
	sf::Packet keyPress;
	keyPress << name << score << position.x << position.y << bulletcount;
	test c1 = convertPacketToinfo(keyPress);
	test c2 = convertPacketToinfo(this->pack);
	if (score ==0)
	{
		this->pack = keyPress;
		Mutex.lock();
		this->dataWaiting = true;
		Mutex.unlock();

	}
}

int Server::getplayersConnected()
{
	return noofplayers;
}

