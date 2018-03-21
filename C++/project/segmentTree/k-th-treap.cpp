#include<bits/stdc++.h>

using namespace std;

struct node{
	node *leftSon, *rightSon;
	int key, pri;
	node ( int k ): leftSon ( 0 ), rightSon ( 0 ), key ( k ), pri ( rand() ){}
};

inline node *merge ( node *a, node * b ){
	if ( !a || !b )
		return a ? a : b;
	if ( a -> pri < b -> pri ){
		a -> rightSon = merge ( a -> rightSon, b );
		return a;
	}
	else{
		b -> leftSon = merge ( a, b -> leftSon );
		return b;
	}
}

inline void *split ( node *o, node *&a, node *&b, int k ){
	if ( !o )
		a = b = nullptr;
	else if ( o -> key < k ){
		a = o;
		split ( o -> rightSon, a -> rightSon, b, k );
	}
	else{
		b = o;
		split ( o -> leftSon, a, b -> leftSon, k );
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
	return erase ( t, k );
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

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

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