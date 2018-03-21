#include<bits/stdc++.h>

using namespace std;

#define int double

struct sausage{
	int x, y, r;
};

#undef int

int main() {
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int double

	int r, d, n, ans = 0;
	double disten;
	cin >> r >> d >> n;
	vector < sausage > data;
	sausage stop;

	while ( n-- ){
		cin >> stop.x >> stop.y >> stop.r;
		data.push_back ( stop );
	}

	for ( auto i: data ){
		disten = sqrt ( i.x * i.x + i.y * i.y );
		disten - i.r >= r - d && disten + i.r <= r ? ans++ : ans;
	}

	cout << ans << '\n';
}