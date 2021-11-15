#include <stdio.h>
#include <stdint.h>

int8_t opcode[429] = {
    1, 1, 0, 33, 1, 10, 2, 1, 33, 1, 1, 2, 1, 33, 1, 15, 2, 1, 33, 1, 8, 2, 1, 33, 1, 19, 2, 1, 33, 1, 125, 2, 1, 33, 1, 90, 2, 1, 33, 1, 29, 2, 1, 33, 1, 1, 2, 1, 33, 1, 23, 2, 1, 33, 1, 121, 2, 1, 33, 1, 86, 2, 1, 33, 1, 19, 2, 1, 33, 1, 126, 2, 1, 33, 1, 15, 2, 1, 33, 1, 26, 2, 1, 33, 1, 99, 2, 1, 33, 1, 31, 2, 1, 33, 1, 17, 2, 1, 33, 1, 6, 2, 1, 33, 1, 30, 2, 1, 33, 1, 11, 2, 1, 33, 1, 19, 2, 1, 33, 1, 72, 2, 1, 33, 1, 26, 2, 1, 33, 1, 17, 2, 1, 33, 1, 105, 2, 1, 33, 1, 31, 2, 1, 33, 1, 68, 2, 1, 33, 1, 25, 2, 1, 33, 1, 19, 2, 1, 33, 1, 14, 2, 1, 1, 1, 87, 6, 1, 1, 1, 104, 6, 1, 1, 1, 97, 6, 1, 1, 1, 116, 6, 1, 1, 1, 32, 6, 1, 1, 1, 105, 6, 1, 1, 1, 115, 6, 1, 1, 1, 32, 6, 1, 1, 1, 121, 6, 1, 1, 1, 111, 6, 1, 1, 1, 117, 6, 1, 1, 1, 114, 6, 1, 1, 1, 32, 6, 1, 1, 1, 102, 6, 1, 1, 1, 108, 6, 1, 1, 1, 97, 6, 1, 1, 1, 103, 6, 1, 1, 1, 63, 6, 1, 1, 1, 10, 6, 1, 1, 1, 0, 5, 2, 3, 2, 2, 1, 7, 1, 32, 8, 245, 1, 1, 0, 10, 1, 64, 2, 1, 7, 1, 32, 8, 246, 1, 1, 64, 4, 2, 11, 1, 1, 49, 1, 2, 7, 1, 32, 8, 243, 1, 1, 32, 17, 2, 1, 11, 2, 32, 25, 1, 2, 2, 1, 7, 1, 64, 8, 240, 1, 1, 32, 10, 1, 32, 2, 1, 7, 1, 64, 8, 246, 1, 1, 0, 1, 2, 32, 9, 1, 204, 23, 1, 2, 8, 46, 2, 1, 2, 2, 7, 1, 32, 8, 239, 1, 1, 82, 6, 1, 1, 1, 105, 6, 1, 1, 1, 103, 6, 1, 1, 1, 104, 6, 1, 1, 1, 116, 6, 1, 1, 1, 33, 6, 1, 1, 1, 10, 6, 1, 24, 35, 1, 1, 87, 6, 1, 1, 1, 114, 6, 1, 1, 1, 111, 6, 1, 1, 1, 110, 6, 1, 1, 1, 103, 6, 1, 1, 1, 33, 6, 1, 1, 1, 10, 6, 1, 0
};

int main()
{
    uint8_t zf = 0;
    uint8_t rsp = 0;
    uint16_t rip = 0;
    uint8_t reg[3] = {0};
    uint8_t memory[0x50] = {0};
    uint8_t stack[0x50] = {0};
    while (opcode[rip] != '\x00') {
        switch (opcode[rip]) {
            case '\x01':
                reg[opcode[rip+1]] = opcode[rip+2];
                rip += 3;
                break;
            case '\x11':
                reg[opcode[rip+1]] = reg[opcode[rip+2]];
                rip += 3;
                break;
            case '\x21':
                memory[reg[opcode[rip+1]]] = opcode[rip+2];
                rip += 3;
                break;
            case '\x31':
                memory[reg[opcode[rip+1]]] = reg[opcode[rip+2]];
                rip += 3;
                break;
            case '\x02':
                reg[opcode[rip+1]]++;
                rip += 2;
                break;
            case '\x03':
                stack[rsp++] = reg[opcode[rip+1]];
                rip += 2;
                break;
            case '\x04':
                reg[opcode[rip+1]] = stack[--rsp];
                rip += 2;
                break;
            case '\x05':
                reg[opcode[rip+1]] = getchar();
                rip += 2;
                break;
            case '\x06':
                putchar(reg[opcode[rip+1]]);
                rip += 2;
                break;
            case '\x07':
                zf = reg[opcode[rip+1]] - opcode[rip+2];
                rip += 3;
                break;
            case '\x17':
                zf = memory[reg[opcode[rip+1]]] - memory[reg[opcode[rip+2]]];
                rip += 3;
                break;
            case '\x08':
                rip += 2;
                if (zf != 0) rip += opcode[rip-2+1];
                break;
            case '\x18':
                rip += 2;
                rip += opcode[rip-2+1];
                break;
            case '\x09':
                memory[reg[opcode[rip+1]]] ^= opcode[rip+2];
                rip += 3;
                break;
            case '\x19':
                memory[reg[opcode[rip+1]]] ^= reg[opcode[rip+2]];
                rip += 3;
                break;
            case '\x0A':
                memory[reg[opcode[rip+1]]] += opcode[rip+2];
                rip += 3;
                break;
            case '\x0B':
                reg[opcode[rip+1]] -= opcode[rip+2];
                rip += 3;
                break;
            default:
                return 0;
        }
    }
    return 0;
}