// #include<bits/stdc++.h>

// using namespace std;

// int main(){
// 	ios::sync_with_stdio ( false );
// 	cin.tie ( 0 );

// 	int n, x = 0, p, left, right;
// 	cin >> n;
// 	vector < int > data ( n );
// 	for ( int i = 0 ; i < n ; i++ )
// 		cin >> data[i];

// 	// for ( x = 0 ; x < n / 2 ; x++ ){
// 		for ( p = 0 ; p < n ; p++ ){
// 			left = right = 0;
// 			for ( int i = 0 ; i < p ; i++ )
// 				left += data[i] * abs ( i - p );
// 			for ( int i = p + 1 ; i < n ; i++ )
// 				right += data[i] * abs ( i - p );

// 			if ( right == left )
// 				break;
// 		}

// 		// if ( right == left )
// 			// break;
// 		// swap ( data[x], data[n - x - 1] );
// 	// }

// 	cout << x << ' ' << p << '\n';
// }

#include <bits/stdc++.h>
#define jizz cin.tie(0);ios_base::sync_with_stdio(0);
#define lld long long
#define F first
#define S second
#define MOD 1000000007
using namespace std;
typedef pair<int,int> Pair;
lld a[20000005];
int n;
lld a1,a2;
signed main(){jizz
    cin >>n;
    for(int i = 1 ; i <= n ; i++)
    	cin >> a[i],a1 += a[i],a2 += i*a[i];
    if(a2%a1 == 0)
    	return cout <<0 << ' '<<(a2/a1)-1 <<endl,0;
    for(int i = 1 ; i < n/2 ; i++){
        a2 -= i*a[i];
        a2 -= (n-i+1)*a[n-i+1];
        a2 += (n-i+1)*a[i];
        a2 += i*a[n-i+1];
        if(a2%a1 == 0)
        	 return cout <<i << ' '<<(a2/a1)-1 <<endl,0;
    }
    return 0;
}