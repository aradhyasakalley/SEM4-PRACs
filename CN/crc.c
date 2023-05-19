#include <stdio.h>
#include <string.h>

#define N strlen(gen_poly)

char data[20], gen_poly[20], check_value[20];
int i, j, data_length;

void xor() {
    for (j = 1; j < N; j++) {
        check_value[j] = (check_value[j] == gen_poly[j]) ? '0' : '1';
    }
}

void receiver() {
    printf("Enter the received data: ");
    scanf("%s", data);
    crc();
    for (i = 0; i < N - 1 && check_value[i] != '1'; i++) {
        // Check if any error is detected
    }
    if (i == N - 1) {
        printf("No error detected.\n");
    } else {
        printf("Error in transmission.\n");
    }
}

void crc() {
    for (i = 0; i < N; i++) {
        check_value[i] = data[i];
    }
    do {
        if (check_value[0] == '1') {
            xor();
        }
        for (j = 0; j < N - 1; j++) {
            check_value[j] = check_value[j + 1];
        }
        check_value[j] = data[i++];
    } while (i < data_length + N - 1);
}

int main() {
    printf("Enter the data to be sent: ");
    scanf("%s", data);
    printf("Enter the generating polynomial: ");
    scanf("%s", gen_poly);

    data_length = strlen(data);

    for (i = data_length; i < data_length + N - 1; i++) {
        data[i] = '0';
    }
    data[i] = '\0';

    printf("The data padded with (N-1) zeros is: %s\n", data);

    crc();
    printf("The CRC or the check value is: %s\n", check_value);

    for (i = data_length; i < data_length + N - 1; i++) {
        data[i] = check_value[i - data_length];
    }
    data[i] = '\0';

    printf("The final data to be sent is: %s\n", data);
    receiver();

    return 0;
}
