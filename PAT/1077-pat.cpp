#include<cstdio>
#include<vector>

using namespace std;

int main(int argc, const char** argv) {
    int num, full;
    scanf("%d %d", &num, &full);
    int temp_count;
    int temp_input;
    int teacher;
    int stdscore;
    int avg;
    int max,min;
    bool bool_max, bool_min;
    int res;
    vector<int> sum(num-1);
    for(int i=0; i<num; i++){
        temp_count = 0;
        stdscore = 0;
        bool_max = true;
        bool_min = true;
        max = 0;
        min = full;
        for(int k=0; k<num; k++){
            scanf("%d", &temp_input);
            if(k == 0){
                teacher = temp_input;
            }
            else{
                if(temp_input>= 0 && temp_input<= full){
                    max = temp_input > max ? temp_input:max;
                    min = temp_input < min ? temp_input:min;
                    sum[temp_count++] = temp_input;
                }
            }
        }
        for(int w=0; w<temp_count; w++){
            if(sum[w] == max && bool_max){
                sum[w] = 0;
                bool_max = false;
            }
            if(sum[w] == min && bool_min){
                sum[w] = 0;
                bool_min = false;
            }
            stdscore += sum[w];
        }
        avg = stdscore/(temp_count-2);
        res = (teacher+avg+1)/2;
        printf("%d\n", res);
    }
    return 0;
}
