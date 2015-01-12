#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Player.h"
#include "IRemoveDeadStones.h"
#include "InvalidPlayerException.h"
#include <vector>
namespace Goban
{
	/// <summary>
	/// A basic class for actually playing a game.  Can have multiple players and can use custom systems for removing dead stones and figuring score.
	/// </summary>
	class Game
	{
	public:
		/// <summary>
		/// Constuctor sets the number of players and the board size in a square size of rows and columns
		/// </summary>
		/// <param name="num">number of players</param>
		/// <param name="size">height and width of the board so 19 passed would be 19X19</param>
		Game(int num, size_t size);

		/// <summary>
		/// Constuctor sets the number of players and the board size in rows and columns
		/// </summary>
		/// <param name="num">number of players</param>
		/// <param name="r">number of rows for the board</param>
		/// <param name="c">number of columns for the board</param>
		Game(int num, size_t r, size_t c);

		/// <summary>
		/// Destructor for the class
		/// </summary>
		virtual ~Game();

		/// <summary>
		/// Sets the player at pnum position to the passed in player does not transfer stones.
		/// </summary>
		/// <param name="pNum">player number to get the player object from</param>
		/// <param name="p"> the player object to set the player to copies the object</param>
		void setPlayer(const int pNum, const Player & p);

		/// <summary>
		/// Sets the player at pnum position to the passed in playername assigns the ID to the Pnum
		/// </summary>
		/// <param name="pNum">player number to get the player object from</param>
		/// <param name="name"> name to set the player too</param>
		void setPlayer(const int pNum, const std::string name);

		/// <summary>
		/// Sets the player at pnum position to the passed in playername 
		/// </summary>
		/// <param name="pNum">player number to get the player object from</param>
		/// <param name="name"> name to set the player too</param>
		/// <param name="PlayerID"> ID to set the player too</param>
		void setPlayer(const int pNum, const std::string name, const int playerID);
		
		/// <summary>
		/// returns the player object for the player of num passed in num
		/// </summary>
		/// <param name="pNum">player number to get the player object from</param>
		/// <returns>player object for the player of num passed in num</returns>
		Player * getPlayer(int pNum) const;

		/// <summary>
		/// Sets the deadstoneRemover to use for the game.
		/// </summary>
		/// <param name="theRemover">the deadstone remover to use in the system</param>
		void setDeadStoneRemover(IRemoveDeadStones * theRemover);

		/// <summary>
		/// Runs the dead stone remover to remove any dead stones from the board.
		/// </summary>
		IRemoveDeadStones::deadStoneReturn runDeadStoneRemover();

		/// <summary>
		/// Plays a move from the selected player in the selected intersection
		/// </summary>
		/// <param name="pNum">player number to get the player object from</param>
		/// <param name="r">number of rows for the board</param>
		/// <param name="c">number of columns for the board</param>
		void makeMove(int pNum, int r, int c);

		/// <summary>
		/// returns the stone at position or nullptr if there is no stone there
		/// </summary>
		/// <param name="r">number of rows for the board</param>
		/// <param name="c">number of columns for the board</param>
		/// <returns>the stone from that intersection if there is one</returns>
		const Stone * getStone(int r, int c);

	private:
		Board *theBoard;
		std::vector<Player *> players;
		IRemoveDeadStones * deadStoneRemover;
		int previousPlayer = -1;
	};
}
#endif


