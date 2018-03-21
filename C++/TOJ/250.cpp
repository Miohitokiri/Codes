#include<bits/stdc++.h>
#define maxn 1000005

using namespace std;

int seg[maxn * 4], Index, v;
inline void modify ( int l, int r, int n ){
	if ( l == r )
		seg[n] += v;
	else{
		int leftSon = n * 2, rightSon = leftSon + 1, mid = ( l + r ) >> 1;
		if ( mid < Index )
			modify ( mid + 1, r, rightSon );
		else
			modify ( l, mid, leftSon );

		seg[n] = max ( seg[leftSon], seg[rightSon] );
	}
}

inline void print ( int l, int r, int n ){
	if ( l == r )
		cout << seg[n] << '\n';
	else{
		int mid = ( l + r ) >> 1;
		print ( l, mid, n * 2 );
		print ( mid + 1, r, n * 2 + 1 );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, q, l, r, stop, leftSon, rightSon, type;
	cin >> n >> q;
	n--;
	while ( q-- ){
		cin >> type;
		if ( type == 1 ){
			cin >> Index >> v;
			Index--;
			modify ( 0, n, 1 );
		}
		else{
			cin >> v;
			l = 0, r = n, stop = 1;
			while ( l != r ){
				leftSon = stop * 2, rightSon = leftSon + 1;
				if ( seg[stop] == seg[leftSon] )
					stop = leftSon, r = ( l + r ) >> 1;
				else
					stop = rightSon, l = ( ( l + r ) >> 1 ) + 1;
			}
			Index = l, v *= -1;
			modify ( 0, n, 1 );
		}
	}
	print ( 0, n, 1 );
}