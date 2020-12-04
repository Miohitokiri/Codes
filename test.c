#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int F, S;
} pii;

typedef struct {
	pii highest;
	int pts, idx;
} node;

pii lib[10][10];
int cnt[25];
node pts[10];

pii translate ( char str[] ) {
	pii res;
	if ( '2' <= str[0] && str[0] <= '9' )
		res.F = str[0] - '0';
	else if ( str[0] == 't' )
		res.F = 10;
	else if ( str[0] == 'j' )
		res.F = 11;
	else if ( str[0] == 'q' )
		res.F = 12;
	else if ( str[0] == 'k' )
		res.F = 13;
	else if ( str[0] == 'a' )
		res.F = 14;

	if ( str[1] == 'c' )
		res.S = 1;
	else if ( str[1] == 'd' )
		res.S = 2;
	else if ( str[1] == 'h' )
		res.S = 3;
	else if ( str[1] == 's' )
		res.S = 4;
	
	return res;
}

int sortCards ( const void *a, const void *b ) {
	if ( ( *( pii *) a ).F == ( *( pii *) b ).F )
		return ( *( pii *) a ).S < ( *( pii *) b ).S ? -1 : 1;
	return ( *( pii *) a ).F < ( *( pii *) b ).F ? -1 : 1;
}

int cmp ( const void *a, const void *b ) {
	if ( ( *( node *) a ).pts == ( *( node *) b ).pts ) {
		if ( ( *( node *) a ).highest.F == ( *( node *) b ).highest.F ) {
			return  ( *( node *) a ).highest.S < ( *( node *) b ).highest.S ? -1 : 1;
		}
		return ( *( node *) a ).highest.F < ( *( node *) b ).highest.F ? -1 : 1;
	}
	return ( *( node *) a ).pts < ( *( node *) b ).pts ? -1 : 1;
}

void init ( void ) {
	for ( int i = 0 ; i < 25 ; i++ )
		cnt[i] = 0;
}

int main() {
	char c[2];
	int sameSuit, ma, idx;
	pii highestCard;
	for ( int i = 0 ; i < 4 ; i++ ) {
		for ( int j = 0 ; j < 5 ; j++ ) {
			scanf ( "%s", c );
			lib[i][j] = translate ( c );
		}
		qsort ( lib[i], 5, sizeof ( pii ), sortCards );

		pts[i].idx = i;
		highestCard = lib[i][4];
		ma = idx = -1;
		init();
		for ( int j = 0 ; j < 5 ; j++ )
			cnt[lib[i][j].F]++;
		for ( int j = 0 ; j < 25 ; j++ )
			if ( ma < cnt[j] )
				ma = cnt[j], idx = j;
		if ( ma == 4 ) {
			highestCard.F = idx, highestCard.S = 4;
			pts[i].highest = highestCard;
			pts[i].pts = 80;
			continue;
		}
		else if ( ma == 3 ) {
			int flag = 0;
			for ( int j = 0 ; j < 25 ; j++ )
				if ( cnt[j] == 2 )
					flag = 1;

			if ( flag )
				pts[i].pts = 70;
			else
				pts[i].pts = 40;
			pts[i].highest.F = idx;
			pts[i].highest.S = 4;
			continue;
		}
		else if ( ma == 2 ) {
			int count = 0;
			for ( int j = 0 ; j < 25 ; j++ )
				if ( cnt[i] == 2 )
					count++;
			highestCard.F = 0, highestCard.S = 0;
			for ( int j = 0 ; j < 5 ; j++ ) {
				if ( cnt[lib[i][j].F] == 1 )
					continue;
				highestCard = lib[i][j];
			}

			if ( count == 1 ) {
				pts[i].pts = 20;
			}
			else if ( count == 2 ) {
				pts[i].pts = 30;
			}
			pts[i].highest = highestCard;
			continue;
		}
		else {
			init();
			for ( int j = 0 ; j < 5 ; j++ )
				cnt[lib[i][j].S]++;
			ma = idx = -1;
			for ( int j = 0 ; j < 25 ; j++ )
				if ( ma < cnt[j] )
					ma = cnt[j], idx = j;

			int flag = 1;
			for ( int j = 1 ; j < 5 ; j++ )
				if ( lib[i][j].F - 1 != lib[i][j - 1].F ) {
					flag = 0;
					break;
				}

			pts[i].highest = highestCard;
			if ( ma == 5 ) {
				if ( flag )
					pts[i].pts = 100;
				else
					pts[i].pts = 60;
			}
			else {
				if ( flag )
					pts[i].pts = 50;
				else
					pts[i].pts = 10;
			}
		}
	}
	qsort ( pts, 4, sizeof ( node ), cmp );
	for ( int i = 3 ; i >= 0 ; i-- )
		printf ( "%c ", 'A' + pts[i].idx );

	for ( int i = 3 ; i >= 0 ; i-- )
			printf ( "%c %d\n", 'A' + pts[i].idx, pts[i].pts );
}
