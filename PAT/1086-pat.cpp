#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include<algorithm>

using namespace std;

int main()
{
    int s1,s2;
    cin >> s1 >> s2;
    int sum = s1 * s2;
    string res = to_string(sum);
    reverse(res.begin(),res.end());
    printf("%d", stoi(res));
    //system("pause");
    return 0;
}
