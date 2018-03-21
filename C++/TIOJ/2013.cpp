// by. MiohitoKiri5474
#include<vector>
#include "lib2013.h"

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using std::vector;

// define tools
#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define REPALL(i,n) for ( auto &i: n )

// define vector && some stl's api
template < class T > using vec = vector < T >;
typedef vec < int > vi;
#define pb push_back
#define CLR(n) n.clear()

#define maxN 1000005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

vi edge[maxN];
int Index, visited[maxN], dep;

inline bool dfs ( int n ){
	visited[n] = dep;
	if ( n == Index )
		return true;
	REPALL ( i, edge[n] )
		if ( visited[i] != dep )
			if ( dfs ( i ) )
				return true;

	return false;
}

inline void init ( int n ){
	n++;
	REPP ( i, 0, n ) CLR ( edge[i] );
}

inline void explore ( int a, int b ){
	edge[a].pb ( b );
}

inline int run ( int a, int b ){
	Index = b;
	dep++;
	return dfs ( a );
}