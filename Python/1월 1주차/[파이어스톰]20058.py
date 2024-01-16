#입력받을 값
N,Q = map(int,input().split())
ice_length = 2**N
A = [[] for _ in range(ice_length)]
for i in range(ice_length):
    n_A = list(map(int,input().split()))
    A[i] = n_A
magic = list(map(int,input().split()))
ice_max = 0 #빙하 크기를 출력할 변수수
dr = [-1,1,0,0]
dc = [0,0,-1,1]

for m in magic:
    #격자 바꾸기
    grid = 2**m
    replace_ice = [[0]*ice_length for _ in range(ice_length)]
    for a in range(0,ice_length):
        for b in range(0,ice_length):
            replace_ice[(a//grid)*grid+b%grid][(b//grid)*grid+grid-a%grid-1] = A[a][b]
    A = replace_ice


    #얼음녹이기
    melt_ice = [[0]*ice_length for _ in range(ice_length)]
    for r in range(ice_length):
        for c in range(ice_length):
            ice_count = 0
            for d in range(4):
                new_r = r+dr[d]
                new_c = c+dc[d]
                if 0 <= new_r < ice_length and 0 <= new_c < ice_length:
                    if A[new_r][new_c] > 0:
                        ice_count += 1
            if ice_count < 3 and A[r][c] > 0:
                melt_ice[r][c] += 1

    for r in range(ice_length):
        for c in range(ice_length):
            A[r][c] -= melt_ice[r][c]

#합계구하기
print(sum(sum(A,[])))

#최대갯수구하기(백트래킹)
ice_visited = [[False]*ice_length for _ in range(ice_length)]
check = []
for i in range(ice_length):
    for j in range(ice_length):
        if ice_visited[i][j] == False and A[i][j] > 0:
            ice_visited[i][j] = True
            check.append([i,j])
            ice_size = 1
            while check:
                r,c = check.pop()
                for d in range(4):
                    nr = r + dr[d]
                    nc = c + dc[d]
                    if 0 <= nr < ice_length and 0 <= nc < ice_length:
                        if A[nr][nc] > 0 and ice_visited[nr][nc] == False:
                            check.append([nr,nc])
                            ice_visited[nr][nc] = True
                            ice_size += 1
            ice_max = max(ice_size,ice_max)
print(ice_max)