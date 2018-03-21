#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );

    int n, q, t;
    cin >> t;
    while ( t-- ){
        set < int > fid;
        vector < int > data;
        cin >> n;
        for ( int i = 0 ; i < n ; i++ ){
            cin >> q;
            for ( int j = 0 ; j < i ; j++ )
                fid.insert ( q + data[j] );
            data.push_back ( q );
        }

        cin >> q;
        while ( q-- ){
            cin >> n;
            cout << ( fid.find ( n ) == fid.end() ? "So Bad!" : "Good!" ) << '\n';
        }
    }
}