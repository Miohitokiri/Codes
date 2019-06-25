#include<stdio.h>

int main(){
	int cnt = 0;
	char c[25];
	printf ( "Hello ," );
	while ( c[cnt] = getchar() && c[cnt] != '\n' && cnt <= 20 ){
		cnt++;
	}
	// c[cnt++] = '!';
	// c[cnt] = '\0';
	// printf ( "%s!\n", c );
	for ( int i = 0 ; i < cnt ; i++ )
		putchar ( c[i] );
	puts ( "" );
}

void update ( int l, int r, int index, int value, int n ){
	if ( l == r )
		seg[n] = value;
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( index <= mid )
			update ( l, mid, index, value, leftSon ); 
		else
			update ( mid + 1, r, index, value, rightSon );

		seg[n] = max ( seg[leftSon], seg[rightSon] );
	}
}

int query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon );

	return max ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
}