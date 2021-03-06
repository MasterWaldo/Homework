// ---------------------------------------------------------------------------
// Project Name		:	Alpha Engine
// File Name		:	AEUtil.h
// Author			:	Sun Tjen Fam
// Creation Date	:	2008/02/01
// Purpose			:	header file for utility library
// History			:
// - 2008/02/01		:	- initial implementation
// ---------------------------------------------------------------------------

#ifndef AE_UTIL_H
#define AE_UTIL_H

// ---------------------------------------------------------------------------
#ifdef __cplusplus 
extern "C"
{
#endif

// Time functions
AE_API f64		AEGetTime(f64* pTime);

// random number generator
AE_API f32		AERandFloat();


#define isZero(x) ((x < EPSILON) && (x > -EPSILON))

#define isEqual(x,y) (((x >= y) ? (x-y) : (y-x)) < EPSILON)




#ifdef __cplusplus 
}
#endif


char *ReadFromFile(const char *fileName);

// ---------------------------------------------------------------------------

#endif // AE_UTIL_H


