#include<bits/stdc++.h>

using namespace std;

struct Data{
	int w, v;
} data[10005];

inline bool operator < ( Data a, Data b ){
	return a.v * b.w < b.v * a.w;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, v;
	double ans = 0;
	cin >> n >> v;
	for ( int i = 0 ; i < n ; i++ )
		cin >> data[i].v >> data[i].w;

	sort ( data, data + n );

	for ( int i = n - 1 ; i >= 0 && v > 0 ; i-- ){
		// ans += ( v >= data[i].w ? data[i].v : data[i].v * v / data[i].w ) * 1.0;
		if ( v >= data[i].w )
			ans += data[i].v;
		else
			ans += 1.0 * data[i].v * v / data[i].w;
		v -= data[i].w;
	}

	printf ( "%.3f\n", ans );
}