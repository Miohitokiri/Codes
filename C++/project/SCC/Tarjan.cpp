#include<bits/stdc++.h>

using namespace std;

#define maxN 10005

vector < int > edges[maxN];
int L[maxN], D[maxN], id;
stack < int > st;

inline void dfs ( int n, int p, int dep ){
	D[n] = L[n] = dep++;
	st.push ( n );
	for ( auto i: edges[n] ){
		if ( i == p )
			continue;
		if ( !D[i] ){
			dfs ( i, p, dep );
			L[n] = min ( L[n], L[i] );
		}
		L[n] = min ( L[n], D[i] );
	}

	if ( D[n] == L[n] ){
		int x;
		do{
			x = st.top();
			st.pop();
			scc[x] = id;
		} while ( x != n );
		id++;
	}
}
