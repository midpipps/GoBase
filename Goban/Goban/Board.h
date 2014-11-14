#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Intersection.h"
#include "Player.h"
#include "InvalidIntersectionException.h"
namespace Goban
{
	/// <summary>
	/// The board object will allow you to play stones on it
	/// </summary>
	class Board
	{
	public:
		/// <summary>
		/// Default Constuctor will make a board of size 1X1
		/// </summary>
		Board();
		/// <summary>
		/// Constuctor will make a board of size size_tXsize_t
		/// </summary>
		/// <param name="boardSize">The board size will be this as row and column amount </param>
		Board(const size_t boardSize);
		/// <summary>
		/// Constuctor will make a board of size rowXcolumn
		/// </summary>
		/// <param name="rowSize">The board size will be this as rows count </param>
		/// <param name="columnSize">The board size will be this as column count </param>
		Board(const size_t rowSize, const size_t columnSize);
		/// <summary>
		/// Destructor
		/// </summary>
		virtual ~Board();
		/// <summary>
		/// Sets the number of rows to have
		/// </summary>
		/// <param name="rowSize">The board size will be this as row amount </param>
		void setRows(const size_t rowSize);
		/// <summary>
		/// returns the size of the rows
		/// </summary>
		/// <returns>size_t number of rows</returns>
		size_t getRows() const;
		/// <summary>
		/// Sets the number of columns to have
		/// </summary>
		/// <param name="columnSize">The board size will be this as column amount </param>
		void setColumns(const size_t columnSize);
		/// <summary>
		/// returns the size of the columns
		/// </summary>
		/// <returns>size_t number of columns</returns>
		size_t getColumns() const;
		/// <summary>
		/// Causes the board to actually build out the board in memory
		/// </summary>
		void createBoard();
		/// <summary>
		/// Constuctor will make a board of size rowXcolumn
		/// </summary>
		/// <param name="c">The board column of the intersection </param>
		/// <param name="r">The board row of the intersection </param>
		/// <returns>Returns the intersection at the current location unless out of scope then throws error</returns>
		Intersection *getIntersection(const size_t r, const size_t c);
		/// <summary>
		/// Constuctor will make a board of size rowXcolumn
		/// </summary>
		/// <param name="playerToPlay">The player object to get the stone from </param>
		/// <param name="c">The board column of the intersection to play the stone on </param>
		/// <param name="r">The board row of the intersection to play the stone on</param>
		void playStone(Player * playerToPlay, int r, int c);
	private:
		bool isValidPosition(int, int);
		size_t rows;
		size_t columns;
		std::vector<std::vector<Intersection>> intersectionMap;
		int stoneIDCounter;
	};
}
#endif