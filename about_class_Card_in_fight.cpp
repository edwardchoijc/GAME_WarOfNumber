#include "const_Value.h"
#include "about_class.h"
#include "about_operation.h"
#include "about_Draw.h"
#include "about_character.h"

using namespace std;

Card_in_fight::Card_in_fight()
{
    if_in_map=false;

    counter_for_move=0;//control the move

    counter_for_add_speed=0;

    card_pos_in_map={-1,-1};
    aim_pos={-1,-1};

}

Card_in_fight::~Card_in_fight()
{

}

void Card_in_fight::operator =(Card &temp_card_choice)
{
    card_name=temp_card_choice.Return_card_name();
    card_HP=temp_card_choice.Return_card_HP();
    card_cost=temp_card_choice.Return_card_cost();
    card_damage=temp_card_choice.Return_card_damage();
    card_speed=temp_card_choice.Return_card_speed();

    card_horizon.X=temp_card_choice.Return_card_horizon().X;
    card_horizon.Y=temp_card_choice.Return_card_horizon().Y;

    if_can_attack=temp_card_choice.if_can_attack;
    if_can_move=temp_card_choice.if_can_move;

    if_can_use=true;

    counter_for_add_speed=0;
}

void Card_in_fight::Set_Card_Date(Card &temp_card_choice,COORD temp_pos_set_card_in_map,bool player_or_computer)
{
    if_in_map=true;

    *this=temp_card_choice;

    card_pos_in_map=temp_pos_set_card_in_map;

    player_or_AI=player_or_computer;

    //default aim_pos is home
    if(player_or_AI==PLAYER)
        aim_pos={HOME_COMPUTER_POS_X,HOME_COMPUTER_POS_Y};
    else
        aim_pos={HOME_PLAYER_POS_X,HOME_PLAYER_POS_Y};

}

COORD Card_in_fight::Check_Action(vector<Card_in_fight> &card_fight)
{
    if(player_or_AI==PLAYER)
        aim_pos={HOME_COMPUTER_POS_X,HOME_COMPUTER_POS_Y};
    else
        aim_pos={HOME_PLAYER_POS_X,HOME_PLAYER_POS_Y};

    //check the if_can_attack
    if(if_can_attack==false)
        return aim_pos;

    int distance_aim_to_card[NUMBER_CARD_MAX_IN_BATTLEFIELD]={-1};

    //check all card_in_fight date
    int min_distance=99;
    for(unsigned short n=0;n<NUMBER_CARD_MAX_IN_BATTLEFIELD;n++)
    {
        //exclude the card not in the map 排除不在场
        if(card_fight[n].Return_if_in_map()==false)
            continue;

        //exclude myself 排除自己
        if(card_pos_in_map.X==card_fight[n].Return_card_pos_in_map().X
         &&card_pos_in_map.Y==card_fight[n].Return_card_pos_in_map().Y)
            continue;

        //exclude the friend card 排除友军
        if(player_or_AI==card_fight[n].Return_player_or_computer())
            continue;


        //exclude the card out the horizon 排除视野外
        if(
           card_pos_in_map.X+card_horizon.X<card_fight[n].Return_card_pos_in_map().X
         ||card_pos_in_map.X-card_horizon.X>card_fight[n].Return_card_pos_in_map().X
         ||card_pos_in_map.Y+card_horizon.Y<card_fight[n].Return_card_pos_in_map().Y
         ||card_pos_in_map.Y-card_horizon.Y>card_fight[n].Return_card_pos_in_map().Y
           )
           continue;

        //find the enemy 正常寻敌 计算距离
        int a=card_fight[n].Return_card_pos_in_map().X-card_pos_in_map.X;
        int b=card_fight[n].Return_card_pos_in_map().Y-card_pos_in_map.Y;
        int temp_distance=a*a+b*b;

        distance_aim_to_card[n]=sqrt(temp_distance);

        if(distance_aim_to_card[n]<=min_distance)
        {
            min_distance=distance_aim_to_card[n];

            aim_pos.X=card_fight[n].Return_card_pos_in_map().X;
            aim_pos.Y=card_fight[n].Return_card_pos_in_map().Y;
        }

    }
    return aim_pos;

}

void Card_in_fight::Set_Card_Pos(short x,short y)
{
    card_pos_in_map.X=x;
    card_pos_in_map.Y=y;
}

void Card_in_fight::Attack_Action(vector<Card_in_fight> &card_fighting,vector<Card> &card)
{

    //find the attack card_in_fight
    for(unsigned short n=0;n<NUMBER_CARD_MAX_IN_BATTLEFIELD;n++)
    {
        if(aim_pos.X==card_fighting[n].Return_card_pos_in_map().X
         &&aim_pos.Y==card_fighting[n].Return_card_pos_in_map().Y)
        {
            if(card_HP>card_fighting[n].Return_card_HP())
            {
                if(Character_for_Card_9(this,&card_fighting[n])==false)
                {
                    if(Character_for_Card_3(&card_fighting[n])==false)
                    {
                        if(Character_for_Card_8(this,&card_fighting[n])==false)
                        {
                            Be_Hurted(card_fighting[n].Return_card_HP(),card);//turn to a new card
                            if(Character_for_Card_5(&card_fighting[n],card[0])==false)
                                card_fighting[n].Be_Killed();
                            Character_for_Card_4(&card_fighting[n],this);
                        }
                        else
                            Be_Hurted(card_fighting[n].Return_card_HP(),card);//turn to a new card
                    }
                }
                break;
            }
            if(card_HP==card_fighting[n].Return_card_HP())
            {
                Be_Killed();
                card_fighting[n].Be_Killed();
                break;
            }
            if(card_HP<card_fighting[n].Return_card_HP())
            {
                if(Character_for_Card_9(&card_fighting[n],this)==false)
                {
                    if(Character_for_Card_3(this)==false)
                    {
                        if(Character_for_Card_8(&card_fighting[n],this)==false)
                        {
                            card_fighting[n].Be_Hurted(card_HP,card);
                            if(Character_for_Card_5(this,card[0])==false)
                                Be_Killed();
                            Character_for_Card_4(this,&card_fighting[n]);
                        }
                        else
                            card_fighting[n].Be_Hurted(card_HP,card);
                    }
                }
                break;
            }
        }
        else
            continue;

    }

}

void Card_in_fight::Attack_Action(Home &home_date)
{
    Be_Killed();
    home_date.Be_Hurted(card_damage);
}

void Card_in_fight::Be_Killed()
{
    if_in_map=false;
    card_pos_in_map={-1,-1};
    return;
}

void Card_in_fight::Be_Hurted(unsigned short d,vector<Card> &card)
{

    card_name=card_name-d;
    for(unsigned short n=0;n<NUMBER_CARD_MAX_IN_BATTLEFIELD;n++)
    {
        if(card_name==card[n].Return_card_name())
        {
            if_in_map=true;
            if(player_or_AI==PLAYER)
                aim_pos={HOME_COMPUTER_POS_X,HOME_COMPUTER_POS_Y};
            else
                aim_pos={HOME_PLAYER_POS_X,HOME_PLAYER_POS_Y};
            *this=card[n];
            break;
        }
    }

}

void Card_in_fight::Move_Action(unsigned short speed_control,Battlefield _map)//传入地图为了检查区域是否为墙
/***********************************
move strategy

don't exist 回型区域
***********************************/
{
    counter_for_move++;

    Character_for_Card_1(this);

    if(counter_for_move>=card_speed)
    {
        COORD check_pos;

        if(card_pos_in_map.X<aim_pos.X&&card_pos_in_map.Y<aim_pos.Y)//目的地在右下
        {
            check_pos.X=card_pos_in_map.X;
            check_pos.Y=card_pos_in_map.Y+1;
            if(_map.Return_map_in_one_pos(check_pos)!='#')//下方可行
            {

                check_pos.X=card_pos_in_map.X+1;
                check_pos.Y=card_pos_in_map.Y;
                if(_map.Return_map_in_one_pos(check_pos)!='#')//下方可行且右方可行->缩短长边
                {
                    if((aim_pos.X-card_pos_in_map.X)<=(aim_pos.Y-card_pos_in_map.Y))
                    {
                        card_pos_in_map.Y++;
                        goto END;
                    }
                    else
                    {
                        card_pos_in_map.X++;
                        goto END;
                    }
                }
                else//下方可行但右方不可行->下行
                {
                    card_pos_in_map.Y++;
                    goto END;
                }
            }
            else
            //下方不可行->根据当前位置决定左右
            {
                if(Return_Left_or_Right(_map,check_pos)==TO_LEFT)
                    card_pos_in_map.X--;
                else
                    card_pos_in_map.X++;
                Character_for_Card_2(this,TO_DOWN);
            }

        }

        if(card_pos_in_map.X<aim_pos.X&&card_pos_in_map.Y>aim_pos.Y)//目的地在右上
        {
            check_pos.X=card_pos_in_map.X;
            check_pos.Y=card_pos_in_map.Y-1;
            if(_map.Return_map_in_one_pos(check_pos)!='#')//上方可行
            {
                check_pos.X=card_pos_in_map.X+1;
                check_pos.Y=card_pos_in_map.Y;
                if(_map.Return_map_in_one_pos(check_pos)!='#')//上方可行且右方可行->缩短长边
                {
                    if((aim_pos.X-card_pos_in_map.X)<=(card_pos_in_map.Y-aim_pos.Y))
                    {
                        card_pos_in_map.Y--;
                        goto END;
                    }
                    else
                    {
                        card_pos_in_map.X++;
                        goto END;
                    }
                }
                else//上方可行但右方不可行->上行
                {
                    card_pos_in_map.Y--;
                    goto END;
                }
            }
            else//上方不可行->根据当前位置决定左右
            {
                if(Return_Left_or_Right(_map,check_pos)==TO_LEFT)
                    card_pos_in_map.X--;
                else
                    card_pos_in_map.X++;
                Character_for_Card_2(this,TO_UP);
            }

        }

        if(card_pos_in_map.X>aim_pos.X&&card_pos_in_map.Y<aim_pos.Y)//目的地在左下
        {
            check_pos.X=card_pos_in_map.X;
            check_pos.Y=card_pos_in_map.Y+1;
            if(_map.Return_map_in_one_pos(check_pos)!='#')
            {
                check_pos.X=card_pos_in_map.X-1;
                check_pos.Y=card_pos_in_map.Y;
                if(_map.Return_map_in_one_pos(check_pos)!='#')//下方可行且左方可行->缩短长边
                {
                    if((card_pos_in_map.X-aim_pos.X)<=(aim_pos.Y-card_pos_in_map.Y))
                    {
                        card_pos_in_map.Y++;
                        goto END;
                    }
                    else
                    {
                        card_pos_in_map.X--;
                        goto END;
                    }
                }
                else//下方可行但左方不可行->下行
                {
                    card_pos_in_map.Y++;
                    goto END;
                }
            }
            else//下方不可行->根据当前位置决定左右
            {
                if(Return_Left_or_Right(_map,check_pos)==TO_LEFT)
                    card_pos_in_map.X--;
                else
                    card_pos_in_map.X++;
                Character_for_Card_2(this,TO_DOWN);
            }
        }

        if(card_pos_in_map.X>aim_pos.X&&card_pos_in_map.Y>aim_pos.Y)//目的地在左上
        {
            check_pos.X=card_pos_in_map.X;
            check_pos.Y=card_pos_in_map.Y-1;
            if(_map.Return_map_in_one_pos(check_pos)!='#')
            {
                check_pos.X=card_pos_in_map.X-1;
                check_pos.Y=card_pos_in_map.Y;
                if(_map.Return_map_in_one_pos(check_pos)!='#')//上方可行且左方可行->缩短长边
                {
                    if((card_pos_in_map.X-aim_pos.X)<=(card_pos_in_map.Y-aim_pos.Y))
                    {
                        card_pos_in_map.Y--;
                        goto END;
                    }
                    else
                    {
                        card_pos_in_map.X--;
                        goto END;
                    }
                }
                else//上方可行但左方不可行->上行
                {
                    card_pos_in_map.Y--;
                    goto END;
                }
            }
            else//上方不可行->根据当前位置决定左右
            {
                if(Return_Left_or_Right(_map,check_pos)==TO_LEFT)
                    card_pos_in_map.X--;
                else
                    card_pos_in_map.X++;
                Character_for_Card_2(this,TO_UP);
            }
        }

        if(card_pos_in_map.X==aim_pos.X&&card_pos_in_map.Y<aim_pos.Y)//目的地在正下方
        {
            check_pos.X=card_pos_in_map.X;
            check_pos.Y=card_pos_in_map.Y+1;
            if(_map.Return_map_in_one_pos(check_pos)!='#')//下方可行
            {
                card_pos_in_map.Y++;
            }
            else//下方不可行
            {
                if(Return_Left_or_Right(_map,check_pos)==TO_LEFT)
                    card_pos_in_map.X--;
                else
                    card_pos_in_map.X++;
                Character_for_Card_2(this,TO_DOWN);
            }

        }

        if(card_pos_in_map.X==aim_pos.X&&card_pos_in_map.Y>aim_pos.Y)//目的地在正上方
        {
            check_pos.X=card_pos_in_map.X;
            check_pos.Y=card_pos_in_map.Y-1;
            if(_map.Return_map_in_one_pos(check_pos)!='#')//上方可行
            {
                card_pos_in_map.Y--;
            }
            else//上方不可行
            {
                if(Return_Left_or_Right(_map,check_pos)==TO_LEFT)
                    card_pos_in_map.X--;
                else
                    card_pos_in_map.X++;
                Character_for_Card_2(this,TO_UP);
            }

        }
        if(card_pos_in_map.X>aim_pos.X&&card_pos_in_map.Y==aim_pos.Y)//目的地在正左方
        {
            check_pos.X=card_pos_in_map.X-1;
            check_pos.Y=card_pos_in_map.Y;
            if(_map.Return_map_in_one_pos(check_pos)!='#')//左方可行
            {
                card_pos_in_map.X--;
            }
            else//左方不可行
            {
                if(Return_Up_or_Down(_map,check_pos)==TO_UP)
                    card_pos_in_map.Y--;
                else
                    card_pos_in_map.Y++;
            }
        }

        if(card_pos_in_map.X<aim_pos.X&&card_pos_in_map.Y==aim_pos.Y)//目的地在正右方
        {
            check_pos.X=card_pos_in_map.X+1;
            check_pos.Y=card_pos_in_map.Y;
            if(_map.Return_map_in_one_pos(check_pos)!='#')//右方可行
            {
                card_pos_in_map.X++;
            }
            else//右方不可行
            {
                if(Return_Up_or_Down(_map,check_pos)==TO_UP)
                    card_pos_in_map.Y--;
                else
                    card_pos_in_map.Y++;
            }
        }

        END:counter_for_move-=card_speed;
    }

}

