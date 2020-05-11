// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005

vector < int > edges[maxN];
int D[maxN], L[maxN], scc[maxN], tms = 1;
stack < int, vector < int > > st; // 用 vector 取代 deque
bool inSt[maxN];

void dfs ( int n ){
	D[n] = L[n] = tms++;
	st.push ( n );
	inSt[n] = true;
	for ( auto i: edges[n] ){
		if ( !D[i] ) // 還沒遍歷過就先 dfs
			dfs ( i );
		if ( inSt[i] ) // 走過就更新 L ( n )
			L[n] = min ( L[n], L[i] );
	}

	if ( D[n] == L[n] ){ // 如果條件符合 -> 做 SCC 縮點
		int swp = -1;
		while ( swp != p ){ // 做到 N 也處理完
			swp = st.top();
			st.pop();
			scc[swp] = n; // 紀錄與哪個點在同一個 SCC 中
						  // 或是另外紀錄 SCC 編號也可以

			inSt[swp] = false;
		}
	}
}

void SCC ( int n ){
	memset ( D, 0, sizeof D );
	for ( int i = 0 ; i < n ; i++ )
		if ( !D[i] ) // 還未遍歷過就對他 dfs 
			dfs ( i );
}