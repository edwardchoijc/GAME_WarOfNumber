#include "const_Value.h"
#include "about_Draw.h"
#include "about_class.h"
#include "about_operation.h"
#include "about_character.h"
#include "about_Story_Game.h"

using namespace std;

//return true mean Chenggong
//return false mean Shibai

/*bool Game_Teach(fstream &file_battlefield,vector<Card> &cards,HANDLE hOut)
//教学关  能放1~9 防守 只有一张卡选择
{
    bool win_player_or_computer=COMPUTER;

    Battlefield _map;
    _map.Load_Battlefield(file_battlefield);

    Home player_home(GAME_TECH_HOME_POS_X,GAME_TECH_HOME_POS_Y);
    _map.Set_Home_in_Battlefield(player_home);
    _map.Display_Battlefield(hOut);

    Selectarea select[NUMBER_SELECT_CARD];
    for(unsigned short n=0;n<NUMBER_SELECT_CARD-3;n++)
    {
        select[n].Random_Get_Card(card,select);
        select[n].Display_Selectarea(card,n,hOut);
    }

    Statue message[2];//record the statue about player and computer
    message[PLAYER].Set_date(PLAYER);
    //message[COMPUTER].Set_date(COMPUTER);


    COORD new_pos={SELECTAREA_POS_X,SELECTAREA_POS_Y};
    SetConsoleCursorPosition(hOut,new_pos);

    //Card_in_fight *card_fight=new Card_in_fight[NUMBER_CARD_MAX_IN_BATTLEFIELD];
    vector<Card_in_fight> card_fight(NUMBER_CARD_MAX_IN_BATTLEFIELD);

    COORD temp_pos_choice_card={0,0};//store the pos chocie card in select area
    COORD temp_pos_set_card_in_screen={0,0};//储存在战场上放置的位置
    COORD temp_pos_set_card_in_map;

    //unsigned computer_action_point=0;
    unsigned power_develop_point_player=0;//player power 资源增长点数
    //unsigned power_develop_point_computer=0;//computer power 资源增长点数


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

    COORD pos_1={};
    Card card_1=cards[1];
    Set_Card_in_Battlefield(pos_1,card_1,cards,card_fight,COMPUTER);
    COORD pos_2={};
    Card card_2=cards[1];
    Set_Card_in_Battlefield(pos_1,card_1,cards,card_fight,COMPUTER);
    COORD pos_2={};
    Card card_2=cards[1];
    Set_Card_in_Battlefield(pos_1,card_1,cards,card_fight,COMPUTER);
    COORD pos_2={};
    Card card_2=cards[1];
    Set_Card_in_Battlefield(pos_1,card_1,cards,card_fight,COMPUTER);

    COORD pos_2={};
    Card card_2=cards[0];
    Set_Card_in_Battlefield(pos_1,card_1,cards,card_fight,PLAYER);



    while(1)
    {
/*******************************************************************************************************
whether win or lose
*******************************************************************************************************/
 /*       if(player_home.Return_home_durable()<=10&&tip_exist==false)
        {
            tip_type=-2;
            tip_exist=true;
        }

        if(player_home.Return_home_durable()<=0)
        {
            win_player_or_computer=COMPUTER;
            if(Draw_Freedom_Mode_Game_Over_Windows(win_player_or_computer,hOut))
                return true;
        }
        for(unsigned short n=0;n<4;n++)
        {
            if(card_fight[n].Return_card_HP()>0&&card_fight[n].Return_player_or_computer()!=PLAYER)
                break;

            win_player_or_computer=PLAYER;
            Draw_Freedom_Mode_Game_Over_Windows(win_player_or_computer,hOut);


        }
    }


    return true;
}*/

bool Game_1_1(fstream &file_battlefield,vector<Card> &cards,HANDLE hOut)
{
    return true;
}

bool Game_1_2(fstream &file_battlefield,vector<Card> &cards,HANDLE hOut)
{
    return true;
}
