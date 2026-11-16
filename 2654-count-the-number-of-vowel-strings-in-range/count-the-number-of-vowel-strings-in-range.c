bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int vowelStrings(char** words, int wordsSize, int left, int right) {
    int count = 0;
    for (int i = left; i <= right; i++) {
        char* s = words[i];
        int len = strlen(s);
        if (isVowel(s[0]) && isVowel(s[len - 1])) {
            count++;
        }
    }
    return count;
}