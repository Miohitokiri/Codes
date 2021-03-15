// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
typedef pair < int, int > pii;
#define pb push_back

vector < int > edges[maxN];
int D[maxN], L[maxN], tms;
vector < int > AP;
vector < pii > bridge;

void dfs ( int n, int p, int dep ){
	D[n] = L[n] = dep++;
	int cnt = 0;
	bool isAP = false;

	for ( auto i: edges[n] ){
		if ( !D[i] ){
			dfs ( i, n, dep );
			cnt++;
			if ( D[n] <= L[i] )
				isAP = true;
			if ( D[n] < L[i] )
				bridge.pb ( pii ( n, i ) );
			L[n] = min ( L[n], L[i] );
		}
		else if ( i != p )
			L[n] = min ( L[n], D[i] );
	}
	if ( n == p && cnt < 2 )
		isAP = false;
	if ( isAP )
		AP.pb ( n );
}
