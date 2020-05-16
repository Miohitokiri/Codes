// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
int D[maxN], L[maxN], tms;
vector < int > edges[maxN], AP;
vector < pair < int, int > > bridge;

void dfs ( int n, int p ){
	D[n] = L[n] = tms++;
	int cnt = 0;
	bool isAP = false;

	for ( auto i: edges[n] ){
		if ( i == p )
			continue;
		if ( !D[i] ){
			dfs ( i, n );
			cnt++;
			if ( D[n] <= L[i] ){
				isAP = true;
				bridge.push_back ( make_pair ( n, i ) );
			}
			L[n] = min ( L[n], L[i] );
		}
	}

	if ( n == p && cnt < 2 )
		isAP = false;
	if ( isAP )
		AP.push_back ( n );
}

int main(){
	dfs ( 0, 0 );
}