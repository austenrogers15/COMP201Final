#include "model.h"
#include <cstdlib>
#include <ctime>

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
		}
    }
	// Randomly place mines .
	srand(time(0));
    int otheri, otherj;
    for (int i = 0; i < 10; i++) {
		otheri = rand() % height;
		otherj = rand() % width;
		// Swap grid[i][j] with grid[otheri][otherj]
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

void Model::flagMine(int row, int col) {
	
}

void Model::clearFlag(int row, int col) {
	
}

void Model::explore(int row, int col) {
	grid[row][col].neighbors++;
}

// Checking whether all mines have been flagged
bool Model::gameOver() {
	// loop through the grid, assuming the game is over, unless shown otherwise.
    return false;
}

