#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );

    long long n;
    cin >> n;
    if ( n == 0 )
        cout <<  "Nothing" << '\n';
    else if ( n == 1 )
        cout << "*"<< '\n';
    else if ( n != 0 && n != 1 ){
        if ( n % 2 == 0 )
            for ( int i = 0 ; i < n ; i++ ){
                if ( i % 2 == 0 )
                    for ( int j = 0 ; j < n / 2 ; j++ )
                        cout << "*-";
                else if ( i % 2 == 1 ){
                    for ( int j = 0 ; j < n / 2 ; j++ )
                        cout << "-*";
                }
                cout << '\n';
            }
        else if ( n % 2 == 1 )
            for ( int i = 0 ; i < n ; i++ ){
                if ( i % 2 == 0 ){
                    for ( int j = 0 ; j < ( n - 1 ) / 2 ; j++ )
                        cout << "*-";
                    cout << "*";
                }
                else if ( i % 2 == 1){
                    for ( int j = 0 ; j < ( n - 1 ) / 2 ; j++ )
                        cout << "-*";
                    cout << "-";
                }
                cout << '\n';
            }
    }
}