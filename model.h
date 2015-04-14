#ifndef _MODEL_H
#define _MODEL_H

#include <vector>

struct Cell {
	int row;
	int col;
	// Has this cell been examined?
	bool explored;
	// Has this cell been flagged?
	bool flagged;
	// Is this cell a mine?
	bool mine;
	// How many mines are nearby?
	int neighbors;
};

// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model();
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    // Is the game over?
    bool gameOver();
    // TODO: Put your stuff here
	void update();
	void flagMine(int row, int col);
	void explore(int row, int col);
	
	// How many mines are there nearby?
	Cell ** grid;
	int width;
	int height;
private:
	std::vector<Cell> neighbors(int row, int col) {
		using namespace std;
		vector<Cell> result;
		for (int i = row - 1; i <= row + 1; i++) {
			for (int j = col - 1; j <= col + 1; j++) {
				if (j < width && i < height && j >= 0 && i >= 0) {
					result.push_back(grid[i][j]);
				}
			}
		}
		return result;
	}
};

#endif