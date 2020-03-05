#include<SFML/Network.hpp>
#include<string>
#include"test.h"
#include<thread>
#include<mutex>

class Server
{
private:
	bool connected;
	sf::TcpListener listener;
	sf::SocketSelector selector;
	int noofplayers;
	bool dataWaiting;
	std::thread Threadu;
	sf::TcpSocket socket;
	sf::Packet pack;
	std::mutex Mutex;
public:
	Server();
	Server(unsigned short port);
	void listenPort(unsigned short port);
	void recieve();
	test convertPacketToinfo(sf::Packet packet);
	void update(char name,int score,sf::Vector2f position,int bulletcount);
	int getplayersConnected();


};

