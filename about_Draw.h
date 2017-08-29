#ifndef ABOUT_DRAW_H_INCLUDED
#define ABOUT_DRAW_H_INCLUDED

#include "const_Value.h"
#include "about_class.h"
#include "about_operation.h"



void Draw_Main_Windows(HANDLE,HWND);

void Draw_Cursor_in_Main_Window_Select(COORD choice_pos,HANDLE hOut);

void Draw_Cursor_in_Display_Card_Message(COORD choice_pos,HANDLE hOut);

void Draw_Cursor_in_Play_Story_Mode_Window(COORD choice_pos,HANDLE hOut);

void Draw_Normal_Box(HANDLE);

void Draw_Display_Window(HANDLE);

void Draw_Play_Freedom_Mode_Windows(HANDLE,HWND);

void Draw_Play_Story_Mode_Window(unsigned short,HANDLE);

void Draw_Lock_Story(COORD,HANDLE);

void Draw_UnLock_Story(COORD,unsigned short,HANDLE);



void Draw_Tips_about_Freedom_Mode_Game(HANDLE);

void Draw_Freedom_Mode_Map(fstream &,HANDLE);

void Draw_Story_Mode_Map(fstream &,HANDLE);

void Draw_Cursor_in_Select_Area(COORD,Selectarea *,HANDLE);

void Draw_Statue(COORD,Statue,HANDLE);

bool Draw_Freedom_Mode_Game_Over_Windows(bool,HANDLE);

void Draw_Tips_in_Select_Area(char);

void Draw_one_Card_Introduce(Card,HANDLE);

void Draw_Number_Story(HANDLE);

void Draw_one_Story(int,unsigned short,HANDLE);
#endif // ABOUT_DRAW_H_INCLUDED
