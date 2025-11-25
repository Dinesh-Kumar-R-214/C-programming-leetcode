char* intToRoman(int num) {
    static char result[20];
    int i = 0;

    while (num >= 1000) { result[i++] = 'M'; num -= 1000; }
    if (num >= 900) { result[i++] = 'C'; result[i++] = 'M'; num -= 900; }
    if (num >= 500) { result[i++] = 'D'; num -= 500; }
    if (num >= 400) { result[i++] = 'C'; result[i++] = 'D'; num -= 400; }
    while (num >= 100) { result[i++] = 'C'; num -= 100; }
    if (num >= 90) { result[i++] = 'X'; result[i++] = 'C'; num -= 90; }
    if (num >= 50) { result[i++] = 'L'; num -= 50; }
    if (num >= 40) { result[i++] = 'X'; result[i++] = 'L'; num -= 40; }
    while (num >= 10) { result[i++] = 'X'; num -= 10; }
    if (num >= 9) { result[i++] = 'I'; result[i++] = 'X'; num -= 9; }
    if (num >= 5) { result[i++] = 'V'; num -= 5; }
    if (num >= 4) { result[i++] = 'I'; result[i++] = 'V'; num -= 4; }
    while (num >= 1) { result[i++] = 'I'; num -= 1; }

    result[i] = '\0';
    return result;
}
