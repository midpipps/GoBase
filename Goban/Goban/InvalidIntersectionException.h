#ifndef INVALIDINTERSECTIONEXCEPTION_H
#define INVALIDINTERSECTIONEXCEPTION_H
#include <exception>
#include <string>
#include <sstream>
namespace Goban
{
	///<summary>
	/// Invalid Intsersection is an exception for the board class to throw when an invalid position selection is made it extends class runtime_error
	/// </summary>
	class InvalidIntersectionException :
		public std::runtime_error
	{
	public:
		/// <summary>
		/// Default Constuctor
		/// </summary>
		InvalidIntersectionException();
		/// <summary>
		/// Constuctor creates exception with the passed in message
		/// </summary>
		/// <param name="message">The Message that will accompany the exception</param>
		explicit InvalidIntersectionException(std::string message);
		/// <summary>
		/// Constuctor creates exception with the passed in row and column as part of the message
		/// </summary>
		/// <param name="r">The row that was causing the exception</param>
		/// <param name="c">The column that was causing the exception</param>
		InvalidIntersectionException(int r, int c);
		/// <summary>
		/// Constuctor creates exception with the passed in row and column as part of the message
		/// </summary>
		/// <param name="r">The row that was causing the exception</param>
		/// <param name="c">The column that was causing the exception</param>
		/// <param name="message">The Message that will accompany the exception</param>
		InvalidIntersectionException(int r, int c, std::string message);
		/// <summary>
		/// Destructor
		/// </summary>
		virtual ~InvalidIntersectionException() throw();
		/// <summary>
		/// get the error message
		/// </summary>
		virtual const char* what() const throw();
	private:
		int row;
		int column;
	};
}
#endif