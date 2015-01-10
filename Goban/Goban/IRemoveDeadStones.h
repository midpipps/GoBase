#ifndef IREMOVEDEADSTONE_H
#define IREMOVEDEADSTONE_H
#include "Board.h"
namespace Goban
{
	class IRemoveDeadStones
	{
	public:

		virtual ~IRemoveDeadStones();
		/// <summary>
		/// Analyze the board to find the groups that possibly should be removed 
		/// </summary>
		/// <param name="theBoard">the board to analyze for dead groups</param>
		virtual void AnalyzeBoard(Board * theBoard) = 0;

		/// <summary>
		/// remove stones from the board.  the id passed in the the player with the most previous move.
		/// </summary>
		/// <param name="playerIDRemoveLast">the player id of the last person to make a move on the board.</param>
		/// <param name="theBoard">the board to analyze for dead groups</param>
		virtual void RemoveDeadStones(int playerIDRemoveLast, Board * theBoard) = 0;
	};
}
#endif