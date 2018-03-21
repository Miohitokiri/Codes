#include<bits/stdc++.h>
#define maxN 100005

using namespace std;

int seg[maxN * 4], Index, basic[maxN];

inline void build ( int l, int r, int n ){
	if ( l == r )
		seg[n] = 1;
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon + 1;
		if ( Index <= mid )
			build ( l, mid, leftSon );
		else
			build ( mid + 1, r, rightSon );
	}
}

inline void modify ( int l, int r, int nowL, int nowR, int n ){
	if ( l == r )
		seg[n] = value;
	else{
		int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon + 1;
		if ( r <= mid )
			modify ( l, r, nowL, mid, leftSon );
		else if ( mid < l )
			modify ( l, r, mid + 1, nowR, rightSon );
		else{
			modify ( l, mid, nowL, mid, leftSon );
			modify ( mid + 1, r, mid + 1, nowR, rightSon );
		}
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
}