#ifndef ABOUT_CHARACTER_H_INCLUDED
#define ABOUT_CHARACTER_H_INCLUDED

#include "const_Value.h"
#include "about_class.h"
#include "about_operation.h"

using namespace std;

void Character_for_Card_1(Card_in_fight *);//add to move_action

void Character_for_Card_2(Card_in_fight *,bool);//add to move_action

bool Character_for_Card_3(Card_in_fight *);//add to attack_action

void Character_for_Card_4(Card_in_fight *,Card_in_fight *);//add to attack_action

bool Character_for_Card_5(Card_in_fight *,Card);//add to attack_action

void Character_for_Card_6(Card &,vector<Card> &);//add to Set_Card_in_Battlefield

void Character_for_Card_7(Card_in_fight);

bool Character_for_Card_8(Card_in_fight *,Card_in_fight *);//add to attack_action

bool Character_for_Card_9(Card_in_fight *,Card_in_fight *);//add to attack_action

#endif // ABOUT_CHARACTER_H_INCLUDED
