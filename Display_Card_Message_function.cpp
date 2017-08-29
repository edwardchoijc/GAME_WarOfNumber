#include "const_Value.h"
#include "about_class.h"
#include "about_operation.h"
#include "about_Draw.h"

using namespace std;

/************************************************
 now format:       X  X  X
                   |  |  |
                   X  X  X
                   |  |  |
                   X  X  X

************************************************/
void Display_Card_Process(vector<Card> &card,HANDLE hOut)
{
    REDISPLAY:;

    Draw_Display_Window(hOut);

    COORD pos={DISPLAY_FIRST_CARD_POS_X,DISPLAY_FIRST_CARD_POS_Y};
    SetConsoleCursorPosition(hOut,pos);

    for(unsigned short n=0;n<3;n++)
    {
        card[n].Display_Message_in_CareBoxshow(hOut);
    }

    pos={DISPLAY_SECOND_CARD_POS_X,DISPLAY_SECOND_CARD_POS_Y};
    SetConsoleCursorPosition(hOut,pos);

    for(unsigned short n=3;n<6;n++)
    {
        card[n].Display_Message_in_CareBoxshow(hOut);
    }

    pos={DISPLAY_THIRD_CARD_POS_X,DISPLAY_THIRD_CARD_POS_Y};
    SetConsoleCursorPosition(hOut,pos);

    for(unsigned short n=6;n<NUMBER_CARD;n++)
    {
        card[n].Display_Message_in_CareBoxshow(hOut);
    }

    COORD choice_pos={DISPLAY_FIRST_CARD_POS_X,DISPLAY_FIRST_CARD_POS_Y};

    Draw_Cursor_in_Display_Card_Message(choice_pos,hOut);//in about_Draw_function.cpp
    SetConsoleCursorPosition(hOut,choice_pos);


    while(1)
    {

        //direct change the choice_pos value and get the key event to temp_ope
        if(_kbhit())
        {
            int temp_ope = Get_and_Respone_Key_Event_in_Display_Card_Message(choice_pos,hOut);
            if(temp_ope==VK_RETURN)
            {
                Display_One_Card(choice_pos,card,hOut);
                goto REDISPLAY;
            }
            if(temp_ope==VK_ESCAPE)
                return;
        }
    }

    //don't care the last cursor position
}

int Get_and_Respone_Key_Event_in_Display_Card_Message(COORD &choice_pos,HANDLE hOut)
{
    int b=_getch();
    if(b!=VK_ESCAPE&&b!=VK_RETURN&&b==224)
    {
        b=_getch();
        switch(b)
        {
        case UP:
            if(choice_pos.Y==DISPLAY_FIRST_CARD_POS_Y)
                choice_pos.Y=DISPLAY_FIRST_CARD_POS_Y+2*DISPLAY_CARD_HIGH;
            else
                choice_pos.Y-=DISPLAY_CARD_HIGH;
            Draw_Cursor_in_Display_Card_Message(choice_pos,hOut);//in about_Draw_function.cpp
            SetConsoleCursorPosition(hOut,choice_pos);
            return 0;
        case DOWN:
            if(choice_pos.Y==DISPLAY_FIRST_CARD_POS_Y+2*DISPLAY_CARD_HIGH)
                choice_pos.Y=DISPLAY_FIRST_CARD_POS_Y;
            else
                choice_pos.Y+=DISPLAY_CARD_HIGH;
            Draw_Cursor_in_Display_Card_Message(choice_pos,hOut);//in about_Draw_function.cpp
            SetConsoleCursorPosition(hOut,choice_pos);
            return 0;
        case LEFT:
            if(choice_pos.X==DISPLAY_FIRST_CARD_POS_X)
                choice_pos.X=DISPLAY_THIRD_CARD_POS_X;
            else
                choice_pos.X-=DISPLAY_CARD_WIDTH;
            Draw_Cursor_in_Display_Card_Message(choice_pos,hOut);//in about_Draw_function.cpp
            SetConsoleCursorPosition(hOut,choice_pos);
            return 0;
        case RIGHT:
            if(choice_pos.X==DISPLAY_THIRD_CARD_POS_X)
                choice_pos.X=DISPLAY_FIRST_CARD_POS_X;
            else
                choice_pos.X+=DISPLAY_CARD_WIDTH;
            Draw_Cursor_in_Display_Card_Message(choice_pos,hOut);//in about_Draw_function.cpp
            SetConsoleCursorPosition(hOut,choice_pos);
            return 0;
        }
    }
    if(b==VK_RETURN)
    {
        return VK_RETURN;
    }
    if(b==VK_ESCAPE)
    {
        return VK_ESCAPE;
    }
}

void Display_One_Card(COORD choice_pos,vector<Card> &card,HANDLE hOut)
{
    Draw_Display_Window(hOut);

    int n=0;

    for(unsigned short a=0;a<3;a++)
        for(unsigned short b=0;b<3;b++)
    {
        if(choice_pos.X==DISPLAY_FIRST_CARD_POS_X+a*DISPLAY_CARD_WIDTH
         &&choice_pos.Y==DISPLAY_FIRST_CARD_POS_Y+b*DISPLAY_CARD_HIGH)
            n=a*3+b;
    }

    Draw_one_Card_Introduce(card[n],hOut);

    //the tips position depend on the effect
    COORD pos={80,35};
    SetConsoleCursorPosition(hOut,pos);
    cout<<"                    Please press any key to back......";

    while(1)
    {
        if(_kbhit())
        {
            int b=_getch();
            return;
        }
    }
}

int Get_and_Respone_Key_Event_in_Number_Story(HANDLE hOut)
{
    int b=_getch();
    if(b!=VK_ESCAPE&&b!=VK_RETURN&&b==224)
    {
        b=_getch();
        if(b==LEFT)
            return TO_LEFT;
        if(b==RIGHT)
            return TO_RIGHT;
    }

    if(b==VK_RETURN)
    {
        return VK_RETURN;
    }
    if(b==VK_ESCAPE)
    {
        return VK_ESCAPE;
    }
}
