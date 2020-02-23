#include <stdio.h>
#include <stdlib.h>
#define sz sizeof(IP)

typedef struct IP{
	unsigned add, len;
	struct IP *next;
} IP;

IP *a[256], *b[4096], *c[4096];

unsigned get_u(unsigned a, unsigned b, unsigned c, unsigned d){
	return a << 24 | b << 16 | c << 8 | d;
}

_Bool cmp(IP a, IP b){
	if(a.add == b.add)
		return a.len > b.len;
	return a.add > b.add;
}

_Bool check(IP a, unsigned u){
	return a.add >> 32 - a.len != u >> 32 - a.len;
}

_Bool diff(IP a, unsigned u, unsigned len){
	return a.add != u || a.len != len;
}

void pushA(unsigned id, unsigned u, unsigned len){
	IP *p, *l, *tmp = (IP*)malloc(sz);
	tmp -> add = u, tmp -> len = len;
	if(!a[id]){
		a[id] = tmp;
		tmp -> next = NULL;
		return;
	}
	for(p = l = a[id]; p && cmp(*p, *tmp); l = p, p = p -> next);
	if(p == a[id])
		tmp -> next = a[id], a[id] = tmp;
	else
		l -> next = tmp, tmp -> next = p;
}

void pushB(unsigned id, unsigned u, unsigned len){
	IP *p, *l, *tmp = (IP*)malloc(sz);
	tmp -> add = u, tmp -> len = len;
	if(!b[id]){
		b[id] = tmp;
		tmp -> next = NULL;
		return;
	}
	for(p = l = b[id]; p && cmp(*p, *tmp); l = p, p = p -> next);
	if(p == b[id])
		tmp -> next = b[id], b[id] = tmp;
	else
		l -> next = tmp, tmp -> next = p;
}

void pushC(unsigned id, unsigned u, unsigned len){
	IP *p, *l, *tmp = (IP*)malloc(sz);
	tmp -> add = u, tmp -> len = len;
	if(!c[id]){
		c[id] = tmp;
		tmp -> next = NULL;
		return;
	}
	for(p = l = c[id]; p && cmp(*p, *tmp); l = p, p = p -> next);
	if(p == c[id])
		tmp -> next = c[id], c[id] = tmp;
	else
		l -> next = tmp, tmp -> next = p;
}

void insert(unsigned u, unsigned len){
	switch(len){
		case 8 ... 15:
			pushA(u >> 24, u, len);
			break;
		case 16 ... 23:
			pushB(u >> 20, u, len);
			break;
		case 24 ... 32:
			pushC(u >> 20, u, len);
			break;
	}
}

_Bool searchA(unsigned u){
	IP *p;
	for(p = a[u >> 24]; p && check(*p, u); p = p -> next);
	return p;
}

_Bool searchB(unsigned u){
	IP *p;
	for(p = b[u >> 20]; p && check(*p, u); p = p -> next);
	return p;
}

_Bool searchC(unsigned u){
	IP *p;
	for(p = c[u >> 20]; p && check(*p, u); p = p -> next);
	return p;
}

_Bool search(unsigned u){
	return searchA(u) || searchB(u) || searchC(u);
}

_Bool delA(unsigned id, unsigned u, unsigned len){
	IP *p, *l;
	for(p = l = a[id]; p && diff(*p, u, len); l = p, p = p -> next);
	if(!p)
		return 0;
	if(p == a[id]){
		a[id] = a[id] -> next;
		free(p);
		return 1;
	}
	l -> next = p -> next;
	free(p);
	p = NULL;
	return 1;
}

_Bool delB(unsigned id, unsigned u, unsigned len){
	IP *p, *l;
	for(p = l = b[id]; p && diff(*p, u, len); l = p, p = p -> next);
	if(!p)
		return 0;
	if(p == b[id]){
		b[id] = b[id] -> next;
		free(p);
		return 1;
	}
	l -> next = p -> next;
	free(p);
	p = NULL;
	return 1;
}

_Bool delC(unsigned id, unsigned u, unsigned len){
	IP *p, *l;
	for(p = l = c[id]; p && diff(*p, u, len); l = p, p = p -> next);
	if(!p)
		return 0;
	if(p == c[id]){
		c[id] = c[id] -> next;
		free(p);
		return 1;
	}
	l -> next = p -> next;
	free(p);
	p = NULL;
	return 1;
}

_Bool del(unsigned u, unsigned len){
	switch(len){
		case 8 ... 15:
			return delA(u >> 24, u, len);
		case 16 ... 23:
			return delB(u >> 20, u, len);
		case 24 ... 32:
			return delC(u >> 20, u, len);
	}
}

int main() {
	freopen("outs.out", "w", stdout);
	unsigned A, B, C, D, len, u, s = 0, f = 0;
	IP *p;
	//create
	freopen("prefix_10K.txt", "r", stdin);
	while(~scanf("%u.%u.%u.%u/%u", &A, &B, &C, &D, &len))
		insert(get_u(A, B, C, D), len);
	// for ( int i = 0 ; i < 4096 ; i++ )
	// 	if ( a[i] ){
	// 		p = a[i];
			// printf ( "%d ", i );
	// 		while ( p ){
				// printf ( "%d ", p -> add );
	// 			p = p -> next;
	// 		}
	// 		puts ( "" );
	// 	}
	freopen("trace_IPaddress_100K.txt", "r", stdin);
	while(~scanf("%u", &u))
		if(search(u))
			puts ( "Y" );
		else
			puts ( "N" );
	// printf ( "%d / %d\n", f, s );
	//insert
	freopen("insert_1K.txt", "r", stdin);
	while(~scanf("%u.%u.%u.%u/%u", &A, &B, &C, &D, &len))
		insert(get_u(A, B, C, D), len);
	freopen("trace_IPaddress_100K.txt", "r", stdin);
	while(~scanf("%u", &u))
		if(search(u))
			puts ( "Y" );
		else
			puts ( "N" );
	// printf ( "%d / %d\n", f, s );
	//delete
	freopen("delete_1K.txt", "r", stdin);
	while(~scanf("%u.%u.%u.%u/%u", &A, &B, &C, &D, &len))
		del(get_u(A, B, C, D), len);
	freopen("trace_IPaddress_100K.txt", "r", stdin);
	while(~scanf("%u", &u))
		if(search(u))
			puts ( "Y" );
		else
			puts ( "N" );
	// printf ( "%d / %d\n", f, s );
}
