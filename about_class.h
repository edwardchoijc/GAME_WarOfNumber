#ifndef ABOUT_CLASS_H_INCLUDED
#define ABOUT_CLASS_H_INCLUDED

#include "const_Value.h"

using namespace std;

class Card
{
private:
    char card_name;
    unsigned short card_HP;
    unsigned short card_cost;
    unsigned short card_damage;
    unsigned short card_speed;
    COORD card_horizon;
public:
    Card();
    ~Card();

    void Set_Card_Date(fstream &);

    void Display_Message_in_Select_Area(HANDLE);
    void Display_Message_in_CareBoxshow(HANDLE);

    char Return_card_name(){return card_name;};
    unsigned short Return_card_HP(){return card_HP;};
    unsigned short Return_card_cost(){return card_cost;};
    unsigned short Return_card_damage(){return card_damage;};
    unsigned short Return_card_speed(){return card_speed;};
    COORD Return_card_horizon(){return card_horizon;};

    bool if_can_attack;
    bool if_can_move;
};

class Home
{
private:
    COORD home_pos;
    short home_durable;
    bool player_or_computer;
public:
    Home(unsigned short,unsigned short);
    ~Home();

    void Be_Hurted(unsigned short);

    COORD Return_home_pos(){return home_pos;};
    short Return_home_durable(){return home_durable;};
    bool Return_player_or_computer(){return player_or_computer;};
};


class Battlefield;


class Card_in_fight
{
private:
    char card_name;
    unsigned short card_HP;
    unsigned short card_cost;
    unsigned short card_damage;
    unsigned short card_speed;
    COORD card_horizon;


    unsigned counter_for_move;
    bool player_or_AI;
    bool if_in_map;
    bool if_can_use;

    COORD card_pos_in_map;
    COORD aim_pos;
public:
    Card_in_fight();
    ~Card_in_fight();

    //for number 1 character
    unsigned short counter_for_add_speed;
    void Add_Card_Speed(){card_speed=card_speed/3;};

    void operator =(Card &);

    void Set_Card_Date(Card &,COORD,bool);
    void Set_Card_Pos(short,short);

    COORD Check_Action(vector<Card_in_fight> &);
    void Attack_Action(vector<Card_in_fight> &,vector<Card> &);
    void Attack_Action(Home &home_date);
    void Move_Action(unsigned short,Battlefield);

    void Be_Killed();
    void Be_Hurted(unsigned short,vector<Card> &);

    void Be_Bried(){player_or_AI=!player_or_AI;};//for number 8 character

    void Use_Skill(){if_can_use=false;};

    unsigned short Return_card_HP(){return card_HP;};
    COORD Return_card_pos_in_map(){return card_pos_in_map;};
    char Return_card_name(){return card_name;};
    bool Return_if_in_map(){return if_in_map;};
    COORD Return_aim_pos(){return aim_pos;};
    bool Return_player_or_computer(){return player_or_AI;};
    unsigned Return_counter_for_move(){return counter_for_move;};

    bool if_can_attack;
    bool if_can_move;

    bool Return_if_can_use(){return if_can_use;};

};


class Battlefield
{
private:
    char battlefield_date[MAP_HIGH][MAP_WIDTH];

    bool if_can_set_card[MAP_HIGH][MAP_WIDTH];
public:
    Battlefield();
    ~Battlefield();

    void Load_Battlefield(fstream &);

    void Display_Battlefield(HANDLE);

    void Set_Battlefield(Home &,Home &,vector<Card_in_fight> &,COORD);

    void Set_Home_in_Battlefield(Home);

    void Set_Card_in_Fight_in_Battlefield(vector<Card_in_fight> &);

    void Check_Battlefield();

    void Set_Cursor_in_Battlefield(COORD);

    bool Return_if_can_set_card_pos(COORD);

    char Return_map_in_one_pos(COORD pos_in_map);
};

class Selectarea
{
private:
    COORD selectarea_pos;
    char card_name_in_selectarea;
public:
    Selectarea();
    ~Selectarea();
    void Display_Selectarea(vector<Card> &,unsigned,HANDLE);
    void Random_Get_Card(vector<Card> &,Selectarea *);

    COORD Return_select_pos(){return selectarea_pos;};

    char Return_card_name_in_selectarea(){return card_name_in_selectarea;};

    void Display_Card_in_Selectarea_Message(vector<Card> &,char,HANDLE);

};

class Statue
{
private:
    unsigned short now_power;
    unsigned short power_develop_speed;
    bool player_or_computer;
    COORD pos_in_screen;
public:
    Statue();
    ~Statue();
    void Set_date(bool);

    bool Add_power();
    bool Cost_power(unsigned short);

    COORD Return_pos_in_screen(){return pos_in_screen;};
    unsigned short Return_now_power(){return now_power;};
    unsigned short Return_power_develop_speed(){return power_develop_speed;};
    bool Return_player_or_computer(){return player_or_computer;};


};

class Tiparea
{
private:
    int tip_type;
    unsigned short counter_tip_exist;
    COORD tip_pos;
public:
    Tiparea(){tip_type=0;counter_tip_exist=0;};
    ~Tiparea(){};
    void Get_tip_type(int &);
    void Get_tip_pos(COORD);
    void Display_Tip(HANDLE hOut);
    void Display_Tip(unsigned short,HANDLE);

    void Add_counter_tip_exist(){counter_tip_exist++;};

    int Return_tip_type(){return tip_type;};
    unsigned short Return_counter_tip_exist(){return counter_tip_exist;};
    COORD Return_tip_pos(){return tip_pos;};
};



#endif // ABOUT_CLASS_H_INCLUDED
