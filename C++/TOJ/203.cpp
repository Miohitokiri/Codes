#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int x, y, stop;
	char a;
	while ( cin >> a  ){
		cin >> a >> x >> a >> y;
		while ( cin >> a ){
			if ( a == 'E' )
				break;

			cin >> stop;
			switch ( a ){
				case 'X': x = stop; break;
				case 'Y': y = stop; break;
				case 'U': y += stop; break;
				case 'D': y -= stop; break;
				case 'L': x -= stop; break;
				case 'R': x += stop; break;
			}
		}

		cout << x << '\n' << y << '\n';
	}
}