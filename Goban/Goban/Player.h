#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Stone.h"
namespace Goban
{
	/// <summary>
	/// Player class keeps track of number of stones and id of the player
	/// </summary>
	class Player
	{
	public:
		/// <summary>
		/// Default Constuctor sets playername to "" and playerid to 0
		/// </summary>
		Player();
		/// <summary>
		/// Constuctor sets the player id 0, and playername to passed in value
		/// </summary>
		/// <param name="name">the name of the player</param>
		explicit Player(std::string name);
		/// <summary>
		/// Constuctor sets the playername to passed in value, and player id to passed in value
		/// </summary>
		/// <param name="name">the name of the player</param>
		/// <param name="playersID">the id of the player</param>
		Player(std::string name, int playersID);
		/// <summary>
		/// Destructor
		/// </summary>
		virtual ~Player();
		/// <summary>
		/// get a new stone from the player with the id set to the players id
		/// </summary>
		/// <returns>a pointer to a new stone that the player controls</returns>
		Stone * getNewStone();
		/// <summary>
		/// add the passed in stone the the players captured stones
		/// </summary>
		/// <param name="pstone">the stone to add to the captured stone list</param>
		void addCapturedStone(Stone *);
		/// <summary>
		/// get a count of captured stones
		/// </summary>
		/// <returns>the int number of stones captured</returns>
		int getCapturedStoneCount() const;
		/// <summary>
		/// set the playername to the passed in string
		/// </summary>
		/// <param name="newName">the name of the player</param>
		void setPlayerName(std::string newName);
		/// <summary>
		/// get the players name
		/// </summary>
		/// <returns>return a string that has the players name</returns>
		std::string getPlayerName() const;
		/// <summary>
		/// set the playerid to the passed in int
		/// </summary>
		/// <param name="newID">the player id to use for stones</param>
		void setPlayerID(int newID);
		/// <summary>
		/// get the players id
		/// </summary>
		/// <returns>return a int of the playerid</returns>
		int getPlayerID() const;
	private:
		std::string playerName;
		int playerID;
		std::vector<Stone *> playersStones;
		std::vector<Stone *> capturedStones;
	};
}
#endif
