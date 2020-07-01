#include<stdio.h>
#include<stdlib.h>

/*int main(){
    char word[162];
    int word_count = 0;
    //scanf("%s", &word);
    gets(word);
    int p = 0;
    int q = 161;
    while(word[p] != '\0'){
        while(word[p]!= ' ' && word[p]!= '\0'){
            word_count++;
            p++;
        }
        for(int i=1; i<word_count+1; i++){
            word[q] = word[p-i];
            q--;
        }
        ++p;
        word_count = 0;
        word[q] = ' ';
        q--;
    }
    int start = 161-p+2;
    for(int k=1; k<p; k++){
        printf("%c", word[start]);
        start++;
    }
    return 0;
}
*/
int main(){
    int i;
    char data[81];
    gets(data);
    for(i=strlen(data)-1; i>=0; i--){
        if(data[i] == ' '){
            printf("%s", &data[i+1]);
            printf("%c", data[i]);
            data[i] = '\0';
        }
        if(i==0){
            printf("%s", &data[i]);
        }
    }
    return 0;
}