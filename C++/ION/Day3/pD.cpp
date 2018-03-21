#include<bits/stdc++.h>
using namespace std;
int n;
struct s{
    int a, b;
    s ( int c, int d ){
        a = c;
        b = d;   
    }
    s(){}
};
bool cmp ( s c, s d ){
    return ( c.b > d.b );
}
s op[10000];
int main(){
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );

    int x, y, ans, now;
    while( cin >> n ){
        if( n == 0 )
            break;
       
        for ( int i = 0 ; i < n ; i++ ){
            cin >> x >> y;
            op[i] = s ( x, y );
        }
     
        sort ( op, op + n, cmp );
        ans = 0; now = 0;
        for ( int i = 0 ; i < n ; i++ ){
             now += op[i].a;
             if( ans < now + op[i].b )
                ans = now + op[i].b;
          
           
        }
        cout << ans << '\n';
    }
}