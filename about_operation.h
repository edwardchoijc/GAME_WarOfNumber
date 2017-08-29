#ifndef ABOUT_OPERATION_H_INCLUDED
#define ABOUT_OPERATION_H_INCLUDED

#include "const_Value.h"
#include "about_class.h"
#include "about_Draw.h"

using namespace std;

bool Main_Windows(HANDLE,HWND);
/**********************************
***********************************

about_Main_Window function

***********************************
**********************************/
void Display_Tips_about_Freedom_Model_Game(HANDLE);

bool Play_Freedom_Mode_Game(fstream &,vector<Card> &,HANDLE);

bool Play_Story_Mode_Game(vector<Card>&,HANDLE);

void Display_Card_Message(vector<Card> &,HANDLE);

void Display_Number_Story(vector<Card> &,HANDLE);

bool Exit_Game(HANDLE);

void Load_Card_Message(fstream &,vector<Card> &);

int Get_and_Respone_Key_Event_in_Main_Window(COORD &,HANDLE);
/*******************************
void Play_Freedom_Mode_Game(fstream &,vector<Card> &,HANDLE,HWND);

about_Play_Game function
*******************************/
void Game_Start(Battlefield &,Selectarea *,vector<Card> &,Home &,Home &,Statue *,HANDLE);

bool Gaming(Battlefield &,Selectarea *,vector<Card> &,Home &,Home &,Statue *,HANDLE,bool &);

bool Game_End(bool,HANDLE);

void Map_Refresh(Battlefield &,Home &,Home &,vector<Card_in_fight> &,HANDLE,COORD);

bool Get_and_Respone_Key_Event_in_Play_Freedom_Mode_Game(unsigned short &,COORD &,COORD &,COORD &,HANDLE,Battlefield);

COORD Select_Card(int,HANDLE,COORD &now_pos,Battlefield);

COORD Select_Pos_to_Set_Card(int,HANDLE,COORD &now_pos,COORD &temp_pos_choice_card,Battlefield);

void Change_Card_in_Selectarea(short,vector<Card> &,Selectarea *,HANDLE);

void Set_Card_in_Battlefield(COORD,Card,vector<Card> &,vector<Card_in_fight> &,bool);

void Take_Action(unsigned short,Card_in_fight &,vector<Card_in_fight> &,Battlefield &,Home &,Home &,vector<Card> &,HANDLE);

bool Return_Left_or_Right(Battlefield _map,COORD check_pos);//关于寻路的函数

bool Return_Up_or_Down(Battlefield _map,COORD check_pos);//关于寻路的函数

bool Computer_Strategy(unsigned short ,COORD &,Card &,vector<Card> &,vector<Card_in_fight> &,Battlefield);

bool Computer_Strategy_Judge(vector<Card_in_fight> &,Battlefield);
bool Computer_Strategy_Attack(unsigned short ,COORD &,Card &,vector<Card> &);
bool Computer_Strategy_Defend(unsigned short ,COORD &,Card &,vector<Card> &);

/*******************************
void Play_Story_Mode_Game(fstream &,vector<Card> &,HANDLE,HWND);

about_Play_Story_Mode_Game function
*******************************/

void Play_Story_Mode_Process(unsigned short &,vector<Card> &,HANDLE );

int Get_and_Respone_Key_Event_in_Play_Story_Mode_Progress(COORD &,HANDLE);

void Play_one_Story_Mode_Game(int ,unsigned short &,vector<Card> &,HANDLE);

/*******************************
void Display_Card_Message(vector<Card> &,HANDLE);

about_Display_Card_Message function
*******************************/

void Display_Card_Process(vector<Card> &card,HANDLE hOut);

void Display_One_Card(COORD,vector<Card> &,HANDLE);

int Get_and_Respone_Key_Event_in_Display_Card_Message(COORD &,HANDLE);

int Get_and_Respone_Key_Event_in_Number_Story(HANDLE);


#endif // ABOUT_OPERATION_H_INCLUDED
