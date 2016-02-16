#include "TagRemover.h"

TagRemover::TagRemover(ifstream cin){
	cin.open("test.html");
	if (cin.is_open())
	{
		while(cin.get()){
			
		}
	}
	cin.close();
}

void TagRemover::print(ostream cout) const{

}
