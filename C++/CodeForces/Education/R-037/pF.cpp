// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define maxN 300005

LL sum[maxN << 2], dp[1000005];
bool used[maxN << 2];
vector < int > prime;
bitset < 1005 > lib;

inline int D ( int n ){
	if ( dp[n] != -1 )
		return dp[n];
	double www = sqrt ( n );
	int ma = www, res = 0, maa = ma + 1;
	for ( int i = 1 ; i < maa ; i++ )
		n % i ? res : res++;

	return dp[n] = res * 2 - ( www == ma ? 1 : 0 );
}

inline void build ( int l, int r, int n ){
	if ( l == r ){
		cin >> sum[n];
		used[n] = ( sum[n] > 2 );
	}
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		build ( l, mid, leftSon );
		build ( mid + 1, r, rightSon );

		sum[n] = sum[leftSon] + sum[rightSon];
		used[n] = ( used[leftSon] || used[rightSon] );
	}
}

inline LL query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return sum[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon );
	return query ( l, r, nowL, mid, leftSon ) + query ( l, r, mid + 1, nowR, rightSon );
}

inline void modify ( int l, int r, int nowL, int nowR, int n ){
	if ( !used[n] )
		return;
	if ( nowL == nowR ){
		sum[n] = D ( sum[n] );
		used[n] = ( sum[n] > 2 );
	}
	else{
		int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( r <= mid )
			modify ( l, r, nowL, mid, leftSon );
		else if ( mid < l )
			modify ( l, r, mid + 1, nowR, rightSon );
		else{
			modify ( l, r, nowL, mid, leftSon );
			modify ( l, r, mid + 1, nowR, rightSon );
		}

		sum[n] = sum[leftSon] + sum[rightSon];
		used[n] = ( used[leftSon] || used[rightSon] );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	lib[0] = lib[1] = true;
	for ( int i = 2 ; i < 1005 ; i++ ){
		if ( !lib[i] ){
			prime.push_back ( i );
			for ( int j = i << 1 ; j < 1005 ; j += i )
				lib[j] = true;
		}
	}

	memset ( dp, -1, sizeof dp );
	int n, m, type, l, r, stop;
	cin >> n >> m;
	build ( 1, n, 1 );

	while ( m-- ){
		cin >> type >> l >> r;
		if ( type == 1 )
			modify ( l, r, 1, n, 1 );
		else
			cout << query ( l, r, 1, n, 1 ) << '\n';
	}
}