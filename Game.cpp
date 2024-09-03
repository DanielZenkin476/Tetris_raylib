#include <Game.h>
#include <random>


Game::Game() {
	grid = Grid();//creates new grid for game
	blocks = { IBlock(), JBlock(), LBlock(), SBlock(), OBlock(), TBlock(), ZBlock() };// init blocks list
	currBlock = GetRandomBlock();// get first
	nextBlock = GetRandomBlock();// get next
	gameOver = false;
	score = 0;
}
tetromino Game::GetRandomBlock() {// return random block from list
	srand((unsigned int)time(NULL));// to get diffrent rand seed every oparation
	int randid = rand() % blocks.size();// get rand id
	tetromino block = blocks[randid];
	blocks.erase(blocks.begin() + randid);// removes from list block that was chosen
	if (blocks.empty()) blocks = { IBlock(), JBlock(), LBlock(), SBlock(), OBlock(), TBlock(), ZBlock() };// check if empty- to refill the blocks 
	return block;// returns the chosen block
}
void Game::Draw() {//draws game board
	grid.Draw();//draw grid
	currBlock.Draw(0,0);//draws current block
	switch (nextBlock.id) {// draws next block centerd in display of next block by case
	default:
		nextBlock.Draw(270, 320);
		break;
	case 3:// I block
		nextBlock.Draw(255, 340);
		break;
	case 4:// O block
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
// for movment dawn- checks if block is out of bounds- if so moves back and locks block
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
{// function to handle input for movement, after move checks if legal - if not move back
	int keyPressed = GetKeyPressed();
	if (gameOver && keyPressed != 0) {// checks for game over
		gameOver = false;
		Reset();
	}
	switch (keyPressed) {
	case KEY_LEFT:// left- move left
		MoveBlockLeft();
		break;
	case KEY_RIGHT:// right - move right
		MoveBlockRight();
		break;
	case KEY_DOWN:// down -add one point and move down
		score += 1;
		MoveBlockDown();
		break;
	case KEY_UP:// up- rotate block
		RotateBlock();
		if (IsBlockOut()) RotateBlockBack();
		break;
	}
}

bool Game::IsBlockOut()// function checks if curr block is out
{
	std::vector<Position> tiles = currBlock.GetCellPos();//vector of curr block position
	for (Position item : tiles) {
		if (grid.IsOut(item.row, item.col)) return true;// loops over all items and checks bounds for each one
	}
	return false;
}

void Game::RotateBlock()//rotates block
{
	currBlock.Rotate();
}
void Game::RotateBlockBack()//rotates block back
{
	currBlock.RotateBack();
}

void Game::LockBlock()// locks block in place- moves to grid, checks completed rows ,adds score and choses new next block
{
	int addScore = 0;
	std::vector<Position> tiles = currBlock.GetCellPos();//vector of curr block position
	for (Position item : tiles) {
		grid.grid[item.row][item.col] = currBlock.id;// loops over block location' colors the locations in grid
	}
	currBlock = nextBlock;
	nextBlock = GetRandomBlock();// rolls new block
	int complete = grid.ClearFullRows();//completed rows
	while (complete >0) {//adds score based on completed rows
		 addScore = addScore + 100 + 50 * (complete-1);
		 complete--;
	}
	score = score + addScore;// adds score
	if (IsBlockOut() == true) {// checks for game over
		gameOver = true;
	}
}
void Game::Reset() {// Resets the game
	grid.Initialize();//init grid
	blocks = { IBlock(), JBlock(), LBlock(), SBlock(), OBlock(), TBlock(), ZBlock() };// init blocks list
	currBlock = GetRandomBlock();// get first
	nextBlock = GetRandomBlock();// get next
}
