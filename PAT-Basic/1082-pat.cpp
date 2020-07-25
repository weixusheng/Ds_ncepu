#include<cstdio>
#include<iostream>


using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;
    int max = 0, min = 10000;
    int id,x,y,len;
    int idmax,idmin;
    for(int i=0; i<num; i++){
        cin >> id >> x >> y;
        len = x*x + y*y;
        if(len < min){
            idmin = id;
            min = len;
        }
        if(len > max){
            idmax = id;
            max = len;
        }
    }
    printf("%04d %04d", idmin, idmax);
    return 0;
}
