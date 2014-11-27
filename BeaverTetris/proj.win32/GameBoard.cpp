#include "GameBoard.h"
#include "GameEnums.h"

using namespace std;

GameBoard::GameBoard(int width, int height)
{
	_gameBoardWidth = width;
	_gameBoardHeight = height;
	cleanGameBoard();
}


GameBoard::~GameBoard(void)
{
}


void GameBoard::setTetraminoXYposition(Tetramino aTetramino, int xPosition, int yPosition)
{
	_tetramins[yPosition * _gameBoardWidth + xPosition] = aTetramino;
}

int GameBoard::getGameBoardWidth()
{
	return _gameBoardWidth;
}

int GameBoard::getGameBoardHeight()
{
	return _gameBoardHeight;
}

Tetramino GameBoard::getTetraminoForXYposition(int xPosition, int yPosition)
{
	Tetramino tetramino = _tetramins[yPosition * _gameBoardWidth + xPosition];
	return tetramino;
}

vector <GamePositionOnBoard> GameBoard::getAvailableTetraminis()
{

	vector <GamePositionOnBoard> availableTetraminos = vector <GamePositionOnBoard>();

	for (int xPosition = 0; xPosition < _gameBoardHeight; xPosition++)
	{

		for (int yPosition = 0; yPosition < _gameBoardWidth; yPosition++)
		{
			Tetramino tetramino = getTetraminoForXYposition(xPosition,yPosition);
			if (tetramino.getTetraminoType > kTetraminoEmpty)
			{
				GamePositionOnBoard position;
				position.xPosition = xPosition;
				position.yPosition = yPosition;
				availableTetraminos.push_back(position);
			}

		}

	}

	return availableTetraminos;

}

void GameBoard::removeTetraminoForXYposition(int xPosition, int yPosition)
{
	Tetramino newTetramino;
	_tetramins[xPosition * _gameBoardWidth + yPosition] = newTetramino;
}

void GameBoard::cleanTetraminoRowForYposition(int yPosition)
{
	for (int xPosition = 0; xPosition < _gameBoardWidth; xPosition++)
	{
		removeTetraminoForXYposition(xPosition, yPosition);
	}
}

void GameBoard::cleanGameBoard(void)
{
	_tetramins = new Tetramino[_gameBoardHeight * _gameBoardWidth];
}