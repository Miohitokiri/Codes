#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
struct func{
	int x1, y1, x2, y2;
};

int main(){
	// ios::sync_with_stdio ( false );
	// cin.tie ( 0 );

	int n;
	double stop;
	pair < int, int > data[1005];
	map < long double, func > m;
	cin >> n;
	func push, l;
	bool ans = false, s;

	for ( int i = 0 ; i < n ; i++ ){
		data[i].x = i + 1;
		cin >> data[i].y;
	}

	for ( int i = 0 ; i < n ; i++ ){
		for ( int j = 0 ; j < i ; j++ ){
			if ( i == j )
				continue;
			else if ( data[i].x == data[j].x ){
				if ( s && ( data[i].x != l.x1  || data[i].x != l.x2 || data[j].x != l.x1 || data[j].x != l.x2 ) ){
					ans = true;
					break;
				}
				else{
					s = true;
					l.x1 = data[i].x, l.x2 = data[j].x, l.y1 = data[i].y, l.y2 = data[j].y;
				}
			}
			else{
				stop = ( double ) ( data[i].y - data[j].y ) / ( data[i].x - data[j].x );
				cout << stop << '\n'; // del
				printf ( "i: ( %d, %d )\nj: ( %d, %d )\n", data[i].x, data[i].y, data[j].x, data[j].y ); // del

				push = m[stop];
				if ( m.find ( stop ) != m.end() ){
					if ( ( ( data[i].x == push.x1 && data[i].y == push.y1 ) || ( data[i].x == push.x2 && data[i].y == push.y2 ) ) || ( ( data[j].x == push.x1 && data[j].y == push.y1 ) || ( data[j].x == push.x2 && data[j].y == push.y2 ) ) )
						continue;
					cout << 111 << '\n'; // del
					ans = true;
					break;
				}
				else{
					push.x1 = data[i].x, push.x2 = data[j].x, push.y1 = data[i].y, push.y2 = data[j].y;
					m[stop] = push;
				}
			}
		}

		if ( ans )
			break;
	}

	cout << ( ans ? "Yes" : "No" ) << '\n';

}