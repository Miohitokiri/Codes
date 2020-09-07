/************************************/
/* Date		: 2020-07-23 12:30:26	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

// by. MiohitoKiri5474

package main

import "fmt"
import "math/rand"
import "time"
import "bufio"
import "os"

type node struct {
	l, r *node
	sz, value, pri, ma int
}

type nodeInterface interface {
	up ()
	down ()
	getValue() int
	getSz() int
	print()
}

func ( o *node ) up () {
	l, r := o.l, o.r

	o.sz = 1 + l.getSz() + r.getSz()
	o.ma = max ( o.value, max ( l.getValue(), r.getValue() ) )
}

func ( o *node ) getValue () int {
	if o == nil {
		return 0
	}
	return o.value
}

func ( o *node ) getSz () int {
	if o == nil {
		return 0
	}
	return o.sz
}

func ( o *node ) print () {
	if o == nil {
		return
	}
	o.l.print()
	fmt.Printf ( "%d ", o.value )
	o.r.print()
}

const maxN = 10000000

func malloc ( val int ) *node {
	o := new ( node )
	o.sz, o.value, o.pri, o.ma = 1, val, Rand(), val
	o.l, o.r = nil, nil
	return o
}

func Rand () int {
	r1 := rand.New ( rand.NewSource ( time.Now().UnixNano() ) )

	return r1.Intn ( maxN )
}

func max ( a int, b int ) int {
	if a > b {
		return a
	}
	return b
}

func merge ( a *node, b *node ) *node {
	if a == nil {
		return b
	}
	if b == nil {
		return a
	}

	if a.pri < b.pri {
		a.r = merge ( a.r, b )
		a.up()
		return a
	}
	b.l = merge ( a, b.l )
	b.up()
	return b
}

func split ( o *node, a *node, b *node, k int ) {
	if o == nil {
		a = nil
		b = nil
		return
	}

	if o.l.getSz() <= k {
		a = o.l
		split ( a.r, a.r, b, k - o.l.getSz() - 1 )
	} else {
		b = o.r
		split ( b.l, a, b.l, k )
	}
	o.up()
}

func main() {
	var n, m, tp, l, r, value int
	in := bufio.NewReader ( os.Stdin )
	root := new ( node )
	root = nil
	fmt.Fscan ( in, &n, &m )

	for i := 0 ; i < n ; i++ {
		fmt.Fscan ( in, &value )
		root = merge ( root, malloc ( value ) )
	}

	root.print()
	fmt.Println()

	for i := 0 ; i < m ; i++ {
		fmt.Fscan ( in, &tp, &l, &r )
		L, R, mid := malloc ( 0 ), malloc ( 0 ), malloc ( 0 )
		if tp == 1 {
			split ( root, mid, R, l )
			root = merge ( mid, merge ( malloc ( r ), R ) )
		} else if tp == 2 {
			split ( root, mid, R, r )
			split ( mid, l, mid, l )
			print ( mid )
		} else if tp == 3 {
			fmt.Println ( "reverse" )
			split ( root, mid, R, r )
			split ( mid, l, mid, l )
			mid.rev ^= 1
		}
	}
}