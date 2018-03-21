#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, in, a = 0, b = 0, c = 0, d = 0;
	cin >> n;
	while ( n-- ){
		cin >> in;
		if ( in == 1 )
			a++;
		else if ( in == 2 )
			b++;
		else if ( in == 3 )
			c++;
		else
			d++;
	}

	cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}