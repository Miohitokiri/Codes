#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef pair < double, double > pdd;

vector < pdd > dot;
const double INF = 1e9;

inline double disten ( pdd a, pdd b ){
	return sqrt ( pow ( ( a.x - b.x ), 2 ) + pow ( ( a.y - b.y ), 2 ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	double mi = INF;
	pdd stop;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> stop.x >> stop.y;
		dot.push_back ( stop );
	}

	if ( n == 2 )
		mi = disten ( dot[0], dot[1] );
	else{
		sort ( dot.begin(), dot.end() );

		for ( int i = 0 ; i < n ; i++ )
			for ( int j = i + 1 ; j < n ; j++ ){
				if ( dot[j].x - dot[i].x >= mi || dot[j].y - dot[i].y >= mi )
					break;
				mi = min ( mi, disten ( dot[i], dot[j] ) );
			}
	}

	printf ( "%.6f\n", mi );
}