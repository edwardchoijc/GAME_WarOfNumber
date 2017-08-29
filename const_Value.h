#ifndef CONST_VALUE_H_INCLUDED
#define CONST_VALUE_H_INCLUDED

#include <string>
#include <ctime>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <tchar.h>
#include <cmath>
#include<vector>

/***********************************************************************************************
Must be recorded
*************************************************************************************************/
#define ZITI_1 char(0xf9)
#define ZITI_2 char(0xae)
#define ZITI_3 char(0xaf)


#define WINDOW_SIZE_X 145
#define WINDOW_SIZE_Y 50

#define MAIN_WINDOW_SELECT_POS_X_1 16
#define MAIN_WINDOW_SELECT_POS_Y_1 30

#define SELECT_POS_X_1_TO_2 30
#define SELECT_POS_Y_1_TO_2 0

#define MAIN_WINDOW_SELECT_POS_X_2 MAIN_WINDOW_SELECT_POS_X_1+SELECT_POS_X_1_TO_2
#define MAIN_WINDOW_SELECT_POS_Y_2 MAIN_WINDOW_SELECT_POS_Y_1+SELECT_POS_Y_1_TO_2


#define SELECT_POS_X_1_TO_3 60
#define SELECT_POS_Y_1_TO_3 0

#define MAIN_WINDOW_SELECT_POS_X_3 MAIN_WINDOW_SELECT_POS_X_1+SELECT_POS_X_1_TO_3
#define MAIN_WINDOW_SELECT_POS_Y_3 MAIN_WINDOW_SELECT_POS_Y_1+SELECT_POS_Y_1_TO_3

#define SELECT_POS_X_1_TO_4 90
#define SELECT_POS_Y_1_TO_4 0

#define MAIN_WINDOW_SELECT_POS_X_4 MAIN_WINDOW_SELECT_POS_X_1+SELECT_POS_X_1_TO_4
#define MAIN_WINDOW_SELECT_POS_Y_4 MAIN_WINDOW_SELECT_POS_Y_1+SELECT_POS_Y_1_TO_4

#define SELECT_POS_X_1_TO_5 45
#define SELECT_POS_Y_1_TO_5 5

#define MAIN_WINDOW_SELECT_POS_X_5 MAIN_WINDOW_SELECT_POS_X_1+SELECT_POS_X_1_TO_5
#define MAIN_WINDOW_SELECT_POS_Y_5 MAIN_WINDOW_SELECT_POS_Y_1+SELECT_POS_Y_1_TO_5




#define DISPLAY_FIRST_CARD_POS_X 15
#define DISPLAY_FIRST_CARD_POS_Y 5

#define DISPLAY_SECOND_CARD_POS_X 55
#define DISPLAY_SECOND_CARD_POS_Y 5

#define DISPLAY_THIRD_CARD_POS_X 95
#define DISPLAY_THIRD_CARD_POS_Y 5

#define DISPLAY_CARD_WIDTH 40
#define DISPLAY_CARD_HIGH  10

#define DISPLAY_ONE_CARD_STORY_POS_X 28
#define DISPLAY_ONE_CARD_STORY_POS_Y 10


#define DISPLAY_FIRST_LEVEL_POS_X  15
#define DISPLAY_FIRST_LEVEL_POS_Y  5

#define DISPLAY_FIFTH_LEVEL_POS_X  DISPLAY_FIRST_LEVEL_POS_X
#define DISPLAY_FIFTH_LEVEL_POS_Y  DISPLAY_FIRST_LEVEL_POS_Y+DISPLAY_LEVEL_HIGH


#define DISPLAY_NINTH_LEVEL_POS_X  DISPLAY_FIRST_LEVEL_POS_X
#define DISPLAY_NINTH_LEVEL_POS_Y  DISPLAY_FIRST_LEVEL_POS_Y+2*DISPLAY_LEVEL_HIGH

#define DISPLAY_THIRTEENTH_LEVEL_POS_X  DISPLAY_FIRST_LEVEL_POS_X
#define DISPLAY_THIRTEENTH_LEVEL_POS_Y  DISPLAY_FIRST_LEVEL_POS_Y+3*DISPLAY_LEVEL_HIGH

#define DISPLAY_LEVEL_HIGH 8
#define DISPLAY_LEVEL_WIDTH 28


#define MAIN_WINDOW_SELECT_WIDTH 15

#define NUMBER_CARD 9

#define NUMBER_CARD_MAX_IN_BATTLEFIELD 20

#define TIP_AREA_POS_X 3
#define TIP_AREA_POS_Y MAP_POS_Y

#define TIP_AREA_HIGH 8

#define NUMBER_TIP_AREA 4


//地图信息

#define MAP_HIGH  31
#define MAP_WIDTH 33

  //地图左上角坐标
#define MAP_POS_X 50
#define MAP_POS_Y 5


#define MAP_TO_SELECTAREA 15

//选择区域信息

#define NUMBER_SELECT_CARD 4
  //第一个选择区域左上角坐标
#define SELECTAREA_POS_X MAP_POS_X+MAP_WIDTH+MAP_TO_SELECTAREA
#define SELECTAREA_POS_Y 5
  //单个选择区域规模
#define SELECTAREA_HIGH 7
#define SELECTAREA_WIDTH 40

#define SELECTAREA_JUMP_TO_MAP_X MAP_POS_X+16
#define SELECTAREA_JUMP_TO_MAP_Y MAP_POS_Y+25

//home 的属性
  //home position
#define HOME_PLAYER_POS_X 16
#define HOME_PLAYER_POS_Y 28

#define HOME_COMPUTER_POS_X 16
#define HOME_COMPUTER_POS_Y 2

  //home durable 家耐久 尽量不改 对应图案
#define HOME_DURABLE 27


//分辨敌我
#define PLAYER 1
#define COMPUTER 0

//卡片视野 可以特殊化
#define CARD_HORIZON_X 5
#define CARD_HORIZON_Y 5

//用于移动逻辑判断
#define TO_LEFT 1
#define TO_RIGHT 0

#define TO_UP 1
#define TO_DOWN 0

//不可改 与地图有墙部分有关
#define SPACE_BETWEEN_WALL 10

//决定电脑行动速度
#define COMPUTER_ACTION_POINT_MAX 35

//状态栏位置
#define MAP_TO_STATUE 2
#define STATUE_POS_X  MAP_POS_X-5
#define STATUE_POS_Y  MAP_POS_Y+MAP_HIGH+MAP_TO_STATUE


//power control
#define POWER_MAX 10
#define POWER_DEVELOP_SPEED_COMPUTER 12
#define POWER_DEVELOP_SPEED_PLAYER 12

//初始能量
#define BEGIN_POWER_FOR_PLAYER 6
#define BEGIN_POWER_FOR_COMPUTER 6


//墙的厚度
//for 2 character
#define WALL_HIGH 8
//flash position
//for 3 character
#define PLAYER_FLASH_POS_X    15
#define PLAYER_FLASH_POS_Y    7
#define COMPUTER_FLASH_POS_X  15
#define COMPUTER_FLASH_POS_Y  23

//for AI
#define GOOD 1
#define BAD 0


using namespace std;

enum Direction{UP=72,DOWN=80,LEFT=75,RIGHT=77};

static HANDLE hOut;
static HANDLE hIn;
static HWND hWnd;
static CONSOLE_SCREEN_BUFFER_INFO bInfo;
static CONSOLE_CURSOR_INFO cci;

static fstream file_battlefield;
static fstream file_cardmessage;

static COORD computer_pos_pre_choice[8]={{8,6},{14,6},{20,6},{26,6},
                                        {8,10},{14,10},{20,10},{26,10}};

#endif // CONST_VALUE_H_INCLUDED
