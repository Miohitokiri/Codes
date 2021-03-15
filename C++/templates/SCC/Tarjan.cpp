#include<bits/stdc++.h>

using namespace std;

#define maxN 100005

vector < int > edges[maxN];
int D[maxN], L[maxN], scc[maxN], tms = 1;
stack < int, vector < int > > st;
bool inSt[maxN];

void dfs ( int n ){
	D[n] = L[n] = tms++;
	st.push ( n );
	inSt[n] = true;
	for ( auto i: edges[n] ){
		if ( !D[i] ) // 沒走過就直接 dfs 下去
			dfs ( i );
		if ( inSt[i] ) // 走過了就更新 L ( N )
			L[n] = min ( L[n], L[i] );
	}

	if ( D[n] == L[n] ){ // 如果目前的 L ( N ) == D ( N ) -> 可以做 SCC 縮點囉
		int swp = -1;
		while ( swp != n ){ // 不斷取到 N 也處理完
			swp = st.top();
			st.pop();
			scc[swp] = n; // 紀錄 SCC 編號（或是說屬於哪個點
			inSt[swp] = false;
		}
	}
}

void DoingSCC ( int n ){
	for ( int i = 0 ; i < n ; i++ )
		if ( !D[i] ) // 如果沒有走過，就 dfs 一下吧
			dfs ( i );
}
