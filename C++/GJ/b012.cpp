#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	string data[3];
	for ( int i = 0 ; i < 3 ; i++ )
		getline ( cin, data[i] );

	cout << data[2] << '\n' << data[0] << '\n' << data[1] << '\n';
}