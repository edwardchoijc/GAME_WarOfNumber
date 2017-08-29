#include "const_Value.h"
#include "about_class.h"
#include "about_operation.h"
#include "about_Draw.h"
#include "about_character.h"

using namespace std;

Card::Card()
{

}

Card::~Card()
{

}

void Card::Set_Card_Date(fstream &file_cardmessage)
{
    card_name=file_cardmessage.get();
    file_cardmessage.get();
    file_cardmessage>>card_HP;
    file_cardmessage.get();
    file_cardmessage>>card_cost;
    file_cardmessage.get();
    file_cardmessage>>card_damage;
    file_cardmessage.get();
    file_cardmessage>>card_speed;
    file_cardmessage.get();

    file_cardmessage>>card_horizon.X;
    file_cardmessage.get();
    file_cardmessage>>card_horizon.Y;
    file_cardmessage.get();

    file_cardmessage>>if_can_attack;
    file_cardmessage.get();
    file_cardmessage>>if_can_move;
    file_cardmessage.get();

}

void Card::Display_Message_in_Select_Area(HANDLE hOut)
{
    GetConsoleScreenBufferInfo(hOut,&bInfo);
    COORD now_pos={bInfo.dwCursorPosition.X,bInfo.dwCursorPosition.Y};

    cout<<" Card Name: "<<card_name;

    now_pos.Y++;
    SetConsoleCursorPosition(hOut,now_pos);
    cout<<" Card Cost: "<<card_cost<<" powers";
    now_pos.Y++;
    SetConsoleCursorPosition(hOut,now_pos);

    Draw_Tips_in_Select_Area(card_name);

}

void Card::Display_Message_in_CareBoxshow(HANDLE hOut)
{
    GetConsoleScreenBufferInfo(hOut,&bInfo);
    COORD now_pos={bInfo.dwCursorPosition.X,bInfo.dwCursorPosition.Y};

    COORD temp_pos=now_pos;

    temp_pos.Y--;
    SetConsoleCursorPosition(hOut,temp_pos);
    for(unsigned short n=0;n<35;n++)
        cout<<'*';
    temp_pos.Y++;
    SetConsoleCursorPosition(hOut,temp_pos);
    for(unsigned short n=0;n<35;n++)
        cout<<char(0xcd);

    //SetConsoleCursorPosition(hOut,pos);
    //cout<<char(0xc0);
    //for(unsigned short n=0;n<24;n++)
    //    cout<<char(0xc4);
    //cout<<char(0xd9);


    temp_pos.Y++;
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<" Card Name:"<<card_name;
    switch (card_name)
    {
    case '1':
        cout<<" a rocket";
        break;
    case '2':
        cout<<" a rabbit";
        break;
    case '3':
        cout<<" a flash";
        break;
    case '4':
        cout<<" a son of death";
        break;
    case '5':
        cout<<" a protector";
        break;
    case '6':
        cout<<" a gambler";
        break;
    case '7':
        cout<<" a knight";
        break;
    case '8':
        cout<<" a businessman";
        break;
    case '9':
        cout<<" a stone guardian";
        break;
    }

    temp_pos.Y++;
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<" Card HP: "<<card_HP;

    temp_pos.Y++;
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<" Card Damage(toward home): "<<card_damage;

    temp_pos.Y++;
    SetConsoleCursorPosition(hOut,temp_pos);
    if(card_name!='7'&&card_name!='1')
        cout<<" Card Speed: "<<card_speed;
    else
        cout<<" Card Speed: "<<card_speed<<"(not add speed)";

    temp_pos.Y++;
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<" Card Horizon: "<<card_horizon.X<<" wide || "<<card_horizon.Y<<" long";


    temp_pos.Y++;
    SetConsoleCursorPosition(hOut,temp_pos);
    cout<<" Card Cost: "<<card_cost<<" powers";

    temp_pos.Y++;
    SetConsoleCursorPosition(hOut,temp_pos);
    for(unsigned short n=0;n<35;n++)
        cout<<char(0xcd);
    temp_pos.Y++;
    SetConsoleCursorPosition(hOut,temp_pos);
    for(unsigned short n=0;n<35;n++)
        cout<<'*';
    temp_pos.Y--;

    now_pos.Y+=DISPLAY_CARD_HIGH;
    SetConsoleCursorPosition(hOut,now_pos);
}

