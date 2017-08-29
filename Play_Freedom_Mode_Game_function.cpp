#include "const_Value.h"
#include "about_class.h"
#include "about_operation.h"
#include "about_Draw.h"
#include "about_character.h"

using namespace std;


void Game_Start(Battlefield &_map,Selectarea *select,vector<Card> &card,Home &player_home,Home &computer_home,Statue * message,HANDLE hOut)
{
    file_battlefield.clear();
    file_battlefield.seekg(0);

    for(unsigned short n=0;n<NUMBER_SELECT_CARD;n++)
    {
        select[n].Random_Get_Card(card,select);
        select[n].Display_Selectarea(card,n,hOut);
    }

    _map.Set_Home_in_Battlefield(player_home);
    _map.Set_Home_in_Battlefield(computer_home);

    _map.Display_Battlefield(hOut);

    message[PLAYER].Set_date(PLAYER);
    message[COMPUTER].Set_date(COMPUTER);

    return;
}

bool Game_End(bool win_player_or_computer,HANDLE hOut)
{
    system("CLS");
    bool choice=Draw_Freedom_Mode_Game_Over_Windows(win_player_or_computer,hOut);
    //true mean continue play
    //false mean back to main window
    if(choice==true)
        return true;
    else
        return false;
}

bool Gaming(Battlefield &_map,Selectarea *select,vector<Card> &card,
            Home &player_home,Home &computer_home,Statue * message,HANDLE hOut,bool &win_player_or_computer)
{

    /***光标初始指向第一个选择区域***/
    COORD new_pos={SELECTAREA_POS_X,SELECTAREA_POS_Y};
    SetConsoleCursorPosition(hOut,new_pos);

    //Card_in_fight *card_fight=new Card_in_fight[NUMBER_CARD_MAX_IN_BATTLEFIELD];
    vector<Card_in_fight> card_fight(NUMBER_CARD_MAX_IN_BATTLEFIELD);

    COORD temp_pos_choice_card={0,0};//store the pos chocie card in select area
    COORD temp_pos_set_card_in_screen={0,0};//储存在战场上放置的位置
    COORD temp_pos_set_card_in_map;

    unsigned computer_action_point=0;
    unsigned power_develop_point_player=0;//player power 资源增长点数
    unsigned power_develop_point_computer=0;//computer power 资源增长点数


    GetConsoleScreenBufferInfo(hOut,&bInfo);
    COORD now_pos={bInfo.dwCursorPosition.X,bInfo.dwCursorPosition.Y};//only key event can change now_pos value

    Draw_Statue(now_pos,message[PLAYER],hOut);//show the power

    unsigned short speed_control=4;

    vector<Tiparea> tip_area(NUMBER_TIP_AREA);
    COORD pos={TIP_AREA_POS_X,TIP_AREA_POS_Y};
    int tip_type=0;
    bool tip_exist=false;
    for(unsigned short n=0;n<NUMBER_TIP_AREA;n++)
    {
        tip_area[n].Get_tip_type(tip_type);
        tip_area[n].Get_tip_pos(pos);
        tip_area[n].Display_Tip(hOut);
        pos.Y+=TIP_AREA_HIGH;
    }

    while(1)
    {
        //false mean want quit
        if(Get_and_Respone_Key_Event_in_Play_Freedom_Mode_Game(speed_control,now_pos,temp_pos_choice_card,temp_pos_set_card_in_screen,hOut,_map)==false)
        {
            if(MessageBox(NULL,"Do you want to quit this game?", "Tip",MB_YESNO)==IDYES)
                return false;//direct quit to main window
        }

        //not change the now_pos value
        if(
          (now_pos.X==SELECTAREA_POS_X&&now_pos.Y==SELECTAREA_POS_Y)
          ||(now_pos.X==SELECTAREA_POS_X&&now_pos.Y==SELECTAREA_POS_Y+1*SELECTAREA_HIGH)
          ||(now_pos.X==SELECTAREA_POS_X&&now_pos.Y==SELECTAREA_POS_Y+2*SELECTAREA_HIGH)
          ||(now_pos.X==SELECTAREA_POS_X&&now_pos.Y==SELECTAREA_POS_Y+3*SELECTAREA_HIGH)
          )
          Draw_Cursor_in_Select_Area(now_pos,select,hOut);

/**************************************************
deal with power
**************************************************/
        power_develop_point_player++;
        if(power_develop_point_player>=message[PLAYER].Return_power_develop_speed()*speed_control)
        {
            message[PLAYER].Add_power();
            power_develop_point_player=0;
            Draw_Statue(now_pos,message[PLAYER],hOut);//show the power
        }

        power_develop_point_computer++;
        if(power_develop_point_computer>=message[COMPUTER].Return_power_develop_speed()*speed_control)
        {
            message[COMPUTER].Add_power();
            power_develop_point_computer=0;
        }
/*************************************************
computer view :computer strategy for choice card and set card
*************************************************/
        computer_action_point++;
        if(computer_action_point>=COMPUTER_ACTION_POINT_MAX*speed_control)
        {
            COORD computer_pos_choice;
            Card computer_card_choice;

            //can return true or false
            if(Computer_Strategy(message[COMPUTER].Return_now_power(),computer_pos_choice,computer_card_choice,card,card_fight,_map)==true)

            //can return true or false
            {
                message[COMPUTER].Cost_power(computer_card_choice.Return_card_cost());

                Set_Card_in_Battlefield(computer_pos_choice,computer_card_choice,card,card_fight,COMPUTER);
            }

            computer_action_point-=COMPUTER_ACTION_POINT_MAX;
        }

/*************************************************
player view :choice card and set card
*************************************************/
        if(temp_pos_choice_card.X!=0&&temp_pos_choice_card.Y!=0)//have choice the card
        {

            if(temp_pos_set_card_in_screen.X!=0&&temp_pos_set_card_in_screen.Y!=0)//选好了位置
            {

                char temp_card_name_selected;
                Card temp_card_choice;
                for(int k=0;k<NUMBER_SELECT_CARD;k++)
                {
                    if(temp_pos_choice_card.Y==SELECTAREA_POS_Y+SELECTAREA_HIGH*k)//找到对应 card_id
                    temp_card_name_selected=select[k].Return_card_name_in_selectarea();
                }

                for(int k=0;k<NUMBER_CARD;k++)//找到对应 card
                {
                    if(temp_card_name_selected==card[k].Return_card_name())
                    {
                        temp_card_choice=card[k];
                    }
                    else
                        continue;
                }


               //玩家放置卡片到战场上

                if(message[PLAYER].Cost_power(temp_card_choice.Return_card_cost())==true)
                {
                    Draw_Statue(now_pos,message[PLAYER],hOut);

                    temp_pos_set_card_in_map={temp_pos_set_card_in_screen.X-MAP_POS_X,temp_pos_set_card_in_screen.Y-MAP_POS_Y};

                    Set_Card_in_Battlefield(temp_pos_set_card_in_map,temp_card_choice,card,card_fight,PLAYER);

                    Change_Card_in_Selectarea(temp_pos_choice_card.Y,card,select,hOut);
                    //SetConsoleCursorPosition(hOut,now_pos);
                }
                else
                {
                    tip_type=1;//offer the tips about why can't set card
                }
                temp_pos_choice_card={0,0};
                temp_pos_set_card_in_screen={0,0};
                temp_pos_set_card_in_map={0,0};
            }
        }

/*******************************************************************************************************
card_fight take action
*******************************************************************************************************/
        for(int k=0;k<NUMBER_CARD_MAX_IN_BATTLEFIELD;k++)
        {
            if(card_fight[k].Return_if_in_map()==true)
            {
                Take_Action(speed_control,card_fight[k]/*一张卡*/,card_fight,_map,player_home,computer_home,card,hOut);
            }
        }
/*******************************************************************************************************
whether win or lose
*******************************************************************************************************/
        if(computer_home.Return_home_durable()<=10&&tip_exist==false)
        {
            tip_type=2;
            tip_exist=true;
        }
        if(player_home.Return_home_durable()<=0)
        {
            win_player_or_computer=COMPUTER;
            return true;
        }
        if(computer_home.Return_home_durable()<=0)
        {
            win_player_or_computer=PLAYER;
            return true;
        }
/*******************************************************************************************************
refresh the map to achieve card action
*******************************************************************************************************/
        Map_Refresh(_map,player_home,computer_home,card_fight,hOut,now_pos);

        //no tip need to display
        if(tip_type==0)
        {
            for(unsigned short n=0;n<NUMBER_TIP_AREA-1;n++)
            {
                 if(tip_area[n].Return_tip_type()!=0&&tip_area[n].Return_counter_tip_exist()<30)
                    tip_area[n].Add_counter_tip_exist();
                 if(tip_area[n].Return_tip_type()!=0&&tip_area[n].Return_counter_tip_exist()>=30)
                 {
                     tip_area[n].Get_tip_type(tip_type);
                     tip_area[n].Display_Tip(hOut);
                 }
            }
        }
        //one tip need to display
        else
        {
            for(unsigned short n=0;n<NUMBER_TIP_AREA-1;n++)
            {
                if(tip_area[n].Return_tip_type()==0)
                {
                    tip_area[n].Get_tip_type(tip_type);
                    tip_area[n].Display_Tip(hOut);
                }
            }
            //没有空位
            if(tip_type!=0)
            {
                unsigned short a=tip_area[0].Return_counter_tip_exist();
                unsigned short b=tip_area[1].Return_counter_tip_exist();
                unsigned short c=tip_area[2].Return_counter_tip_exist();
                if(a>=b&&a>=c)
                {
                    tip_area[0].Get_tip_type(tip_type);
                    tip_area[0].Display_Tip(hOut);
                }
                if(b>=a&&b>=c)
                {
                    tip_area[1].Get_tip_type(tip_type);
                    tip_area[1].Display_Tip(hOut);
                }
                if(c>=b&&c>=a)
                {
                    tip_area[2].Get_tip_type(tip_type);
                    tip_area[2].Display_Tip(hOut);
                }
            }
        }

        tip_area[NUMBER_TIP_AREA-1].Display_Tip(speed_control,hOut);
    }

}

void Take_Action(unsigned short speed_control,Card_in_fight &card_fight/*一张卡*/,vector<Card_in_fight> &card_fights,
                 Battlefield &_map,Home &player_home,Home &computer_home,vector<Card> &card,HANDLE hOut)
//have know the card is in the map
{
    COORD temp_aim_pos=card_fight.Check_Action(card_fights);

    int a=card_fight.Return_aim_pos().X-card_fight.Return_card_pos_in_map().X;
    int b=card_fight.Return_aim_pos().Y-card_fight.Return_card_pos_in_map().Y;
    int _distance=a*a+b*b;
    int distance_aim_to_card=sqrt(_distance);

    //attack or move
    if(distance_aim_to_card<=2)
    {
        if(card_fight.Return_aim_pos().X==HOME_COMPUTER_POS_X
         &&card_fight.Return_aim_pos().Y==HOME_COMPUTER_POS_Y)
        {
            card_fight.Attack_Action(computer_home);
            return;
        }
        else
        if(card_fight.Return_aim_pos().X==HOME_PLAYER_POS_X
         &&card_fight.Return_aim_pos().Y==HOME_PLAYER_POS_Y)
         {

            card_fight.Attack_Action(player_home);
            return;
        }
        else
        if(distance_aim_to_card<=1)
        {
            card_fight.Attack_Action(card_fights,card);
            return;
        }
    }

    if(card_fight.if_can_move==true)
        card_fight.Move_Action(speed_control,_map);

    return;
}

bool Get_and_Respone_Key_Event_in_Play_Freedom_Mode_Game(unsigned short &k,COORD &now_pos,COORD &temp_pos_choice_card,COORD &temp_pos_set_card_in_screen,HANDLE hOut,Battlefield _map)
{
    if(_kbhit())
    {
        int b=_getch();
        if(b=='a')//add speed
        {
            if(k>1)
                k-=1;
            return true;
        }
        if(b=='s')//slow down
        {
            if(k<9)
                k+=1;
            return true;
        }

        if(
          (now_pos.X==SELECTAREA_POS_X&&now_pos.Y==SELECTAREA_POS_Y)
          ||(now_pos.X==SELECTAREA_POS_X&&now_pos.Y==SELECTAREA_POS_Y+1*SELECTAREA_HIGH)
          ||(now_pos.X==SELECTAREA_POS_X&&now_pos.Y==SELECTAREA_POS_Y+2*SELECTAREA_HIGH)
          ||(now_pos.X==SELECTAREA_POS_X&&now_pos.Y==SELECTAREA_POS_Y+3*SELECTAREA_HIGH)
          )//now_pos is in select area
          {
              temp_pos_choice_card=Select_Card(b,hOut,now_pos,_map);
              if(temp_pos_choice_card.X==-1&&temp_pos_choice_card.Y==-1)
                return false;
          }
        else//now_pos is in map
        if(now_pos.X>MAP_POS_X&&now_pos.Y>MAP_POS_Y
         &&now_pos.X<MAP_POS_X+MAP_WIDTH&&now_pos.Y<MAP_POS_Y+MAP_HIGH)
        {
            temp_pos_set_card_in_screen=Select_Pos_to_Set_Card(b,hOut,now_pos,temp_pos_choice_card,_map);
        }
        return true;
    }
    return true;
}

COORD Select_Card(int b,HANDLE hOut,COORD &now_pos,Battlefield _map)
{
    COORD temp_pos=now_pos;
    if(b!=VK_ESCAPE&&b!=VK_RETURN&&b==224)
    {
        b=_getch();
        switch(b)
        {
        case UP:
            if(temp_pos.Y!=SELECTAREA_POS_Y)
            {
                temp_pos.Y-=SELECTAREA_HIGH;
                now_pos=temp_pos;
                temp_pos={0,0};
                return temp_pos;
            }
            else
            {
                temp_pos.Y=SELECTAREA_POS_Y+3*SELECTAREA_HIGH;
                now_pos=temp_pos;
                temp_pos={0,0};
                return temp_pos;
            }
        case DOWN:
            if(temp_pos.Y!=SELECTAREA_POS_Y+3*SELECTAREA_HIGH)
            {
                temp_pos.Y+=SELECTAREA_HIGH;
                now_pos=temp_pos;
                temp_pos={0,0};
                return temp_pos;
            }
            else
            {
                temp_pos.Y=SELECTAREA_POS_Y;
                now_pos=temp_pos;
                temp_pos={0,0};
                return temp_pos;
            }
        }
    }
    else if(b==VK_RETURN)
    {
        COORD jump_pos={SELECTAREA_JUMP_TO_MAP_X,SELECTAREA_JUMP_TO_MAP_Y};//根据 Map 位置而定
        COORD jump_pos_in_map={jump_pos.X-MAP_POS_X,jump_pos.Y-MAP_POS_Y};
        while(_map.Return_if_can_set_card_pos(jump_pos_in_map)==false)
        {
            jump_pos_in_map.Y--;
        }
        now_pos={jump_pos_in_map.X+MAP_POS_X,jump_pos_in_map.Y+MAP_POS_Y};
        return temp_pos;
    }
    else if(b==VK_ESCAPE)
    {
        temp_pos={-1,-1};
        return temp_pos;
    }
}

COORD Select_Pos_to_Set_Card(int b,HANDLE hOut,COORD &now_pos,COORD &temp_pos_choice_card,Battlefield _map)
{
   COORD temp_pos=now_pos;
   COORD pre_pos={now_pos.X-MAP_POS_X,now_pos.Y-MAP_POS_Y};
    if(b!=VK_ESCAPE&&b!=VK_RETURN&&b==224)
    {
        b=_getch();
        switch(b)
        {
        case UP:
            pre_pos.Y--;
            if(_map.Return_if_can_set_card_pos(pre_pos)&&pre_pos.Y!=MAP_HIGH/2+3)
            {
                temp_pos.Y--;
                now_pos=temp_pos;
                temp_pos={0,0};
                return temp_pos;
            }
            else
            {
                temp_pos={0,0};
                return temp_pos;
            }
        case DOWN:
            pre_pos.Y++;
            if(_map.Return_if_can_set_card_pos(pre_pos))
            {
                temp_pos.Y++;
                now_pos=temp_pos;
                temp_pos={0,0};
                return temp_pos;
            }
            else
            {
                temp_pos={0,0};
                return temp_pos;
            }
        case LEFT:
            pre_pos.X--;
            if(_map.Return_if_can_set_card_pos(pre_pos))
            {
                temp_pos.X--;
                now_pos=temp_pos;
                temp_pos={0,0};
                return temp_pos;
            }
            else
            {
                temp_pos={0,0};
                return temp_pos;
            }
        case RIGHT:
            pre_pos.X++;
            if(_map.Return_if_can_set_card_pos(pre_pos))
            {
                temp_pos.X++;
                now_pos=temp_pos;
                temp_pos={0,0};
                return temp_pos;
            }
            else
            {
                temp_pos={0,0};
                return temp_pos;
            }
        }
    }
    else if(b==VK_RETURN)
    {
        COORD jump_pos={SELECTAREA_POS_X,SELECTAREA_POS_Y};
        now_pos=jump_pos;
        return temp_pos;
    }
    else if(b==VK_ESCAPE)
    {
        COORD jump_pos={temp_pos_choice_card.X,temp_pos_choice_card.Y};
        now_pos=jump_pos;
        temp_pos={0,0};
        return temp_pos;
    }
}

void Map_Refresh(Battlefield &_map,Home &player_home,Home &computer_home,vector<Card_in_fight> &card_fight,HANDLE hOut,COORD now_pos)
{
    fstream temp_file_battlefield;
    temp_file_battlefield.open("FreedomModeMap.txt");
    _map.Load_Battlefield(temp_file_battlefield);

    _map.Set_Battlefield(player_home,computer_home,card_fight,now_pos);

    _map.Check_Battlefield();

    _map.Display_Battlefield(hOut);
}

void Change_Card_in_Selectarea(short temp_pos_choice_card_Y,vector<Card> &card,Selectarea *select,HANDLE hOut)
{
    unsigned short n=0;
    for(unsigned short k=0;k<NUMBER_SELECT_CARD;k++)
    {
        if(temp_pos_choice_card_Y==SELECTAREA_POS_Y+SELECTAREA_HIGH*k)
        {
            n=k;
            break;
        }
    }
    select[n].Random_Get_Card(card,select);
    select[n].Display_Selectarea(card,n,hOut);
}

void Set_Card_in_Battlefield(COORD temp_pos_set_card_in_map,
                             Card temp_card_choice,vector<Card> &cards,vector<Card_in_fight> &card_fight,bool player_or_computer)
{
    for(unsigned short n=0;n<NUMBER_CARD_MAX_IN_BATTLEFIELD;n++)
    {
        if(card_fight[n].Return_if_in_map()==false)
        {
            Character_for_Card_6(temp_card_choice,cards);
            card_fight[n].Set_Card_Date(temp_card_choice,temp_pos_set_card_in_map,player_or_computer);
            break;
        }
        else
            continue;
    }
}

bool Return_Left_or_Right(Battlefield _map,COORD check_pos)//关于寻路的函数
{
    COORD left_check_pos,right_check_pos;
    left_check_pos.Y=right_check_pos.Y=check_pos.Y;

    for(unsigned short n=0;n<MAP_WIDTH;n++)
    {
        left_check_pos.X=check_pos.X-n-1;
        right_check_pos.X=check_pos.X+n+1;

        if(_map.Return_map_in_one_pos(left_check_pos)!='#')
            return TO_LEFT;
        if(_map.Return_map_in_one_pos(right_check_pos)!='#')
            return TO_RIGHT;
    }

}

bool Return_Up_or_Down(Battlefield _map,COORD check_pos)//关于寻路的函数
{
    COORD up_check_pos,down_check_pos;
    up_check_pos.X=down_check_pos.X=check_pos.X;

    for(unsigned short n=0;n<MAP_WIDTH;n++)
    {
        up_check_pos.Y=check_pos.Y-n-1;
        down_check_pos.Y=check_pos.Y+n+1;

        if(_map.Return_map_in_one_pos(up_check_pos)!='#')
            return TO_UP;
        if(_map.Return_map_in_one_pos(down_check_pos)!='#')
            return TO_DOWN;
    }
}
