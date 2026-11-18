int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
    
    for (int i = 0; i < imageSize; i++) {
        int n = imageColSize[i];
        (*returnColumnSizes)[i] = n;
        int left = 0, right = n - 1;
        while (left <= right) {
            int temp = image[i][left] ^ 1;
            image[i][left] = image[i][right] ^ 1;
            image[i][right] = temp;
            left++;
            right--;
        }
    }
    return image;
}