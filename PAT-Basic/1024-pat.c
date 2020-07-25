#include<stdio.h>
#include<stdlib.h>

/*
int main(){
    char data[10000];
    scanf("%s", &data);
    int i = 0;
    while(data[i]!= 'E'){
        i++;
    }
    int xiaoshu = i-4;
    int num = i;  
    int zhishu = 0; 
    char zheng_fu;
    zheng_fu = data[i+1];
    i = i+2;
    while(data[i] != '\0'){
        zhishu = (data[i]-'0')+10*zhishu;
        i++;
    }
    if(zheng_fu == '-'){   
        printf("%c0.", data[0]);
        for(int k = 1; k<zhishu; k++){
            printf("0");
        }
        for(int h=1; h<num; h++){
            if(data[h]!='.'){
                printf("%c", data[h]);
            }
        }
    }
    else{   //姝ｆ暟
        //printf("%c",data[0]);
        if(zhishu > xiaoshu){
            for(int h=1; h<num; h++){
                if(data[h]!='.'){
                    printf("%c", data[h]);
                }
            }
            for(int w=1; w<(zhishu-xiaoshu);w++){
                printf("0");
            }
        }
        else{
            for(int h=1; h<num; h++){
                if(data[h]!='.'){
                    printf("%c", data[h]);
                }
                if((h-2) == zhishu){
                    printf(".");
                }
            }
        }
    }
    return 0;
}
*/
int main()
{
    int exponent;    /* the exponent part */
    char line[10000], *p = line;
    scanf("%[^E]E%d", line, &exponent);
    //char si,f[10005];
    //int indx;
    //scanf("%c%c.%[0-9]E%d",&si,&f[0],f+1,&indx);
    //scanf("%[^4]4E%d", line, &exponent);
    //printf("%s\n",line);
    //printf("%d\n",exponent);
    //printf("%s\n",f);
    if(*p++ == '-') putchar('-');   
    if(exponent >= 0)         
    {
        putchar(*p);
        for(p += 2; exponent; exponent--)  
            putchar(*p ? *p++ : '0');
        if(*p)                              
        {
            putchar('.');
            while(*p) putchar(*p++);
        }
    }
    if(exponent < 0)           
    {
        printf("0.");
        for(exponent++; exponent; exponent++)       
            putchar('0');
        for(; *p; p++) if(*p != '.') putchar(*p);  
    }
    fflush(stdin); //这三行代码，实现自己的pause功能。 先清除缓存中的数据
    printf("<------------outputend"); //提示
    getchar();//等等按键
    return 0;
}
