struct Point {
    int r;
    int c;
    int dist;
};

int cmp(const void* a, const void* b) {
    struct Point* p1 = (struct Point*)a;
    struct Point* p2 = (struct Point*)b;
    return p1->dist - p2->dist;
}

int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes) {
    int totalCells = rows * cols;
    *returnSize = totalCells;
    
    *returnColumnSizes = (int*)malloc(totalCells * sizeof(int));
    int** result = (int**)malloc(totalCells * sizeof(int*));
    
    struct Point* points = (struct Point*)malloc(totalCells * sizeof(struct Point));
    
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            points[index].r = i;
            points[index].c = j;
            points[index].dist = abs(i - rCenter) + abs(j - cCenter);
            index++;
        }
    }
    
    qsort(points, totalCells, sizeof(struct Point), cmp);
    
    for (int i = 0; i < totalCells; i++) {
        (*returnColumnSizes)[i] = 2;
        result[i] = (int*)malloc(2 * sizeof(int));
        result[i][0] = points[i].r;
        result[i][1] = points[i].c;
    }
    
    free(points);
    return result;
}