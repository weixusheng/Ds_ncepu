#include<cstdio>
#include<set>

using namespace std;

int main(int argc, const char** argv) {
    int num;
    scanf("%d", &num);
    set<int> data;
    int temp, sum = 0;
    int count = 0;
    for(int i=0; i<num; i++){
        sum = 0;
        scanf("%d", &temp);
        while(temp > 0){
            sum += temp%10;
            temp = temp/10;
        }
        if(data.find(sum) == data.end()){
            data.insert(sum);
            count++;
        }
    }
    printf("%d\n", count);
    int flag = 0;
    for(auto it = data.begin(); it != data.end(); it++){
        if(flag == 0){
            flag = 1;
        }
        else{
            printf(" ");
        }
        printf("%d", *it);
    }
    return 0;
}