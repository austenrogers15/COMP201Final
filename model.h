#ifndef _MODEL_H
#define _MODEL_H

struct Cell {
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
	void clearFlag(int row, int col);
	void explore(int row, int col);
	
	// How many mines are there nearby?
	Cell ** grid;
	int width;
	int height;
};

#endif