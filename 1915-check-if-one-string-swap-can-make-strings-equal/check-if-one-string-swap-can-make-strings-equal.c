bool areAlmostEqual(char* s1, char* s2) {
    int firstDiff = -1;
    int secondDiff = -1;
    int diffCount = 0;
    
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            diffCount++;
            if (diffCount == 1) {
                firstDiff = i;
            } else if (diffCount == 2) {
                secondDiff = i;
            } else {
                // More than 2 mismatches cannot be fixed with a single swap
                return false;
            }
        }
    }
    
    // Case 1: Strings are already identical
    if (diffCount == 0) return true;
    
    // Case 2: Exactly 2 mismatches, check if swapping them makes the strings equal
    if (diffCount == 2) {
        return (s1[firstDiff] == s2[secondDiff] && s1[secondDiff] == s2[firstDiff]);
    }
    
    // Case 3: Exactly 1 mismatch is impossible to fix with a swap
    return false;
}