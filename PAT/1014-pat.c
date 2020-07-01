#include <stdio.h>
#include <ctype.h>

/*标准答案*/
int main()
{
    char str1[61], str2[61], str3[61], str4[61];
    scanf("%s %s %s %s", str1, str2, str3, str4);

    /* Find day, same char from [A-G] and same position in frist two lines */
    int DAY;
    char *weekdays[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    for(DAY = 0; str1[DAY] && str2[DAY]; DAY++)
        if(str1[DAY] == str2[DAY] && str1[DAY] >= 'A' && str1[DAY] <= 'G')
        {
            printf("%s", weekdays[str1[DAY] - 'A']);
            break;
        }

    /* Find hour, picking up from DAY, same character and position, [A-N|0-9] */
    int HH;
    for(HH = DAY + 1; str1[HH] && str2[HH]; HH++)
        if(str1[HH] == str2[HH])
        {
            if(str1[HH] >= 'A' && str1[HH] <= 'N')
            {
                printf(" %02d", str1[HH] - 'A' + 10);
                break;
            }
            if(isdigit(str1[HH]))
            {
                printf(" %02d", str1[HH] - '0');
                break;
            }
        }

    /* Find minute, same alphabet character from last two lines */
    int MM;
    for(MM = 0; str3[MM] && str4[MM]; MM++)
        if(str3[MM] == str4[MM] && isalpha(str3[MM]))
        {
            printf(":%02d", MM);
            break;
        }

    return 0;
}

/*测试点4无法通过
int main(){
    char a1[61], a2[61], a3[61], a4[61];
    scanf("%s", a1);
    scanf("%s", a2);
    scanf("%s", a3);
    scanf("%s", a4);    //输入字符串
    int flag = 0; //找到了第一个
    int output1;    //输出星期
    int output2,output3=0;
    char week[7][10] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    //判断第一对字符串
    int i=0;
    while(a1[i]!= '\0' && a2[i]!= '\0'){    //第一个字符串
        if(a1[i] == a2[i] && flag == 0 && (a1[i]>='A'&&a1[i]<='G')){ //找到第一个
            output1 = a1[i]-'A';
            printf("%s ", week[output1]);
            flag = 1;
            i = i+1;
        }
        if(a1[i] == a2[i] && flag == 1 && ((a1[i]>='A'&&a1[i]<='N') || (a1[i]>='0'&&a1[i]<='9'))){
            output2 = isdigit(a1[i]);
            if(output2){   //当前为数字
                output2 = a1[i]-'0';
                printf("%02d:", output2);
            }
            else{    //字母
                output2 = a1[i]- 'A' + 10;
                printf("%02d:", output2);
            }
            break;
        }
        i++;
    }   //第一个字符串结束
    i = 0;
    while(a3[i] && a4[i]){
        if((a3[i] == a4[i]) && (a3[i]>='a'&&a3[i]<='z')){
            printf("%02d", i);
            break;
        }
        i++;
    }
    return 0;
}
*/