#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int a, b, n = 0;

	cin >> a >> b;

	for ( int i = a ; i <= b ; i++ )
		( i % 2 != 0 && i % 3 != 0 && i % 5 != 0 ) ? n++ : n;

	cout << n << '\n';
}