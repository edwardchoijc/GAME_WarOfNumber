#include "const_Value.h"
#include "about_class.h"
#include "about_operation.h"
#include "about_Draw.h"
#include "about_character.h"

using namespace std;

void Draw_Cursor_in_Display_Card_Message(COORD choice_pos,HANDLE hOut)//finished
{
     for(unsigned short a=0;a<3;a++)
        for(unsigned short b=0;b<3;b++)
    {
        if(choice_pos.X==DISPLAY_FIRST_CARD_POS_X+a*DISPLAY_CARD_WIDTH
         &&choice_pos.Y==DISPLAY_FIRST_CARD_POS_Y+b*DISPLAY_CARD_HIGH)
         {
             COORD temp_pos={choice_pos.X,choice_pos.Y+1};
             SetConsoleCursorPosition(hOut,temp_pos);
             cout<<">";
         }
        else
        {
            COORD temp_pos={DISPLAY_FIRST_CARD_POS_X+a*DISPLAY_CARD_WIDTH,DISPLAY_FIRST_CARD_POS_Y+b*DISPLAY_CARD_HIGH+1};
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<" ";
        }
    }
}

void Draw_Cursor_in_Main_Window_Select(COORD choice_pos,HANDLE hOut)
{
    COORD temp_pos={choice_pos.X+1,choice_pos.Y};
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<">";
    temp_pos={choice_pos.X+24,choice_pos.Y};
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<"<";
    if(choice_pos.X!=MAIN_WINDOW_SELECT_POS_X_1)
    {
        temp_pos={MAIN_WINDOW_SELECT_POS_X_1+1,MAIN_WINDOW_SELECT_POS_Y_1};
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<" ";
        temp_pos={MAIN_WINDOW_SELECT_POS_X_1+24,MAIN_WINDOW_SELECT_POS_Y_1};
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<" ";
    }

    if(choice_pos.X!=MAIN_WINDOW_SELECT_POS_X_2||choice_pos.Y!=MAIN_WINDOW_SELECT_POS_Y_2)
    {
        temp_pos={MAIN_WINDOW_SELECT_POS_X_2+1,MAIN_WINDOW_SELECT_POS_Y_2};
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<" ";
        temp_pos={MAIN_WINDOW_SELECT_POS_X_2+24,MAIN_WINDOW_SELECT_POS_Y_2};
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<" ";
    }

    if(choice_pos.X!=MAIN_WINDOW_SELECT_POS_X_3)
    {
        temp_pos={MAIN_WINDOW_SELECT_POS_X_3+1,MAIN_WINDOW_SELECT_POS_Y_3};
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<" ";
        temp_pos={MAIN_WINDOW_SELECT_POS_X_3+24,MAIN_WINDOW_SELECT_POS_Y_3};
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<" ";
    }

    if(choice_pos.X!=MAIN_WINDOW_SELECT_POS_X_4||choice_pos.Y!=MAIN_WINDOW_SELECT_POS_Y_4)
    {
        temp_pos={MAIN_WINDOW_SELECT_POS_X_4+1,MAIN_WINDOW_SELECT_POS_Y_4};
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<" ";
        temp_pos={MAIN_WINDOW_SELECT_POS_X_4+24,MAIN_WINDOW_SELECT_POS_Y_4};
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<" ";
    }
    if(choice_pos.X!=MAIN_WINDOW_SELECT_POS_X_5||choice_pos.Y!=MAIN_WINDOW_SELECT_POS_Y_5)
    {
        temp_pos={MAIN_WINDOW_SELECT_POS_X_5+1,MAIN_WINDOW_SELECT_POS_Y_5};
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<" ";
        temp_pos={MAIN_WINDOW_SELECT_POS_X_5+24,MAIN_WINDOW_SELECT_POS_Y_5};
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<" ";
    }
}

void Draw_Cursor_in_Select_Area(COORD now_pos,Selectarea *select,HANDLE hOut)
{
    COORD temp_pos;
    for(unsigned short n=0;n<NUMBER_SELECT_CARD;n++)
    {
            temp_pos.Y=select[n].Return_select_pos().Y;
            temp_pos.X=select[n].Return_select_pos().X;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<' ';
            SetConsoleCursorPosition(hOut,now_pos);
            if(select[n].Return_select_pos().Y==now_pos.Y)
            cout<<'>';

    }
    SetConsoleCursorPosition(hOut,now_pos);
}

void Draw_Cursor_in_Play_Story_Mode_Window(COORD choice_pos,HANDLE hOut)
{

     for(unsigned short a=0;a<3;a++)
        for(unsigned short b=0;b<4;b++)
    {
        if(choice_pos.X==DISPLAY_FIRST_LEVEL_POS_X+b*DISPLAY_LEVEL_WIDTH
         &&choice_pos.Y==DISPLAY_FIRST_LEVEL_POS_Y+a*DISPLAY_LEVEL_HIGH)
         {
             COORD temp_pos={choice_pos.X,choice_pos.Y};
             SetConsoleCursorPosition(hOut,temp_pos);
             cout<<">>";
         }
        else
        {
            COORD temp_pos={DISPLAY_FIRST_LEVEL_POS_X+b*DISPLAY_LEVEL_WIDTH,DISPLAY_FIRST_LEVEL_POS_Y+a*DISPLAY_LEVEL_HIGH};
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"  ";
        }
    }

    for(unsigned short a=0;a<2;a++)
    {
        if(choice_pos.X==DISPLAY_THIRTEENTH_LEVEL_POS_X+a*DISPLAY_LEVEL_WIDTH
         &&choice_pos.Y==DISPLAY_THIRTEENTH_LEVEL_POS_Y)
         {
             COORD temp_pos={choice_pos.X,choice_pos.Y};
             SetConsoleCursorPosition(hOut,temp_pos);
             cout<<">>";
         }
        else
        {
            COORD temp_pos={DISPLAY_THIRTEENTH_LEVEL_POS_X+a*DISPLAY_LEVEL_WIDTH,DISPLAY_THIRTEENTH_LEVEL_POS_Y};
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"  ";
        }
    }
}

void Draw_Normal_Box(HANDLE hOut)
{
    system("CLS");
    COORD pos={0,0};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xc9);
    for(unsigned short n=1;n<WINDOW_SIZE_X-5;n++)
        cout<<char(0xcd);
    cout<<char(0xbb);

    for(short k=1;k<MAP_POS_Y+MAP_HIGH+MAP_TO_STATUE+3;k++)
    {
        pos={0,k};
        SetConsoleCursorPosition(hOut,pos);
        cout<<char(0xba);
        pos={WINDOW_SIZE_X-5,k};
        SetConsoleCursorPosition(hOut,pos);
        cout<<char(0xba);
    }
    pos={0,MAP_POS_Y+MAP_HIGH+MAP_TO_STATUE+3};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xc8);
    for(unsigned short n=1;n<WINDOW_SIZE_X-5;n++)
        cout<<char(0xcd);
    cout<<char(0xbc);


    pos={1,1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xc9);
    for(unsigned short n=1;n<WINDOW_SIZE_X-7;n++)
        cout<<char(0xcd);
    cout<<char(0xbb);
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    for(unsigned short k=1;k<MAP_POS_Y+MAP_HIGH+MAP_TO_STATUE+1;k++)
    {
        cout<<char(0xba);
        pos={WINDOW_SIZE_X-6,k+1};
        SetConsoleCursorPosition(hOut,pos);
        cout<<char(0xba);
        pos={1,k+2};
        SetConsoleCursorPosition(hOut,pos);
    }

    cout<<char(0xc8);
    for(unsigned short n=1;n<WINDOW_SIZE_X-7;n++)
        cout<<char(0xcd);
    cout<<char(0xbc);
}

void Draw_Main_Windows(HANDLE hOut,HWND hWnd)
{
    Draw_Normal_Box(hOut);

    COORD pos={59,2};
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"   "<<ZITI_1<<ZITI_1;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"   "<<ZITI_1<<ZITI_1;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"   "<<ZITI_1<<ZITI_1;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"   "<<ZITI_1<<ZITI_1;

    pos={68,2};
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_1<<ZITI_1<<"     "<<ZITI_1<<ZITI_1;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_1<<ZITI_1<<"     "<<ZITI_1<<ZITI_1;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_1<<ZITI_1<<"     "<<ZITI_1<<ZITI_1;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_1<<ZITI_1<<"     "<<ZITI_1<<ZITI_1;

    pos={78,2};
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_1<<ZITI_1;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_1<<ZITI_1;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1<<ZITI_1;





    pos={39,7};
    SetConsoleCursorPosition(hOut,pos);
    WORD att=FOREGROUND_RED|FOREGROUND_INTENSITY;//change the computer home color
    GetConsoleScreenBufferInfo(hOut,&bInfo);
    WORD now_att=bInfo.wAttributes;
    SetConsoleTextAttribute(hOut,att);
    cout<<"|||       |||       |||      |||||||||        |||||||||||||||||";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"|||     |||||||     |||     |||     |||       ||||          |||";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"|||     |||||||     |||    |||       |||      ||||          |||";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"|||     ||| |||     |||   |||||||||||||||     |||||||||||||||||";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<" |||   |||   |||   |||   |||||||||||||||||    ||||||||||       ";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"  |||  |||   |||  |||   |||             |||   ||||    ||||     ";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"   ||||||     ||||||   |||               |||  ||||      ||||   ";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"    ||||       ||||   |||                 ||| ||||         ||||";
    SetConsoleTextAttribute(hOut,now_att);

    pos={67,15};
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_2<<ZITI_2<<ZITI_2<<ZITI_2<<ZITI_2<<" "<<ZITI_3<<ZITI_3<<ZITI_3<<ZITI_3<<ZITI_3;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_2<<"   "<<ZITI_2<<" "<<ZITI_3;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_2<<"   "<<ZITI_2<<" "<<ZITI_3<<ZITI_3<<ZITI_3<<ZITI_3;
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<ZITI_2<<ZITI_2<<ZITI_2<<ZITI_2<<ZITI_2<<" "<<ZITI_3;
    pos.Y++;

    pos={21,19};
    SetConsoleCursorPosition(hOut,pos);

    att=FOREGROUND_RED|FOREGROUND_INTENSITY;
    SetConsoleTextAttribute(hOut,att);
    cout<<"||||||        |||  |||         |||  |||||||||||||||  ||||||||||||||  ||||||||||||  |||||||||||||";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"||| |||       |||  |||         |||  |||||||||||||||  |||        |||  |||           |||       |||";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"|||  |||      |||  |||         |||  |||  |||||  |||  |||        |||  |||           |||       |||";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"|||   |||     |||  |||         |||  |||  |||||  |||  |||        |||  |||           |||       |||";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"|||    |||    |||  |||         |||  |||  |||||  |||  ||||||||||||||  ||||||||||||  |||||||||||||";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"|||     |||   |||  |||         |||  |||  |||||  |||  |||        |||  |||           |||   |||";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"|||      |||  |||  |||         |||  |||  |||||  |||  |||        |||  |||           |||    |||";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"|||       ||| |||  |||||||||||||||  |||  |||||  |||  |||        |||  |||           |||     |||";
    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"|||        ||||||  |||||||||||||||  |||  |||||  |||  ||||||||||||||  ||||||||||||  |||       |||";
    SetConsoleTextAttribute(hOut,now_att);

    pos={MAIN_WINDOW_SELECT_POS_X_1,MAIN_WINDOW_SELECT_POS_Y_1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xb3)<<"     VISIT CARD BOX     "<<char(0xb3);


    pos={MAIN_WINDOW_SELECT_POS_X_1,MAIN_WINDOW_SELECT_POS_Y_1-1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xda);
    for(unsigned short n=0;n<24;n++)
        cout<<char(0xc4);
    cout<<char(0xbf);
    pos={MAIN_WINDOW_SELECT_POS_X_1,MAIN_WINDOW_SELECT_POS_Y_1+1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xc0);
    for(unsigned short n=0;n<24;n++)
        cout<<char(0xc4);
    cout<<char(0xd9);


    pos={MAIN_WINDOW_SELECT_POS_X_2,MAIN_WINDOW_SELECT_POS_Y_2};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xb3)<<"    PLAY FREEDOM MODE   "<<char(0xb3);

    pos={MAIN_WINDOW_SELECT_POS_X_2,MAIN_WINDOW_SELECT_POS_Y_2-1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xda);
    for(unsigned short n=0;n<24;n++)
        cout<<char(0xc4);
    cout<<char(0xbf);
    pos={MAIN_WINDOW_SELECT_POS_X_2,MAIN_WINDOW_SELECT_POS_Y_2+1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xc0);
    for(unsigned short n=0;n<24;n++)
        cout<<char(0xc4);
    cout<<char(0xd9);


    pos={MAIN_WINDOW_SELECT_POS_X_3,MAIN_WINDOW_SELECT_POS_Y_3};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xb3)<<"    PLAY STORY MODE     "<<char(0xb3);

    pos={MAIN_WINDOW_SELECT_POS_X_3,MAIN_WINDOW_SELECT_POS_Y_3-1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xda);
    for(unsigned short n=0;n<24;n++)
        cout<<char(0xc4);
    cout<<char(0xbf);
    pos={MAIN_WINDOW_SELECT_POS_X_3,MAIN_WINDOW_SELECT_POS_Y_3+1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xc0);
    for(unsigned short n=0;n<24;n++)
        cout<<char(0xc4);
    cout<<char(0xd9);



    pos={MAIN_WINDOW_SELECT_POS_X_4,MAIN_WINDOW_SELECT_POS_Y_4};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xb3)<<"    LOOK NUMBER STORY   "<<char(0xb3);
    pos={MAIN_WINDOW_SELECT_POS_X_4,MAIN_WINDOW_SELECT_POS_Y_4-1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xda);
    for(unsigned short n=0;n<24;n++)
        cout<<char(0xc4);
    cout<<char(0xbf);
    pos={MAIN_WINDOW_SELECT_POS_X_4,MAIN_WINDOW_SELECT_POS_Y_4+1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xc0);
    for(unsigned short n=0;n<24;n++)
        cout<<char(0xc4);
    cout<<char(0xd9);

    pos={MAIN_WINDOW_SELECT_POS_X_5,MAIN_WINDOW_SELECT_POS_Y_5};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xb3)<<"        EXIT GAME       "<<char(0xb3);
    pos={MAIN_WINDOW_SELECT_POS_X_5,MAIN_WINDOW_SELECT_POS_Y_5-1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xda);
    for(unsigned short n=0;n<24;n++)
        cout<<char(0xc4);
    cout<<char(0xbf);
    pos={MAIN_WINDOW_SELECT_POS_X_5,MAIN_WINDOW_SELECT_POS_Y_5+1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xc0);
    for(unsigned short n=0;n<24;n++)
        cout<<char(0xc4);
    cout<<char(0xd9);

    pos={110,39};
    SetConsoleCursorPosition(hOut,pos);
    cout<<"Produced By : Edward && CROW";
}

void Draw_Display_Window(HANDLE hOut)
{
    Draw_Normal_Box(hOut);

    COORD pos={85,35};
    SetConsoleCursorPosition(hOut,pos);
    cout<<"Choice a card and press enter for read its story......";
}

void Draw_Play_Freedom_Mode_Windows(HANDLE hOut,HWND hWnd)
{
    Draw_Normal_Box(hOut);


    COORD pos={MAP_POS_X+MAP_WIDTH+8,1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xcb);

    for(unsigned short n=0;n<WINDOW_SIZE_Y-12;n++)
    {
        pos.Y++;
        SetConsoleCursorPosition(hOut,pos);
        cout<<char(0xba);
    }

    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xca);

    pos={MAP_POS_X-8,1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xcb);

    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xba)<<"             The Number Battlefield";

    for(unsigned short n=1;n<WINDOW_SIZE_Y-12;n++)
    {
        pos.Y++;
        SetConsoleCursorPosition(hOut,pos);
        cout<<char(0xba);
    }

    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xca);



    pos={SELECTAREA_POS_X-5,1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xcb);

    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xba)<<"      The Number Soldier";

    for(unsigned short n=1;n<WINDOW_SIZE_Y-12;n++)
    {
        pos.Y++;
        SetConsoleCursorPosition(hOut,pos);
        cout<<char(0xba);
    }

    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xca);


    pos={MAP_POS_X-10,1};
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xcb);

    for(unsigned short n=0;n<WINDOW_SIZE_Y-12;n++)
    {
        pos.Y++;
        SetConsoleCursorPosition(hOut,pos);
        cout<<char(0xba);
    }

    pos.Y++;
    SetConsoleCursorPosition(hOut,pos);
    cout<<char(0xca);

    pos={TIP_AREA_POS_X,TIP_AREA_POS_Y-3};
    SetConsoleCursorPosition(hOut,pos);
    cout<<"     The Number Saying";

}

void Draw_Play_Story_Mode_Window(unsigned short n,HANDLE hOut)
{
    Draw_Normal_Box(hOut);

    for(unsigned short d=0;d<3;d++)
        for(unsigned short i=0;i<4;i++)
        {
            COORD pos={DISPLAY_FIRST_LEVEL_POS_X+i*DISPLAY_LEVEL_WIDTH,DISPLAY_FIRST_LEVEL_POS_Y+d*DISPLAY_LEVEL_HIGH};
            if(n<4*d+i)
            {
                Draw_Lock_Story(pos,hOut);
            }
            else
            {
                Draw_UnLock_Story(pos,4*d+i,hOut);
            }
        }

    for(unsigned short d=0;d<2;d++)
    {
        COORD pos={DISPLAY_THIRTEENTH_LEVEL_POS_X+d*DISPLAY_LEVEL_WIDTH,DISPLAY_THIRTEENTH_LEVEL_POS_Y};
        if(n<12+d)
        {
            Draw_Lock_Story(pos,hOut);
        }
        else
        {
            Draw_UnLock_Story(pos,12+d,hOut);
        }
    }

    COORD pos={75,30};
    SetConsoleCursorPosition(hOut,pos);
    cout<<"Press Left or Right key for selecting a task...... ";
    pos.Y+=2;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"Press Enter key for challenging......";

}

/**
#define DISPLAY_LEVEL_HIGH 15
#define DISPLAY_LEVEL_WIDTH 15
*/
void Draw_Lock_Story(COORD pos,HANDLE hOut)
{
    COORD temp_pos;
    temp_pos.X=pos.X-1;
    temp_pos.Y=pos.Y-1;
    SetConsoleCursorPosition(hOut,temp_pos);

    cout<<char(0xda);
    for(unsigned short n=0;n<DISPLAY_LEVEL_WIDTH-2;n++)
        cout<<char(0xc4);
    cout<<char(0xbf);

    for(unsigned short k=0;k<DISPLAY_LEVEL_HIGH-2;k++)
    {
        temp_pos.X=pos.X-1;
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<char(0xb3);
        temp_pos.X+=DISPLAY_LEVEL_WIDTH-1;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<char(0xb3);
    }

    temp_pos.X=pos.X-1;
    temp_pos.Y=pos.Y+DISPLAY_LEVEL_HIGH-2;
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<char(0xc0);
    for(unsigned short n=0;n<DISPLAY_LEVEL_WIDTH-2;n++)
        cout<<char(0xc4);
    cout<<char(0xd9);




    temp_pos.X=pos.X+3;
    temp_pos.Y=pos.Y+1;
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<"   \\\\\\\\      ////";
    temp_pos.Y++;
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<"     \\\\\\\\  ////";
    temp_pos.Y++;
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<"      * LOCK *";
    temp_pos.Y++;
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<"     ////  \\\\\\\\";
    temp_pos.Y++;
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<"   ////      \\\\\\\\";

}

void Draw_UnLock_Story(COORD pos,unsigned short n,HANDLE hOut)
{
    COORD temp_pos;
    temp_pos.X=pos.X-1;
    temp_pos.Y=pos.Y-1;
    SetConsoleCursorPosition(hOut,temp_pos);

    cout<<char(0xda);
    for(unsigned short n=0;n<DISPLAY_LEVEL_WIDTH-2;n++)
        cout<<char(0xc4);
    cout<<char(0xbf);

    for(unsigned short k=0;k<DISPLAY_LEVEL_HIGH-2;k++)
    {
        temp_pos.X=pos.X-1;
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<char(0xb3);
        temp_pos.X+=DISPLAY_LEVEL_WIDTH-1;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<char(0xb3);
    }

    temp_pos.X=pos.X-1;
    temp_pos.Y=pos.Y+DISPLAY_LEVEL_HIGH-2;
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<char(0xc0);
    for(unsigned short n=0;n<DISPLAY_LEVEL_WIDTH-2;n++)
        cout<<char(0xc4);
    cout<<char(0xd9);

    SetConsoleCursorPosition(hOut,pos);
    switch(n)
    {
    case 0:
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        <*Prologue*> ";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" ++++++++++++++++++++++++";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"         New King!";
        break;
    case 1:
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        <Chapter 1> ";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" ++++++++++++++++++++++++";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"      Unquiet Number";
        break;
    case 2:
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        <Chapter 2> ";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" ++++++++++++++++++++++++";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        Train By S";
        break;
    case 3:
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        <Chapter 3> ";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" ++++++++++++++++++++++++";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        King Entrust";
        break;
    case 4:
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        <Chapter 4> ";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" ++++++++++++++++++++++++";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"      More Crazy Number?";
        break;
    case 5:
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        <Chapter 5> ";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" ++++++++++++++++++++++++";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"      Complete the Task";
        break;
    case 6:
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        <Chapter 6> ";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" ++++++++++++++++++++++++";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"  Congratulations from E";
        break;
    case 7:
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        <Chapter 7> ";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" ++++++++++++++++++++++++";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        The Intruder";
        break;
    case 8:
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        <Chapter 8> ";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" ++++++++++++++++++++++++";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"       A Little Secret";
        break;
    case 9:
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        <Chapter 9> ";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" ++++++++++++++++++++++++";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"      Complete the Task";
        break;
    case 10:
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        <Chapter 10> ";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" ++++++++++++++++++++++++";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        King Entrust";
        break;
    case 11:
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        <Chapter 11> ";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" ++++++++++++++++++++++++";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"       Search for Truth";
        break;
    case 12:
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        <Chapter 12> ";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" ++++++++++++++++++++++++";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"            0";
        break;
    case 13:
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"        < Ending > ";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" ++++++++++++++++++++++++";
        pos.Y+=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"     Real Number World";
        break;
    }
}


void Draw_Tips_about_Freedom_Mode_Game(HANDLE hOut)
{
    Draw_Normal_Box(hOut);

    COORD pos={10,10};
    SetConsoleCursorPosition(hOut,pos);

    cout<<"Game Tips:";
    pos.Y+=2;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"1.Number war starts!Please select number in the select area and put it in the battlefield.";
    pos.Y+=2;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"2.Your opponent is cunning!His number is dangerous.";
    pos.Y+=2;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"3.Find the clever way that you can attack your enemy.";
    pos.Y+=2;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"4.Protect your home from attacking!";

    pos.Y+=2;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"5.Your number power is valuable.It develops according to the time.";

    pos.Y+=2;
    SetConsoleCursorPosition(hOut,pos);
    cout<<"Please enter any key to continue.........";
}

void Draw_Freedom_Mode_Map(fstream &file_battlefield,HANDLE hOut)
{
    COORD begin_pos={MAP_POS_X,MAP_POS_Y};
    SetConsoleCursorPosition(hOut,begin_pos);

    char temp_map[MAP_HIGH][MAP_WIDTH];

    for(unsigned short n=0;n<MAP_HIGH;n++)
    {
        for(unsigned short k=0;k<MAP_WIDTH;k++)
            temp_map[n][k]=file_battlefield.get();
        file_battlefield.get();
    }

    for(unsigned short n=0;n<MAP_HIGH;n++)
    {
        for(unsigned short k=0;k<MAP_WIDTH;k++)
            cout<<temp_map[n][k];
        begin_pos.Y++;
        SetConsoleCursorPosition(hOut,begin_pos);
    }
}

void Draw_Story_Mode_Map(fstream &file_battlefield,HANDLE hOut)
//to be finished
{
    COORD begin_pos={MAP_POS_X,MAP_POS_Y};
    SetConsoleCursorPosition(hOut,begin_pos);

    char temp_map[MAP_HIGH][MAP_WIDTH];

    for(unsigned short n=0;n<MAP_HIGH;n++)
    {
        for(unsigned short k=0;k<MAP_WIDTH;k++)
            temp_map[n][k]=file_battlefield.get();
        file_battlefield.get();
    }

    for(unsigned short n=0;n<MAP_HIGH;n++)
    {
        for(unsigned short k=0;k<MAP_WIDTH;k++)
            cout<<temp_map[n][k];
        begin_pos.Y++;
        SetConsoleCursorPosition(hOut,begin_pos);
    }
}

void Draw_Statue(COORD now_pos,Statue player_statue,HANDLE hOut)
{
    COORD temp_pos={player_statue.Return_pos_in_screen().X,player_statue.Return_pos_in_screen().Y};
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<"                                        ";
    SetConsoleCursorPosition(hOut,temp_pos);

    cout<<"NUMBER POWER:";

    switch(player_statue.Return_now_power())
    {
    case 10:
        cout<<"$ ";
    case 9:
        cout<<"$ ";
    case 8:
        cout<<"$ ";
    case 7:
        cout<<"$ ";
    case 6:
        cout<<"$ ";
    case 5:
        cout<<"$ ";
    case 4:
        cout<<"$ ";
    case 3:
        cout<<"$ ";
    case 2:
        cout<<"$ ";
    case 1:
        cout<<"$ ";
    case 0:
        break;
    }

    if(player_statue.Return_now_power()==10)
        cout<<"MAX";
    SetConsoleCursorPosition(hOut,now_pos);
}

bool Draw_Freedom_Mode_Game_Over_Windows(bool win_player_or_computer,HANDLE hOut)
{
    //true mean continue play
    //false mean back to main window
    if(win_player_or_computer==COMPUTER)
    {
        if(MessageBox(NULL,"Do you want to retry?", "You Lose!",MB_YESNO)==IDYES)
            return true;
        else
            return false;
    }
    else
    {
        if(MessageBox(NULL,"Do you want to continue next game?", "You Win!",MB_YESNO)==IDYES)
            return true;
        else
            return false;
    }
}

void Draw_one_Card_Introduce(Card temp_card,HANDLE hOut)
{
    COORD pos={DISPLAY_ONE_CARD_STORY_POS_X-1,DISPLAY_ONE_CARD_STORY_POS_Y-1};
    SetConsoleCursorPosition(hOut,pos);

    cout<<'*';
    for(unsigned short n=1;n<90;n++)
        cout<<'-';
    cout<<'*';

    for(unsigned short k=0;k<15;k++)
    {
        pos={DISPLAY_ONE_CARD_STORY_POS_X-1,k+DISPLAY_ONE_CARD_STORY_POS_Y};
        SetConsoleCursorPosition(hOut,pos);
        cout<<'|';
        pos={DISPLAY_ONE_CARD_STORY_POS_X+89,k+DISPLAY_ONE_CARD_STORY_POS_Y};
        SetConsoleCursorPosition(hOut,pos);
        cout<<'|';
    }

    pos={DISPLAY_ONE_CARD_STORY_POS_X-1,DISPLAY_ONE_CARD_STORY_POS_Y+15};
    SetConsoleCursorPosition(hOut,pos);
    cout<<'*';
    for(unsigned short n=1;n<90;n++)
        cout<<'-';
    cout<<'*';



    pos={DISPLAY_ONE_CARD_STORY_POS_X,DISPLAY_ONE_CARD_STORY_POS_Y+1};
    SetConsoleCursorPosition(hOut,pos);

    cout<<" Card Name:"<<temp_card.Return_card_name()<<" ";
    switch (temp_card.Return_card_name())
    {
    case '1':
        cout<<" like rocket";
        break;
    case '2':
        cout<<" like rabbit";
        break;
    case '3':
        cout<<" like flash";
        break;
    case '4':
        cout<<" like son of death";
        break;
    case '5':
        cout<<" like protector";
        break;
    case '6':
        cout<<" like gambler";
        break;
    case '7':
        cout<<" like knight";
        break;
    case '8':
        cout<<" like businessman";
        break;
    case '9':
        cout<<" like stone guardian";
        break;
    }

    pos.Y+=2;
    SetConsoleCursorPosition(hOut,pos);

    switch(temp_card.Return_card_name())
    {
    case '1':
        cout<<" -->The Story of Number 1/One :";
        pos.Y+=2;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" -->1 is the fleet-footed runner, they can gain incredible rate with the help of wind.";
        break;
    case '2':
        cout<<" -->The Story of Number 2/Two :";
        pos.Y+=2;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" -->Though 2 always complains that their legs are too bulk, ";
        pos.Y+=2;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" -->they have the most striking jumping ability above all numbers.";
        break;
    case '3':
        cout<<" -->The Story of Number 3/Three :";
        pos.Y+=2;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" -->3 has the ability to dissociate themselves into particles temporarily, ";
        pos.Y+=2;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" -->which enable them to escape many dangers";
        break;
    case '4':
        cout<<" -->The Story of Number 4/Four :";
        pos.Y+=2;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" -->4 is called the chilren of the Death, the one who kills them would be punished.";
        break;
    case '5':
        cout<<" -->The Story of Number 5/Five :";
        pos.Y+=2;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" -->5 is the representative of balance, most  of \"5\" are even-tempered.";
        break;
    case '6':
        cout<<" -->The Story of Number 6/Six :";
        pos.Y+=2;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" -->6 has peculiar internal structure, sometimes will change into another number";
        break;
    case '7':
        cout<<" -->The Story of Number 7/Seven :";
        pos.Y+=2;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" -->As a grand knight, 7 has outstanding vision and unyielding will";
        break;
    case '8':
        cout<<" -->The Story of Number 8/Eight :";
        pos.Y+=2;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" -->8 has outstanding business acumen and ";
        pos.Y+=2;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" -->have a in-depth knowledge with every number race 's psychology";
        break;
    case '9':
        cout<<" -->The Story of Number 9/Nine :";
        pos.Y+=2;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" -->9 is born with a pair of armor, ";
         pos.Y+=2;
        SetConsoleCursorPosition(hOut,pos);
        cout<<" -->but also resulting in difficult to move because of too heavy";
        break;
    }
}

void Draw_Tips_in_Select_Area(char card_name)
{
    switch(card_name)
    {
    case '1':
        cout<<" Tips:1 is a fast man!                  ";
        break;
    case '2':
        cout<<" Tips:I'm 2!Let us jump!                ";
        break;
    case '3':
        cout<<" Tips:Do you know Flash?I'm the flash!  ";
        break;
    case '4':
        cout<<" Tips:4 is son of death.Now he comes!   ";
        break;
    case '5':
        cout<<" Tips:Use 5 to protect your home!       ";
        break;
    case '6':
        cout<<" Tips:Do you want to believe you luck?  ";
        break;
    case '7':
        cout<<" Tips:7 is a knight,knight is 7!        ";
        break;
    case '8':
        cout<<" Tips:Nothing can't be bribed by money! ";
        break;
    case '9':
        cout<<" Tips:9 is the largest stone.           ";
        break;
    }
}

void Draw_Number_Story(HANDLE hOut)
{
    system("CLS");
    Draw_Normal_Box(hOut);

    COORD pos={75,35};
    SetConsoleCursorPosition(hOut,pos);
    cout<<"Press Left or Right key to choice the chapter to read......";

    int n=-1;

    fstream file_progress;
    file_progress.open("StoryProgress.txt");
    if(!file_progress.is_open())
    {
        MessageBox(NULL,"Lack the important date file!", "Error", MB_OK | MB_ICONEXCLAMATION);
        exit(1);
    }
    unsigned short progress;
    file_progress>>progress;
    file_progress.close();

    Draw_one_Story(n,progress,hOut);

    while(1)
    {
        if(_kbhit())
        {
            int temp_ope = Get_and_Respone_Key_Event_in_Number_Story(hOut);//in Display_Card_Message_function.cpp
            if(temp_ope==TO_LEFT)
            {
                if(n==-1)
                    n=13;
                else
                    n--;
                Draw_one_Story(n,progress,hOut);
            }
            if(temp_ope==TO_RIGHT)
            {
                if(n==13)
                    n=-1;
                else
                    n++;
                Draw_one_Story(n,progress,hOut);
            }
            if(temp_ope==VK_ESCAPE)
                return;
        }
    }
}

void Draw_one_Story(int n,unsigned short progress,HANDLE hOut)
{
    COORD pos={20,7};
    SetConsoleCursorPosition(hOut,pos);

    COORD temp_pos;
    temp_pos.X=pos.X;
    temp_pos.Y=pos.Y;


    if(n==-1)
    {
        cout<<"                                         <World View>                                                     ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"-->   There are ten kind of number in the peaceful Number Kingdom.Every number is able to do different    ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"      job according to its intention,so that the kingdom has developed since 2700 years ago.              ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"-->   Every 100 years Number Kingdom will hold an election to select a number as the Kingdom Mentor,who   ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"      shoulders the responsibilities of maintaining a balance of \"Counting field\",and the one selected  ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"      not only need to lead his people to guard against their evil neighbors, the Letter Kingdom, in case ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"      to be assimilated secretly,but also try their best to fight against the human mathematician,who try ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"      to steal their kingdom's secrets.                                                                   ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"-->   What's more, the most outstanding mentor will be regarded as their King, which is an honor for      ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"      every number.                                                                                       ";
    }
    else if(n==0)
    {
        cout<<"                                         <*Prologue*>                                                     ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                           New King!                                                      ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"-->  In May 55th, 2016 of the Number Calendar, the term of the most courageous of \"9\" who is the King   ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"     ended, while the new period, which is 0's turn to be the Kingdom Mentor.                             ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"-->  They chose Z, the most intelligent member of Number 0, to be the King. Then a new story began...     ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";

    }
    //temp_pos.Y++;
    //SetConsoleCursorPosition(hOut,temp_pos);
    //cout<<"                                                                                                          ";
    //19 hang
    else if(n>progress)
    {
        cout<<"                                        < Chapter ???>                                                    ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                           ?????????                                                      ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"-->  ??????????????                                                                                       ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
        temp_pos.Y++;
        SetConsoleCursorPosition(hOut,temp_pos);
        cout<<"                                                                                                          ";
    }
    else if(n<=progress)
    {
        switch(n)
        {
        case 1:
        {
            cout<<"                                         < Chapter 1 >                                                     ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                        Troubled Number                                                   ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  Because of the inauguration ceremony of the new King Z, many numbers came to the capital of the      ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     Number Kingdom and you are no exception. Unexpectedly, there are some trouble when you are sightsee  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     -ing the city.                                                                                       ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  After kicking their ass, who are rude and brutal, your ability to take bold, decisive action had     ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     drawn the attention of S, who is a member of Number 7 and is the General appointed by the new King,  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     so that he invited you to go to the Palace. There is no doubt that you accepted his invitation with  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     pleasure and decide to see the new King by this chance.                                              ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            break;
        }
        case 2:
        {
            cout<<"                                         < Chapter 2 >                                                     ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                       Join in the Troop                                                  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  The magnificent Palace amazed you and instead of visiting the King, you was brought to the Soldier   ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     Playground. S explained that the King is recruiting brave warriors to form a new army that against   ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     foreign enemy and he thought you have real potential so that you can join in the troops after an     ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     easy test. After hearing his words, you had great interest in it.                                    ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  Though test is not easy, you had finished faultlessly, which make you win many soldier's admirations.";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     On account of your excellent behavior, S decided to take you to see Z.                               ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            break;
        }
        case 3:
        {
            cout<<"                                         < Chapter 3 >                                                     ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                          King's Entrust                                                  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  You came to reception room respectfully and saw Z, who were much more emaciated than you thought,    ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     understanding why little of 0 can be a soldier. Rather than getting angry, Z didn¡¯t care about your  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     contempt for his physique and talk with you politely, which make you feel that he was more gracious  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     than usual one. After chatting for a while, Z asked his attendants to leave and talked with you one  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     on one, hoping that you can join in the army.                                                        ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  On account of your excellent behavior, S decided to take you to see Z.                               ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     He said, there were an increasing amount of those abnormal numbers since the day he became the new   ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     King, just like the rude number you had met in the bazaar. On account that S was too busy to manage  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     the troops and in the meanwhile, you were an ordinary number so that you can make a undercover       ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     investigation to figure out this case.                                                               ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  You accepted his entrust with hesitation and surprisingly you were attacked by a mysterious character";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     again when you were leaving.                                                                         ";
            break;
        }
        case 4:
        {
            cout<<"                                         < Chapter 4 >                                                     ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                       Join in the Troop                                                  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  You defeated the mysterious character resourcefully and you picked up something that is similar  with";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     the jewelry that usually used by Letter, so the Letter Kingdom became your suspect.                  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  In the following days, you got information that more and more numbers were getting much more         ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     aggressive and the King request you to help Army arrest these numbers.                               ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  When you succeeded in stabilizing the situation in city, you found that the Letter Kingdom were more ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"      and more suspect. As expected, S wanted you to arrest the spy of the Letter Kingdom and you accepted";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"      with a firm hand.                                                                                   ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            break;
        }
        case 5:
        {
            cout<<"                                         < Chapter 5 >                                                    ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                       Complete the Task                                                  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  Congratulations! You succeeded in catching the spy and sending him to S under guard and felt grateful";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     that you can make contributions to the country though you were a ordinary number. S conveyed your    ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     thank to Z and told you that Z expected you to come to a party of leaders of number as a bright      ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"     talent held by hi.                                                                                   ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  In the party, you were invited to describe how you found Letter’s conspiracy, winning the admiration ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"      of all leaders. At the end of the party, Z suggested every county to form a sthonger Army to resist ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"      the enemy and every leader was agreed with it except the silent F(Number 5) and E(Number 8) who was ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"      negotiating with the Letter King.                                                                   ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->   At the end of the party, Z rewarded you with prize and honor and you went back home carefree.       ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            break;
        }
        case 6:
        {
            cout<<"                                         < Chapter 6 >                                                    ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                      Congratulations from E                                              ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  To be finished                                                                                       ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            break;
        }
        case 7:
        {
            cout<<"                                         < Chapter 7 >                                                    ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                          The Intruder                                                    ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  To be finished                                                                                       ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            break;
        }
        case 8:
            {
            cout<<"                                         < Chapter 8 >                                                    ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                         A Little Secret                                                  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  To be finished                                                                                       ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            break;
        }
        case 9:
        {
            cout<<"                                         < Chapter 9 >                                                    ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                         A Little Secret                                                  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  To be finished                                                                                       ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            break;
        }
        case 10:
        {
            cout<<"                                         < Chapter 10>                                                    ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                           Train again?                                                   ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  To be finished                                                                                       ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            break;
        }
        case 11:
        {
            cout<<"                                         < Chapter 11>                                                    ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                        Search for Truth                                                  ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  To be finished                                                                                       ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            break;
        }
            break;
        case 12:
        {
            cout<<"                                         < Chapter 12>                                                    ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                           Z's story                                                      ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  To be finished                                                                                       ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            break;
        }
        case 13:
            {
            cout<<"                                         <   Ending  >                                                    ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                      Number World,Number Rule                                            ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"-->  To be finished                                                                                       ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            temp_pos.Y++;
            SetConsoleCursorPosition(hOut,temp_pos);
            cout<<"                                                                                                          ";
            break;
        }
        }
    }

    temp_pos={6,40};
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<n+2<<'/'<<15<<' ';
}


