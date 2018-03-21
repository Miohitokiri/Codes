// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

// define tools
#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define REPALL(i,n) for ( auto &i: n )
#define MEM(n,i) memset ( n, i, sizeof n )

// define vector && some stl's api
template < class T > using vec = vector < T >;
typedef vec < int > vi;
#define pb push_back
#define REV reverse
#define EMP(n) n.empty()
#define RSZ(n,s) n.resize ( s )
#define GETDATA(data,n) RSZ ( data, n ); REPALL ( i, data ) cin >> i

// graph
#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define maxN 100005

GRE ( int, edge );
int d, dis[maxN];
vi data;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, u, v, sum = 0, now;
	queue < int > q;
	cin >> n >> m;
	GETDATA ( data, n );
	while ( m-- ){
		cin >> u >> v;
		UNI ( u, v, edge );
	}
	cin >> d;

	REPP ( i, 0, n ) dis[i] = INF;
	q.push ( 0 );
	dis[0] = 0;
	while ( !EMP ( q ) ){
		now = q.front();
		q.pop();
		if ( dis[now] > d )
			continue;
		REPALL ( i, edge[now] ) if ( dis[i] > dis[now] + 1 ){
			q.push ( i );
			dis[i] = dis[now] + 1;
		}
	}

	REPP ( i, 0, n ) if ( dis[i] <= d ) sum += data[i];
	cout << sum << '\n';
}