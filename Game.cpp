#include <Game.h>
#include <random>


Game::Game() {
	grid = Grid();
	blocks = { IBlock(), JBlock(), LBlock(), SBlock(), OBlock(), TBlock(), ZBlock() };// init blocks list
	currBlock = GetRandomBlock();// get first
	nextBlock = GetRandomBlock();// get next
	gameOver = false;
	score = 0;
}
tetromino Game::GetRandomBlock() {
	srand((unsigned int)time(NULL));
	int randid = rand() % blocks.size();
	tetromino block = blocks[randid];
	blocks.erase(blocks.begin() + randid);
	if (blocks.empty()) blocks = { IBlock(), JBlock(), LBlock(), SBlock(), OBlock(), TBlock(), ZBlock() };// check if empty- to refill the blocks 
	return block;
}
void Game::Draw() {
	grid.Draw();
	currBlock.Draw(0,0);
	switch (nextBlock.id) {
	default:
		nextBlock.Draw(270, 320);
		break;
	case 3:
		nextBlock.Draw(255, 320);
		break;
	case 4:
		nextBlock.Draw(255, 320);
		break;
	}

}
// movment - left right down , if out of bounds - move back
void Game::MoveBlockLeft() {
	if (!gameOver) {
		currBlock.Move(0, -1);
		if (IsBlockOut()) currBlock.Move(0, 1);
	}
	
};
void Game::MoveBlockRight() {
	if (!gameOver) {
		currBlock.Move(0, 1);
		if (IsBlockOut()) { currBlock.Move(0, -1); }
	}
};
void Game::MoveBlockDown() {
	if (!gameOver) {
		currBlock.Move(1, 0);
		if (IsBlockOut()) {
			currBlock.Move(-1, 0);
			LockBlock();
		}
	}

};

void Game::HandleInput()
{
	int keyPressed = GetKeyPressed();
	if (gameOver && keyPressed != 0) {
		gameOver = false;
		Reset();
	}
	switch (keyPressed) {
	case KEY_LEFT:
		MoveBlockLeft();
		break;
	case KEY_RIGHT:
		MoveBlockRight();
		break;
	case KEY_DOWN:
		score += 1;
		MoveBlockDown();
		break;
	case KEY_UP:
		RotateBlock();
		if (IsBlockOut()) RotateBlockBack();
		break;
	}
}

bool Game::IsBlockOut()
{
	std::vector<Position> tiles = currBlock.GetCellPos();
	for (Position item : tiles) {
		if (grid.IsOut(item.row, item.col)) return true;
	}
	return false;
}

void Game::RotateBlock()
{
	currBlock.Rotate();
}
void Game::RotateBlockBack()
{
	currBlock.RotateBack();
}

void Game::LockBlock()
{
	int addScore = 0;
	std::vector<Position> tiles = currBlock.GetCellPos();
	for (Position item : tiles) {
		grid.grid[item.row][item.col] = currBlock.id;
	}
	currBlock = nextBlock;
	nextBlock = GetRandomBlock();
	int complete = grid.ClearFullRows();
	while (complete >0) {
		 addScore = addScore + 100 + 50 * (complete-1);
		 complete--;
	}
	score = score + addScore;
	if (IsBlockOut() == true) {
		gameOver = true;
	}
}
void Game::Reset() {
	grid.Initialize();
	blocks = { IBlock(), JBlock(), LBlock(), SBlock(), OBlock(), TBlock(), ZBlock() };// init blocks list
	currBlock = GetRandomBlock();// get first
	nextBlock = GetRandomBlock();// get next
}
