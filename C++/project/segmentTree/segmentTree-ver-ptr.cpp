// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node *l, *r;
	node ( int d ): data ( d ), l ( nullptr ), r ( nullptr ){}
	inline void up ( void ){
		data = -1;
		if ( l )
			data = max ( data, l -> data );
		if ( r )
			data = max ( data, r -> data );
	}
} *root;

node *build ( int l, int r ){
	node *o = new node ( 0 );
	if ( l == r )
		return o;
	int mid = ( l + r ) >> 1;
	o -> l = build ( l, mid );
	o -> r = build ( mid + 1, r );
	return o;
}

void insert ( int l, int r, int index, int value, node *&o ){
	if ( l == r )
		o -> data = value;
	else{
		int mid = ( l + r ) >> 1;
		if ( index <= mid )
			insert ( l, mid, index, value, o -> l );
		else
			insert ( mid + 1, r, index, value, o -> r );

		o -> up();
	}
}

int query ( int l, int r, int nowL, int nowR, node *o ){
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