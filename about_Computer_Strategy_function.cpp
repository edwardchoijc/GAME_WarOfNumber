#include "const_Value.h"
#include "about_class.h"
#include "about_operation.h"
#include "about_Draw.h"
#include "about_character.h"

using namespace std;

bool Computer_Strategy(unsigned short now_power,COORD &computer_pos_choice,
                       Card &computer_card_choice,vector<Card> &cards,
                       vector<Card_in_fight> &card_fight,Battlefield _map)
{

    //COORD computer_pos_pre_choice[8]={{8,6},{14,6},{20,6},{26,6},
                                      //{8,10},{14,10},{20,10},{26,10}};

    //int n=rand()%8;
    //computer_pos_choice=computer_pos_pre_choice[n];
    //int a=rand()%NUMBER_CARD;
    //computer_card_choice=cards[a];

    if(Computer_Strategy_Judge(card_fight,_map)==GOOD)
    {
        //Advantage
        if(Computer_Strategy_Attack(now_power,computer_pos_choice,computer_card_choice,cards)==false)
            return false;
    }
    else
    {
        //Disadvantage
        if(Computer_Strategy_Defend(now_power,computer_pos_choice,computer_card_choice,cards)==false)
            return false;
    }

    return true;
}

bool Computer_Strategy_Judge(vector<Card_in_fight> &card_fight,Battlefield _map)
{
    unsigned short a=0;
    unsigned short b=0;
    for(unsigned short n=0;n<NUMBER_CARD_MAX_IN_BATTLEFIELD;n++)
    {
        if(card_fight[n].Return_player_or_computer()==COMPUTER)
            a=a+card_fight[n].Return_card_HP();
        else
            b=b+card_fight[n].Return_card_HP();
    }
    if(a>=b)
       return GOOD;
    else
       return BAD;
}

bool Computer_Strategy_Attack(unsigned short now_power,COORD &computer_pos_choice,
                              Card &computer_card_choice,vector<Card> &card)
//card position in front of the home area
//more willing to choice attack card
{
    if(now_power<=2)
        return false;
    else if(now_power<=3)//Always give up action for saving power
    {
        int action=rand()%10;

        //can use 1,2,3,5
        if(action<4)
        {
            int n=rand()%4+4;
            computer_pos_choice=computer_pos_pre_choice[n];

            int k=rand()%3;
            //use 1,2,3
            if(k==0)
                computer_card_choice=card[0];
            else if(k==1)
                computer_card_choice=card[1];
            else if(k==2)
                computer_card_choice=card[2];
            return true;
        }
        else
            return false;
    }
    else if(now_power<=4)//usually give up action for saving power
    {
        int action=rand()%10;

        //can use 1,2,3,5,4
        if(action<5)
        {
            int n=rand()%4+4;
            computer_pos_choice=computer_pos_pre_choice[n];

            int k=rand()%3;
            //use 1,2,3
            if(k==0)
                computer_card_choice=card[0];
            else if(k==1)
                computer_card_choice=card[1];
            else if(k==2)
                computer_card_choice=card[2];
            return true;
        }
        else
            return false;
    }
    else if(now_power<=5)//
    {
        int action=rand()%10;//often give up action for saving power
        //can use 1,2,3,5,4,6
        if(action<6)
        {
            int n=rand()%4+4;
            computer_pos_choice=computer_pos_pre_choice[n];

            int k=rand()%3;
            //use 1,3,6
            if(k==0)
                computer_card_choice=card[0];
            else if(k==1)
                computer_card_choice=card[2];
            else if(k==2)
                computer_card_choice=card[5];
            return true;
        }
        else
            return false;
    }
    else if(now_power<=6)
    {
        int action=rand()%10;//sometime give up action for saving power
        //can use 1,2,3,5,4,6,7
        if(action<7)
        {
            int n=rand()%4+4;
            computer_pos_choice=computer_pos_pre_choice[n];

            int k=rand()%3;
            //use 1,6,7
            if(k==0)
                computer_card_choice=card[0];
            else if(k==1)
                computer_card_choice=card[5];
            else if(k==2)
                computer_card_choice=card[6];

            return true;
        }
        else
            return false;
    }
    else if(now_power<=7)
    {
        int action=rand()%10;//almost not give up action for saving power
        //can use 1,2,3,5,4,6,7,9
        if(action<8)
        {
            int n=rand()%4+4;
            computer_pos_choice=computer_pos_pre_choice[n];

            int k=rand()%2;
            //use 6,7
            if(k==0)
                computer_card_choice=card[5];
            else if(k==1)
                computer_card_choice=card[6];
            return true;
        }
        else
            return false;
    }
    else if(now_power>7)
    {
        //nevergive up action for saving power
        //can use 1,2,3,5,4,6,7,9,8

        int n=rand()%4+4;
        computer_pos_choice=computer_pos_pre_choice[n];

        int k=rand()%2;
        //use 7,8
        if(k==0)
            computer_card_choice=card[6];
        else if(k==1)
            computer_card_choice=card[7];
        return true;
    }
    return true;
}

bool Computer_Strategy_Defend(unsigned short now_power,COORD &computer_pos_choice,
                              Card &computer_card_choice,vector<Card> &card)
//card position in behind of the home area
//more willing to choice defend card
{
    if(now_power<=2)
        return false;
    else if(now_power<=3)
    {
        int action=rand()%10;

        //can use 1,2,3,5
        if(action<6)//often give up action for saving power
        {
            int n=rand()%4;
            computer_pos_choice=computer_pos_pre_choice[n];

            int k=rand()%3;
            //use 2,3,5
            if(k==0)
                computer_card_choice=card[1];
            else if(k==1)
                computer_card_choice=card[2];
            else if(k==2)
                computer_card_choice=card[4];
            return true;
        }
        else
            return false;
    }
    else if(now_power<=4)
    {
        int action=rand()%10;

        //can use 1,2,3,5,4
        if(action<7)//sometime give up action for saving power
        {
            int n=rand()%4;
            computer_pos_choice=computer_pos_pre_choice[n];

            int k=rand()%3;
            //use 4,3,5
            if(k==0)
                computer_card_choice=card[3];
            else if(k==1)
                computer_card_choice=card[2];
            else if(k==2)
                computer_card_choice=card[4];
            return true;
        }
        else
            return false;
    }
    else if(now_power<=5)
    {
        int action=rand()%10;

        //can use 1,2,3,5,4,6
        if(action<8)//sometime give up action for saving power
        {
            int n=rand()%4;
            computer_pos_choice=computer_pos_pre_choice[n];

            int k=rand()%3;
            //use 4,6,5
            if(k==0)
                computer_card_choice=card[3];
            else if(k==1)
                computer_card_choice=card[5];
            else if(k==2)
                computer_card_choice=card[4];
            return true;
        }
        else
            return false;
    }
    else if(now_power<=6)
    {
        int action=rand()%10;

        //can use 1,2,3,5,4,6,7
        if(action<8)//sometime give up action for saving power
        {
            int n=rand()%4;
            computer_pos_choice=computer_pos_pre_choice[n];

            int k=rand()%3;
            //use 4,6,5
            if(k==0)
                computer_card_choice=card[3];
            else if(k==1)
                computer_card_choice=card[5];
            else if(k==2)
                computer_card_choice=card[4];
            return true;
        }
        else
            return false;
    }
    else if(now_power<=7)
    {
        //can use 1,2,3,5,4,6,7,9
        //must do action
        int n=rand()%4;
            computer_pos_choice=computer_pos_pre_choice[n];

        int k=rand()%3;
        //use 4,5,9
        if(k==0)
            computer_card_choice=card[3];
        else if(k==1)
            computer_card_choice=card[4];
        else if(k==2)
            computer_card_choice=card[8];
        return true;
    }
    else if(now_power>7)
    {
        //can use 1,2,3,5,4,6,7,9,8
        //must do action
        int n=rand()%4;
            computer_pos_choice=computer_pos_pre_choice[n];

        int k=rand()%3;
        //use 4,5,8,9
        if(k==0)
            computer_card_choice=card[3];
        else if(k==1)
            computer_card_choice=card[4];
        else if(k==2)
            computer_card_choice=card[7];
        else if(k==3)
            computer_card_choice=card[8];
        return true;
    }

    return true;
}
