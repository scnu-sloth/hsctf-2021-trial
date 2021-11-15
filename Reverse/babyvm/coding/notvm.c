#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t flag[32] = "flag{T0ver_1s_my_boyfri3nd_h4ha}";

    for (int i = 0; i < 32; i++) {
        flag[i] ^= i;
    }
    for (int i = 0; i < 32; i++) {
        flag[i] += 32;
    }
    for (int i = 0; i < 32; i++) {
        flag[i] ^= 0xCC;
    }
    for (int i = 0; i < 32; i++) {
        flag[i] -= 64;
    }

    for (int i = 0; i < 32; i++) {
        printf("%d, ", flag[i]);
    }
    printf("\n");
    return 0;
}