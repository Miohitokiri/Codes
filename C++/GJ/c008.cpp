#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int n;

	cin >> n;

	n *= 0.8;
	n += 30;
	cout << ( ( n > 100 ) ? 100 : n ) << '\n';
}