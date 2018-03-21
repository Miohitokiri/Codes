//最大值查詢
#include<bits/stdc++.h>

using namespace std;


int heap[105], sz = 0;
inline void push ( int x );
inline void pop ( void );

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, stop;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> stop;
		push ( stop );
	}

	cout << heap[0] << '\n';

	for ( int i = 0 ; i < 2 * n ; i++ )
		cout << heap[i] << ' ';
	cout << '\n';
}

inline void push ( int x ){
	int i = sz++;

	while ( i > 0 ){
		int p = ( i - 1 ) / 2;

		if ( heap[p] <= x )
			break;
		swap ( heap[i], heap[p] );
		i = p;
	}
}

inline void pop ( void ){
	int ret = heap[0];

	int x = heap[--sz];

	int i = 0;
	while ( i * 2 + i < sz ){
		int leftSon = i * 2 + 1, rightSon = i * 2 + 2;
		if ( rightSon < sz && heap[rightSon] < heap[leftSon] )
			leftSon = rightSon;

		if ( heap[leftSon] >= x )
			break;
		heap[i] = heap[leftSon];
		i = leftSon;
	}
}