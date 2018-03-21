#include<bitset>
#include<map>
#include<iostream>
#define MAX 10000000
using namespace std;
bitset<MAX + 1> ansData;
map <int, int> ansData2;
int main(){
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );
    ansData[0] = 1;
    ansData[1] = 1;
    ansData[2] = 0;
    int ct = 0, a, b, ans;
    for ( int i  = 2 ; i <= MAX ; i++ )
        if ( ansData[i] == 0 ){
            for ( int j = i * 2 ; j <= MAX ; j += i )
                ansData[j] = 1;
            ct++;
            ansData2[i] = ct;
        }
    while ( cin >> a >> b ){
		ans = 0;
		b++;
		for ( int i = a ; i < b ; i++ )
			( ansData2.find(i) == ansData2.end() ) ? ans : ans++;
		cout << ans << endl;
	}
}