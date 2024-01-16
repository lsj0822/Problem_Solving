N,M = map(int,input().split())
marble = [[] for _ in range(N)]
for i in range(N):
    added_marble = list(map(int,input().split()))
    marble[i] = added_marble
marble_linear = [0] * (N**2-1) #원형으로 둘러져있는 구슬을 일자로 정렬할 리스트. 메모이제이션
marble_index = 0
broken_marble = [0,0,0]
dr = [0,1,0,-1]
dc = [-1,0,1,0]
remove_ls = [[0]*((N-1)//2) for _ in range(4)]

#방향에 따라 지울 인덱스 설정
remove_index = 1
for i in range((N-1)//2):
    for j in range(4):
        remove_ls[j][i] = remove_index
        remove_index += (i+1)*2
remove_ls.append(remove_ls.pop(1))
remove_ls.append(remove_ls.pop(0))
remove_ls.append(remove_ls.pop(0))

#원형의 구슬을 일자로 정렬
r,c = (N-1)//2, (N-1)//2
for i in range(2*N-1):
    for j in range(i//2 + 1):
        r += dr[i%4]
        c += dc[i%4]
        if 0<=r<N and 0<=c<N:
            marble_linear[marble_index] = marble[r][c]
            marble_index+=1

#마법 리스트
magic = [[] for _ in range(M)]
for i in range(M):
    new_magic = list(map(int,input().split()))
    magic[i] = new_magic

#마법 시행
while magic:
    dir, length = magic.pop(0)
    for i in range(length):
        remove_marble = marble_linear.pop(remove_ls[dir-1][i]-1)

    #폭파 검사
    max_cnt = 5
    while max_cnt >= 4:
        last_m = marble_linear[0]
        c_cnt = 1
        max_cnt = 0
        bomb_ls = [0] * len(marble_linear)
        for i in range(1,len(marble_linear)):
            if last_m == marble_linear[i]:
                c_cnt+=1
            else:
                if c_cnt>=4:
                    for b in range(i-1,i-c_cnt-1,-1):
                        bomb_ls[b] = 1
                        broken_marble[last_m-1] += 1
                    max_cnt = max(max_cnt,c_cnt)
                c_cnt = 1
                last_m = marble_linear[i]

        #구슬 폭파
        for i in range(len(marble_linear)-1,-1,-1):
            if bomb_ls[i] == 1:
                marble_linear.pop(i)

    #구슬 변화
    new_marble = [0]* (N**2-1)
    c_cnt = 1
    last_m = marble_linear[0]
    new_index = 0
    for i in range(1,len(marble_linear)):
        if last_m == marble_linear[i]:
            c_cnt+=1
        else:
            if new_index < (N**2-1):
                new_marble[new_index] = c_cnt
                new_marble[new_index+1] = last_m
                c_cnt = 1
                last_m = marble_linear[i]
                new_index += 2
    marble_linear = new_marble

result = 0
for i in range(3):
    result += (i+1)*broken_marble[i]
print(result)