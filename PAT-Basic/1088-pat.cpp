#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

int rev(int a){
    int tmp1;
    int tmp2;
    tmp1 = a%10;
    tmp2 = a/10;
    return (tmp1*10 + tmp2);
}

int main(int argc, char const *argv[])
{
    int m;
    double x, y;
    cin >> m >> x >> y;
    double charg = x/y;
    bool isfind = false;
    double shit[3];
    /* find alpha */
    for(int i=10; i<=99; i++){
        if(fabs(i-rev(i)) == charg*rev(i)){
            shit[0] = i;
            isfind = true;
        }
    }
    shit[1] = rev(shit[0]);
    shit[2] = (shit[1])/y;
    if(isfind){
        printf("%d",int(shit[0]));
        for(int k=0; k<3; k++){
            if(shit[k] > m){
                printf(" Cong");
            }
            if(shit[k] == m){
                printf(" Ping");
            }
            if(shit[k] < m){
                printf(" Gai");
            }
        }
    }
    else{
        printf("No Solution");
    }
    system("pause");
    return 0;
}
