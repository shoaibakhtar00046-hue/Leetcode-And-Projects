bool checkIfPangram(char* sentence) {
    int seen = 0;
    for (int i = 0; sentence[i] != '\0'; i++) {
        int bitIndex = sentence[i] - 'a';
        seen |= (1 << bitIndex);
    }
    return seen == 0x3FFFFFF; // 26 bits set to 1
}