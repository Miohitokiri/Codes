#include<bits/stdc++.h>

using namespace std;

#define maxN 10005

vector < int > edges[maxN];
int L[maxN], D[maxN], id, scc[maxN];
stack < int > st;
bool inSt[maxN];

inline void init ( void ){
	memsest ( L, 0, sizeof L );
	memset ( D, 0, sizeof D );
	memset ( scc, -1, sizeof scc );
	memset ( inSt, 0, sizeof inSt );
	id = 0;
	for ( auto &i: edges )
		i.clear();
	st.clear();
}

inline void dfs ( int n, int dep ){
	D[n] = L[n] = dep++;
	st.push ( n );
	for ( auto i: edges[n] ){
		if ( !D[i] ){
			dfs ( i, dep );
			L[n] = min ( L[n], L[i] );
		}
		else if ( inSt[i] )
			L[n] = min ( L[n], D[i] );
	}

	if ( D[n] == L[n] ){
		int x;
		do{
			inSt[x = st.top()] = false;
			st.pop();
			scc[x] = id;
		} while ( x != n );
		id++;
	}
}
