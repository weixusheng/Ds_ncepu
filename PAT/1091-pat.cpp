#include<cstdlib>
#include<iostream>

using namespace std;

bool isshit(int a, int b){
    int shit = a*a*b;
    while(a != 0){
        if(shit % 10 == a % 10){
            shit = shit/10;
            a = a/10;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int num, tmp;
    cin >> num;
    for(int i=0; i<num; i++){
        cin >> tmp;
        bool hasshit = false;
        for(int j=1; j<10; j++){
            if(isshit(tmp, j)){
                printf("%d %d\n", j, tmp*tmp*j);
                hasshit = true;
                break;
            }
        }
        if(!hasshit){
            printf("No\n");
        }
    }
    system("pause");
    return 0;
}
