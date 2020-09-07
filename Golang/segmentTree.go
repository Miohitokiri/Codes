// by. MiohitoKiri5474
package main

import . "fmt"
import "os"
import "bufio"

var seg [100005 * 4]int

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func update(l int, r int, index int, value int, n int) {
	if l == r {
		seg[n] = value
	} else {
		mid, leftSon, rightSon := (l+r)>>1, n<<1, (n<<1)|1
		if index <= mid {
			update(l, mid, index, value, leftSon)
		} else {
			update(mid+1, r, index, value, rightSon)
		}

		seg[n] = max(seg[leftSon], seg[rightSon])
	}
}

func query(l int, r int, nowL int, nowR int, n int) int {
	if l <= nowL && nowR <= r {
		return seg[n]
	}
	mid, leftSon, rightSon := (nowL+nowR)>>1, n<<1, n<<1|1
	if r <= mid {
		return query(l, r, nowL, mid, leftSon)
	}
	if mid < l {
		return query(l, r, mid+1, nowR, rightSon)
	}

	return max(query(l, r, nowL, mid, leftSon), query(l, r, mid+1, nowR, rightSon))
}

func printSegmentTree(l int, r int, n int) {
	Printf("%d ", seg[n])
	if l == r {
		return
	}
	mid, leftSon, rightSon := (l+r)>>1, n<<1, n<<1|1
	printSegmentTree(l, mid, leftSon)
	printSegmentTree(mid+1, r, rightSon)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	var n, m, l, r, num, tp int
	Fscan(in, &n, &m)
	for i := 1; i <= n; i++ {
		Fscan(in, &num)
		update(1, n, i, num, 1)
	}

	for i := 0; i < m; i++ {
		Fscan(in, &tp, &l, &r)
		if tp == 1 {
			update(1, n, l, r, 1)
		} else {
			Println(query(l, r, 1, n, 1))
		}
	}
}
