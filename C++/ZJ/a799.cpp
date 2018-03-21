#include<iostream>
using namespace std;
int main(){
	string a;
	while ( cin >> a ){
		long long data = a.size();
		if ( a[0] != '-' )
			cout << a;
		else
			for ( int i = 1 ; i < data ; i++ )
				cout << a[i];
		cout << endl;
	}
	return 0;
}