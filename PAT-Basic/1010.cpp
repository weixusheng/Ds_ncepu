#include<cstdlib>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char ch;
    int tmp1, tmp2;
    bool flag = false;
    while(1){
        cin >> tmp1 >> tmp2;
        if(flag){
            cout << " ";
        }
        else{
            flag = true;
        }
        if(tmp2 != 0){
            cout << tmp1*tmp2 << " " << tmp2-1;
        }
        if((ch = getchar()) == '\n'){
            break;
        }
    }
    if (flag == false) cout << "0 0";
    system("pause");
    return 0;
}
