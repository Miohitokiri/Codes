#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );
    cout.tie ( 0 );

    int n;
    cin >> n;
    vector < int > data ( n );
    for ( auto &i: data )
        cin >> i;
    for ( int i = 0 ; i < n ; i++ ){
        for ( int j = 1 ; j < n ; j++ )
            if ( data[j - 1] > data[j] )
                swap ( data[j - 1], data[j] );
        for ( auto i: data )
            cout << i << ' ';
        cout << '\n';
    }
}
