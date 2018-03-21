#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );
    
    int a, b, data = 0, c;
    vector < int > ansData;
    cin >> a >> b >> c;
    if ( c == 0 ){
    	cout << 0 << '\n';
    	return 0;
    }
    for ( int i = 0 ; c > 0 ; i++ ){
        data += ( c % 10 ) * pow ( a, i );
        c /= 10;
    }
    while ( data > 0 ){
        ansData.push_back ( data % b );
        data /= b;
    }
    for ( int i = ansData.size() - 1 ; i >= 0 ; i-- )
        cout << ansData[i];
    cout << '\n';
}