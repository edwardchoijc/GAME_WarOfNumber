#include "const_Value.h"
#include "about_class.h"
#include "about_operation.h"
#include "about_Draw.h"
#include "about_character.h"

using namespace std;

void Character_for_Card_1(Card_in_fight *temp_card)//add to move_action
{
    if(temp_card->Return_card_name()=='1'&&temp_card->Return_if_can_use()==true)
    {
        temp_card->counter_for_add_speed++;
        if(temp_card->counter_for_add_speed>=20)//20 control the time add speed
        {
            temp_card->Add_Card_Speed();
            temp_card->Use_Skill();
        }
    }
    else
        return;
}

void Character_for_Card_2(Card_in_fight *temp_card,bool up_or_down)//add to move_action
{
    if(temp_card->Return_card_name()=='2'&&temp_card->Return_if_can_use()==true)
    {
        if(up_or_down==TO_DOWN)
        {
            short a=temp_card->Return_card_pos_in_map().X;
            short b=temp_card->Return_card_pos_in_map().Y+WALL_HIGH;
            temp_card->Set_Card_Pos(a,b);
        }
        else
        {
            short a=temp_card->Return_card_pos_in_map().X;
            short b=temp_card->Return_card_pos_in_map().Y-WALL_HIGH;
            temp_card->Set_Card_Pos(a,b);
        }
        temp_card->Use_Skill();
    }
    else
        return;
}

bool Character_for_Card_3(Card_in_fight *temp_card)//add to attack_action
{
    if(temp_card->Return_card_name()=='3'&&temp_card->Return_if_can_use()==true)
    {
        if(temp_card->Return_player_or_computer()==PLAYER)
        {
            temp_card->Set_Card_Pos(PLAYER_FLASH_POS_X,PLAYER_FLASH_POS_Y);
        }
        else
        if(temp_card->Return_player_or_computer()==COMPUTER)
        {
            temp_card->Set_Card_Pos(COMPUTER_FLASH_POS_X,COMPUTER_FLASH_POS_Y);
        }

        temp_card->Use_Skill();
        return true;
    }
    else
        return false;
}

void Character_for_Card_4(Card_in_fight *temp_card,Card_in_fight *temp_card_2)//add to attack_action
{
    if(temp_card->Return_card_name()=='4'&&temp_card->Return_if_can_use()==true)
    {
        temp_card_2->if_can_move=false;
        temp_card_2->if_can_attack=false;
        temp_card->Use_Skill();
    }
    else
        return;
}

bool Character_for_Card_5(Card_in_fight *temp_card,Card card1)//add to attack_action
{
    if(temp_card->Return_card_name()=='5'&&temp_card->Return_if_can_use()==true)
    {
        *temp_card=card1;

        temp_card->Use_Skill();

        return true;
    }
    else
        return false;
}

void Character_for_Card_6(Card &temp_card,vector<Card> &cards)//add to Set_Card_in_Battlefield
{
    if(temp_card.Return_card_name()=='6')
    {
        int n=rand()%NUMBER_CARD;
        temp_card=cards[n];
        return;
    }
    else
        return;
}

void Character_for_Card_7(Card_in_fight temp_card)//add to move_action
{
    if(temp_card.Return_card_name()=='7'&&temp_card.Return_if_can_use()==true)
    {

        temp_card.Use_Skill();
    }
    else
        return;
}

bool Character_for_Card_8(Card_in_fight *temp_card,Card_in_fight *temp_card_2)//add to attack_action
{
    if(temp_card->Return_card_name()=='8'&&temp_card->Return_if_can_use()==true)
    {
        temp_card_2->Be_Bried();

        temp_card->Use_Skill();
        return true;
    }
    else
        return false;
}

bool Character_for_Card_9(Card_in_fight *temp_card,Card_in_fight *temp_card_2)//add to attack_action
/******************************
1.finish 9 character
2.finish react to user
3.finish view
******************************/
{
    if(temp_card->Return_card_name()=='9'&&temp_card->Return_if_can_use()==true)
    {
        temp_card_2->Be_Killed();

        temp_card->Use_Skill();
        return true;
    }
    else
        return false;
}
