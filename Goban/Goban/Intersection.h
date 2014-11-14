#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "Stone.h"
namespace Goban
{
	/// <summary>
	/// Intersection that can have a stone played on it and can link to other intersections
	/// </summary>
	class Intersection
	{
	public:
		/// <summary>
		/// Default Constuctor sets all the intersection * to nullptr
		/// </summary>
		Intersection();
		/// <summary>
		/// Constuctor sets left pointer to intersection all the other intersection * to nullptr
		/// </summary>
		/// <param name="pleft">sets the left pointer to the intersection </param>
		explicit Intersection(Intersection *pleft);
		/// <summary>
		/// Constuctor sets left and right pointer to intersection all the other intersection * to nullptr
		/// </summary>
		/// <param name="pleft">sets the left pointer to the intersection </param>
		/// <param name="pright">sets the right pointer to the intersection </param>
		Intersection(Intersection *pleft, Intersection *pright);
		/// <summary>
		/// Constuctor sets left, right, up pointer to intersection all the other intersection * to nullptr
		/// </summary>
		/// <param name="pleft">sets the left pointer to the intersection </param>
		/// <param name="pright">sets the right pointer to the intersection </param>
		/// <param name="pup">sets the up pointer to the intersection </param>
		Intersection(Intersection *pleft, Intersection *pright, Intersection *pup);
		/// <summary>
		/// Constuctor sets left, right, up, and down pointer to intersections
		/// </summary>
		/// <param name="pleft">sets the left pointer to the intersection </param>
		/// <param name="pright">sets the right pointer to the intersection </param>
		/// <param name="pup">sets the up pointer to the intersection </param>
		/// <param name="pdown">sets the down pointer to the intersection </param>
		Intersection(Intersection *pleft, Intersection *pright, Intersection *pup, Intersection *pdown);
		/// <summary>
		/// Destructor
		/// </summary>
		virtual ~Intersection();
		/// <summary>
		/// returns intersection to up
		/// </summary>
		/// <returns>intersection up pointer</returns>
		Intersection* getUp();
		/// <summary>
		/// Sets up to the passed in intersection
		/// </summary>
		/// <param name="inter">the intersection to set up to</param>
		void setUp(Intersection *inter);
		/// <summary>
		/// returns intersection to down
		/// </summary>
		/// <returns>intersection down pointer</returns>
		Intersection* getDown();
		/// <summary>
		/// Sets down to the passed in intersection
		/// </summary>
		/// <param name="inter">the intersection to set down to</param>
		void setDown(Intersection *inter);
		/// <summary>
		/// returns intersection to right
		/// </summary>
		/// <returns>intersection right pointer</returns>
		Intersection* getRight();
		/// <summary>
		/// Sets right to the passed in intersection
		/// </summary>
		/// <param name="inter">the intersection to set right to</param>
		void setRight(Intersection *inter);
		/// <summary>
		/// returns intersection to left
		/// </summary>
		/// <returns>intersection left pointer</returns>
		Intersection* getLeft();
		/// <summary>
		/// Sets left to the passed in intersection
		/// </summary>
		/// <param name="inter">the intersection to set left to</param>
		void setLeft(Intersection *inter);
		/// <summary>
		/// get the ID of the intersection
		/// </summary>
		/// <returns>returns an int ID</returns>
		unsigned int getID() const;
		/// <summary>
		/// resets the static counter to 0
		/// </summary>
		static void resetIDCounter();
		/// <summary>
		/// Sets the stone to be played on this intersection
		/// </summary>
		/// <param name="pstone">the stone to play on the intersection</param>
		void setStone(Stone *pstone);
		/// <summary>
		/// returns pointer to the stone held at this position
		/// </summary>
		/// <returns>pointer to the stone on the intersection</returns>
		Stone* getStone();
		/// <summary>
		/// returns true if there is a stone on this intersection empty stone is also equal to nullptr
		/// </summary>
		/// <returns>true if there is a stone on the intersection false otherwise</returns>
		bool hasStone() const;
	private:
		Intersection *up;
		Intersection *right;
		Intersection *left;
		Intersection *down;
		Stone *stone;
		static unsigned int iDTracker;
		int id;
	};
}
#endif
