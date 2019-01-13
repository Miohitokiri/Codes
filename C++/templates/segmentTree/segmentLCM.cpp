#include<bits/stdc++.h>
#pragma GCC optimize ("O3")

using namespace std;

#define int long long
#define mod 1000000009

int seg[100005 * 4], Index, value;

inline int gcd ( int a, int b ){
	while ( a % b && b % a )
		a > b ? a %= b : b %= a;
	return min ( a, b );
}

inline int lcm ( int a, int b ){
	return a * b / gcd ( a, b ) % mod;
}

inline void update ( int l, int r, int n ){
	if ( l == r ){
		cin >> seg[n];
		seg[n] %= mod;
	}
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon + 1;
		if ( mid < Index )
			update ( mid + 1, r, rightSon );
		else
			update ( l, mid, leftSon );

		if ( !seg[leftSon] || !seg[rightSon] )
			return;

		seg[n] = lcm ( seg[leftSon], seg[rightSon] ) % mod;
	}
}

inline int query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int nowMid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon + 1;
	if ( r <= nowMid )
		return query ( l, r, nowL, nowMid, leftSon );
	else if ( nowMid < l )
		return query ( l, r, nowMid + 1, nowR, rightSon );
	else
		return lcm ( query ( l, nowMid, nowL, nowMid, leftSon ), query ( nowMid + 1, r, nowMid + 1, nowR, rightSon ) ) % mod;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, l, r, q;
	cin >> n >> q;
	n--;
	
	for ( Index = 0 ; Index <= n ; Index++ )
		update ( 0, n, 1 );

	while ( q-- ){
		cin >> l >> r;
		cout << query ( l, r, 0, n, 1 ) << '\n';
	}
}