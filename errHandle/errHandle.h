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
	const char *str; ///< error string to put on the error

	/// Default constructor generates a generic error
	errHandle() : e(genericErr) { }

	/// Constructor
	/// @arg _e type of the error
	errHandle(errType _e) : e(_e), str(NULL) { }

	/// Constructor
	/// @arg _e type of the error
	/// @arg _str error string
	errHandle(errType _e, const char* _str) : e(_e), str(_str) { }

	/// Operator to output the error
	inline friend ostream& operator << (ostream& out, const errHandle& err) {

		if (err.e == genericErr)
			out << "Generic error";

		if (err.e == usageErr)
			out << "Error reading arguments!\n" << err.str;

		if (err.e == readErr)
			out << "Cannot read " << err.str;

		if (err.e == writeErr)
			out << "Cannot write " << err.str;

		if (err.e == memoryErr)
			out << "Cannot (de)allocate memory!";

		out << endl;

		return out;

	}

};

