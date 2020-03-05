
#include <iostream>
#include "Client.h"

Client::Client(const sf::IpAddress& ip, unsigned short port) :recievedData()
{
    m_connected = false;
    connected2 = true;
    //connection(ip,port);
    Threadu = std::thread(&Client::connection, this, ip, port);
    Threadu.detach();
}

  Client::~Client() {
    connected2 = false;
    //m_socket.disconnect();
}

void Client::connection(const sf::IpAddress& ip, unsigned short port)
{
    unsigned short initPort = port;
    while (!m_connected) {
        static int checkLoop = 0;
        if (socket.connect(ip, port, sf::seconds(150)) != sf::Socket::Done)
        {
            if (checkLoop < 2) {
                std::cout << "Error connecting to port " << port << std::endl;
                port++;
                checkLoop++;
            }
            else
            {
                checkLoop = 0;
                port = initPort;
                std::cout << "Error connecting to server" << std::endl;
            }
        }
        else {
            m_connected = true;
            std::cout << "Connected to the server" << std::endl;
            //            sf::Packet NameP;
            //            m_socket.receive(NameP);
            //            m_mutex.lock();
            //            NameP>>Name;
            //            m_mutex.unlock();
        }
    }
    while (this->connected2 && m_connected) {
        this->recievedData = recieveData();
    }

}

const std::string& Client::getName() const {
    return Name;
}

const  test& Client::getRecievedData() const {
    return recievedData;
}

  test Client::recieveData() {
    socket.setBlocking(true);
    //    while(m_running2)
    //    {
    
    sf::Packet pack;

    if (socket.receive(pack) == sf::Socket::Done) {
        char h;
        int s,b;
        sf::Vector2f pos;
        pack >> &h >> s >>pos.x >>pos.y >>b;
        test c1(s, h, pos, b);
        //std::cout << moveX;
        return c1;
    }
    else
    {
        //std::cout << "No data recieved";
        test c1(0,' ',sf::Vector2f(0,0),0);
        return c1;
    }
    // }
}

