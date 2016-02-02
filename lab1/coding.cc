#include "coding.h"

unsigned char Coding::encode(unsigned char c){
	return c + 'a';
}

unsigned char Coding::decode(unsigned char c){
	return c - 'a';
}
