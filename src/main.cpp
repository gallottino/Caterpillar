#include <SFML/Graphics.hpp>
#include <SnakeBlock.h>
#include <vector>
#include <iostream>

#define OFFSET 64


using namespace std;

sf::Texture asset[6];
sf::Sprite sprite[6];

int tri=0;


void generateSnakeBody();
std::vector<SnakeBlock*> snake;

float up = 0;

int main()
{

    int n_text = 0;
    sf::Sprite terrain,apple;

    sf::Transform applePos;
    applePos.translate(64,32);


    sf::RenderWindow window(sf::VideoMode(32*24, 32*24), "Caterpillar");
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


    snake.push_back(new SnakeBlock(32*6+OFFSET,32+OFFSET,&asset[0]));
    snake[0]->setDir(0);

    for(int i=0;i<2;i++)
        generateSnakeBody();


    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        sf::Event event;
        up += elapsed.asSeconds();
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
            if(up >= 0.1){
                snake[i]->update(elapsed);
            }
            snake[i]->render(&window);
        }

        if(up >= 0.1) up = 0;

        window.draw(apple,applePos);
        window.display();
        tri++;
        if(tri>=1000){
            generateSnakeBody();
            tri = 0;
        }
    }

    return 0;
}

void generateSnakeBody()
{
    //DX,DOWN,SX UP
    int magicMatrix[4][2] = {
                                {-1,0},
                                {0,-1},
                                {1,0},
                                {0,1},
                            };
    SnakeBlock* tail = snake[snake.size()-1];
    int dir = tail->getDir();


    SnakeBlock* body = new SnakeBlock(tail->Getx()+(32)*magicMatrix[dir][0],
                                      tail->Gety()+(32)*magicMatrix[dir][1],
                                      &asset[0]);

    body->setTexture(asset[2]);
    body->setDir(dir);
    tail->setNext(body);
    body->setPrev(tail);

    snake.push_back(body);
}

