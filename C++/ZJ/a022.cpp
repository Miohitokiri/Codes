#include<string>
#include<iostream>
using namespace std;
int main(){
	string a;
	while ( cin >> a ){
		string b = a[0];
		for ( int i = 1 ; i < a.size() ; i++ )
			b += a[i];
		if ( a == b )
			cout << "yes";
		else
			cout << "no";
		cout << endl;
	}
	return 0;
}