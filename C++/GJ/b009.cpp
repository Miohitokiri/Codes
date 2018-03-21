#include<iostream>
#include<string>
using namespace std;
int main(){
	string a, b;
	cin >> a >> b;
	long long stop = 0;
	bool ansData[a.size()];
	bool finallAns;
	for ( long long i = 0 ; i < a.size() ; i++ )
		for ( long long j = stop ; j < b.size() ; j++ )
			if ( a[i] == b[j] ){
				ansData[i] = true;
				stop = j;
			}
			else
				ansData[i] = false;
	for ( int i = 0 ; i < a.size() ; i++ ){
		if ( ansData[i] == false )
	}
}