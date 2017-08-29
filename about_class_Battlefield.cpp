#include "const_Value.h"
#include "about_Draw.h"
#include "about_class.h"
#include "about_operation.h"
#include "about_character.h"

using namespace std;

Battlefield::Battlefield()
{
    /*for(int k=0;k<MAP_HIGH;k++)
        for(int d=0;d<MAP_WIDTH;d++)
            if_can_set_card[k][d]=false;*/
}

Battlefield::~Battlefield()
{

}

void Battlefield::Check_Battlefield()
{
    for(int k=0;k<MAP_HIGH;k++)
        for(int d=0;d<MAP_WIDTH;d++)
        {
            if(battlefield_date[k][d]==' '||battlefield_date[k][d]=='S')
                if_can_set_card[k][d]=true;
            else
                if_can_set_card[k][d]=false;
        }
}

void Battlefield::Load_Battlefield(fstream &file_battlefield)
{
    for(int k=0;k<MAP_HIGH;k++)
        for(int d=0;d<MAP_WIDTH;d++)
            if_can_set_card[k][d]=false;

    file_battlefield.clear();
    file_battlefield.seekg(0);

    for(unsigned short n=0;n<MAP_HIGH;n++)
    {
        for(unsigned short k=0;k<MAP_WIDTH;k++)
           battlefield_date[n][k]=file_battlefield.get();
        file_battlefield.get();
    }
}

void Battlefield::Display_Battlefield(HANDLE hOut)
{
    COORD pos={MAP_POS_X,MAP_POS_Y};
    SetConsoleCursorPosition(hOut,pos);

    for(int k=0;k<MAP_HIGH;k++)
    {
        for(int d=0;d<MAP_WIDTH;d++)
        {
            if(battlefield_date[k][d]=='#')//ignore the wall
            {
                pos.X++;
                SetConsoleCursorPosition(hOut,pos);
                continue;
            }
            if(battlefield_date[k][d]=='+'||battlefield_date[k][d]=='*')//display the player home
            {
                WORD att=FOREGROUND_BLUE;//change the player home color
                GetConsoleScreenBufferInfo(hOut,&bInfo);
                WORD now_att=bInfo.wAttributes;
                SetConsoleTextAttribute(hOut,att);
                cout<<battlefield_date[k][d];
                SetConsoleTextAttribute(hOut,now_att);

                pos.X++;
                SetConsoleCursorPosition(hOut,pos);
                continue;
            }
            if(battlefield_date[k][d]=='+'-16||battlefield_date[k][d]=='*'-16)//display the computer home
            {
                WORD att=FOREGROUND_RED;//change the computer home color
                GetConsoleScreenBufferInfo(hOut,&bInfo);
                WORD now_att=bInfo.wAttributes;
                SetConsoleTextAttribute(hOut,att);
                cout<<char(battlefield_date[k][d]+16);
                SetConsoleTextAttribute(hOut,now_att);

                pos.X++;
                SetConsoleCursorPosition(hOut,pos);
                continue;
            }

            if(battlefield_date[k][d]=='1'||battlefield_date[k][d]=='2'||battlefield_date[k][d]=='3'
                  ||battlefield_date[k][d]=='4'||battlefield_date[k][d]=='5'||battlefield_date[k][d]=='6'
                  ||battlefield_date[k][d]=='7'||battlefield_date[k][d]=='8'||battlefield_date[k][d]=='9')
            {
                WORD att=FOREGROUND_BLUE;
                GetConsoleScreenBufferInfo(hOut,&bInfo);
                WORD now_att=bInfo.wAttributes;
                SetConsoleTextAttribute(hOut,att);
                cout<<battlefield_date[k][d];
                SetConsoleTextAttribute(hOut,now_att);

                pos.X++;
                SetConsoleCursorPosition(hOut,pos);
                continue;
            }

            if(battlefield_date[k][d]=='A'||battlefield_date[k][d]=='B'||battlefield_date[k][d]=='C'
                  ||battlefield_date[k][d]=='D'||battlefield_date[k][d]=='E'||battlefield_date[k][d]=='F'
                  ||battlefield_date[k][d]=='G'||battlefield_date[k][d]=='H'||battlefield_date[k][d]=='I')
            {
                WORD att=FOREGROUND_RED;
                GetConsoleScreenBufferInfo(hOut,&bInfo);
                WORD now_att=bInfo.wAttributes;
                SetConsoleTextAttribute(hOut,att);
                cout<<char(battlefield_date[k][d]-16);
                SetConsoleTextAttribute(hOut,now_att);

                pos.X++;
                SetConsoleCursorPosition(hOut,pos);
                continue;
            }

            if(battlefield_date[k][d]==' ')
            {
                cout<<battlefield_date[k][d];

                pos.X++;
                SetConsoleCursorPosition(hOut,pos);
                continue;
            }
            if(battlefield_date[k][d]=='S')
            {
                WORD att=FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN;//改变光标颜色
                GetConsoleScreenBufferInfo(hOut,&bInfo);
                WORD now_att=bInfo.wAttributes;
                SetConsoleTextAttribute(hOut,att);
                cout<<battlefield_date[k][d];
                SetConsoleTextAttribute(hOut,now_att);

                pos.X++;
                SetConsoleCursorPosition(hOut,pos);
                continue;
            }

            pos.X++;
            SetConsoleCursorPosition(hOut,pos);
            continue;

        }
        pos.Y++;
        pos.X=MAP_POS_X;
        SetConsoleCursorPosition(hOut,pos);
    }
}

void Battlefield::Set_Battlefield(Home &player_home,Home &computer_home,vector<Card_in_fight> &card_fight,COORD now_pos)
{
     Set_Home_in_Battlefield(player_home);
     Set_Home_in_Battlefield(computer_home);
     Set_Card_in_Fight_in_Battlefield(card_fight);
     Set_Cursor_in_Battlefield(now_pos);
}

void Battlefield::Set_Home_in_Battlefield(Home home)
{
    COORD home_pos=home.Return_home_pos();
    unsigned short home_durable=home.Return_home_durable();
    if(home_durable<=0)
        return;

    if(home.Return_player_or_computer()==PLAYER)
    {
    battlefield_date[home_pos.Y-1][home_pos.X-1]='+';
    battlefield_date[home_pos.Y][home_pos.X-1]='+';
    battlefield_date[home_pos.Y+1][home_pos.X-1]='+';
    battlefield_date[home_pos.Y-1][home_pos.X]='+';
    battlefield_date[home_pos.Y][home_pos.X]='+';
    battlefield_date[home_pos.Y+1][home_pos.X]='+';
    battlefield_date[home_pos.Y-1][home_pos.X+1]='+';
    battlefield_date[home_pos.Y][home_pos.X+1]='+';
    battlefield_date[home_pos.Y+1][home_pos.X+1]='+';
    }
    if(home.Return_player_or_computer()==COMPUTER)
    {
    battlefield_date[home_pos.Y-1][home_pos.X-1]='+'-16;
    battlefield_date[home_pos.Y][home_pos.X-1]='+'-16;
    battlefield_date[home_pos.Y+1][home_pos.X-1]='+'-16;
    battlefield_date[home_pos.Y-1][home_pos.X]='+'-16;
    battlefield_date[home_pos.Y][home_pos.X]='+'-16;
    battlefield_date[home_pos.Y+1][home_pos.X]='+'-16;
    battlefield_date[home_pos.Y-1][home_pos.X+1]='+'-16;
    battlefield_date[home_pos.Y][home_pos.X+1]='+'-16;
    battlefield_date[home_pos.Y+1][home_pos.X+1]='+'-16;
    }

    if(home.Return_player_or_computer()==COMPUTER)
    {

        switch (home_durable/3)
        {
        case 0:
            battlefield_date[home_pos.Y-1][home_pos.X]='*'-16;
        case 1:
            battlefield_date[home_pos.Y-1][home_pos.X-1]=' ';
        case 2:
            battlefield_date[home_pos.Y-1][home_pos.X+1]=' ';
        case 3:
            battlefield_date[home_pos.Y][home_pos.X+1]=' ';
        case 4:
            battlefield_date[home_pos.Y][home_pos.X]=' ';
        case 5:
            battlefield_date[home_pos.Y][home_pos.X-1]=' ';
        case 6:
             battlefield_date[home_pos.Y+1][home_pos.X-1]=' ';
        case 7:
            battlefield_date[home_pos.Y+1][home_pos.X]=' ';
        case 8:
            battlefield_date[home_pos.Y+1][home_pos.X+1]=' ';
        }
    }
    else if(home.Return_player_or_computer()==PLAYER)
    {
        switch (home_durable/3)
        {
        case 0:
             battlefield_date[home_pos.Y+1][home_pos.X]='*';
        case 1:
            battlefield_date[home_pos.Y+1][home_pos.X+1]=' ';
        case 2:
            battlefield_date[home_pos.Y+1][home_pos.X-1]=' ';
        case 3:
             battlefield_date[home_pos.Y][home_pos.X-1]=' ';
        case 4:
            battlefield_date[home_pos.Y][home_pos.X]=' ';
        case 5:
            battlefield_date[home_pos.Y][home_pos.X+1]=' ';
        case 6:
            battlefield_date[home_pos.Y-1][home_pos.X+1]=' ';
        case 7:
            battlefield_date[home_pos.Y-1][home_pos.X]=' ';
        case 8:
           battlefield_date[home_pos.Y-1][home_pos.X-1]=' ';
        }
    }



}

void Battlefield::Set_Card_in_Fight_in_Battlefield(vector<Card_in_fight> &card_fight)
{
    for(unsigned short n=0;n<NUMBER_CARD_MAX_IN_BATTLEFIELD;n++)
    {
        if(card_fight[n].Return_if_in_map()==true)
        {
            if(card_fight[n].Return_player_or_computer()==PLAYER)
            {
                COORD temp=card_fight[n].Return_card_pos_in_map();
                battlefield_date[temp.Y][temp.X]=card_fight[n].Return_card_name();
            }
            else
            {
                COORD temp=card_fight[n].Return_card_pos_in_map();
                battlefield_date[temp.Y][temp.X]=card_fight[n].Return_card_name()+16;//change to letter store for distinguish
            }
        }
        else
            continue;
    }

}

void Battlefield::Set_Cursor_in_Battlefield(COORD now_pos)
{
    if(now_pos.X>=MAP_POS_X&&now_pos.Y>=MAP_POS_Y
     &&now_pos.X<=MAP_POS_X+MAP_WIDTH&&now_pos.Y<=MAP_POS_Y+MAP_HIGH)
    {
        COORD now_pos_in_map={now_pos.X-MAP_POS_X,now_pos.Y-MAP_POS_Y};
        battlefield_date[now_pos_in_map.Y][now_pos_in_map.X]='S';
    }
}

bool Battlefield::Return_if_can_set_card_pos(COORD pos_in_map)
{
    return if_can_set_card[pos_in_map.Y][pos_in_map.X];
}

char Battlefield::Return_map_in_one_pos(COORD pos_in_map)
{
    return battlefield_date[pos_in_map.Y][pos_in_map.X];
}

