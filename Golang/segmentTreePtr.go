// by. MiohitoKiri5474
package main

import "fmt"

func max ( a int, b int ) int {
	if a > b {
		return a
	}
	return b
}

type node struct {
	l, r *node
	value int
}

type nodeInterface interface {
	up ()
}

func ( o *node ) up () {
	L, R := 0, 0
	if o.l != nil {
		L = o.l.value
	}
	if o.r != nil {
		R = o.r.value
	}

	o.value = max ( L, R )
}

func malloc() *node {
	o := new ( node )
	o.value = 0
	o.l = nil
	o.r = nil
	return o
}

func build ( l int, r int ) *node {
	o := malloc()
	if l == r {
		return  o
	}
	mid := ( l + r ) >> 1
	o.l = build ( l, mid )
	o.r = build ( mid + 1, r )
	return o
}

func update ( l int, r int, index int, value int, o *node ) {
	if l == r {
		o.value = value
	} else {
		mid := ( l + r ) >> 1
		if index <= mid {
			update ( l, mid, index, value, o.l )
		} else {
			update ( mid + 1, r, index, value, o.r );
		}

		// o.value = max ( o.l.value, o.r.value )
		o.up();
	}
}

func query ( l int, r int, nowL int, nowR int, o *node ) int {
	if l <= nowL && nowR <= r {
		return o.value
	}
	mid := ( nowL + nowR ) >> 1
	if r <= mid {
		return query ( l, r, nowL, mid, o.l )
	}
	if mid < l {
		return query ( l, r, mid + 1, nowR, o.r )
	}

	return max ( query ( l, r, nowL, mid, o.l ), query ( l, r, mid + 1, nowR, o.r ) )
}

func main() {
	var n, m, in, l, r, tp int
	fmt.Scanf ( "%d%d", &n, &m )
	seg := build ( 1, n )
	for i := 1 ; i <= n ; i++ {
		fmt.Scanf ( "%d", &in )
		update ( 1, n, i, in, seg )
	}

	for i := 1 ; i <= m ; i++ {
		fmt.Scanf ( "%d %d %d", &tp, &l, &r )
		if tp == 1 {
			update ( 1, n, l, r, seg )
		} else {
			fmt.Println ( query ( l, r, 1, n, seg ) )
		}
	}
}