#include<bits/stdc++.h>
#define maxN 10005

using namespace std;

#define int long long

struct disjionSet{
	int dis[maxN], size[maxN];

	inline void Init ( void ){
		for ( int i = 0 ; i < maxN ; i++ ){
			dis[i] = i;
			size[i] = 1;
		}
	}

	inline int find ( int a ){
		return dis[a] == a ? a : dis[a] = find ( dis[a] );
	}

	inline void Union ( int a, int b ){
		a = find ( a ), b = find ( b );
		dis[a] = b;
		size[b] += size[a];
	}

	inline bool same ( int a, int b ){
		return find ( a ) == find ( b );
	}

	inline int getLider ( void ){
		return size[find ( 1 )];
	}
} dis;

struct bridge{
	int u, v, w;
	bridge ( int a, int b, int c ): u ( a ), v ( b ), w ( c ){}
};

vector < bridge > data;
int weigh;

inline bool cmp ( bridge a, bridge b ){
	return a.w < b.w;
}

inline void Kurskal ( void ){
	weigh = 0;
	sort ( data.begin(), data.end(), cmp );

	dis.Init();

	for ( auto i: data ){
		if ( dis.same ( i.u, i.v ) )
			continue;

		weigh += i.w;
		dis.Union ( i.u, i.v );
	}
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, m, u, v, w;
	while ( cin >> n >> m ){
		if ( !n && !m )
			break;
		data.clear();
		while ( m-- ){
			cin >> u >> v >> w;
			data.push_back ( bridge ( u, v, w ) );
		}

		Kurskal();

		cout << ( dis.getLider() == n ? weigh : -1 ) << '\n';
	}
}