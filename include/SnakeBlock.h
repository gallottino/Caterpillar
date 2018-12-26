#ifndef SNAKEBLOCK_H
#define SNAKEBLOCK_H

#include <SFML/Graphics.hpp>


class SnakeBlock
{
    public:
        SnakeBlock();
        SnakeBlock(float x,float y,sf::Texture* asset);
        ~SnakeBlock();

        float Getx() { return x; }
        void Setx(int val) { x = val; }
        float Gety() { return y; }
        void Sety(int val) { y = val; }
        void setDir(int val);
        int getDir(){return where;}
        void moveSnake(float x,float y){
            this->x += x;
            this->y += y;
        }
        void setTexture(sf::Texture text){texture = text; sprite.setTexture(texture);}
        void render(sf::RenderWindow *window);
        void update(sf::Time elapsed);

        SnakeBlock *next,*prev;

        void setNext(SnakeBlock* block){next = block;}
        void setPrev(SnakeBlock* block){prev = block;}
        void chooseTexture();

    private:

        int nRotate();
        int metodoLanciani();


        float x;
        float y;
        int rot;
        int where;
        bool change;
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Texture* asset;
};

#endif // SNAKEBLOCK_H
