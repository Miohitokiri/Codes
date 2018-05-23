// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

typedef pair < int, int > pii;
template < class T > using vec = vector < T >;
typedef vec < int > vi;
typedef vec < LL > vl;
#define pb push_back

#define maxN 100005

vi edge[maxN], AP;
vec < pii > bridge;
int L[maxN], parent[maxN], D[maxN];
bool go[maxN];

inline void dfs ( int n, int d ){
	go[n] = true;
	D[n] = L[n] = d++;
	int child = 0;
	bool isAP = false;

	for ( auto i: edge[n] )
		if ( !go[i] ){
			parent[i] = n;
			dfs ( i, d );
			child++;
			if ( D[n] <= L[i] )
				isAP = true;
			if ( D[n] < L[i] )
				bridge.pb ( pii ( min ( n, i ), max ( n, i ) ) );

			L[n] = min ( L[n], L[i] );
		}
		else if ( i != parent[n] )
			L[n] = min ( L[n], D[i] );

	if ( ( parent[n] && isAP ) || ( !parent[n] && child >= 2 ) )
		AP.pb ( n );
}
