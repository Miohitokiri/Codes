// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

typedef long long LL;

// define tools
#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define REPM(i,f,s) for ( int i = f ; i >= s ; i-- )
#define REPALL(i,n) for ( auto &i: n )
#define debuger cout << "111\n"
#define MEM(n,i) memset ( n, i, sizeof n )

// define pair
typedef pair < LL, LL > pll;
typedef pair < int, int > pii;
#define F first
#define S second
#define mp make_pair

// define vector && some stl's api
template < class T > using vec = vector < T >;
typedef vec < int > vi;
typedef vec < LL > vl;
#define pb push_back
#define ep emplace_back
#define REV reverse
#define SZ(n) ( int ) n.size()
#define CLR(n) n.clear()
#define BEG(n) n.begin()
#define END(n) n.end()
#define EMP(n) n.empty()
#define RSZ(n,s) n.resize ( s )
#define ALL(n) BEG ( n ), END ( n )
#define PIO(n) REPALL ( i, n ) cout << i << ' '; cout << '\n'
#define GETDATA(data,n) RSZ ( data, n ); REPALL ( i, data ) cin >> i

// define set
typedef set < int > si;
typedef set < LL > sl;
#define FID(n,Index) ( n.find ( Index ) != n.end() )

// graph
#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
#define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )

// IO
#define GL(n) getline ( cin, n )

// define stack, queue, pri-queue
template < class T > using MaxHeap = priority_queue < T, vec < T >, less < T > >;
template < class T > using MinHeap = priority_queue < T, vec < T >, greater < T > >;

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define maxN 100005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

inline bool isNum ( char c ){
	return '0' <= c && c <= '9';
}

inline bool isSma ( char c ){
	return 'a' <= c && c <= 'z';
}

inline bool is ( char c ){
	return isSma ( c ) || ( 'A' <= c && c <= 'Z' );
}

inline map < string, int > dfs ( string str ){
	bool ch = false;
	REPALL ( i, str ){
		if ( i == '(' ){
			ch = true;
			break;
		}
	}

	int num = 0, last;
	string p, now;
	set < string > used;
	map < string, int > lib, stop, res;
	stack < char, vec < char > > s;
	vi data;
	if ( SZ ( str ) == 0 )
		return lib;
	if ( !ch ){
		REPP ( i, 0, SZ ( str ) ){
			p = "";
			p += str[i++];
			if ( isSma ( str[i] ) )
				p += str[i++];
			while ( isNum ( str[i] ) ){
				num *= 10;
				num += ( int ) str[i++] - '0';
			}
			i--;
			if ( !num )
				num++;
			if ( FID ( used, p ) )
				lib[p] += num;
			else{
				lib[p] = num;
				used.insert ( p );
			}
			num = 0;
		}
	}
	else{
		REPM ( i, SZ ( str ) - 1, 0 ){
			if ( str[i] == ')' ){
				last = i;
				break;
			}
		}
		REPP ( i, 0, last ){
			while ( str[i] != ')' && i < SZ ( str ) )
				s.push ( str[i++] );
			now = "";
			while ( s.top() != '(' && !EMP ( s ) ){
				now += s.top();
				s.pop();
			}
			REV ( ALL ( now ) );
			stop = dfs ( now );
			while ( !isNum ( str[i] ) && i < SZ ( str ) )
				i++;
			while ( isNum ( str[i] ) && i < SZ ( str ) ){
				num *= 10;
				num += ( int ) str[i++] - '0';
			}
			if ( num > 1 ){
				for ( auto j = stop.begin() ; j != stop.end() ; j++ )
					j -> S *= num;
			}
			for ( auto j = stop.begin() ; j != stop.end() ; j++ ){
				if ( FID ( used, j -> F ) )
					lib[j -> F] += j -> S;
				else{
					lib[j -> F] = j -> S;
					used.insert ( j -> F );
				}
			}
			num = 0;
		}
		REPP ( i, last + 1, SZ ( str ) ){
			num *= 10;
			num += ( int ) str[i] - '0';
		}

		if ( num > 1 ){
			REPALL ( i, lib ) i.S *= num;
		}

		now = "";
		while ( !EMP ( s ) ){
			if ( s.top() == '(' || !( is ( s.top() ) || isNum ( s.top() ) ) ){
				s.pop();
				continue;
			}
			now += s.top();
			s.pop();
		}
		REV ( ALL ( now ) );
		stop = dfs ( now );
		REPALL ( i, stop ){
			if ( FID ( used, i.F ) )
				lib[i.F] += i.S;
			else{
				lib[i.F] = i.S;
				used.insert ( i.F );
			}
		}
	}

	return lib;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int num = 0;
	string str, now, p;
	bool ch = false;
	cin >> str;
	map < string, int > lib;
	set < char > used;
	REPALL ( i, str ){
		if ( is ( i ) )
			used.insert ( i );
	}
	lib = dfs ( str );

	cout << str << '\n';
	REPALL ( i, lib ){
		now = i.F;
		ch = true;
		REPALL ( j, now ){
			if ( !FID ( used, j ) ){
				ch = false;
				break;
			}
		}

		if ( ch )
			cout << i.F << ':' << i.S << '\n';
	}
}
