bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (n == 0) return true;
    
    for (int i = 0; i < flowerbedSize; i++) {
        // Check if the current plot is empty and its adjacent plots are also empty (or out of bounds)
        if (flowerbed[i] == 0 && 
            (i == 0 || flowerbed[i - 1] == 0) && 
            (i == flowerbedSize - 1 || flowerbed[i + 1] == 0)) {
            
            // Plant a flower
            flowerbed[i] = 1;
            n--;
            
            // If we have placed all necessary flowers, return true early
            if (n == 0) return true;
        }
    }
    
    return n <= 0;
}