#include <SFML/Graphics.hpp>
#include <SnakeBlock.h>
#include <vector>
#include <iostream>

#define OFFSET 64


using namespace std;

sf::Texture asset[6];
sf::Sprite sprite[6];

int n = 3;


SnakeBlock* generateSnakeBody();
std::vector<SnakeBlock*> snake;

int main()
{

    int n_text = 0;
    sf::Sprite terrain,apple;

    sf::Transform applePos;
    applePos.translate(64,64);


    sf::RenderWindow window(sf::VideoMode(32*24, 32*24), "SFML works!");
    sf::Clock clock;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            if(!asset[n_text].loadFromFile("snake-asset.png",sf::IntRect((j)*32, (i)*32, 32, 32))){

            }
            else{
                sprite[n_text].setTexture(asset[n_text]);
                n_text++;
            }
        }
    }

    terrain.setTexture(asset[0]);
    apple.setTexture(asset[3]);
    apple.setOrigin(16,16);


    snake.push_back(new SnakeBlock(96+OFFSET,32+OFFSET,&asset[0]));
    snake.push_back(new SnakeBlock(64+OFFSET,32+OFFSET,&asset[0]));
    snake.push_back(new SnakeBlock(32+OFFSET,32+OFFSET,&asset[0]));
    snake.push_back(new SnakeBlock(0+OFFSET,32+OFFSET,&asset[0]));
    snake[0]->setNext(snake[1]);
    snake[1]->setPrev(snake[0]);
    snake[1]->setNext(snake[2]);
    snake[2]->setPrev(snake[1]);
    snake[2]->setNext(snake[3]);
    snake[3]->setPrev(snake[2]);

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                // DIR{DX,DOWN,SX,UP}
                snake[0]->setDir(1);

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                // DIR{DX,DOWN,SX,UP}
                snake[0]->setDir(3);

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                // DIR{DX,DOWN,SX,UP}
                snake[0]->setDir(2);

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                // DIR{DX,DOWN,SX,UP}
                snake[0]->setDir(0);
        }

        window.clear();

        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                sf::Transform t;
                t.translate(i*32+OFFSET,j*32+OFFSET);
                window.draw(terrain,t);
            }
        }

        for(int i = snake.size()-1;i>=0;i--){
            snake[i]->update(elapsed);
            snake[i]->render(&window);
        }

        window.draw(apple,applePos);
        window.display();
    }

    return 0;
}

SnakeBlock* generateSnakeBody()
{
    SnakeBlock* tail = snake[n-1];
    SnakeBlock* body = new SnakeBlock(0,0,&asset[0]);

    body->setTexture(asset[1]);

    return body;
}
