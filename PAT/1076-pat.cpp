#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(int argc, const char** argv) {
    int num;
    int i=0;
    scanf("%d", &num);
    vector<vector<char> > chos;
    chos.resize(4, vector<char>(2));
    vector<char> res(num);
    getchar();
    for(int i=0; i<num; i++){
        //A-T B-F C-F D-F
        scanf("%c-%c %c-%c %c-%c %c-%c",&chos[0][0], &chos[0][1], &chos[1][0],&chos[1][1], &chos[2][0],&chos[2][1], &chos[3][0],&chos[3][1]);
        for(int k=0; k<4; k++){
            if(chos[k][1] == 'T'){
                res[i] = chos[k][0];
            }
        }
        getchar();
    }
    for(int w=0; w<num; w++){
        switch (res[w])
        {
        case 'A':
            printf("1");
            break;
        case 'B':
            printf("2");
            break;
        case 'C':
            printf("3");
            break;
        case 'D':
            printf("4");
            break;
        }
    }
    return 0;
}