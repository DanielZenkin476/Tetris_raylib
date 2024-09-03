#include "tetromino.h"
#include "Position.h"

// 7 child classes of tetromino - each one is a diffrent block. cells keep rotation states, O and I block move to be centered.
class JBlock :public tetromino{
public: 
	JBlock() {
		id = 1;
		cells[0] = { Position(0,2),Position(1,0) ,Position(1,1) ,Position(1,2) };
		cells[1] = { Position(0,1),Position(1,1) ,Position(2,1) ,Position(2,2) };
		cells[2] = { Position(1,0),Position(1,1) ,Position(1,2) ,Position(2,0) };
		cells[3] = { Position(0,0),Position(0,1) ,Position(1,1) ,Position(2,1) };
	}
};

class LBlock :public tetromino {
public: 
	LBlock() {
		id = 2;
		cells[0] = { Position(0,0),Position(1,0) ,Position(1,1) ,Position(1,2) };
		cells[1] = { Position(0,1),Position(0,2) ,Position(1,1) ,Position(2,1) };
		cells[2] = { Position(1,0),Position(1,1) ,Position(1,2) ,Position(2,2) };
		cells[3] = { Position(0,1),Position(1,1) ,Position(2,0) ,Position(2,1) };
	}
};


class IBlock :public tetromino {
public: 
	IBlock() {
		id = 3;
		cells[0] = { Position(1,0),Position(1,1) ,Position(1,2) ,Position(1,3) };
		cells[1] = { Position(0,2),Position(1,2) ,Position(2,2) ,Position(3,2) };
		cells[2] = { Position(2,0),Position(2,1) ,Position(2,2) ,Position(2,3) };
		cells[3] = { Position(0,1),Position(1,1) ,Position(2,1) ,Position(3,1) };
		Move(-1,0);// To center
	}
};
class OBlock :public tetromino {
public: 
	OBlock() {
		id = 4;
		cells[0] = cells[1]= cells[2] = cells[3]= { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		Move(0, 1);//To center
	}
};
class SBlock :public tetromino {
public: 
	SBlock() {
		id = 5;
		cells[0] = { Position(0,1),Position(0,2) ,Position(1,0) ,Position(1,1) };
		cells[1] = { Position(0,1),Position(1,1) ,Position(1,2) ,Position(2,2) };
		cells[2] = { Position(1,1),Position(1,2) ,Position(2,0) ,Position(2,1) };
		cells[3] = { Position(0,0),Position(1,0) ,Position(1,1) ,Position(2,1) };
	}
};
class TBlock :public tetromino {
public: 
	TBlock() {
		id = 6;
		cells[0] = { Position(0,1),Position(1,0) ,Position(1,1) ,Position(1,2) };
		cells[1] = { Position(0,1),Position(1,1) ,Position(1,2) ,Position(2,1) };
		cells[2] = { Position(1,0),Position(1,1) ,Position(1,2) ,Position(2,1) };
		cells[3] = { Position(0,1),Position(1,0) ,Position(1,1) ,Position(2,1) };
	}
};
class ZBlock :public tetromino {
public: 
	ZBlock() {
		id = 7;
		cells[0] = { Position(0,0),Position(0,1) ,Position(1,1) ,Position(1,2) };
		cells[1] = { Position(0,2),Position(1,1) ,Position(1,2) ,Position(2,1) };
		cells[2] = { Position(1,0),Position(1,1) ,Position(2,1) ,Position(2,2) };
		cells[3] = { Position(0,1),Position(1,0) ,Position(1,1) ,Position(2,0) };
	}
};




