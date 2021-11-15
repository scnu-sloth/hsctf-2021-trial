#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(0x2021);
    char opchar[2] = {'+', '-'};
    printf("Welcome to EZest RE in the world!!! 0v0\n");
    printf("Please answer all the math probs~\n");
    printf("READY...?\n");
    for (int rounds = 0; rounds < 0xDEAD; rounds++) {
        int cnt = rand() % 21 + 1;
        int res = 2021;
        int ans;
        printf("2021");
        for (int i = 0; i < cnt; i++) {
            int num = rand() % 21;
            int op;
            op = rand()&1;
            printf(" %c %d", opchar[op], num);
            switch(op) {
                case 0:
                    res += num;
                    break;
                case 1:
                    res -= num;
                    break;
                default:
                    printf("Are you serious? \n");
                    break;
            }
        }
        printf("\n");
        // printf("%d", res);
        scanf("%d", &ans);
        if (ans != res) {
            printf("Try again and try again~ \n");
            return 0;
        } else {
            printf("OK! \n");
        }
    }
    printf("Congratulations! Get your flag as \"flag{\"+md5(str(answer1)+str(answer2)+...).hexdigest()+\"}\"\n");
    return 0;
}

// flag{474a444e5d6cb14261e8408e891ac1b8}