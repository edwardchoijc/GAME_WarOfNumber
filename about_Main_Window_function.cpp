#include "const_Value.h"
#include "about_Draw.h"
#include "about_class.h"
#include "about_operation.h"

using namespace std;

bool Main_Windows(HANDLE hOut,HWND hWnd)
{
    //relevant card date
    file_cardmessage.open("Card.txt");
    if(!file_cardmessage.is_open())
    {
        MessageBox(NULL,"Lack the important date file!", "Error", MB_OK | MB_ICONEXCLAMATION);
        exit(1);
    }

    //for game running
    srand((unsigned int)time(0));

    //creat Card and load the card message
    vector<Card> card(NUMBER_CARD);

    Load_Card_Message(file_cardmessage,card);


    //draw the main interface
    Draw_Main_Windows(hOut,hWnd);


    //get current cursor position
    GetConsoleScreenBufferInfo(hOut,&bInfo);
    COORD now_pos={bInfo.dwCursorPosition.X,bInfo.dwCursorPosition.Y};


    COORD choice_pos={MAIN_WINDOW_SELECT_POS_X_2,MAIN_WINDOW_SELECT_POS_Y_2};

    Draw_Cursor_in_Main_Window_Select(choice_pos,hOut);
    SetConsoleCursorPosition(hOut,choice_pos);


    //get and respone the key event
    while(1)
    {
        //direct change the choice_pos value and get the key event to temp_ope
        if(_kbhit())
        {
            int temp_ope = Get_and_Respone_Key_Event_in_Main_Window(choice_pos,hOut);
            if(temp_ope!=0)
            {
                switch (temp_ope)
                {
                    case VK_RETURN:
                        goto SURE_CHOICE;
                    case VK_ESCAPE:
                        goto END_CHOICE;
                }
            }
        }
    }

    SURE_CHOICE:;
    if(choice_pos.X==MAIN_WINDOW_SELECT_POS_X_1&&choice_pos.Y==MAIN_WINDOW_SELECT_POS_Y_1)
    {
        Display_Card_Message(card,hOut);
        file_cardmessage.close();
        return true;
    }
    if(choice_pos.X==MAIN_WINDOW_SELECT_POS_X_2&&choice_pos.Y==MAIN_WINDOW_SELECT_POS_Y_2)
    {
        Draw_Tips_about_Freedom_Mode_Game(hOut);
        while(1)
        {
            if(_kbhit())
            {
                _getch();
                break;
            }
        }

        while(1)
        {
            if(Play_Freedom_Mode_Game(file_battlefield,card,hOut)==false)
            {
                file_cardmessage.close();
                return true;
            }
        }
    }
    if(choice_pos.X==MAIN_WINDOW_SELECT_POS_X_3&&choice_pos.Y==MAIN_WINDOW_SELECT_POS_Y_3)
    {
        while(1)
        {
            //true mean continue play
            //false mean back to main window
            if(Play_Story_Mode_Game(card,hOut)==false)
            {
                file_cardmessage.close();
                return true;
            }
        }
    }
    if(choice_pos.X==MAIN_WINDOW_SELECT_POS_X_4&&choice_pos.Y==MAIN_WINDOW_SELECT_POS_Y_4)
    {
        Display_Number_Story(card,hOut);

        file_cardmessage.close();
        return true;
    }
    if(choice_pos.X==MAIN_WINDOW_SELECT_POS_X_5&&choice_pos.Y==MAIN_WINDOW_SELECT_POS_Y_5)
    {
        END_CHOICE:;

        //sure the exit operation
        if(Exit_Game(hOut)==true)
        {
            file_cardmessage.close();
            return false;
        }
        else
        {
            file_cardmessage.close();
            return true;
        }
    }

}

bool Play_Freedom_Mode_Game(fstream &file_battlefield,vector<Card> &card,HANDLE hOut)
{
    file_battlefield.open("FreedomModeMap.txt");
    if(!file_battlefield.is_open())
    {
        MessageBox(NULL,"Lack the important date file!", "Error", MB_OK | MB_ICONEXCLAMATION);
        exit(1);
    }

    Draw_Play_Freedom_Mode_Windows(hOut,hWnd);

    file_battlefield.clear();
    file_battlefield.seekg(0);

    Draw_Freedom_Mode_Map(file_battlefield,hOut);


    Battlefield _map;
    _map.Load_Battlefield(file_battlefield);

    Selectarea select[NUMBER_SELECT_CARD];

    Home player_home(HOME_PLAYER_POS_X,HOME_PLAYER_POS_Y);
    Home computer_home(HOME_COMPUTER_POS_X,HOME_COMPUTER_POS_Y);

    Statue message[2];//record the statue about player and computer

    bool win_player_or_computer=COMPUTER;


    file_battlefield.close();


    Game_Start(_map,select,card,player_home,computer_home,message,hOut);

    if(Gaming(_map,select,card,player_home,computer_home,message,hOut,win_player_or_computer)==false)
        return false;//direct quit to main window


    //true mean continue play
    //false mean back to main window
    if(Game_End(win_player_or_computer,hOut)==true)
        return true;
    else
        return false;

}

void Display_Card_Message(vector<Card> &card,HANDLE hOut)
{
    Display_Card_Process(card,hOut);
}

void Display_Number_Story(vector<Card> &card,HANDLE hOut)
{
    system("CLS");
    Draw_Number_Story(hOut);
}

bool Play_Story_Mode_Game(vector<Card> &cards,HANDLE hOut)
{
    fstream file_progress;
    file_progress.open("StoryProgress.txt");
    if(!file_progress.is_open())
    {
        MessageBox(NULL,"Lack the important date file!", "Error", MB_OK | MB_ICONEXCLAMATION);
        exit(1);
    }
    unsigned short progress;
    file_progress>>progress;

    Play_Story_Mode_Process(progress,cards,hOut);

    //Save the progress
    file_progress.clear();
    file_progress.seekg(0);

    file_progress<<progress;
    file_progress.close();
    return false;
}

bool Exit_Game(HANDLE hOut)
{
    if(MessageBox(NULL,"Do you really want to quit?", "Tip",MB_YESNO)==IDYES)
        return true;
    else
        return false;
}

void Load_Card_Message(fstream &file_cardmessage,vector<Card> &card)
{
    for(int n=0;n<NUMBER_CARD;n++)
        card[n].Set_Card_Date(file_cardmessage);
}

int Get_and_Respone_Key_Event_in_Main_Window(COORD &choice_pos,HANDLE hOut)
{
        int b=_getch();
        if(b!=VK_ESCAPE&&b!=VK_RETURN&&b==224)
        {
            b=_getch();
            switch(b)
            {
            case UP:
                if(choice_pos.Y==MAIN_WINDOW_SELECT_POS_Y_1)
                {
                    choice_pos={MAIN_WINDOW_SELECT_POS_X_5,MAIN_WINDOW_SELECT_POS_Y_5};
                }
                else if(choice_pos.Y==MAIN_WINDOW_SELECT_POS_Y_5)
                {
                    choice_pos={MAIN_WINDOW_SELECT_POS_X_2,MAIN_WINDOW_SELECT_POS_Y_2};
                }
                //SetConsoleCursorPosition(hOut,choice_pos);
                Draw_Cursor_in_Main_Window_Select(choice_pos,hOut);//in about_Draw_function.cpp
                SetConsoleCursorPosition(hOut,choice_pos);
                return 0;
            case DOWN:
                if(choice_pos.Y==MAIN_WINDOW_SELECT_POS_Y_1)
                {
                    choice_pos={MAIN_WINDOW_SELECT_POS_X_5,MAIN_WINDOW_SELECT_POS_Y_5};
                }
                else if(choice_pos.Y==MAIN_WINDOW_SELECT_POS_Y_5)
                {
                    choice_pos={MAIN_WINDOW_SELECT_POS_X_3,MAIN_WINDOW_SELECT_POS_Y_3};
                }
                //SetConsoleCursorPosition(hOut,choice_pos);
                Draw_Cursor_in_Main_Window_Select(choice_pos,hOut);//in about_Draw_function.cpp
                SetConsoleCursorPosition(hOut,choice_pos);
                return 0;
            case LEFT:
                if(choice_pos.Y==MAIN_WINDOW_SELECT_POS_Y_1)
                {
                    if(choice_pos.X==MAIN_WINDOW_SELECT_POS_X_1)
                        choice_pos={MAIN_WINDOW_SELECT_POS_X_4,MAIN_WINDOW_SELECT_POS_Y_4};
                    else
                    if(choice_pos.X==MAIN_WINDOW_SELECT_POS_X_2)
                        choice_pos={MAIN_WINDOW_SELECT_POS_X_1,MAIN_WINDOW_SELECT_POS_Y_1};
                    else
                    if(choice_pos.X==MAIN_WINDOW_SELECT_POS_X_3)
                        choice_pos={MAIN_WINDOW_SELECT_POS_X_2,MAIN_WINDOW_SELECT_POS_Y_2};
                    else
                    if(choice_pos.X==MAIN_WINDOW_SELECT_POS_X_4)
                        choice_pos={MAIN_WINDOW_SELECT_POS_X_3,MAIN_WINDOW_SELECT_POS_Y_3};

                }
                else if(choice_pos.Y==MAIN_WINDOW_SELECT_POS_Y_5)
                    {
                        choice_pos={MAIN_WINDOW_SELECT_POS_X_1,MAIN_WINDOW_SELECT_POS_Y_1};
                    }
                //SetConsoleCursorPosition(hOut,choice_pos);
                Draw_Cursor_in_Main_Window_Select(choice_pos,hOut);//in about_Draw_function.cpp
                SetConsoleCursorPosition(hOut,choice_pos);
                return 0;
            case RIGHT:
                if(choice_pos.Y==MAIN_WINDOW_SELECT_POS_Y_1)
                {
                    if(choice_pos.X==MAIN_WINDOW_SELECT_POS_X_1)
                        choice_pos={MAIN_WINDOW_SELECT_POS_X_2,MAIN_WINDOW_SELECT_POS_Y_2};
                    else
                    if(choice_pos.X==MAIN_WINDOW_SELECT_POS_X_2)
                        choice_pos={MAIN_WINDOW_SELECT_POS_X_3,MAIN_WINDOW_SELECT_POS_Y_3};
                    else
                    if(choice_pos.X==MAIN_WINDOW_SELECT_POS_X_3)
                        choice_pos={MAIN_WINDOW_SELECT_POS_X_4,MAIN_WINDOW_SELECT_POS_Y_4};
                    else
                    if(choice_pos.X==MAIN_WINDOW_SELECT_POS_X_4)
                        choice_pos={MAIN_WINDOW_SELECT_POS_X_1,MAIN_WINDOW_SELECT_POS_Y_1};
                }
                else if(choice_pos.Y==MAIN_WINDOW_SELECT_POS_Y_5)
                {
                    choice_pos={MAIN_WINDOW_SELECT_POS_X_4,MAIN_WINDOW_SELECT_POS_Y_4};
                }
                //SetConsoleCursorPosition(hOut,choice_pos);
                Draw_Cursor_in_Main_Window_Select(choice_pos,hOut);//in about_Draw_function.cpp
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

