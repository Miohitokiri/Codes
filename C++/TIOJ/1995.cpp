#include<bits/stdc++.h>
// #include "lib1995.h"

using namespace std;

struct node{
	int data;
	node *l, *r;
	node ( int d ): data ( d ), l ( nullptr ), r ( nullptr ){}
	inline void up ( void ){
		if ( !l )
			data = r -> data;
		else if ( !r )
			data = l -> data;
		else
			data = max ( l -> data, r -> data );
	}
} *root;

int value, Index;

inline node *build ( int l, int r ){
	node *o = new node ( 0 );
	if ( l == r )
		return o;
	int mid = ( l + r ) >> 1;
	o -> l = build ( l, mid );
	o -> r = build ( mid + 1, r );
	return o;
}

inline void insert ( int l, int r, node *o ){
	if ( l == r )
		o -> data = value;
	else{
		int mid = ( l + r ) >> 1;
		if ( Index <= mid )
			insert ( l, mid, o -> l );
		else
			insert ( mid + 1, r, o -> r );

		o -> up();
	}
}

inline int query ( int l, int r, int nowL, int nowR, node *o ){
	if ( !o )
		return 0;
	if ( l <= nowL && nowR <= r )
		return o -> data;
	int nowMid = ( nowL + nowR ) >> 1;
	if ( nowMid < l )
		return query ( l, r, nowMid + 1, nowR, o -> r );
	else if ( r <= nowMid )
		return query ( l, r, nowL, nowMid, o -> l );
	else
		return max ( query ( l, nowMid, nowL, nowMid, o -> l ), query ( nowMid + 1, r, nowMid + 1, nowR, o -> r ) );
}

int main(){
	int n, q, l, r;
	vector < pair < int, int > > data;
	scanf ( "%d%d", &n, &q );
	root = build ( 0, n );
	n--;
	while ( q-- ){
		scanf ( "%d%d", &l, &r );
		data.push_back ( make_pair ( --l, --r ) );
	}

	for ( int i = 0 ; i <= n ; i++ ){
		scanf ( "%d", &value );
		insert ( 0, n, root );
		Index++;
	}

	for ( auto i: data )
		printf ( "%d\n", query ( i.first, i.second, 0, n, root ) );
}