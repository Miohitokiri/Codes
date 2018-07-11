// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using std::string;
using std::cin;
using std::cout;
using std::swap;

typedef long long LL;

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define NEG_INF 0x8f8f8f8f
#define maxN 100005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

struct node{
	node *l, *r;
	char val;
	int sz;
	bool rev;

	node ( char _val ){
		l = r = nullptr;
		val = _val;
		rev = false;
		sz = 1;
	}

	node ( node *o ): l ( o -> l ), r ( o -> r ), val ( o -> val ), rev ( o -> rev ), sz ( o -> sz ) {}

	inline void up ( void ){
		sz = 1 + ( l ? l -> sz : 0 ) + ( r ? r -> sz : 0 );
	}

	inline void down ( void ){
		if ( !rev )
			return;
		swap ( l, r );
		if ( l ){
			l = new node ( *l );
			l -> rev ^= 1;
		}
		if ( r ){
			r = new node ( *r );
			r -> rev ^= 1;
		}
		rev ^= 1;
	}
};

inline int ran(){
	static int x = 20180711;
	return x = ( x * 0xdefaced + 1) & INT_MAX;
}

inline int SZ ( node *o ){
	return o ? o -> sz : 0;
}

node *merge ( node *a, node *b ){
	if ( !a || !b )
		return a ? a : b;
	if ( ran() % ( a -> sz + b -> sz ) < a -> sz ){
		a = new node ( *a );
		a -> down();
		a -> r = merge ( a -> r, b );
		a -> up();
		return a;
	}
	b = new node ( *b );
	b -> down();
	b -> l = merge ( a, b -> l );
	b -> up();
	return b;
}

void split ( node *o, node *&a, node *&b, int k ){
	if ( !o ){
		a = b = nullptr;
		return;
	}
	o = new node ( *o );
	o -> down();
	if ( SZ ( o -> l ) < k ){
		a = o;
		split ( o -> r, a -> r, b, k - SZ ( o -> l ) - 1 );
		a -> up();
	}
	else{
		b = o;
		split ( o -> l, a, b -> l, k );
		b -> up();
	}
	o -> up();
}

void dfs ( node *o, bool rev ){
	if ( !o )
		return;
	rev ^= o -> rev;
	if ( rev ){
		dfs ( o -> r, rev );
		putchar ( o -> val );
		dfs ( o -> l, rev );
	}
	else{
		dfs ( o -> l, rev );
		putchar ( o -> val );
		dfs ( o -> r, rev );
	}
}

int main(){
	int t, n, m, _l, _r, type;
	node *root, *l, *r, *swp, *mid;
	char str[maxN];
	scanf ( "%d", &t );
	while ( t-- ){
		scanf ( "%d%d%s", &n, &m, str );
		root = nullptr;
		for ( int i = 0 ; i < n ; i++ ){
			root = merge ( root, new node ( str[i] ) );
		}

		while ( m-- ){
			scanf ( "%d%d%d", &type, &_l, &_r );
			split ( root, swp, r, _r );
			split ( swp, l, mid, _l - 1 );
			if ( type == 1 ){
				dfs ( mid, 0 );
				puts ( "" );
			}
			else if ( type == 2 ){
				root = merge ( merge ( swp, mid ), r );
			}
			else{
				mid -> rev ^= 1;
				root = merge ( merge ( l, mid ), r );
			}
		}
	}
}