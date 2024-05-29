
#ifndef F2_H
#define F2_H

void print_data(const u_char *data, int len) {
    int i;
    int gap;
    const u_char *ch;

    printf("Packet data:\n");
    for (i = 0; i < len; i++) {
        if (i % 16 == 0) {
            printf("0x%04x: ", i);
        }

        printf("%02x ", data[i]);

        if ((i % 16 == 15) || (i == len - 1)) {
            gap = 15 - (i % 16);
            if (gap) {
                printf("%*s", gap * 3, " ");
            }
            printf(" | ");
            ch = data + (i - (i % 16));
            for (int j = 0; j < 16 - gap; j++) {
                if (isprint(ch[j])) {
                    printf("%c", ch[j]);
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
    }
}
#endif