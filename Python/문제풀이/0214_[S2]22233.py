import sys



n, m = map(int,sys.stdin.readline().split())

S = set()

for _ in range(n):
  S.add(sys.stdin.readline().rstrip())

for _ in range(m):
  ls = list(map(str,sys.stdin.readline().rstrip().split(',')))
  for item in ls:
    S.discard(item)
  print(len(S))
