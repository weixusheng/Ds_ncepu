#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

int main()
{
    int N, count = 0;
    /* store name and birthday in one string: "YYYY/MM/DD\0NAMES\0" */
    char cur[17], eldest[17] = {'9'}, youngest[17] = {'0'};

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%s %s", cur + 11, cur);
        if(strcmp(cur, "1814/09/06") >= 0 && strcmp(cur, "2014/09/06") <= 0)
        {
            if(strcmp(cur, eldest) <= 0)
                memcpy(eldest, cur, 17);
            if(strcmp(cur, youngest) >= 0)
                memcpy(youngest, cur, 17);
            count++;
        }
    }
    if(count)
        printf("%d %s %s", count, eldest + 11, youngest + 11);
    else
        printf("0");

    return 0;
}

/*
typedef struct {
    char name[100];
    int age;
}person,*node;

int main(){
    int num,year,month,day;
    int max,maxd=0,max_day = 200*365,count = 0;
    int min,mind = max_day;
    scanf("%d", &num);
    node data[100000];
    char temp_name[100];
    int init_day = 2014*365 + 9*30 + 6;
    int temp_age,sumday;
    for(int i=0; i<num; i++){
        scanf("%s %d/%d/%d", &temp_name, &year, &month, &day);
        sumday = (year*365 + 30*month + day);
        temp_age = init_day-sumday;
        node newp = (node)malloc(sizeof(person));
        if(temp_age <= max_day && temp_age>0){
            strcpy(newp->name, temp_name);
            newp->age = temp_age;
            data[i] = newp;
            if(temp_age > maxd){
                max = i;
                maxd = temp_age;
            }
            if(temp_age < mind){
                min = i;
                mind = temp_age;
            }
            count++;
        }
    }
    if(count == 0){
        printf("0");
    }
    else{
        printf("%d %s %s",count, data[max]->name, data[min]->name);
    }
    return 0;
}
*/