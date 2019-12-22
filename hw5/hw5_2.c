/************************************/
/* Date		: 2019-11-15 02:35:57	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

/* by. MiohitoKiri5474 */
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

void solve1 ( int data[][2], int n, int v ){
	int i, flag = 0;
	printf ( "R = { " );
	for ( i = 0 ; i < n ; i++ )
		if ( data[i][0] <= v && v <= data[i][1] ){
			if ( flag )
				printf ( ", [%d, %d]", data[i][0], data[i][1] );
			else{
				printf ( "[%d, %d]", data[i][0], data[i][1] );
				flag = 1;
			}
		}
	puts ( " }" );
}

struct node {
	struct node *l, *r;
	int value, pri;
} *root = NULL;

struct res {
	struct node *a, *b;
};

struct node *New ( int k ){
	struct node *res = ( struct node * ) malloc ( sizeof ( struct node ) );
	res -> value = k;
	res -> pri = rand();
	res -> l = res -> r = NULL;
	return res;
}

int find ( struct node *o, int k ){
	if ( o == NULL )
		return 0;
	if ( o -> value == k )
		return 1;
	if ( o -> value < k )
		return find ( o -> l, k );
	return find ( o -> r, k );
}

struct node *merge ( struct node *a, struct node *b ){
	if ( a == NULL )
		return b;
	if ( b == NULL )
		return a;

	if ( a -> pri < b -> pri ){
		a -> r = merge ( a -> r, b );
		return a;
	}
	b -> l = merge ( a, b -> l );
	return b;
}

struct res split ( struct node *o, struct node *a, struct node *b, int k ){
	struct res swp;
	if ( o == NULL ){
		swp.a = swp.b = NULL;
		return swp;
	}

	if ( o -> value < k ){
		a = o;
		swp = split ( o -> r, a -> r, b, k );
		a -> r = swp.a, b = swp.b;
		swp.a = a, swp.b = b;
	}
	else{
		b = o;
		swp = split ( o -> l, a, b, k );
		a = swp.a, b -> l = swp.b;
		swp.a = a, swp.b = b;
	}

	return swp;
}

int ans[30], idx = 0;

void print ( struct node *o ){
	if ( o == NULL ){
		return;
	}
	if ( o -> l != NULL )
		print ( o -> l );
	ans[idx++] = o -> value;
	if ( o -> r != NULL )
		print ( o -> r );
}

struct node *insert ( struct node *o, int k ){
	struct node *l, *r, *in, *swp;
	if ( find ( o, k ) )
		return o;
	struct res wtf = split ( o, l, r, k );
	l = wtf.a, r = wtf.b;
	in = New ( k );
	return merge ( merge ( l, in ), r );
}

void solve2 ( int data[][2], int n ){
	int i;
	srand ( time ( NULL ) );
	root = NULL;

	for ( i = 0 ; i < n ; i++ ){
		root = insert ( root, data[i][0] - 1 );
		root = insert ( root, data[i][1] );
	}

	print ( root );
	printf ( "T = { %d", ans[0] );
	for ( i = 1 ; i < idx ; i++ )
		printf ( ", %d", ans[i] );
	puts ( " }" );
}

int main(){
	srand ( time ( NULL ) );

	// data define here
	int n = 4, i, v = 19;;
	int data[4][2] = {
		{ 3, 19 },
		{ 11, 33 },
		{ 18, 80 },
		{ 80, 100 }
	};

	solve1 ( data, n, v );
	solve2 ( data, n );
}