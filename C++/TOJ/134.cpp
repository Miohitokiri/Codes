#include<bits/stdc++.h>

using namespace std;

#define maxN 128

short a[maxN], b[maxN], tmp[maxN];

inline void bigPrint ( short *big ){
	int i = maxN - 1;
	while ( i && !big[i] )
		i--;
	while ( i >= 0 )
		cout << big[i--];

	cout << '\n';
}

inline void bigChange ( short *a, short  *b ){
	int i = maxN - 1;
	while ( i && !b[i] )
		i--;
	while ( i >= 0 )
		a[i] = b[i], i--;
}

inline void bigAdd ( short *Index, short *a, short *b ){
	int i, sum, add;
	for ( add = i = 0 ; i < maxN ; i++ ){
		Index[i] = a[i] + b[i] + add;
		add = Index[i] / 10;
		Index[i] %= 10;
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	b[0] = 1;
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ ){
		bigAdd ( tmp, a, b );
		bigChange ( a, b );
		bigChange ( b, tmp );
	}

	bigPrint ( a );
}