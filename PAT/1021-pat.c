#include<stdio.h>
#include<stdlib.h>

int main(){
    int hash[10] = {0};
    int max = 0;
    char num[1001];
    scanf("%s", &num);
    int i = 0;
    while(num[i]!= '\0'){
        int cur = num[i]-'0';
        if(cur>max){
            max = cur;
        }
        hash[cur]++;
        i++;
    }
    for(int k=0; k<10; k++){
        if(hash[k]!=0){
            printf("%d:%d",k, hash[k]);
            if(k != max){
                printf("\n");
            }
        }
    }
    return 0;
}

/*
int main()
{
    char c;
    int count[10] = {0};
    while((c = getchar()) != '\n')
        count[c - '0']++;

    for(int i = 0; i < 10; i++) if(count[i])
        printf("%d:%d\n", i, count[i]);

    return 0;
}
*/