// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

#define maxN 200005

int seg[maxN << 2];

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
	if ( nowL == nowR )
		seg[n] %= value;
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

		seg[n] = max ( seg[leftSon], seg[rightSon] );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, type, l, r, x, in;
	cin >> n;
	n--;
	for ( int i = 0 ; i <= n ; i++ ){
		cin >> in;
		update ( 0, n, i, in, 1 );
	}

	cin >> m;
	while ( m-- ){
		cin >> type;
		if ( type == 1 ){
			cin >> l >> r;
			update ( 0, n, r, l, 1 );
		}		
		else if ( type == 2 ){
			cin >> l >> r >> x;
			modify ( l, r, 0, n, x, 1 );
		}
		else
			cout << seg[1] << '\n';
	}
}