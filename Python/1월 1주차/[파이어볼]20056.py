#N : 격자의 크기, M : 파이어볼 개수, K : 시행횟수
N,M,K = map(int,input().split()) 
fireball = []
fmap = [[[] for _ in range(N)] for _ in range(N)]
dr = [-1,-1,0,1,1,1,0,-1]
dc = [0,1,1,1,0,-1,-1,-1]

for _ in range(M):
    r,c,m,s,d = map(int,input().split())
    fireball.append([r-1,c-1,m,s,d])

for _ in range(K):
    while fireball: #저장된 fireball을 맵에 뿌림
        m_r,m_c,m_m,m_s,m_d = fireball.pop()
        new_r = (m_r+(dr[m_d]*m_s))%N
        new_c = (m_c+(dc[m_d]*m_s))%N
        fmap[new_r][new_c].append([m_m,m_s,m_d])

    for r in range(N):
        for c in range(N):
            if len(fmap[r][c]) >= 2: #2개 이상 합쳐졌을때
                comb_m,comb_s,comb_odd,comb_even, count = 0,0,0,0, len(fmap[r][c])
                while fmap[r][c]:
                    m, s, d = fmap[r][c].pop()
                    comb_m += m
                    comb_s += s
                    if d%2 == 0:
                        comb_even += 1
                    else:
                        comb_odd += 1
                if comb_even == count or comb_odd == count:
                    new_d = [0,2,4,6]
                else:
                    new_d = [1,3,5,7]
                if comb_m//5:
                    for i in new_d:
                        fireball.append([r,c,comb_m//5,comb_s//count,i])
            elif len(fmap[r][c]) == 1:
                fireball.append([r,c]+fmap[r][c].pop())
print(sum(f[2] for f in fireball))