#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;


int main(int argc, const char** argv) {
    string a,b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int sum, count;
    if(a.size() > b.size()){
        b.append(a.size()-b.size(),'0');
    }
    else{
        a.append(b.size()-a.size(),'0');
    }
    count = a.size();
    //int count = a.size()>b.size() ? b.size():a.size();
    for(int i=0; i<count; i++){
        if((i+1)%2 == 1){   //single
            sum = (a[i]-'0') + (b[i]-'0');
            sum = sum%13;
            if(sum == 10){
                b[i] = 'J';
            }
            else if(sum == 11){
                b[i] = 'Q';
            }
            else if(sum == 12){
                b[i] = 'K';
            }
            else{
                b[i] = sum + '0';
            }
        }
        else{
            sum = (b[i]-'0')-(a[i]-'0');
            if(sum < 0){
                sum += 10;
            }
            b[i] = sum + '0';
        }
    }
    reverse(b.begin(),b.end());
    cout << b; 
    return 0;
}

/*
int main(){
	string a, b, c;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int lena = a.length();
	int lenb = b.length();
	int length = 0;
	if (lena > lenb){
		b.append(lena - lenb, '0');
		length = lena;
	}
	else{
		a.append(lenb - lena, '0');
		length = lenb;
	}
	string x = {"0123456789JQK"};
	for (int i = 1; i <= length; i++){
		if (i % 2 == 1){
			int d = (a[i-1] - '0' + b[i-1] - '0') % 13;
			c+=x[d];
		}
		else{
			int d = b[i-1] - a[i-1];
			if (d < 0){
				d = d + 10;
			}
			c += to_string(d);
		}
	}
	reverse(c.begin(), c.end());
	cout<< c << endl;
	return 0;
}
*/
