#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	ifstream in("text.txt");
	ofstream out("output.txt");

	string s1("Detta är 1 string som innehåller många ord. \n Till och med olika meningar.");
	istringstream sin(s1);
	ostringstream sout;

	string data;
	char c;
	char text[256];
	string word;
	int i;
	string s2;


	sin >> word;
	sout << word;
	sin >> word;
	sin >> i;
	std::cout<< word;
	std::cout<< endl;

	s2 = sout.str();
	std::cout << s2 << endl;


	/// get()
	c = in.get();
	std::cout<< c;
	std::cout<<endl;

	in.get(c);
	std::cout<< c;
	std::cout << endl;

	//getLine
	in.getline(text,256);
	std::cout << text;
	std::cout << endl;

	// >> string
	in >> data;
	std::cout << data;
	std::cout << endl;

	// >> char
	in >> c;
	std::cout<< c;
	std::cout << endl;

	
	// hela filen med streamiterators
	//string content; 
	std:: string content((std::istreambuf_iterator<char>(in)),
                       (std::istreambuf_iterator<char>()));
	std::cout<< content;

}