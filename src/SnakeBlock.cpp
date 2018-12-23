#include "SnakeBlock.h"

SnakeBlock::SnakeBlock()
{


}

SnakeBlock::SnakeBlock(float x,float y,sf::Texture* asset)
{
    this->x = x;
    this->y = y;
    this->rot = 0;
    this->asset = asset;
    this->change = false;
    this->where = -5;

    prev = NULL;
    next = NULL;

    sprite.setOrigin(16,16);
    sprite.setTexture(asset[1]);
}

SnakeBlock::~SnakeBlock()
{
    //dtor
}


void SnakeBlock::render(sf::RenderWindow *window)
{
    sf::Transform t,t2;
    t.translate(x,y);
    t.rotate(rot*90);

    window->draw(sprite,t);
}


void SnakeBlock::setDir(int val)
{
    if(abs(val-where) == 2)
        return;

    if(val != where && !change){
        where = val;
        change = true;
    }
}

void SnakeBlock::update(sf::Time elapsed)
{
    /*SETTING TEXTURES */
    if(next != NULL && prev != NULL){
        if(prev->where != where){
            sprite.setTexture(asset[5]);
            rot = metodoLanciani();
        }
        else{
            sprite.setTexture(asset[1]);
            if(where == 0 || where == 2)
                rot = 0;
            else
                rot = 1;
        }

    }

    else{
        if(next == NULL)
            sprite.setTexture(asset[2]);
        else
            sprite.setTexture(asset[4]);

        rot = metodoLanciani();
    }

    /*MOVE SNAKE*/
    switch(where){

    //DX
    case 0:
        moveSnake(32,0);
        break;
    //DOWN
    case 1:
        moveSnake(0,32);
        break;
    //SX
    case 2:
        moveSnake(-32,0);
        break;
    //UP
    case 3:
        moveSnake(0,-32);
        break;

    }


    if(prev != NULL)
        setDir(prev->where);

    change = false;
}

int SnakeBlock::metodoLanciani()
{
    int magicMatrix[4][4] = {
                                {1,1,0,2},
                                {3,2,2,0},
                                {0,0,3,3},
                                {0,0,1,0}
                            };
    /*TAIL*/
    if(next == NULL)
        return magicMatrix[prev->where][prev->where];

    /*HEAD*/
    if(prev == NULL)
        return magicMatrix[where][where];

    return magicMatrix[prev->where][next->where];
}
