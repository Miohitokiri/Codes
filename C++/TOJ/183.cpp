#include<bits/stdc++.h>
#define MAX 10000000
using namespace std;
bitset<MAX + 1> ansData;
map < int, int > ansData2;
int main(){
	int ct = 0, a, b;
	char c;
	for ( int i  = 2 ; i <= MAX ; i++ )
		if ( ansData[i] == 0 ){
			for ( int j = i * 2 ; j <= MAX ; j += i )
				ansData[j] = 1;
			ct++;
			ansData2[i] = ct;
		}
	while ( cin >> a >> c >> b ){
		int sum, A = ansData2.find ( a ), B = ansData2.find ( b );
		sum = A + B;
		printf ( "%d\n", ansData2[sum] );
	}
}