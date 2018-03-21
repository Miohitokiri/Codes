#include<bits/stdc++.h>

using namespace std;

#define int long long

struct node{
	node *l, *r;
	vector < int > data;
	node ( void ): l ( nullptr ), r ( nullptr ){
		if (!data.empty() )
			data.clear();
	}

	inline void up ( int L, int R ){
		data.resize ( R - L + 1 );
		merge ( l -> data.begin(), l -> data.end(), r -> data.begin(), r -> data.end(), data.begin() );
	}
} *root;

int Index, value;
vector < int > stop;

inline node *build ( int l, int r ){
	node *o = new node();
	if ( l == r )
		return o;
	int mid = ( l + r ) >> 1;
	o -> l = build ( l, mid );
	o -> r = build ( mid + 1, r );
	return o;
}

inline void insert ( int l, int r, node *o ){
	if ( l == r ){
		o -> data.clear();
		o -> data.push_back ( value );
	}
	else{
		int mid = ( l + r ) >> 1;
		if ( Index <= mid )
			insert ( l, mid, o -> l );
		else
			insert ( mid + 1, r, o -> r );

		o -> up ( l, r );
	}
}

inline void query ( int l, int r, int nowL, int nowR, node *o ){
	if ( !o )
		return;
	if ( l <= nowL && nowR <= r ){
		for ( auto i: o -> data )
			stop.push_back ( i );
		return;
	}
	int nowMid = ( nowL + nowR ) >> 1;
	if ( nowMid < l )
		query ( l, r, nowMid + 1, nowR, o -> r );
	else if ( r <= nowMid )
		query ( l, r, nowL, nowMid, o -> l );
	else{
		query ( l, nowMid, nowL, nowMid, o -> l );
		query ( nowMid + 1, r, nowMid + 1, nowR, o -> r );
	}
}

inline bool cmp ( int a, int b ){
	return a > b;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, q, l, r, k;
	cin >> n >> q;
	n--;
	root = build ( 0, n );
	for ( int i = 0 ; i <= n ; i++ ){
		cin >> value;
		insert ( 0, n, root );
		Index++;
	}

	while ( q-- ){
		cin >> l >> r >> k;
		stop.clear();
		query ( l, r, 0, n, root );
		sort ( stop.begin(), stop.end() );
		cout << stop[n - k + 1] << '\n';
	}
}