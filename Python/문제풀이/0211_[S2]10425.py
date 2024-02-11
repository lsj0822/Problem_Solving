T = int(input())
dict = {}
fibo = [0] * 100005
fibo[0] = 0
fibo[1] = 1
for i in range(2,100001):
  fibo[i] = fibo[i-1] + fibo[i-2]
  dict[fibo[i]] = i

for i in range(T):
  k = int(input())
  print(dict[k])