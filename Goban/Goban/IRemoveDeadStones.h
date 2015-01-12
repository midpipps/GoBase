#ifndef IREMOVEDEADSTONE_H
#define IREMOVEDEADSTONE_H
#include "Board.h"
namespace Goban
{
	class IRemoveDeadStones
	{
	public:
		struct deadStoneReturn
		{
			int playerID;
			int numberOfStones;
		};

		virtual ~IRemoveDeadStones();
		/// <summary>
		/// Analyze the board to find the groups that possibly should be removed 
		/// </summary>
		/// <param name="theBoard">the board to analyze for dead groups</param>
		/// <returns>number of possible dead stone groups.</returns>
		virtual int AnalyzeBoard(Board * theBoard) = 0;

		/// <summary>
		/// remove stones from the board.  the id passed in the the player with the most previous move.
		/// </summary>
		/// <param name="playerIDRemoveLast">the previous players ID stored in the object</param>
		/// <param name="theBoard">the board to remove dead stones from</param>
		/// <returns> return the playersid of the stones removed and how many in an array of 2</returns>
		virtual deadStoneReturn RemoveDeadStones(int playerIDRemoveLast, Board * theBoard) = 0;
	};
}
#endif