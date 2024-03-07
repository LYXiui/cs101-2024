#include <stdio.h>

int main() {
    int a[] = {0, 1, 2};
    char b[] = {"ABC"};
    float c[] = { 2.2, 3.3};

    FILE *file = fopen("a.bin", "wb");
    if (file == NULL) {
        printf("無法開啟檔案\n");
        return 1;
    }

    fwrite(a, sizeof(int), 3, file);
    fwrite(b, sizeof(char), 3, file);
    fwrite(c, sizeof(float), 3, file);

    fclose(file);

    file = fopen("a.bin", "rb");
    if (file == NULL) {
        printf("無法開啟檔案\n");
        return 1;
    }

    fread(a, sizeof(int), 3, file);
    fread(b, sizeof(char), 3, file);
    fread(c, sizeof(float), 3, file);

    fclose(file);

    for (int i = 0; i < 3; i++) {
        printf("%d %c %.1f\n", a[i], b[i], c[i]);
    }

    return 0;
}
