/************************************/
/* Date		: 2020-07-05 19:13:03	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

// by. MiohitoKiri5474
package main

import (
	"bufio"
	. "fmt"
	"os"
)

const maxN = 100005

var dis, sz [maxN]int

func Init() {
	for i := 0; i < maxN; i++ {
		dis[i] = i
		sz[i] = 1
	}
}

func find(n int) int {
	if dis[n] == n {
		return n
	}
	dis[n] = find(dis[n])
	return dis[n]
}

func same(a int, b int) bool {
	return find(a) == find(b)
}

func Union(a int, b int) {
	if same(a, b) {
		return
	}
	a = find(a)
	b = find(b)
	dis[a] = b
	sz[b] += sz[a]
}

func main() {
	in := bufio.NewReader(os.Stdin)
	var n, m, tp, a, b int
	Fscan(in, &n, &m)
	Init()

	for i := 0; i < m; i++ {
		Fscan(in, &tp, &a, &b)
		if tp == 1 {
			Union(a, b)
		} else {
			if same(a, b) {
				Println("Yes")
			} else {
				Println("No")
			}
		}
	}
}
