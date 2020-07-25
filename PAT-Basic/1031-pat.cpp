#include<stdio.h> 
#include<string.h>
int main()
{   
    int N;
    scanf("%d",&N);
    int quan[18] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char jiaoyan[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
    bool flag = true;
    char id[20];
    for(int i = 0;i < N;i++) {
        scanf("%s",id);
        int j,sum = 0;
        for(j = 0;j<17;j++) {
            if(!(id[j] >= '0'&&id[j] <= '9')) break;
            sum += (id[j]-'0')*quan[j];
        }
        if(j<17) {
            flag = false;
            printf("%s\n",id);
        } else{
            if(jiaoyan[sum % 11] != id[17]) {
                flag = false;
                printf("%s\n",id);
            }
        }       
    } 
    if(flag == true) printf("All passed\n");
    return 0;
 } 