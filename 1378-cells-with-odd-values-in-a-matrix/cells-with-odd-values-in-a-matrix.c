int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize) {
    int* rowCount = (int*)calloc(m, sizeof(int));
    int* colCount = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < indicesSize; i++) {
        rowCount[indices[i][0]]++;
        colCount[indices[i][1]]++;
    }
    
    int oddCount = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((rowCount[i] + colCount[j]) % 2 != 0) {
                oddCount++;
            }
        }
    }
    
    free(rowCount);
    free(colCount);
    return oddCount;
}