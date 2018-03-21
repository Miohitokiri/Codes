#include<iostream>

using namespace std;

#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )

int main(){
	bool prime[10000001];
	prime[0] = prime[1] = true;
	REPP ( i, 2, 10000001 ) if ( !prime[i] ) for ( int j = i * 2 ; j <= 10000001 ; j += i ) prime[j] = true;

	int n, cnt;
	while ( cin >> n ){
		cnt = 0;
		REPP ( i, 2, n + 1 ) if ( !prime[i] ) cnt++;
		cout << cnt << '\n';
	}
}