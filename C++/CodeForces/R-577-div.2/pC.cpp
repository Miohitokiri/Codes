/************************************/
/* Date		: 2019-08-05 01:37:14	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/
 
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
#define eb emplace_back
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
 
// define stringstream
#define sstr stringstream
 
// number~ remember change maxN
#define INF 0x3f3f3f3f
#define NEG_INF 0x8f8f8f8f
#define maxN 200005
 
// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く
 
// ready~ go!
// let's go coding and have fun!
// I can solve this problem!
 
pii seg[maxN << 2];
 
void update ( int l, int r, int index, int value, int n ){
	if ( l == r )
		seg[n] = pii ( value, 0 );
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( index <= mid )
			update ( l, mid, index, value, leftSon );
		else
			update ( mid + 1, r, index, value, rightSon );
 
		seg[n].F = seg[leftSon].F + seg[rightSon].F;
	}
}
 
int query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n].F + seg[n].S;
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon ) + seg[n].S;
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon ) + seg[n].S;
	return -1;
}
 
void modify ( int l, int r, int nowL, int nowR, int value, int n ){
	if ( l <= nowL && nowR <= r )
		seg[n].S += value;
	else{
		int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( r <= mid )
			modify ( l, r, nowL, mid, value, leftSon );
		else if ( mid < l )
			modify ( l, r, mid + 1, nowR, value, rightSon );
		else{
			modify ( l, r, nowL, mid, value, leftSon );
			modify ( l, r, mid + 1, nowR, value, rightSon );
		}
	}
}
 
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );
 
	int n, k, swp, mid, num, N, len;
	vi data;
	cin >> n >> k;
	GETDATA ( data, n );
	N = n - 1;
	sort ( ALL ( data ) );
	REPP ( i, 0, n ){
		update ( 0, N, i, data[i], 1 );
	}
	while ( k ){
		mid = query ( n / 2, n / 2, 0, N, 1 );
		swp = upper_bound ( ALL ( data ), mid ) - BEG ( data );
		len = swp - n / 2;
		if ( swp == n )
			swp--;
		if ( k < len )
			break;
		if ( data[swp] - mid != 0 )
			num = min ( k / len, data[swp] - mid );
		else
			num = k / len;
		if ( !num )
			break;
		k -= num * len;
		modify ( n / 2, swp - ( mid != data[swp] ), 0, N, num, 1 );
	}
	cout << query ( n / 2, n / 2, 0, N, 1 ) << '\n';
}