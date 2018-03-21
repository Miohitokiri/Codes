#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull pow3 ( ull a, ull b, ull mod ){
    __int128 res = 1, base = a % mod;
    while ( b ){
        if ( b & 1 )
            res = ( res * base ) % mod;
        base = ( base * base ) % mod;
        b >>= 1;
    }

    return ( ull ) res;
}

int main(){
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );

    ull a, b, c;
    int t;
    
    cin >> t;
    while ( t-- ){
        cin >> a >> b >> c;
        cout << pow3 ( a, b, c ) << '\n';
    }
}