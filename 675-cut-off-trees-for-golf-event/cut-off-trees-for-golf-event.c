
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int r, c, d;
} Node;

int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

int bfs(int **forest, int rows, int cols,
        int sr, int sc, int tr, int tc) {

    int visited[50][50] = {0};
    Node q[2500];

    int front = 0, rear = 0;

    q[rear++] = (Node){sr, sc, 0};
    visited[sr][sc] = 1;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (front < rear) {
        Node cur = q[front++];

        if (cur.r == tr && cur.c == tc)
            return cur.d;

        for (int k = 0; k < 4; k++) {
            int nr = cur.r + dr[k];
            int nc = cur.c + dc[k];

            if (nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols &&
                !visited[nr][nc] &&
                forest[nr][nc] != 0) {

                visited[nr][nc] = 1;

                q[rear++] = (Node){
                    nr, nc, cur.d + 1
                };
            }
        }
    }

    return -1;
}

int cutOffTree(int** forest, int forestSize,
               int* forestColSize) {

    int rows = forestSize;
    int cols = forestColSize[0];

    int trees[2500];
    int n = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (forest[i][j] > 1) {
                trees[n++] = forest[i][j];
            }
        }
    }

    // Sort tree heights
    qsort(trees, n, sizeof(int), cmp);

    int sr = 0, sc = 0;
    int total = 0;

    for (int t = 0; t < n; t++) {
        int found = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (forest[i][j] == trees[t]) {

                    int dist = bfs(
                        forest, rows, cols,
                        sr, sc, i, j
                    );

                    if (dist == -1)
                        return -1;

                    total += dist;

                    sr = i;
                    sc = j;

                    forest[i][j] = 1;
                    found = 1;
                    break;
                }
            }

            if (found) break;
        }
    }

    return total;
}