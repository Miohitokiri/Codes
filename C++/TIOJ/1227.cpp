// by. MiohitoKiri5474
// #include<bits/stdc++.h>
#include "lib1227.h"

using namespace std;

#define maxN 1000005

long long seg[maxN * 4], N;
long long *basic;

inline void update ( int l, int r, int n, int Index, int value ){
	if ( l == r )
		seg[n] = value;
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( Index <= mid )
			update ( l, mid, leftSon, Index, value );
		else
			update ( mid + 1, r, rightSon, Index, value );
	}
}

inline void modify ( int l, int r, int nowL, int nowR, long long value, int n ){
	if ( l <= nowL && nowR <= r )
		seg[n] += value;
	else{
		int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( r <= mid )
			modify ( l, r, nowL, mid, value, leftSon );
		else if ( mid < l )
			modify ( l, r, mid + 1, nowR, value, rightSon );
		else{
			modify ( l, mid, nowL, mid, value, leftSon );
			modify ( mid + 1, r, mid + 1, nowR, value, rightSon );
		}
	}
}

inline long long www ( int l, int r, int Index, int n ){
	if ( l == r )
		return seg[n];
	int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( Index <= mid )
		return seg[n] + www ( l, mid, Index, leftSon );
	else
		return seg[n] + www ( mid + 1, r, Index, rightSon );
}

inline void init ( int n, long long D[] ){
	N = n - 1;
	basic = D;
}

inline void change ( int a, int b, long long k ){
	modify ( a, b, 0, N, k * ( a & 1 ? 1 : -1 ), 1 );
}

inline long long query ( int c ){
	return www ( 0, N, c, 1 ) * ( c & 1 ? -1 : 1 ) + basic[c];
}