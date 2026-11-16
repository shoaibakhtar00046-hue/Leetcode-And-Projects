int countConsistentStrings(char * allowed, char ** words, int wordsSize) {
    int mask = 0;
    for (int i = 0; allowed[i] != '\0'; i++) {
        mask |= (1 << (allowed[i] - 'a'));
    }
    
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        int consistent = 1;
        for (int j = 0; words[i][j] != '\0'; j++) {
            if (!(mask & (1 << (words[i][j] - 'a')))) {
                consistent = 0;
                break;
            }
        }
        if (consistent) {
            count++;
        }
    }
    
    return count;
}