#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int x1, y1, x2, y2;
	while ( cin >> x1 >> y1 >> x2 >> y2 ){
		if ( !x1 && !x2 && !y1 && !y2 )
			break;
		if ( x1 == x2 && y1 == y2 )
			cout << 0 << '\n';
		else{
			if ( y1 == y2 || x1 == x2 )
				cout << 1 << '\n';
			else if ( abs ( x2 - x1 ) == abs ( y2 - y1 ) )
				cout << 1 << '\n';
			else
				cout << 2 << '\n';
		}
	}
}