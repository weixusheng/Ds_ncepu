#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    int data[10000000] = {0};
    long int tmp;
    int cmax = 0;
    long int smax = 0;
    scanf("%d %d", &a, &b);
    for(int i=0; i<b; i++){
        for(int j=0; j<a; j++){
            scanf("%ld", &tmp);
            data[tmp] += 1;
            if(data[tmp] > cmax){
                cmax = data[tmp];
            }
            smax = tmp;
        }
    }
    printf("%ld", smax);
    return 0;
}
