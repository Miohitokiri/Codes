// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 105

int BIT[maxN][maxN], n = 100, m = 100;

inline void add ( int x, int y, int in ){
	for ( int i = x ; i <= n ; i += i & -i )
		for ( int j = y ; j <= m ; j += j & -j )
			BIT[i][j] += in;
}

inline int sum ( int x, int y, int in ){
	int res = 0;
	for ( int i = x ; i ; i -= i & -i )
		for ( int j = y ; j ; j -= j & -j )
			res += BIT[i][j];

	return res;
}