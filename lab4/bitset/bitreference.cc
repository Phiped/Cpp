#include "bitreference.h"
#include "bitset.h"
#include <iostream>

BitReference& BitReference::operator=(bool b) {
	//
	// *** IMPLEMENT ***
	// This corresponds to the set() function in SimpleBitset.
	//
	if (b) {
		*p_bits |= 1L << *(p_bits+pos);
	} else { 
		*p_bits &= ~ (1L << *(p_bits+pos));
	}

	return *this;
}

BitReference& BitReference::operator=(const BitReference& rhs) {
	//
	// *** IMPLEMENT ***
	// Same as operator=(bool), but the bit is picked from rhs
	//
	return *this;
}

BitReference::operator bool() const {
	//
	// *** IMPLEMENT ***
	// This corresponds to the get() function in SimpleBitset.
	//
	return true;
}
