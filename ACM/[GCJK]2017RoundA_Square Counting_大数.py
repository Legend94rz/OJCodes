T = int(input())
P = 1000000007
for t in range(1, T+1):
	R, C = [int(x) for x in input().split()]
	if R>C:
		R, C = C, R
	m = (6*R**2*C*(R+1)-2*R*(R+1)*(R+C)*(2*R+1)+3*R**2*(R+1)**2)//12
	print('Case #%d: %d' % (t, m%P))


	