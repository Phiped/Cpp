/*
*A palindrome is a word that reads the same both forwards and backwards. 
*Examples: anna, amanaplanacanalpanama. Write a function that takes a string as 
*parameter and returns true if the word is a palindrome, false otherwise. 
*Also write a program that reads words from the terminal and checks whether they are palindromes. 
*Modify the makefile to build the program.
**/


#include <iostream>
#include <string>

using namespace std;


bool palindrome(string s){
	string snew = "";
	for(string::size_type i = 0; i != s.size(); i++){
		snew += s.back();
		s.pop_back();
	}
	return (s.compare(snew) == 0);
}

int main(int argc, char* argv[]){
	for(int i = 1; i < argc; i++){
		string s = argv[i];

		if(palindrome(s)){
			cout<<"You found a Palindrome. You can take your medal from the blue box over there."<<endl;
		}else{
			cout<<"Kom inte tillbaka förens du har hittat ett palindrome!"<<endl;
		}
	}
}