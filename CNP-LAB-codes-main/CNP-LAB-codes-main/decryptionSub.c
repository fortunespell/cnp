#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main() {
    char seq[] = "qwertyuiopasdfghjklzxcvbnm1234567890", data[100], decoded[100];
    int i, j, len;
    printf("Enter data: ");
    gets(data);
    len = strlen(data);

    for (i = 0; i < len; i++) {
        for (j = 0; j < 36; j++) {
            if (seq[j] == tolower(data[i])) {
                decoded[i] = isupper(data[i]) ? 'A' + j : (islower(data[i]) ? 'a' + j : '0' + (j - 26));
                break;
            }
        }
        if (j == 36) decoded[i] = data[i];
    }
    decoded[len] = '\0';
    printf("\nDecoded string is: %s", decoded);
}
