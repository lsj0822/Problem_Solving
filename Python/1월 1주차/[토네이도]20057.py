#초기 설정
N = int(input())
sand = [[] for _ in range(N)]
out_sand = 0
dr = [0,1,0,-1]
dc = [-1,0,1,0]

def rotate(list):
    new_list = [[0]*5 for _ in range(5)]
    for i in range(5):
        for j in range(5):
            new_list[j][5-i-1] = list[i][j]
    return new_list


ds_left = [[0,0,0.02,0,0],[0,0.1,0.07,0.01,0],[0.05,0,0,0,0],[0,0.1,0.07,0.01,0],[0,0,0.02,0,0]]
ds_up = rotate(ds_left)
ds_right = rotate(ds_up)
ds_down = rotate(ds_right)
ds = [ds_left,ds_down,ds_right,ds_up]
r,c = N//2, N//2
#모래 설정
for i in range(N):
    sand_c = list(map(int,input().split()))
    sand[i] = sand_c
for j in range(2*N-1):
    for k in range(j//2+1):
        r += dr[j%4]
        c += dc[j%4]
        start_sand = sand[r][c]
        for l in range(5):
            for m in range(5):
                if ds[j%4][l][m] != 0:
                    move_r = r+l-2
                    move_c = c+m-2
                    move_sand = int(start_sand*ds[j%4][l][m])
                    if 0 <= move_r < N and 0 <= move_c < N:
                        sand[move_r][move_c] += move_sand
                    else:
                        out_sand += move_sand
                    sand[r][c] -= move_sand
        if 0<=r+dr[j%4]<N and 0<=c+dc[j%4]<N:
            sand[r+dr[j%4]][c+dc[j%4]] += sand[r][c]
        else:
            out_sand += sand[r][c]
        sand[r][c] = 0
print(out_sand)