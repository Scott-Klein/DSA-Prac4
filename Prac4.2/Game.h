/*
 * Game.h
 *
 *  Created on: 22 Mar. 2019
 *      Author: dongmo
 */

#include "ScottsSmartPlayer.h"
#ifndef GAME_H_
#define GAME_H_

class Game {
private:
	char winner;
public:
	char GetWinner()
	{
		if (winner == 'X' || winner == 'O')
		{
			return winner;
		}
		else
		{
			return 'D';
		}
	}

	void play(bool ScottFirst) {
		ticTacToe board;
		board.displayBoard();

		ScottsSmartPlayer hplayer('X');
		BestFirstPlayer mplayer('O');

		if (!ScottFirst)
		{
			hplayer = ScottsSmartPlayer('O');
			mplayer = BestFirstPlayer('X');
		}

		
		bool done = false;
		char player = 'X';

		while (!done) {
			int x = -1;
			int y = -1;
			if (player == 'X') {
				hplayer.getMove(board, x, y);
				board.addMove(player, x, y);
				cout << "X makes a move (" << (x + 1) << "," << (y + 1) << ") "
						<< endl;
				board.displayBoard();
				done = checkWin(player, board);
				player = 'O';
			} else {
				mplayer.getMove(board, x, y);
				board.addMove(player, x, y);
				cout << "O makes a move (" << (x + 1) << "," << (y + 1) << ") "
						<< endl;
				board.displayBoard();
				done = checkWin(player, board);
				player = 'X';
			}
		}
	}

	bool checkWin(char playerSymbol, ticTacToe board) {
		char gStatus = board.gameStatus();

		if (gStatus == playerSymbol) {
			winner = playerSymbol;
			cout << "Player " << playerSymbol << " wins!" << endl;
			return true;
		} else if (gStatus == 'D') {
			cout << "This game is a draw!" << endl;
			return true;
		} else if (gStatus != 'C') {
			return true;
		} else
			return false;
	}
};

#endif /* GAME_H_ */
