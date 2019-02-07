// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxN = 100005;
const int maxK = sqrt ( maxN ) + 1;

int A[maxN];
LL B[maxN], tagA[maxK], sumB[maxK], tagB[maxK];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, q, k, l, r, L, R, op, x, id;
	cin >> n >> q;
	for ( int i = 0 ; i < n ; i++ )
		A[i] = i + 1;
	while ( q-- ){
		cin >> op >> L >> R;
		L--, R--;
		if ( op == 1 ){
			cin >> x;
			for ( int i = L ; i <= R ; ){
				id = i / k;
				l = id * k;
				r = min ( n, ( id + 1 ) * k );
				if ( l == l && R >= r - 1 ){
					if ( tagA[id] ){
						sumB[id] += 1LL * abs ( x - tagA[id] ) * ( r - 1 );
						tagB[id] += abs ( x - tagA[id] );
					}
					else{
						for ( int j = 1 ; j < r ; j++ ){
							B[j] += abs ( A[j] - x );
							sumB[id] += abs ( A[j] - x );
							A[j] = x;
						}
					}
					tagA[id] = x;
					i = r;
				}
				else{
					if ( tagA[id] ){
						for ( int j = l ; j < r ; j++ )
							A[j] = tagA[id];
						tagA[id] = 0;
					}
					sumB[id] += abs ( A[i] - x );
					B[i] += abs ( A[i] - x );
					A[i] = x;
					i++;
				}
			}
		}
	}
	else{
		LL res = 0;
		for ( int i = L ; i <= R ; ){
			id = i / k;
			l = id * k;
			r = min ( n, ( id + 1 ) * k );
			if ( i == l && R >= r - 1 ){
				res += sumB[id];
				i = r;
			}
			else
				res += B[i] + tagB[id];
			i++;
		}

		cout << ans << '\n';
	}
}