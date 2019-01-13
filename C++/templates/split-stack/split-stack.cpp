#include<bits/stdc++.h>

using namespace std;

#define int long long

vector < int > basic, left, right, sumData;

inline int query ( int L, int R ){
	int lData = *lower_bound ( left.begin(), left.end(), L ), rData = *lower_bound ( right.begin(), right.end(), R );
	
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, k, cnt = 0, sum = 0, tms = 0, q, l, r;
	cin >> n;
	k = sqrt ( n );
	basic.resize ( n );
	for ( int i = 0 ; i <  n ; i++ ){
		cin >> basic[i];
		sum += basic[i];
		cnt++;
		if ( cnt == k ){
			sumData.push_back ( sum );
			left.push_back ( k * tms++ + 1 );
			right.push_back ( k * tms );
			sum = cnt = 0;
		}
	}

	sumData.push_back ( sum );
	left.push_back ( k * tms );
	right.push_back ( n );

	cin >> q;
	while ( q-- ){
		cin >> l >> r;
		cout << query ( l, r ) << '\n';
	}
}
