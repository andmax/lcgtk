/**
 *
 *    Error Handle Class
 *
 *  File: errHandle.h
 *
 *  Author: Andre Maximo
 *
 *  Last Update: May 16, 2007
 *
 **/

/**
 *
 *  errHandle (Error Handle Class)
 *
 * This class is designed to be used in a try/catch block passed by
 * the throw statement. Example:
 *
 * try {
 *
 *      // do something
 *      // ops... error/exception occurred
 *      throw errHandle(readErr, filename);
 *
 * } catch(errHandle& e) {
 *
 *      cerr << e;
 *      return 1;
 *
 * } catch(...) {
 *
 *      throw errHandle();
 *
 * }
 *
 **/

/// Note:
/// Adapt the error type and messages as needed

enum errType { genericErr, usageErr, readErr, writeErr, memoryErr };

class errHandle {

public:

	errType e; ///< Type of the error occurred
	const char *str1, *str2; ///< additional strings to put on the error

	/// Default constructor generates a generic error
	errHandle() : e(genericErr) { }

	/// Constructor
	/// @arg _e type of the error
	errHandle(errType _e) : e(_e), str1(NULL), str2(NULL) { }

	/// Constructor
	/// @arg _e type of the error
	/// @arg _str additional string (first)
	errHandle(errType _e, const char* _str) : e(_e), str1(_str), str2(NULL) { }

	/// Constructor
	/// @arg _e type of the error
	/// @arg _str additional string (first)
	/// @arg _str additional string (second)
	errHandle(errType _e, const char* _str1, const char* _str2) :
		e(_e), str1(_str1), str2(_str2) { }

	/// Operator to output the error
	inline friend ostream& operator << (ostream& out, const errHandle& err) {

		if (err.e == genericErr)
			out << "Generic error";

		if (err.e == usageErr) {

			out << "Usage: " << err.str1 << " file" << endl << endl
			    << "  Where the following files will be readed: " << endl
			    << "    (x) 'file'" << offExt << " : vertex position and tetrahedra vertex ids" << endl
			    << "    (-) 'file'" << incidExt << " : incidents in vertex" << endl
			    << "    (-) 'file'" << conExt << " : tetrahedra connectivity" << endl
			    << "    (-) 'file'" << tfExt << " : transfer function with [0, 255] colors" << endl
			    << "  Reading from the directory: " << err.str2 << endl
			    << "  Files marked by (x) need to exist." << endl
			    << "  If the files marked by (-) does not exist, it will be computed and created." << endl;

		}

		if (err.e == readErr)
			out << "Cannot read " << err.str1;

		if (err.e == writeErr)
			out << "Cannot write " << err.str1;

		if (err.e == memoryErr)
			out << "Cannot (de)allocate memory!";

		out << endl;

		return out;

	}

};
