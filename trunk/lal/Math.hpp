#ifndef LAL_MATH_HPP_
#define LAL_MATH_HPP_


#include <cmath>

//-----------------------------------------------------------------------------
// Common math functions and constants.
//-----------------------------------------------------------------------------


namespace LAL {

	class Math
	{
	public:
	    static const float PI;
	    static const float HALF_PI;
	    static const float EPSILON;
	    static const float INVSQRT2;
	
	    static bool closeEnough(float f1, float f2)
	    {
	        // Determines whether the two floating-point values f1 and f2 are
	        // close enough together that they can be considered equal.
	
	        return fabsf((f1 - f2) / ((f2 == 0.0f) ? 1.0f : f2)) < EPSILON;
	    }
	
	    static float degreesToRadians(float degrees)
	    {
	        return (degrees * PI) / 180.0f;
	    }
	
	    static float radiansToDegrees(float radians)
	    {
	        return (radians * 180.0f) / PI;
	        
	    }
		virtual ~Math();
		
	};


}/* LAL :: NAMESPACE */
#endif /*MATH_HPP_*/