#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int main(int argc, const char** argv) {
    double s1,s2,s3,s4;
    scanf("%lf %lf %lf %lf",&s1, &s2, &s3, &s4);
    double A,B;
    A = s1*s3*cos(s2+s4);
    B = s1*s3*sin(s2+s4);
    if(abs(A) < 0.01){
        A = 0;
    }
    if(abs(B) < 0.01){
        B = 0;
    }
    if(B >= 0){
        printf("%.2f+%.2fi", A, B);
    }
    else{
        printf("%.2f%.2fi", A, B);
    }
    return 0;
}