// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

struct node{
	node *l, *r;
	int value, pri, lSum, rSum, maSum, size, sum;
	bool rev, mod;

	node ( int _value ){
		l = r = nullptr;
		pri = rand();
		size = 1;
		lSum = rSum = maSum = sum = value = _value;
		rev = mod = false;
	}

	~node(){
		if ( l )
			delete l;
		if ( r )
			delete r;
	}
} *root;

inline int SZ ( node *o ){
	return o ? o -> size : 0;
}

inline void reverse ( node *o ){
	o -> rev ^= 1;
	swap ( o -> l, o -> r );
	swap ( o -> lSum, o -> rSum );
}

inline void modify ( node *o, int value ){
	o -> mod = true;
	o -> value = value;
	o -> sum = value * o -> size;
	o -> lSum = o -> rSum = o -> maSum = ( value < 0 ? value : o -> sum );
}

inline void down ( node *o ){
	if ( o -> rev ){
		if ( o -> l )
			reverse ( o -> l );
		if ( o -> r )
			reverse ( o -> r );
		o -> rev = false;
	}
	if ( o -> mod ){
		if ( o -> l )
			modify ( o -> l, o -> value );
		if ( o -> r )
			modify ( o -> r, o -> value );
		o -> mod = false;
	}
}

inline void pullUp ( node *p, node *l, node *r ){
	if ( !l || !r )
		return;
	p -> maSum = max ( max ( l -> maSum, r -> maSum ), l -> rSum + r -> lSum );
	p -> lSum = max ( l -> lSum, l -> sum + r -> lSum );
	p -> rSum = max ( r -> rSum, l -> rSum + r -> sum );
	p -> sum = l -> sum + r -> sum;
}

inline void up ( node *o ){
	o -> size = SZ ( o -> l ) + SZ ( o -> r ) + 1;
	o -> sum = o -> maSum = o -> lSum = o -> rSum = o -> value;
	pullUp ( o, o -> l, o );
	pullUp ( o, o, o -> r );
}

node *merge ( node *a, node *b ){
	if ( !a || !b )
		return a ? a : b;
	if ( a -> pri < b -> pri ){
		down ( a );
		a -> r = merge ( a -> r, b );
		up ( a );
		return a;
	}
	down ( b );
	b -> l = merge ( a, b -> l );
	up ( b );
	return b;
}

void split ( node *o, node *&a, node *&b, int k ){
	if ( !o ){
		a = b = nullptr;
		return;
	}
	down ( o );
	if ( SZ ( o -> l ) < k ){
		a = o;
		split ( a -> r, a -> r, b, k - SZ ( o -> l ) - 1 );
		up ( a );
	}
	else{
		b = o;
		split ( b -> l, a, b -> l, k );
		up ( b );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	srand ( clock() );
	root = nullptr;
	int n, m, value, p, k;
	string type;
	cin >> n >> m;
	while ( n-- ){
		cin >> value;
		root = merge ( root, new node ( value ) );
	}

	while ( m-- ){
		cin >> type;
		if ( type == "INSERT" ){
			cin >> p >> k;
			node *l, *tmp = nullptr;
			split ( root, l, root, p );
			while ( k-- ){
				cin >> value;
				tmp = merge ( tmp, new node ( value ) );
			}

			root = merge ( merge ( l, tmp ), root );
		}
		else if ( type == "DELETE" ){
			cin >> p >> k;
			p--;
			node *l, *r;
			split ( root, root, r, p + k );
			split ( root, l, root, p );
			delete root;
			root = merge ( l, r );
		}
		else if ( type == "MAKE-SAME" ){
			cin >> p >> k >> value;
			p--;
			node *l, *r;
			split ( root, root, r, p + k );
			split ( root, l, root, p );
			modify ( root, value );
			root = merge ( merge ( l, root ), r );
		}
		else if ( type == "REVERSE" ){
			cin >> p >> k;
			p--;
			node *l, *r;
			split ( root, root, r, p + k );
			split ( root, l, root, p );
			reverse ( root );
			root = merge ( merge ( l, root ), r );
		}
		else if ( type == "GET-SUM" ){
			cin >> p >> k;
			p--;
			node *l, *r;
			split ( root, root, r, p + k );
			split ( root, l, root, p );
			cout << ( root ? root -> sum : 0 ) << '\n';
			root = merge ( merge ( l, root ), r );
		}
		else
			cout << ( root ? root -> maSum : 0 ) << '\n';
	}
}
