# -*- coding: utf-8 -*-
# Date    : 2019-05-29 19:19:17
# Author  : MiohitoKiri5474 ( lltzpp@gmail.com )
# Link    : https://miohitokiri5474.github.io

n, a, x, b, y = [int(_) for _ in input().strip().split()]
while a != x and b != y:
	if a == b:
		break

	if a != n:
		a += 1
	else:
		a = 1

	if b != 1:
		b -= 1
	else:
		b = n

if a == b:
	print ( "Yes" )
else:
	print ( "No" )