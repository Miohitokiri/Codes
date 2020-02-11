#include<bits/stdc++.h>

using namespace std;

#define maxN 100005

int cnt[maxN], in[maxN];

int main(){
	int n;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ )
		cin >> in[i];
	for ( int i = 0 ; i < maxN ; i++ )
		for ( int j = 0 ; j < cnt[i] ; j++ )
			cout << i << ' ';

	cout << '\n';
}