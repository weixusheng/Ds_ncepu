#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

/*
vector<int> shit1(21);
vector<int> data1(21);
vector<int> data2(21);

vector<int> num_convert(int num, vector<int> data){
    int temp;
    int sum = 0;
    while(num > 0){
        temp = num %10;
        data[++sum] = temp;
        num = num/10;
    }
    data[0] = sum;
    return data;
}

int main(int argc, const char** argv) {
    int shit, num1, num2;
    scanf("%d %d %d", &shit, &num1, &num2);
    vector<int> res(20);
    shit1 = num_convert(shit,shit1);
    data1 = num_convert(num1,data1);
    data2 = num_convert(num2,data2);
    int size1 = data1[0];
    int size2 = data2[0];
    int leftshit, tempsum;
    int j = 1;
    int inshit = 0;
    while(size1 > 0 || size2 > 0){
        tempsum = 0;
        if(size1 >0 && size2 >0){
            tempsum = data1[j] + data2[j];
            size1--;
            size2--;
        }
        else{
            if(size1 > 0){
                tempsum = data1[j];
                size1--;
            }
            else{
                tempsum = data2[j];
                size2--;
            }
        }
        if(inshit){
            tempsum += inshit;
        }
        int convert_shit1;
        if(shit1[j] == 0){
            convert_shit1 = 10;
        }
        else{
            convert_shit1 = shit1[j];
        }
        if(tempsum >= convert_shit1){
            inshit = tempsum/convert_shit1;
        }
        else{
            inshit = 0;
        }
        leftshit = tempsum % convert_shit1;
        res[j] = leftshit;
        j++;
    }
    int h = j-1;
    if(inshit){
        res[j] = 1;
        h = j;
    }
    for(; h>0; h--){
        printf("%d", res[h]);
    }
    if(j == 1){
        printf("0");
    }
    return 0;
}
*/
int main() {
    string s, s1, s2, ans;
    int carry = 0, flag = 0;
    cin >> s >> s1 >> s2;
    ans = s;
    string ss1(s.length() - s1.length(), '0');
    s1 = ss1 + s1;
    string ss2(s.length() - s2.length(), '0');
    s2 = ss2 + s2;
    for(int i = s.length() - 1; i >= 0; i--) {
        int mod = s[i] == '0' ? 10 : (s[i] - '0');
        ans[i] = (s1[i] - '0' + s2[i] - '0' + carry) % mod + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry) / mod;
    }
    if (carry != 0) ans = '1' + ans;
    for(int i = 0; i < ans.size(); i++) {
        if (ans[i] != '0' || flag == 1) {
            flag = 1;
            cout << ans[i];
        }
    }
    if (flag == 0) cout << 0;
    return 0;
}
