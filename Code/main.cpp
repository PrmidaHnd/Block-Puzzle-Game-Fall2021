#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

#include "class_game.h"
char puzzle[100][100];
int size=11;
char dif='2';
int next_block2;
Game game=Game(0,0);
#include "menu.h"
#include "play.h"


int main()
{
	srand(time(0));
	menu();
	return 0;
}