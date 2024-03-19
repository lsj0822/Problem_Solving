n = int(input())
board = [0]*n
dp = [[0]*n for _ in range(n)]
for i in range(n):
  board[i] = list(map(int,input().split()))
dp[0][0] = 1
for i in range(n):
  for j in range(n):
    for x in range(0,i):
      if board[x][j] == i-x:
        dp[i][j] += dp[x][j]
    for y in range(0,j):
      if board[i][y] == j-y:
        dp[i][j] += dp[i][y]
print(dp[n-1][n-1])