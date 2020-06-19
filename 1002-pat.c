#include<stdlib.h>
#include<stdio.h>

int main(){
	//printf("hello"); 
    char pinyin[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char getnum;
    int sum;
    while((getnum = getchar())!= '\n'){
        sum += getnum - '0';
    }
    char res[4];
    sprintf(res, "%d", sum);
    printf("wodiu:%c\n", res[1]);
	    for(int i=0; res[i]!=0; i++){
    	//printf("%d\n",i);
        //printf("%d\n", res[i]-'0');
        //printf("%s\n", res);
        //if(i != 0){
          //  printf(" ");
        //}
        //printf("%s", pinyin[res[i]-'0']);
    }
    return 1;
}
