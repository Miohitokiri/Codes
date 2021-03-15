// by. MiohitoKiri5474
// 區間出現數字數量
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
#define pb push_back

struct query{
	int l, r, id, lid;

	query ( int _l, int _r, int _id, int _lid ):
		l ( _l ), r ( _r ), id ( _id ), lid ( _lid ) {}

	inline bool operator < ( query &b ) const{
		if ( lid == b.lid )
			return r < b.r;
		return lid < b.lid;
	}
};

vector < query > Q;
vector < int > data;
int cur_ans, cnt[maxN], ans[maxN];

inline void add ( int x ){
	if ( !cnt[x]++ )
		cur_ans++;
}

inline void sub ( int x ){
	if ( !--cnt[x] )
		cur_ans--;
}

inline void solved ( void ){
	int l = 1, r = 0;
	for ( auto i: Q ){
		while ( r < i.r )
			add ( data[++r] );
		while ( i.l < l )
			add ( data[--l] );

		while ( i.r < r )
			sub ( data[r--] );
		while ( l < i.l )
			sub ( data[l++] );

		ans[i.id] = cur_ans;
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, q, l, r, b, siz;
	cin >> n >> q;
	data.resize ( n );
	for ( auto &i: data )
		cin >> i;
	siz = sqrt ( n );
	for ( int i = 0 ; i < q ; i++ ){
		cin >> l >> r;
		b = l;
		b /= siz;
		if ( l % siz )
			b++;
		Q.pb ( query ( l, r, i, b ) );
	}

	sort ( Q.begin(), Q.end() );

	solved();

	for ( int i = 0 ; i < n ; i++ )
		cout << ans[i] << ' ' ;
	cout << '\n';
}
