N,M = map(int,input().split())
water = [[] for _ in range(N)]
for i in range(N):
    added_water = list(map(int,input().split()))
    water[i] = added_water
moving_list = [[] for _ in range(M)]
for j in range(M):
    added_moving = list(map(int,input().split()))
    moving_list[j] = added_moving

#방향지정
dr = [0,0,-1,-1,-1,0,1,1,1]
dc = [0,-1,-1,0,1,1,1,0,-1]


cloud = [[0]*N for _ in range(N)]
for i in range(N-1,N-3,-1):
    for j in range(0,2):
        cloud[i][j] = 1

while moving_list:
    dir, speed = moving_list.pop(0)
    moved_cloud = [[0]*N for _ in range(N)]
    #구름 옮기기
    for r in range(N):
        for c in range(N):
            if cloud[r][c] == 1:
                new_r = (r+dr[dir]*speed)%N
                new_c = (c+dc[dir]*speed)%N
                moved_cloud[new_r][new_c] = 1

    #비내리기
    for r in range(N):
        for c in range(N):
            if moved_cloud[r][c] == 1:
                water[r][c] += 1
    

    #물복사하기
    for r in range(N):
        for c in range(N):
            if moved_cloud[r][c] == 1:
                for i in range(2,9,2):
                    new_r = r+dr[i]
                    new_c = c+dc[i]
                    if 0<=new_r<N and 0<=new_c<N and water[new_r][new_c] >0:
                        water[r][c] += 1
    #새구름 만들기
    cloud = [[0]*N for _ in range(N)]                   
    for r in range(N):
        for c in range(N):
            if water[r][c] >= 2:
                if moved_cloud[r][c] == 0:
                    water[r][c] -= 2
                    cloud[r][c] = 1
print(sum(sum(water,[])))