#ifndef CLASS_GAME_H
#define CLASS_GAME_H
class Game
{
	public :
		int score=0;
		int high_score=0;
		Game(int a,int b)
		{
			score=a;
			high_score=b;
		}
};
#endif