// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

const int maxN = 100005;
typedef pair < int, int > pii;
#define pb push_back

vector < int > edges[maxN];
int D[maxN], L[maxN], tms;
vector < int > AP;
vector < pii > bridge;

void dfs ( int n, int p ){
	D[n] = V[n] = tms++;
	int cnt = 0;
	bool isAP = false;

	for ( auto i: edges[n] ){
		if ( i == p )
			continue;
		if ( !D[i] ){
			dfs ( i, n );
			cnt++;
			if ( D[n] <= L[i] )
				isAP = true;
			if ( D[n] < L[i] )
				bridge.pb ( pii ( v, w ) );
			L[n] = min ( L[n], L[i] );
		}
	}
	if ( n == p && cnt < 2 )
		isAP = false;
	if ( isAP )
		AP.pb ( n );
}