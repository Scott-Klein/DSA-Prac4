//Main program

#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#include "Cell.h"
#include "TicTacToe.h"
#include "HumanPlayer.h"
#include "BestFirstPlayer.h"
#include "Game.h"

using namespace std;

int main() {
	srand(time(0));
	int dongmoWins = 0, scottmoWins = 0;

	for (int i = 0; i < 1000; i++)
	{
		Game game;

		game.play(true);

		if (game.GetWinner() == 'X')
		{
			scottmoWins++;
		}
		else
		{
			dongmoWins++;
		}
	}


	for (int i = 0; i < 1000; i++)
	{
		Game game;

		game.play(false);

		if (game.GetWinner() == 'X')
		{
			dongmoWins++;
		}
		else
		{
			scottmoWins++;
		}
	}

	cout << "Scott player wins: " << scottmoWins << endl;

	cout << "Dongmo player wins: " << dongmoWins << endl;

	return 0;
}
