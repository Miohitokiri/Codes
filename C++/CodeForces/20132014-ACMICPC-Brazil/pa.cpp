#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int a, b, c;
	cin >> a >> b >> c;
	if ( a == b && b == c )
		cout << '*';
	else if ( b == c )
		cout << 'A';
	else if ( a == b )
		cout << 'C';
	else if ( a == c )
		cout << 'B';
	cout << '\n';
}