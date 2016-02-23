#include "TagRemover.h"
#include <iostream>
#include <fstream>


int main() {
	std::ifstream cin;
	cin.open("test.html");
	TagRemover tr(cin); // read from cin
	tr.print(std::cout); // print on cout
}