#include "tetromino.h"
#include "Position.h"


class LBlock :public tetromino{
public: // must be public const or else permission error
	LBlock() {
		id = 1;
		cells[0] = { Position(0,2),Position(1,0) ,Position(1,1) ,Position(1,2) };
		cells[1] = { Position(0,1),Position(1,1) ,Position(2,1) ,Position(2,2) };
		cells[2] = { Position(1,0),Position(1,1) ,Position(1,2) ,Position(2,0) };
		cells[3] = { Position(0,0),Position(0,1) ,Position(1,1) ,Position(2,1) };
	}
};

class JBlock :public tetromino {
public: // must be public const or else permission error
	JBlock() {
		id = 2;
		cells[0] = { Position(0,0),Position(1,0) ,Position(1,1) ,Position(1,2) };
		cells[1] = { Position(0,1),Position(0,2) ,Position(1,1) ,Position(2,1) };
		cells[2] = { Position(1,0),Position(1,1) ,Position(1,2) ,Position(2,1) };
		cells[3] = { Position(0,2),Position(1,2) ,Position(2,1) ,Position(2,2) };
	}
};


class IBlock :public tetromino {
public: // must be public const or else permission error
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
public: // must be public const or else permission error
	OBlock() {
		id = 4;
		cells[0] = cells[1]= cells[2] = cells[3]= { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		Move(0, 1);
	}
};
class SBlock :public tetromino {
public: // must be public const or else permission error
	SBlock() {
		id = 5;
		cells[0] = { Position(0,1),Position(0,2) ,Position(1,0) ,Position(1,1) };
		cells[1] = { Position(0,1),Position(1,1) ,Position(1,2) ,Position(2,2) };
		cells[2] = { Position(1,1),Position(1,2) ,Position(2,0) ,Position(2,1) };
		cells[3] = { Position(0,0),Position(1,0) ,Position(1,1) ,Position(2,1) };
	}
};
class TBlock :public tetromino {
public: // must be public const or else permission error
	TBlock() {
		id = 6;
		cells[0] = { Position(0,1),Position(1,0) ,Position(1,1) ,Position(1,2) };
		cells[1] = { Position(0,1),Position(1,1) ,Position(1,2) ,Position(2,1) };
		cells[2] = { Position(1,0),Position(1,1) ,Position(1,2) ,Position(2,1) };
		cells[3] = { Position(0,1),Position(1,0) ,Position(1,1) ,Position(2,1) };
	}
};
class ZBlock :public tetromino {
public: // must be public const or else permission error
	ZBlock() {
		id = 7;
		cells[0] = { Position(0,0),Position(0,1) ,Position(1,1) ,Position(1,2) };
		cells[1] = { Position(0,2),Position(1,1) ,Position(1,2) ,Position(2,1) };
		cells[2] = { Position(1,0),Position(1,1) ,Position(2,1) ,Position(2,2) };
		cells[3] = { Position(0,1),Position(1,0) ,Position(1,1) ,Position(2,0) };
	}
};




