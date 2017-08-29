#include "const_Value.h"
#include "about_class.h"
#include "about_operation.h"
#include "about_Draw.h"
#include "about_character.h"
//#include "about_Story_Game.h"

using namespace std;

void Play_Story_Mode_Process(unsigned short &progress,vector<Card> &cards,HANDLE hOut)
{
    Draw_Play_Story_Mode_Window(progress,hOut);

    RECHOICE:;

    COORD choice_pos={DISPLAY_FIRST_LEVEL_POS_X,DISPLAY_FIRST_LEVEL_POS_Y};

    Draw_Cursor_in_Play_Story_Mode_Window(choice_pos,hOut);

    while(1)
    {
        //direct change the choice_pos value and get the key event to temp_ope
        if(_kbhit())
        {
            int temp_ope = Get_and_Respone_Key_Event_in_Play_Story_Mode_Progress(choice_pos,hOut);
            if(temp_ope==VK_RETURN)
            {
                //if(choice_pos.Y!=DISPLAY_THIRTEENTH_LEVEL_POS_Y)
                int a=(choice_pos.X-DISPLAY_FIRST_LEVEL_POS_X)/DISPLAY_LEVEL_WIDTH;
                int b=(choice_pos.Y-DISPLAY_FIRST_LEVEL_POS_Y)/DISPLAY_LEVEL_HIGH;
                int sum=a+4*b;
                if(sum>progress)
                {
                    MessageBox(NULL,"Please finish more level to unlock this game.", "Tip", MB_OK );
                    goto RECHOICE;
                }
                Play_one_Story_Mode_Game(sum,progress,cards,hOut);//sum
                return;
            }
            if(temp_ope==VK_ESCAPE)
                return;
        }
    }
}

int Get_and_Respone_Key_Event_in_Play_Story_Mode_Progress(COORD &choice_pos,HANDLE hOut)
{
    int b=_getch();
    if(b!=VK_ESCAPE&&b!=VK_RETURN&&b==224)
    {
        b=_getch();
        switch(b)
        {
        case LEFT:
            if(choice_pos.X!=DISPLAY_FIRST_LEVEL_POS_X)
                choice_pos.X-=DISPLAY_LEVEL_WIDTH;
            else
            if(choice_pos.X==DISPLAY_FIRST_LEVEL_POS_X&&choice_pos.Y!=DISPLAY_FIRST_LEVEL_POS_Y)
            {
                choice_pos.Y-=DISPLAY_LEVEL_HIGH;
                choice_pos.X=DISPLAY_FIRST_LEVEL_POS_X+3*DISPLAY_LEVEL_WIDTH;
            }
            else
            if(choice_pos.X==DISPLAY_FIRST_LEVEL_POS_X&&choice_pos.Y==DISPLAY_FIRST_LEVEL_POS_Y)
            {
                choice_pos.Y=DISPLAY_THIRTEENTH_LEVEL_POS_Y;
                choice_pos.X=DISPLAY_THIRTEENTH_LEVEL_POS_X+1*DISPLAY_LEVEL_WIDTH;
            }

            Draw_Cursor_in_Play_Story_Mode_Window(choice_pos,hOut);
            SetConsoleCursorPosition(hOut,choice_pos);
            return 0;
        case RIGHT:
            if(choice_pos.X!=DISPLAY_FIRST_LEVEL_POS_X+3*DISPLAY_LEVEL_WIDTH&&choice_pos.Y!=DISPLAY_THIRTEENTH_LEVEL_POS_Y)
                choice_pos.X+=DISPLAY_LEVEL_WIDTH;
            else
            if(choice_pos.X==DISPLAY_FIRST_LEVEL_POS_X&&choice_pos.Y==DISPLAY_THIRTEENTH_LEVEL_POS_Y)
                choice_pos.X+=DISPLAY_LEVEL_WIDTH;
            else
            if(choice_pos.X==DISPLAY_FIRST_LEVEL_POS_X+DISPLAY_LEVEL_WIDTH&&choice_pos.Y==DISPLAY_THIRTEENTH_LEVEL_POS_Y)
            {
                choice_pos.X=DISPLAY_FIRST_CARD_POS_X;
                choice_pos.Y=DISPLAY_FIRST_CARD_POS_Y;
            }
            else
            if(choice_pos.X==DISPLAY_FIRST_LEVEL_POS_X+3*DISPLAY_LEVEL_WIDTH&&choice_pos.Y!=DISPLAY_THIRTEENTH_LEVEL_POS_Y)
            {
                choice_pos.Y+=DISPLAY_LEVEL_HIGH;
                choice_pos.X=DISPLAY_FIRST_LEVEL_POS_X;
            }

            Draw_Cursor_in_Play_Story_Mode_Window(choice_pos,hOut);
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

void Play_one_Story_Mode_Game(int sum,unsigned short &progress,vector<Card> &cards,HANDLE hOut)
{
    switch(sum)
    {
    case 0:
        file_battlefield.open("StoryModeMap0.txt");
        break;
    case 1:
        file_battlefield.open("StoryModeMap1.txt");
        break;
    case 2:
        file_battlefield.open("StoryModeMap2.txt");
        break;
    case 3:
        file_battlefield.open("StoryModeMap3.txt");
        break;
    case 4:
        file_battlefield.open("StoryModeMap4.txt");
        break;
    case 5:
        file_battlefield.open("StoryModeMap5.txt");
        break;
    case 6:
        file_battlefield.open("StoryModeMap6.txt");
        break;
    case 7:
        file_battlefield.open("StoryModeMap7.txt");
        break;
    case 8:
        file_battlefield.open("StoryModeMap8.txt");
        break;
    case 9:
        file_battlefield.open("StoryModeMap9.txt");
        break;
    case 10:
        file_battlefield.open("StoryModeMap10.txt");
        break;
    case 11:
        file_battlefield.open("StoryModeMap11.txt");
        break;
    case 12:
        file_battlefield.open("StoryModeMap12.txt");
        break;
    case 13:
        file_battlefield.open("StoryModeMap13.txt");
        break;
    }
    if(!file_battlefield.is_open())
    {
        MessageBox(NULL,"Lack the important date file!", "Error", MB_OK | MB_ICONEXCLAMATION);
        exit(1);
    }


    Draw_Play_Freedom_Mode_Windows(hOut,hWnd);

    file_battlefield.clear();
    file_battlefield.seekg(0);

    Draw_Story_Mode_Map(file_battlefield,hOut);

    switch(sum)
    {
    case 0:
        if(progress==sum)
            progress++;
        break;
    case 1:
        if(progress==sum)
            progress++;
        break;
    case 2:
        if(progress==sum)
            progress++;
        break;
    case 3:
        if(progress==sum)
            progress++;
        break;
    case 4:
        if(progress==sum)
            progress++;
        break;
    case 5:
        if(progress==sum)
            progress++;
        break;
    case 6:
        if(progress==sum)
            progress++;
        break;
    case 7:
        if(progress==sum)
            progress++;
        break;
    case 8:
        if(progress==sum)
            progress++;
        break;
    case 9:
        if(progress==sum)
            progress++;
        break;
    case 10:
        if(progress==sum)
            progress++;
        break;
    case 11:
        if(progress==sum)
            progress++;
        break;
    case 12:
        if(progress==sum)
            progress++;
        break;
    case 13:
        if(progress==sum)
            progress++;
        break;
    }

}
