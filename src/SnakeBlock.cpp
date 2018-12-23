#include "SnakeBlock.h"

SnakeBlock::SnakeBlock()
{



}

SnakeBlock::SnakeBlock(float x,float y,sf::Texture* asset)
{
    //ctor
    this->x = x;
    this->y = y;
    upd = 0;
    rot = 0;

    printf("%f %f\n",this->x,this->y);
    sprite.setOrigin(16,16);

    prev = NULL;
    next = NULL;

    for(int i=0;i<4;i++){
        dir[i] = false;
    }

    dir[0] = true;
    change = false;
    where = 0;
    this->asset = asset;
    sprite.setTexture(asset[1]);
}

SnakeBlock::~SnakeBlock()
{
    //dtor
}


void SnakeBlock::render(sf::RenderWindow *window)
{
    sf::Transform t,t2;
    //printf("%d\n",nRotate());

    t.translate(x,y);

    t.rotate(rot*90);

    window->draw(sprite,t);
}


void SnakeBlock::setDir(int val)
{

    if(abs(val-where) == 2)
        return;

    if(val != where && !change){

        for(int i=0;i<4;i++){

            if(val == i){
                dir[i] = true;
                continue;
            }
            dir[i] = false;
        }

        where = val;

        change = true;
    }



}

void SnakeBlock::update(sf::Time elapsed)
{
    int pos = 0;

    upd += elapsed.asSeconds();

    if(upd >= 0.5){
        upd = 0;

        for(int i=0;i<4;i++){
            if(dir[i]){
                pos = i;
                break;
            }
        }

        if(next != NULL && prev != NULL){
            if(prev->dir[pos] != dir[pos]){
                sprite.setTexture(asset[5]);
                rot = nRotate();
            }
            else{
                sprite.setTexture(asset[1]);
                if(pos == 0 || pos == 2)
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


        switch(pos){

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

}

int SnakeBlock::metodoLanciani()
{
    int vet[4] = {2,3,0,1};

    if(next == NULL)
        return vet[prev->where];

    return vet[where];
}


int SnakeBlock::nRotate()
{

    if(prev != NULL && next != NULL){

        //DX DOWN SX UP
       if((prev->dir[3] && next->dir[2]) || (prev->dir[0] && next->dir[1])){
            return 1;
        }

        else if((prev->dir[2] && next->dir[1]) || (prev->dir[3] && next->dir[0])){
            return 0;
        }

        else if((prev->dir[0] && next->dir[3]) || (prev->dir[1] && next->dir[2])){
            return 2;
        }

        else if((prev->dir[1] && next->dir[0]) || (prev->dir[2] && next->dir[3])){
            return 3;
        }
    }

    return 0;
}
