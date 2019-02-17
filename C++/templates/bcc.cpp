// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
#define pb push_back
typedef pair < int, int > pii;

vector < int > edges[maxN];
bool visited[maxN];
int L[maxN], D[maxN], cnt;
vector < pii > BCC[maxN], edgeStack;

void dfs ( int n, int p, int dep ){
	visited[n] = true;
	D[n] = L[n] = dep;

	for ( auto i: edges[n] ){
		if ( i == p )
			continue;

		if ( visited[n] && D[i] < dep ){
			edgeStack.pb ( pii ( n, i ) );
			L[n] = min ( L[n], D[i] );
		}
		else{
			edgeStack.pb ( pii ( n, i ) );
			dfs ( i, p, dep + 1 );
			if ( L[i] >= dep ){
				pii t = edgeStack.back();
				edgeStack.pop_back();
				while ( t != pii ( n, i ) ){
					BCC[cnt].pb ( t );
					t = edgeStack.back();
					edgeStack.pop_back();
				}
				BCC[cnt].pb ( t );
				cnt++;
			}
			L[n] = min ( L[n], L[i] );
		}
	}
}
