#include<stdio.h>
#include<stdlib.h>

int main()
{
    int B;
    char A[1001], *p = A;
    scanf("%s %d", A, &B);
    int twodigit, remainder = 0;
    for(int i = 0; A[i]; i ++)
    {
        twodigit = remainder * 10 + (A[i] - '0');
        A[i] = twodigit / B + '0';
        remainder = twodigit % B;
    }
    B = remainder;
    if(A[0] == '0' && A[1] != '\0') p++;
    printf("%s %d", p, B);
    return 0;
}