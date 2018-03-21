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
#define FID(n,Index) n.find ( Index ) != n.end()

// graph
#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
#define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )

// IO
#define GL(n) getline ( cin, n )

// define stack, queue, pri-queue
template < class T > using stack = stack < T, vec < T > >;
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

inline int lcm ( int a, int b ){
	return a * b / __gcd ( a, b );
}

int main(){
	int t, n, a, b;
	double ans;
	scanf ( "%d", &t );
	while ( t-- ){
		scanf ( "%d", &n );
		if ( n == 1 ){
			scanf ( "%d%d", &a, &b );
			ans = ( double ) b / a;
			printf ( "%.15f\n", ans );
		}
		else{
			int a1,b1,c1,a2,b2,c2;
			cin>>a1>>b1>>c1>>a2>>b2>>c2;

			int w, p;
			double x, y;
			if ( a1 == 0 ){
				w = lcm ( b1, b2 );
			}
			if ( b1 == b2 ){
				x = ( double ) ( c2 - c1 ) / ( a2 - a1 );
				y = ( double ) ( c1 - x * a1 ) / b1;
			}
			else{
				w = lcm ( a1, a2 );
				p = w / a1;
				a1 *= p, b1 *= p, c1 *= p;
				p = w / a2;
				a2 *= p, b2 *= p, c2 *= p;
				y = ( double ) ( c2 - c1 ) / ( b2 - b1 );
				x = ( double ) ( c1 - b1 * y ) / a1;
			}
			// deltax1=c1*b2-b1*c2;
			// deltax2=a1*c2-c1*a2;
			// delta=a1*b2-a2*b1;
			// if(delta != 0)
			// {
			//     x1=(float)deltax1/delta;
			//     x2=(float)deltax2/delta;
			//     cout<<"x1="<<x1<<"\tx2="<<x2<<endl;
			// }
			printf ( "%.15f\n%.15f\n", x, y );
		}
	}
}