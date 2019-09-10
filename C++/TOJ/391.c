#include<stdio.h>

const int maxN = 200005;

int seg[maxN << 2];

int max ( int a, int b ){
	if ( a > b )
		return a;
	return b;
}

void update ( int l, int r, int index, int value, int n ){
	if ( l == r )
		seg[n] += value;
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( index <= mid )
			update ( l, mid, index, value, leftSon );
		else
			update ( mid + 1, r, index, value, rightSon );

		seg[n] = max ( seg[leftSon], seg[rightSon] );
	}
}

void modify ( int l, int r, int nowL, int nowR, int value, int n ){
	if ( seg[n] < value )
		return;
	else if ( nowL == nowR )
		seg[n] %= value;
	else{
		int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( r <= mid )
			modify ( l, r, nowL, mid, value, leftSon );
		else if ( mid < l )
			modify ( l, r, mid + 1, nowR, value, rightSon );
		else{
			modify ( l, r, nowL, mid, value, leftSon );
			modify ( l, r, mid + 1, nowR, value, rightSon );
		}

		seg[n] = max ( seg[leftSon], seg[rightSon] );
	}
}

int main(){
	int n, m, k, in, l, r, i;
	scanf ( "%d", &n );
	n--;
	for ( i = 0 ; i <= n ; i++ ){
		scanf ( "%d", &in );
		update ( 0, n, i, in, 1 );
	}
	scanf ( "%d", &m );
	while ( m-- ){
		scanf ( "%d", &k );
		if ( k == 1 ){
			scanf ( "%d %d", &l, &r );
			update ( 0, n, r, l, 1 );
		}
		else if ( k == 2 ){
			scanf ( "%d %d %d", &l, &r, &in );
			modify ( l, r, 0, n, in, 1 );
		}
		else if ( k == 3 )
			printf ( "%d\n", seg[1] );
	}
}