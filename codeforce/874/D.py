# -*- coding: utf-8 -*-
# @Author: chatting
# @Date:   2023-05-20 20:03:35
# @Last Modified by:   10592
# @Last Modified time: 2023-05-20 20:56:34



t = int(input())
while t:
	
	t -= 1
	n = int(input())
	a = list(map(int, input().split()))
	if n == 1:
		print(*a)
		continue
	i = a.index(n - 1 if a[0] == n else n)
	if i == n - 1:
		i = n
	j = i - 2
	while j > 0 and a[j] > a[0]:
		j -= 1
	print(*(a[i:] + a[j+1:i][::-1] + a[:j+1]))

