#include "model.h"
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Constructor initializes the object
Model::Model() {
	width = 8;
    height = 8;
    grid = new Cell*[height];
    // For every row, create the array for that row
    for (int i = 0; i < height; i++) {
        grid[i] = new Cell[width];
		for (int j = 0; j < width; j++) {
			grid[i][j].explored = false;
			grid[i][j].flagged = false;
			grid[i][j].mine = false;
			grid[i][j].neighbors = 0;
			grid[i][j].row = i;
			grid[i][j].col = j;
		}
    }
	// Randomly place mines .
	srand(time(0));
    int otheri, otherj;
    for (int i = 0; i < 10; i++) {
		otheri = rand() % height;
		otherj = rand() % width;
		grid[otheri][otherj].mine = true;
	}
	// Bookkeeping for the number of adjacent mines
    for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			vector<Cell> adjacent = neighbors(i, j);
			for (int k = 0; k < adjacent.size(); k++) {
				if (adjacent[k].mine) {
					grid[i][j].neighbors++;
				}
			}
		}
	}
}

// Destructor deletes dynamically allocated memory
Model::~Model() {
	 for (int i = 0; i < height; i++) {
        delete grid[i];
    }
    delete grid;
}

//TODO:
void Model::update() {
	
}

// Flag and clear
void Model::flagMine(int row, int col) {
	grid[row][col].flagged = !grid[row][col].flagged;
}

void Model::explore(int row, int col) {
	grid[row][col].explored = true;
	vector<Cell> adjacent = neighbors(row, col);
	if (grid[row][col].neighbors > 0) {
		return;
	}
	for (int i = 0; i < adjacent.size(); i++) {
		if (adjacent[i].neighbors <= 1 && !adjacent[i].explored) {
			explore(adjacent[i].row, adjacent[i].col);
		}
	}
}

// Checking whether all mines have been flagged
bool Model::gameOver() {
	bool result = false;
	int flagged = 10;
	int b = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (grid[i][j].mine) {
				if (grid[i][j].mine == grid[i][j].explored) {
					return true;
				}
				if (grid[i][j].mine == grid[i][j].flagged) {
					b++;
				}
				if (b == flagged) {
					
				}
			}
		}
	}
	return b;
}

