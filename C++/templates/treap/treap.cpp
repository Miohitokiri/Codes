// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

struct node{
	node *leftSon, *rightSon;
	int key, pri, sz, rev;
	node ( int k ): leftSon ( nullptr ), rightSon ( nullptr ), key ( k ), pri ( rand() ), sz ( 1 ), rev ( 0 ){}

	inline void up ( void ){
		sz = 1;
		if ( leftSon )
			sz += leftSon -> sz;
		if ( rightSon )
			sz += rightSon -> sz;
	}

	inline void down ( void ){
		if ( rev ){
			swap ( leftSon, rightSon );
			if ( leftSon )
				leftSon -> rev = rev;
			if ( rightSon )
				rightSon -> rev = rev;
			rev = false;
		}
	}
};

inline int sz ( node *o ){
	return o ? o -> sz : 0;
}

inline node *merge ( node *a, node *b ){
	if ( !a || !b )
		return a ? a : b;
	if ( a -> pri < b -> pri ){
		a -> down();
		a -> rightSon = merge ( a -> rightSon, b );
		a -> up();
		return a;
	}
	else{
		b -> down();
		b -> leftSon = merge ( a, b -> leftSon );
		b -> up();
		return b;
	}
}

inline void split ( node *o, node *&a, node *&b, int k ){
	if ( !o )
		a = b = nullptr;
	else{
		o -> down();
		if ( o -> key < k ){
			a = o;
			split ( o -> rightSon, a -> rightSon, b, k );
		}
		else{
			b = o;
			split ( o -> leftSon, a, b -> leftSon, k );
		}
		o -> up();
	}
}

inline void insert ( node *&root, int k ){
	node *a, *b;
	split ( root, a, b, k );
	root = merge ( a, merge ( new node ( k ), b ) );
}

inline bool erase ( node *&o, int k ){
	if ( !o )
		return false;
	if ( o -> key == k ){
		node *t = o;
		o = merge ( o -> leftSon, o -> rightSon );
		delete t;
		return true;
	}
	node *&t = k < o -> key ? o -> leftSon : o -> rightSon;
	if ( erase ( t, k ) )
		return o -> up(), true;
	return false;
}

inline bool find ( node *o, int k ){
	if ( !o )
		return false;
	if ( o -> key == k )
		return true;
	if ( k < o -> key )
		return find ( o -> leftSon, k );
	else
		return find ( o -> rightSon, k );
}

inline int Rank ( node *&root, int k ){
	node *a, *b;
	split ( root, a, b, k );
	int res = sz ( a );
	root = merge ( a, b );
	return res;
}

inline void splitK ( node *o, node *&a, node *&b, int k ){
	if ( !o ){
		a = b = nullptr;
		return;
	}
	o -> down();
	if ( sz ( o -> leftSon ) < k ){
		a = o;
		splitK ( a -> rightSon, a -> rightSon, b, k - sz ( o -> leftSon ) - 1 );
		a -> up();
	}
	else{
		b = o;
		splitK ( b -> leftSon, a, b -> leftSon, k );
		b -> up();
	}
	o -> up();
}

inline int kth ( node *&root, int k ){
	node *a, *b, *c;
	splitK ( root, a, c, k );
	splitK ( a, a, b, k - 1 );
	root = merge ( a, merge ( b, c ) );
	return b -> key;
}

inline void reverse ( node *root, int l, int r ){
	node *a, *b, *c;
	splitK ( root, a, b, l - 1 );
	splitK ( b, b, c, r - l + 1 );
	b -> rev ^= 1;
	root = merge ( a, merge ( b, c ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	srand ( clock () );
	int n, stop, q, k;
	cin >> n >> q >> stop;
	n--;
	node *root = new node ( stop );
	while ( n-- ){
		cin >> stop;
		insert ( root, stop );
	}

	while ( q-- ){
		cin >> k;
		cout <<  ( find ( root, k ) ? "Yes" : "No" ) << '\n';
	}
}