#include "const_Value.h"
#include "about_class.h"
#include "about_operation.h"
#include "about_Draw.h"
#include "about_character.h"

using namespace std;

Selectarea::Selectarea()
{
    card_name_in_selectarea='0';
}

Selectarea::~Selectarea()
{

}

void Selectarea::Random_Get_Card(vector<Card> &card,Selectarea *select)
//random and no repeated get card
{

    unsigned short k=rand()%NUMBER_CARD;

    while(1)
    {
        for(unsigned short n=0;n<NUMBER_SELECT_CARD;n++)
        {
            if(card[k].Return_card_name()!=select[n].Return_card_name_in_selectarea())
                continue;
            else
            {
                if(k<NUMBER_CARD-1)
                {
                    k++;
                    goto END;
                }
                else
                {
                    k=0;
                    goto END;
                }
            }
        }
        card_name_in_selectarea=card[k].Return_card_name();
        break;
        END:;
    }
}

void Selectarea::Display_Selectarea(vector<Card> &card,unsigned order,HANDLE hOut)
{
    unsigned temp1=SELECTAREA_POS_X;
    unsigned temp2=SELECTAREA_POS_Y+SELECTAREA_HIGH*order;
    COORD pos={temp1,temp2};
    selectarea_pos=pos;
    SetConsoleCursorPosition(hOut,pos);

    Display_Card_in_Selectarea_Message(card,card_name_in_selectarea,hOut);
}

void Selectarea::Display_Card_in_Selectarea_Message(vector<Card> &card,char card_name_in_selectarea,HANDLE hOut)
{
    unsigned short n;
    for(n=0;n<NUMBER_CARD;n++)
    {
        if(card_name_in_selectarea==card[n].Return_card_name())
            break;
    }

    card[n].Display_Message_in_Select_Area(hOut);
}

/********************
1.check Statue
2.check card_in_fight
*******************/
Statue::Statue()
{
    pos_in_screen={STATUE_POS_X,STATUE_POS_Y};
}

Statue::~Statue()
{

}

void Statue::Set_date(bool get_player_or_computer)
{
    player_or_computer=get_player_or_computer;
    if(player_or_computer==PLAYER)
    {
        power_develop_speed=POWER_DEVELOP_SPEED_PLAYER;
        now_power=BEGIN_POWER_FOR_PLAYER;
    }
    else
    {
        power_develop_speed=POWER_DEVELOP_SPEED_COMPUTER;
        now_power=BEGIN_POWER_FOR_COMPUTER;
    }
}

bool Statue::Add_power()
{
    if(now_power<POWER_MAX)
    {
        now_power++;
        return true;
    }
    else
        return false;

}

bool Statue::Cost_power(unsigned short cost)
{
    if(cost<=now_power)
    {
        now_power=now_power-cost;
        return true;
    }
    else
        return false;
}

void Tiparea::Get_tip_type(int &k)
{
    tip_type=k;
    counter_tip_exist=0;
    k=0;
}

void Tiparea::Get_tip_pos(COORD pos)
{
    tip_pos.X=pos.X;
    tip_pos.Y=pos.Y;
}

void Tiparea::Display_Tip(HANDLE hOut)
{
    COORD pos={tip_pos.X,tip_pos.Y};
    SetConsoleCursorPosition(hOut,pos);
    switch (tip_type)
    {
        case 0:
            for(unsigned short n=0;n<TIP_AREA_HIGH;n++)
            {
                cout<<"                                ";
                pos.Y++;
                SetConsoleCursorPosition(hOut,pos);
            }
            break;
        case 1:
            cout<<"Number power is not enough.";
            break;
        case 2:
            cout<<"You will win soon if you insist!";
            break;
        case 3:

            break;
    }
}

void Tiparea::Display_Tip(unsigned short k,HANDLE hOut)
{
    k=10-k;
    COORD pos={tip_pos.X,tip_pos.Y};
    SetConsoleCursorPosition(hOut,pos);
    cout<<"Now Game Speed: x"<<k;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"Press key A for adding speed";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"Press key S for slowing down";
}

