#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int a, b;
	cin >> a >> b;
	if ( a < 30 )
		cout << 1;
	else if ( a < 50 )
		cout << 2;
	else if ( a < 70 )
		cout << 3;
	else if ( a < 90 )
		cout << 4;
	else
		cout << 5;
	cout << ' ';
	if ( b < 50 )
		cout << 1;
	else if ( b < 150 )
		cout << 2;
	else if ( b < 250 )
		cout << 3;
	else if ( b < 350 )
		cout << 4;
	else
		cout << 5;
	cout << '\n';
}