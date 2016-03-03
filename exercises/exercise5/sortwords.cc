#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	vector<string> v = {"Mary", "had", "a", "little", "lamb", "and", "some",
		"olives", "on", "the", "side"};
	
	// print the words: Mary had a little lamb and some olives on the side
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	
	// sort in alphabetical order: Mary a and had lamb little olives on side some the
	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	
	// in reverse order: the some side on olives little lamb had and a Mary
	reverse(v.begin(),v.end());
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
	cout << endl;

	
	// by ascending length: a on the and had Mary lamb side some olives little

	sort(v.begin(), v.end(), [] (string s1, string s2)->bool{return s1.size()<s2.size() && s1<s2;});
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	
	// sort in alphabetical order again, print three-letter words: and had the

	sort(v.begin(), v.end());
	auto it =remove_if(v.begin(), v.end(), [] (string s1)->bool{return s1.size()!=3;});
	copy(v.begin(), it, ostream_iterator<string>(cout, " "));
	cout << endl;
	
	// remove words with <= three letters: Mary lamb little olives side some
	sort(v.begin(), v.end());
	it = remove_if(v.begin(), v.end(), [] (string s1)->bool{return s1.size()<=3;});
	copy(v.begin(), it, ostream_iterator<string>(cout, " "));
	cout << endl;

	//cout << v << endl;
}