// by. MiohitoKiri5474
// 區間出現數字數量
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
#define pb push_back

struct query{
	int l, r, id, lid, rid, t;

	query ( int _l, int _r, int _id, int _lid, int _rid, int _t ):
		l ( _l ), r ( _r ), id ( _id ), lid ( _lid ), rid ( _rid ), t ( _t ) {}

	inline bool operator < ( query &b ){
		if ( lid != b.lid )
			return lid < b.lid;
		if ( rid != b.rid )
			return rid < b.rid;
		return t < b.t;
	}
};

struct modify{
	int idx, x, la;

	modify ( int _idx, int _x, int _la ):
		idx ( _idx ), x ( _x ), la ( _la ) {}
};

vector < query > q;
vector < modify > m;
vector < int > data, modified;

int cur_ans, cnt[maxN], ans[maxN];

inline void add ( int x ){
	if ( !cnt[x]++ )
		cur_ans++;
}

inline void sub ( int x ){
	if ( !--cnt[x] )
		cur_ans--;
}

inline void addTime ( int l, int r, int t ){
	modify swp = m[t];
	if ( l <= swp.idx && swp.idx <= r )
		sub ( data[swp.idx] ), add ( swp.x );
	data[swp.idx] = swp.x;
}

inline void subTime ( int l, int r, int t ){
	modify swp = m[t];
	if ( l <= swp.idx && swp.idx <= r )
		sub ( data[swp.idx] ), add ( swp.la );
	data[swp.idx] = swp.la;
}

inline void solved ( void ){
	int l = 1, r = 0, t = -1;
	for ( auto i: q ){
		while ( t < q.t )
			addTime ( l, r, ++t );
		while ( q.t < t )
			addTime ( l, r, t-- );

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

	int n, q, l, r, lb, rb, type, idx, in, siz, tms = 0;
	cin >> n >> q;
	data.resize ( n );
	for ( auto &i: data )
		cin >> i;

	modified = data;
	siz = cbrt ( n );
	for ( int i = 0 ; i < q ; i++ ){\
		cin >> type;
		if ( type == 1 ){
			// query
			cin >> l >> r;
			lb = l;
			lb /= siz;
			if ( l % siz )
				lb++;
			rb = r;
			rb /= siz;
			if ( r % siz )
				rb++;
			q.pb ( query ( l, r, i, lb, rb, tms ) );
		}
		else{
			// modify
			cin >> idx >> in;
			m.pb ( modify ( idx, in, modified[idx] ) );
			modified[idx] = in;
			tms++;
		}
	}

	solved();

	for ( int i = 0 ; i < n ; i++ )
		cout << ans[i] << ' ' ;
	cout << '\n';
}
