// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

struct node{
	int x, y;

	node(){}
	node ( int _x, int _y ): x ( _x ), y ( _y ) {}
};

inline bool cmp ( node a, node b ){
	return a.x < b.x || ( a.x == b.x && a.y < b.y );
}

// Graham
inline void Graham ( vector < node > nodes ){
	sort ( nodes.begin(), nodes.end(), cmp );

	vector < node > res;
	int m = 0;
	for ( auto i: nodes ){ // 凸包下側
		while ( m >= 2 && ( res[m - 1] - res[m - 2] ).cross ( i - res[m - 2] ) <= 0 ) m--;
		p.push_back ( i );
		m++;
	}
}