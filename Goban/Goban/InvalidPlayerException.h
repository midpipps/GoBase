#ifndef INVALIDPLAYEREXCEPTION_H
#define INVALIDPLAYEREXCEPTION_H
#include <exception>
#include <string>
#include <sstream>
namespace Goban
{
	///<summary>
	/// Invalid player is an exception for the game class to throw when an invalid position selection is made it extends class runtime_error
	/// </summary>
	class InvalidPlayerException :
		public std::runtime_error
	{
	public:
		/// <summary>
		/// Default Constuctor
		/// </summary>
		InvalidPlayerException();
		/// <summary>
		/// Constuctor creates exception with the passed in message
		/// </summary>
		/// <param name="message">The Message that will accompany the exception</param>
		explicit InvalidPlayerException(std::string message);
		/// <summary>
		/// Constuctor creates exception with the passed in position as part of the message
		/// </summary>
		/// <param name="player">The playernumber that was causing the exception</param>
		InvalidPlayerException(int player);
		/// <summary>
		/// Constuctor creates exception with the passed in position as part of the message
		/// </summary>
		/// <param name="player">The row that was causing the exception</param>
		/// <param name="message">The Message that will accompany the exception</param>
		InvalidPlayerException(int player, std::string message);
		/// <summary>
		/// Destructor
		/// </summary>
		virtual ~InvalidPlayerException() throw();
		/// <summary>
		/// get the error message
		/// </summary>
		virtual const char* what() const throw();
	private:
		int position;
	};
}
#endif