#include "TagRemover.h"
#include <iostream>


ifstream cin;
ofstream cout;

int main() {
	TagRemover tr(cin); // read from cin
	tr.print(cout); // print on cout

}