// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

struct node{
	int value;
	node *leftSon, *rightSon;
	node ( int v ): leftSon ( nullptr ), rightSon ( nullptr ), value ( v ){};
};

node *insert ( node *p, int x );
bool find ( node *p, int x );
node *remove ( node *p, int x );

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	node *root = nullptr;
	int n, q, stop, type;
	cin >> n >> q;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> type >> stop;
		if ( type == 1 )
			root = insert ( root, stop );
		else
			root = remove ( root, stop );
	}

	while ( q-- ){
		cin >> stop;
		cout << ( find ( root, stop ) ? "Yes" : "No" ) << '\n';
	}
}

node *insert ( node *p, int x ){
	if ( p == nullptr ){
		node *q = new node ( x );
		return q;
	}
	else{
		if ( x < p -> value )
			p -> leftSon = insert ( p -> leftSon, x );
		else
			p -> rightSon = insert ( p -> rightSon, x );
		return p;
	}
}

bool find ( node *p, int x ){
	if ( p == nullptr )
		return false;
	if ( x > p -> value )
		return find ( p -> rightSon, x );
	if ( x < p -> value )
		return find ( p -> leftSon, x );
	if ( x == p -> value )
		return true;
	return false;
}

node *remove ( node *p, int x ){
	if ( p == nullptr )
		return nullptr;
	else if ( x < p -> value )
		p -> leftSon = remove ( p -> leftSon, x );
	else if ( x > p -> value )
		p -> rightSon = remove ( p -> rightSon, x );
	else if ( p -> leftSon == nullptr ){
		node *q = p -> rightSon;
		delete p;
		return q;
	}
	else if ( p -> leftSon -> rightSon == nullptr ){
		node *q = p -> leftSon;
		q -> rightSon = p -> rightSon;
		delete p;
		return q;
	}
	else{
		node *q;
		for ( q = p -> leftSon ; q -> rightSon -> rightSon != nullptr ; q = q -> rightSon );
		node *r = q -> rightSon;
		q -> rightSon = r -> leftSon;
		r -> leftSon = p -> leftSon;
		r -> rightSon = p -> rightSon;
		delete p;
		return r;
	}
	return p;
}