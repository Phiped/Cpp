#include "TagRemover.h"

using namespace std;

TagRemover::TagRemover(ifstream& cin){
	regex e ("<[a-zA-Z'.\\s]+>");
	result ="";

	if (cin)
	{
		while(cin>>result){
			s+=result;
			s+=" ";
		}

		result = regex_replace (s,e,"");
		result = regex_replace (result,regex("&lt"),"<");
		result = regex_replace (result,regex("&gt"),">");
		result = regex_replace (result,regex("&nbsp")," ");
		result = regex_replace (result,regex("&amp"),"&");
		//<[a-zA-Z\s.']*>
	}
	cin.close();
}

void TagRemover::print(std::ostream& cout) const{
	cout<<result<<endl;
}
