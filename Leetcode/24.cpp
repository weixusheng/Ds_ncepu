#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

typedef struct listnode{
    struct listnode *next;
    int data;
}listnode;

listnode* init_list(vector<int> a){
    listnode *l = (listnode*)malloc(sizeof(listnode));
    listnode *q;
    bool tag = false;
    q = l;
    for(int i=0; i<a.size(); i++){
        listnode *p = (listnode*)malloc(sizeof(listnode));
        p->data = a[i];
        if(tag == false){
            q->next = p;
            tag = true;
        }
        q->next = p;
        p->next = nullptr;
        q = p;
    }
    return l->next;
}

listnode* reversel(listnode* head){
    if(head == nullptr || head->next == nullptr){
            return head;
    }
    else{
        listnode *p, *q;
        p = head;
        q = p->next;
        bool tag = false;
        listnode *pre;
        listnode *shit = (listnode*)malloc(sizeof(listnode));
        while(q != nullptr){
            if(tag == false){
                pre = shit;
                tag = true;
            }
            pre->next = q;
            p->next = q->next;
            q->next = p;
            pre = p;
            if(p->next != nullptr){
                p = p->next;
                q = p->next;
            }
            else{
                break;
            }
        }
        return shit->next;
    }
}

int main(int argc, char const *argv[])
{
    int tmp;
    vector<int> data;
    while(1){
        scanf("%d", &tmp);
        data.push_back(tmp);
        if(getchar() == '\n'){
            break;
        }
    }
    listnode *p =  init_list(data);
    reversel(p);
    return 0;
}
