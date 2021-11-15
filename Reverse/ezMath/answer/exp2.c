#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv, const char **envp)
{
  int v3; // eax
  int v4; // er8
  int v5; // er9
  int v6; // ecx
  int v7; // er8
  int v8; // er9
  int v9; // edx
  int v10; // ecx
  int v11; // er8
  int v12; // er9
  char v14; // [rsp+0h] [rbp-30h]
  char v15; // [rsp+0h] [rbp-30h]
  int v16; // [rsp+8h] [rbp-28h] BYREF
  int i; // [rsp+Ch] [rbp-24h]
  int v18; // [rsp+10h] [rbp-20h]
  int j; // [rsp+14h] [rbp-1Ch]
  int v20; // [rsp+18h] [rbp-18h]
  int v21; // [rsp+1Ch] [rbp-14h]
  int v22; // [rsp+20h] [rbp-10h]
  char v23[2]; // [rsp+26h] [rbp-Ah]
  // unsigned __int64 v24; // [rsp+28h] [rbp-8h]

  // v24 = __readfsqword(0x28u);
  srandom(8225);
  v23[0] = 43;
  v23[1] = 45;
  // puts("Welcome to EZest RE in the world!!! 0v0");
  // puts("Please answer all the math probs~");
  // puts("READY...?");
  for ( i = 0; i <= 57004; ++i )
  {
    v3 = rand();
    v20 = v3 % 21 + 1;
    v18 = 2021;
    // printf((unsigned int)"2021", (_DWORD)argv, v3 % 21, v3 % 21, v4, v5, v14);
    for ( j = 0; j < v20; ++j )
    {
      v21 = (int)rand() % 21;
      v22 = rand() & 1;
      // v22 = (unsigned __int8)v22;
      // printf((unsigned int)" %c %d", v23[(unsigned __int8)v22], v21, v6, v7, v8, v15);
      if ( v22 )
      {
        if ( v22 == 1 )
          v18 -= v21;
        else
          puts("Are you serious? ");
      }
      else
      {
        v18 += v21;
      }
    }
    printf("%d", v18);
    // putchar(10LL);
    // argv = (const char **)&v16;
    // _isoc99_scanf((unsigned int)"%d", (unsigned int)&v16, v9, v10, v11, v12, v15);
    // if ( v18 != v16 )
    // {
    //   puts("Try again and try again~ ");
    //   return 0;
    // }
    // puts("OK! ");
  }
  // puts("Congratulations! Get your flag as \"flag{\"+md5(str(answer1)+str(answer2)+...).hexdigest()+\"}\"");
  return 0;
}