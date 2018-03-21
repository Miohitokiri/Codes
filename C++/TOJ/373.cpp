//A
#include<bits/stdc++.h> 
  
using namespace std; 
  
int main() { 
    ios::sync_with_stdio ( false ); 
    cin.tie ( 0 ); 
  
    double x1, x2, y1, y2, x, y; 
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y; 
    double ans = 0.0; 
      
//  printf ( "%.3f\n", ans ); 
      
    if ( x1 <= x && x <= x2 && y1 <= y && y <= y2 ) ans = 0; 
    else if ( y1 < y && y < y2 ){ 
        if ( x < x1 ) ans = ( y2 - y1 ) * fabs ( x1 - x ); 
        else ans = ( y2 - y1 ) * fabs ( x - x2 ); 
//      cout << ans << '\n'; 
    } 
    else if ( x1 < x && x < x2 ){ 
        if ( y < y1 ) ans = ( x2 - x1 ) * fabs ( y1 - y ); 
        else ans = ( x2 - x1 ) * fabs ( y - y2 ); 
//      cout << ans << '\n'; 
    } 
    else{ 
        ans += ( x2 - x1 ) * min ( fabs ( y - y1 ), fabs ( y - y2 ) ); 
        ans += ( y2 - y1 ) * min ( fabs ( x - x1 ), fabs ( x - x2 ) ); 
    } 
      
    ans += ( x1 - x2 ) * ( y1 - y2 ) * 2; 
    ans /= 2; 
    printf ( "%.1f\n", ans ); 
      
//  cout << fabs ( y1 - y ) << '\n'; 
//  cout << fabs ( y2 - y ) << '\n'; 
//  cout << fabs ( x1 - x ) << '\n'; 
//  cout << fabs ( x2 - x ) << '\n';  
}