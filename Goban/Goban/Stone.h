#ifndef STONE_H
#define STONE_H
namespace Goban
{
	/// <summary>
	/// Stone can be played on an intersection keeps track of player id and stoneid
	/// </summary>
	class Stone
	{
	public:
		/// <summary>
		/// Default Constuctor sets playerid, stoneid and checked to 0
		/// </summary>
		Stone();
		/// <summary>
		/// Constuctor sets the player id to passed in int, and stoneid to 0 and checked to false
		/// </summary>
		/// <param name="player">the id of the player whos stone this is</param>
		explicit Stone(int player);
		/// <summary>
		/// Copy Constructor will copy all elements over
		/// </summary>
		/// <param name="stoneToCopy">the stone to copy</param>
		Stone(const Stone& stoneToCopy);
		/// <summary>
		/// Constuctor sets the player id to passed in int, and stoneid to passed in int and checked to false
		/// </summary>
		/// <param name="player">the id of the player whos stone this is</param>
		/// <param name="stone">the id of the stone</param>
		Stone(int player, int stone);
		/// <summary>
		/// Constuctor sets the player id to passed in int, and stoneid to passed in int and checked to false
		/// </summary>
		/// <param name="player">the id of the player whos stone this is</param>
		/// <param name="stone">the id of the stone</param>
		/// <param name="check">initial value of checked</param>
		Stone(int player, int stone, bool check);
		/// <summary>
		/// Destructor
		/// </summary>
		virtual ~Stone();
		/// <summary>
		/// sets the player id to passed in int
		/// </summary>
		/// <param name="player">the id of the player whos stone this is</param>
		void setPlayerID(int player);
		/// <summary>
		/// sets the bool of checked
		/// </summary>
		/// <param name="check">bool to set the checked value to</param>
		void setChecked(bool check);
		/// <summary>
		/// sets the stone id to passed in int
		/// </summary>
		/// <param name="stone">the id of the stone</param>
		void setStoneID(int stone);
		/// <summary>
		/// get the playerID
		/// </summary>
		/// <returns>the int id of the player set on the stone</returns>
		int getPlayerID() const;
		/// <summary>
		/// get the value of whether this stone has been checked yet or not
		/// </summary>
		/// <returns>true if checked false otherwise</returns>
		bool getChecked() const;
		/// <summary>
		/// get the stoneif
		/// </summary>
		/// <returns>the int id of the stone</returns>
		int getStoneID() const;
	private:
		size_t playerID;
		bool checked;
		size_t stoneID;
	};
}
#endif

