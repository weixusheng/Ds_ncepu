#include<iostream>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    string d,tmp,shit;
    int num, cnt;
    int j;
    cin >> d;
    scanf("%d", &num);
    for(int k=0; k<num-1; k++){
        /*
        tmp = "";
        cnt = 1;
        for(int j=0; j<d.size(); j++){
            if(d[j+1] == d[j]){
                cnt++;
            }
            else{
                shit = cnt+'0';
                tmp = tmp + d[j] + shit;
                cnt = 1;
            }
        }
        d = tmp;
        */
        string t;
        for (int i = 0; i < d.length(); i = j) {
            for (j = i; j < d.length() && d[j] == d[i]; j++);
            t += d[i] + to_string(j - i);
        }
        d = t;
    }
    printf("%s", d.c_str());
    return 0;
}
