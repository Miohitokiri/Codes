// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define maxN 10005

inline int count ( int n ){
	switch ( n ){
		case 3:
		case 1: return 1;
		case 5:
		case 2: return 0;
		default: 
			switch ( n % 4 ){
				case 2:
				case 0: return n / 2;
				case 1: return n / 4;
				case 3: return count ( n / 2 );
			}
	}
	return 0;
}

int main(){
	int k, m;
	scanf ( "%d%d", &k, &m );
	printf ( "%d\n", ( k == 1 ? m : count ( m ) ) );
}