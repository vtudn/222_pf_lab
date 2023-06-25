#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

#define HP_MIN 1
#define HP_MAX 999
#define LEVEL_MIN 1
#define LEVEL_MAX 10
#define REMEDY_MIN 0
#define REMEDY_MAX 99
#define MAIDENKISS_MIN 0
#define MAIDENKISS_MAX 99
#define PHOENIXDOWN_MIN 0
#define PHOENIXDOWN_MAX 99

#define BOWSER_SURRENDERED 0
#define MEET_MADBEAR 1
#define MEET_BANDIT 2
#define MEET_LORDLUPIN 3
#define MEET_ELF 4
#define MEET_TROLL 5
#define MEET_SHAMAN 6
#define MEET_SIRENVAJSH 7
#define PICK_MUSHMARIO 11
#define PICK_MUSHFIB 12
#define PICK_MUSHGHOST 13
#define OBTAIN_REMEDY 15
#define OBTAIN_MAIDENKISS 16
#define PICK_PHOENIXDOWN 17
#define MEET_MERLIN 18
#define MEET_ASCLEPIUS 19
#define MEET_BOWSER 99

#define BASE_DMG_MADBEAR 1
#define BASE_DMG_BANDIT 1.5
#define BASE_DMG_LORDLUPIN 4.5
#define BASE_DMG_ELF 7.5
#define BASE_DMG_TROLL 9.5

#define MAX_INT 2147483647
#define MIN_INT -2147483648

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
bool containMerlinOnly(string Merlin_item);
bool containMerlinLetters(string Merlin_item);
void checkMountainSequence(int n2_sequence[], int n2, int &mtx, int &mti);
int decrementToNearestFibonacciMushFib(int n);
bool isPrimeMushMario(int n);
int nextPrimeMushMario(int n);
int incrementToNearestPrimeMushMario(int n);
int s1MushMario(int n1);
void checkFrogState(int &frog_state_cnt, int level_before_frog, int &level, int &maidenkiss);
void checkTinyState(int &tiny_state_cnt, int maxHP, /* int HP_before_tiny, */ int &HP, int &remedy, int &phoenixdown);
int updateLevelO(int i);
void checkLimit(int maxHP, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown);
int countEvents(string str_countEvents);
void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue);

#endif // __KNIGHT_H__