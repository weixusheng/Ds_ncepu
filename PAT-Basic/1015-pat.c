#include<stdlib.h>
#include<stdio.h>

typedef struct _student{
    int id;
    int d;
    int c;
    int rank;
    int sum;
}sstudent, *Student;

int rank(Student s, int h, int l){
    if(s->d<l || s->c<l) return 0;
    else if(s->d>=h && s->c>=h) return 4;
    else if(s->d>=h) return 3;
    else if(s->d>=s->c) return 2;
    else return 1;
}

int comp(const void *a, const void *b){
    Student s1= *(Student*)a;
    Student s2= *(Student*)b;
    if(s1->rank != s2->rank) return s1->rank-s2->rank;
    else if(s1->sum != s2->sum) return s1->sum-s2->sum;
    else if(s1->d != s2->d)     return s1->d - s2->d;
    else if(s1->id != s2->id) return s2->id-s1->id;
    else{
        return 0;
    }
}

int main() {
    int n, l, h,m=0;
    Student students[100000] = {0};
    //sstudent buffer[100000];
    scanf("%d %d %d", &n, &l, &h);
    for(int i=0; i<n; i++){
        //Student s = buffer + i;
        Student s = (Student)malloc(sizeof(sstudent));
        scanf("%d %d %d", &s->id, &s->d, &s->c);
        s->sum = s->d + s->c;
        if((s->rank = rank(s, h, l)) != 0){
            students[m++] = s;
        }
    }
    qsort(students, m, sizeof(Student), comp);
    printf("%d\n", m);
    for(int i = m - 1; i >= 0; i--)
        printf("%d %d %d\n", students[i]->id, students[i]->d, students[i]->c);
    return 0;
}