int totalMoney(int n) {
    int weeks = n / 7;
    int days = n % 7;
    
    // Sum of complete weeks: 
    // Week i (0-indexed) contributes (7 * (i + 1) + 21)
    // Sum for 'weeks' weeks = 28 * weeks + 7 * (weeks * (weeks - 1)) / 2
    int total = 28 * weeks + 7 * weeks * (weeks - 1) / 2;
    
    // Sum of remaining days in the last incomplete week
    int start = weeks + 1;
    for (int i = 0; i < days; i++) {
        total += start + i;
    }
    
    return total;
}