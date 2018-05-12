// by. MiohitoKiri5474
#include<bits/stdc++.h>

// 加速用，編譯器優化
#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

struct node{
	node *leftSon, *rightSon;
	int val;

	// 建構子
	node ( int _val ): val ( _val ), leftSon ( nullptr ), rightSon ( nullptr ) {}
} *root;

inline void insert ( int n, node *&o ){ // 用*&直接對指標做修改，不用回傳
	if ( !o ) // 如果是空的樹，建構一顆新的
		o = new node ( n );
	else{
		if ( n > o -> val ) // 較大，往右遞迴
			insert ( n, o -> rightSon );
		else // 較小，往左遞迴
			insert ( n, o -> leftSon );
	}
}

inline void print ( node *o ){
	if ( !o ) // 如果這棵樹是空的，結束不繼續遞迴
		return;
	cout << o -> val << ' ';
	// 先往左，再往右
	print ( o -> leftSon );
	print ( o -> rightSon );
}

int main(){
	// 輸入優化
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, in;
	while ( cin >> n >> in ){
		n--;
		root = new node ( in ); // 建構一顆全新的樹
		while ( n-- ){
			cin >> in;
			insert ( in, root );
		}

		print ( root );
		cout << '\n';
	}
}