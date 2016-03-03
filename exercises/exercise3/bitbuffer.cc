#include "bitbuffer.h"

#include <iostream>

BitBuffer::BitBuffer(std::ostream& out): cout(out) {}

void BitBuffer::put(bool b) {
	++n_bits;
	byte = (byte<<1) | b;

	if(n_bits == 8){
		n_bits=0;
		cout << byte;
	}
}