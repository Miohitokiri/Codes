#include<bits/stdc++.h>
using namespace std;
map < string, int > skills;
queue < string > quu;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, stop, before, k;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> stop >> k;
		quu.push ( stop );
		skills[stop] = k;
		cin >> k;
		for ( int j = 0 ; j < k ; j++ ){
			cin >> before;
			skills[stop] += skills[before];
		}
	}

	for ( int i = 0 ; i < n ; i++ ){
		cout << quu.front() << ' ' << skills[quu.front()] << '\n';
		quu.pop();
	}
}