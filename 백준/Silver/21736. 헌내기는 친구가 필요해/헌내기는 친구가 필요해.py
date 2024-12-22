import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int,input().split())
board = [list(input()) for i in range(N)]

ans = 0
dx = [-1,0,1,0]
dy = [0,1,0,-1]

pos = (0,0)

def bfs(k):
    global ans
    visited=[[0]*M for i in range(N)]
    x,y = k
    queue = deque()
    queue.append(k)
    visited[x][y] = 1
    while queue :
        x,y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= N or ny < 0 or ny >= M :
                continue
            if visited[nx][ny] == 0 and board[nx][ny] != 'X':
                queue.append((nx,ny))
                visited[nx][ny]=1
                if board[nx][ny] == 'P':
                    ans+=1

for i in range(N):
    for j in range(M):
        if board[i][j] == 'I':
            pos = (i,j)

bfs(pos)
if ans == 0 :
    print("TT")
else:
    print(ans)
