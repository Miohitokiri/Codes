/************************************/
/*  Date	: 2019-03-31 15:40:56	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

func read() int {
	input := bufio.NewScanner ( os.Stdin )
	input.Scan()
	num, _ := strconv.Atoi ( input.Text() )
	return num
}

func min ( a int, b int ) int {
	if a > b {
		tmp := a
		a = b
		b = tmp
	}

	return a
}

func max ( a int, b int ) int {
	if a < b {
		tmp := a
		a = b
		b = tmp
	}

	return a
}

func _gcd ( a int, b int ) int {
	for a % b != 0 && b % a != 0 {
		if a > b {
			a %= b
		} else {
			b %= a
		}
	}

	return min ( a, b )
}

func main(){
	n := make ( chan int )
	n <- 12
	data := <- n
	fmt.Println ( data )
}

var seg[105 * 4] int

func update ( l int, r int, index int, value int, n int ) {
	if l == r {
		seg[n] = value
		return
	}
	mid := ( l + r ) / 2
	leftSon := n * 2
	rightSon := leftSon + 1
	if index <= mid {
		update ( l, mid, index, value, leftSon )
	} else {
		update ( mid + 1, r, index, value, rightSon )
	}

	seg[n] = max ( seg[leftSon], seg[rightSon] )
}

func query ( l int, r int, nowL int, nowR int, n int ) {
	if l <= nowL && nowR <= r {
		return seh[n]
	}
	mid := ( nowL + nowR ) / 2
	leftSon := n * 2
	rightSon := leftSon + 1
	if r <= mid {
		return query ( l, r, nowL, mid, leftSon )
	}
	if mid < l {
		return query ( l, r, mid + 1, nowR, rightSon )
	}
	return max ( query ( l, r, nowL, mid, leftSon ), query ( l, r, nowL, mid, leftSon ) )
}