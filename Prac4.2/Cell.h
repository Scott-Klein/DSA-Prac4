/*
 * Cell.h
 *
 *  Created on: 27 Mar. 2019
 *      Author: dongmo
 */

#ifndef CELL_H_
#define CELL_H_

struct Cell {
	int x;
	int y;
	int heuristic;

	Cell(int xx, int yy, int hh):x(xx), y(yy), heuristic(hh) {}


	//returns true if left hand cell is less than right hand cell.
	bool operator<(const Cell& c) const {
		return heuristic < c.heuristic;
	}
};



#endif /* CELL_H_ */