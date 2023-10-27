#include <stdio.h>

int main() {
    // =================================
    // THIS IS FIRST LEVEL ENCRYPTION
    // =================================

    // Secret array for algorithm
    char arr[] = "ABCDEFGHIJKLMN12345abcdefghijklmnopqrstuvwxyzOPQRSTUVWXYZ67890abcdefghijklmnopqrstuvwxyz !@#$%^&*,.;:/?abcdefghijklmnopqrstuvwxyz";
    int arrLen = sizeof(arr) - 1;

    // Secret array
    char secret[1000];
    int i;

    // Message input as an array.
    char message[1000];
    printf("Write your message => ");
    fgets(message, sizeof(message), stdin);

    // For first level encryption
    for (i = 0; i < sizeof(message); ++i) {
        char data[1];

        if (message[i] == '\0') {
            break;
        } else {
            for (int x = 0; x < arrLen; x++) {
                if (arr[x] == message[i]) {
                    data[0] = arr[x + 3]; // here 3 is the secret shifting.
                    break;
                }
            }
            secret[i] = data[0];
        }
    }

    // Output for first level encryption
    printf("FIRST LEVEL ENCRYPTION: %s\n", secret);

    // =================================
    // THIS IS SECOND LEVEL ENCRYPTION
    // =================================

    int c = 0;
    int decimaArr[1000];

    while (secret[c] != '\0') {
        char character = secret[c];
        // CONVERT TO DECIMAL
        int decimalValue = (int)character;
        // Add to decimaArr
        decimaArr[c] = decimalValue * 3; // here 3 is the secret shifting.
        c++;
    }

    // Output for second level encryption
    printf("SECOND LEVEL ENCRYPTION: ");
    int x = 0;
    while (decimaArr[x] != '\0') {
        printf("%d", decimaArr[x]);
        x++;
    }

    printf("\n");

    return 0;
}
