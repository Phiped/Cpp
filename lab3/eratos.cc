#include <string>
#include <iostream>

using namespace std;

string eratos(int max){
	string primes;

	primes.assign(max,'P');	
	primes.replace(0,2,"CC");

	for (int k = 2; k < primes.size(); ++k)
	{
		if(k*k < max && primes.at(k) == 'P'){
			for (int i = 2*k; i < primes.size(); i=i+k)
			{
				primes.replace(i,1,"C");			
			}
		}
	}
	return primes;
}

int main (int, char* argv[]){
	string primes;
	int last =0;

	primes = eratos(200);

	cout<<"Primtalen mellan 1-200:"<<endl;
	for (int i = 0; i < primes.size(); ++i)
	{
		if (primes.at(i) == 'P' )
		{
			cout<<i;
			cout<<"   ";
		}
	}

	primes = eratos(200000);

	for (int i = 0; i < primes.size(); ++i)
	{
		if (primes.at(i) == 'P' && i > last)
		{
			last = i;
		}
	}
	cout<<endl<<"Sista primtalet innan 200000:	";
	cout<<last<<endl;
}
