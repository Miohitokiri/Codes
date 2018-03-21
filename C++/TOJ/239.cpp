#ifndef EVAL
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int Answer(int N,int P,int *H,int *L,int *R,int *V);

int main()
{
	const int maxN = 1000000;
	const int maxP = 1000000;
	int *H = new int[maxN];
	int *L = new int[maxP];
	int *R = new int[maxP];
	int *V = new int[maxP];
	int N,P;
	while( cin>>N>>P )
	{
		for(int i=0;i<N;++i)
			cin>>H[i];
		for(int i=0;i<P;++i)
			cin>>L[i]>>R[i]>>V[i];
		cout<<Answer(N,P,H,L,R,V)<<endl;
	}
}
#endif
/*================================================================*/
/*================================================================*/
/*================================================================*/
/*================================================================*/
/*Write Your Program Here*/
/*Notice: You should include header for youself*/

// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )

int Answer ( int N, int P, int *H, int *L, int *R, int *V){
	int t[N];
	t[0] = H[0];
	REPP ( i, 1, n ) t[i] = H[i] - H[i - 1];
	REPP ( i, 0, P ){
		t[L[i] - 1] += V[i];
		if ( R[i] < N )
			t[R[i]] -= V[i];
	}
	int mi = t[0], ma = t[0];
	REPP ( i, 1, n ){
		t[i] += t[i - 1];
		ma = max ( t[i], ma );
		mi = min ( t[i], mi );
	}
	return ma - mi;
}