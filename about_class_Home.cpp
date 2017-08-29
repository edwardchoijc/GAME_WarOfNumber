#include "const_Value.h"
#include "about_Draw.h"
#include "about_class.h"
#include "about_operation.h"
#include "about_character.h"

using namespace std;


Home::Home(unsigned short x,unsigned short y)
{
    home_pos.X=x;
    home_pos.Y=y;
    if(y==HOME_COMPUTER_POS_Y&&x==HOME_COMPUTER_POS_X)
        player_or_computer=COMPUTER;
    else
    if(y==HOME_PLAYER_POS_Y&&x==HOME_PLAYER_POS_X)
        player_or_computer=PLAYER;
    else
        player_or_computer=PLAYER;

    home_durable=HOME_DURABLE;
}

Home::~Home()
{

}

void Home::Be_Hurted(unsigned short card_damage)
{
    home_durable=home_durable-card_damage;
}

