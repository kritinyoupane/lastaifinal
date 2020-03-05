
#pragma once
#include <thread>
//#include "Global.h"
#include "test.h"
#include <SFML/Network.hpp>

class Client {

public:
    Client();
    Client(const sf::IpAddress& ip, unsigned short port);
    void connection(const sf::IpAddress& ip, unsigned short port);
    test recieveData();
    bool isConnected() { return m_connected; }
    virtual ~Client();
    const test& getRecievedData() const;
    const std::string& getName() const;

private:
    sf::TcpSocket socket;
    bool m_connected;
    bool connected2;
    std::string Name;
    test recievedData;
    std::thread Threadu;
};
