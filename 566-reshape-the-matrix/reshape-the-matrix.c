int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int m = matSize;
    int n = matColSize[0];
    
    if (m * n != r * c) {
        *returnSize = m;
        *returnColumnSizes = matColSize;
        return mat;
    }
    
    *returnSize = r;
    *returnColumnSizes = (int*)malloc(r * sizeof(int));
    int** result = (int**)malloc(r * sizeof(int*));
    
    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
        result[i] = (int*)malloc(c * sizeof(int));
    }
    
    for (int i = 0; i < m * n; i++) {
        result[i / c][i % c] = mat[i / n][i % n];
    }
    
    return result;
}