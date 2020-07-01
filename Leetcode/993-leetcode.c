#include"Level_Tree.c"

/*链表结点-start*/
typedef struct List_node {
    struct node* data;
    struct List_node* next;
}listnode;
/*链表结点-end*/

/*链表头节点-start*/
typedef struct{
    listnode* head;
    int count;
    listnode* next;
}listhead;
/*链表头节点-end*/

bool isCousins(struct node* root, int x, int y){
    listhead* head = (listhead*)malloc(sizeof(listhead));
    head->count = 1;
    listnode* firstnode = (listnode*)malloc(sizeof(listnode));
    firstnode->data = root;
    head->next = firstnode;
    int num = 0;
    int flag1 = 0;
    int flag2 = 0;
    while(head->count != 0){
        num = head->count;
        listnode* visinode = head->next;
        for(int i=0; i<num; i++){
            if(visinode->data->val == x){
                flag1 = 1;
            }
            if(visinode->data->val == y){
                flag2 = 1;
            }
            if(visinode->data->left){
                head->count++;
                listnode* newnode = (listnode*)malloc(sizeof(listnode));
                newnode->data = visinode->data->left;
                newnode->next = head->next;
                head->next = newnode;
            }
            if(visinode->data->right){
                head->count++;
                listnode* newnode = (listnode*)malloc(sizeof(listnode));
                newnode->data = visinode->data->right;
                newnode->next = head->next;
                head->next = newnode;
            }
            visinode = visinode->next;
            head->count--;
        }
        if(flag1==1 && flag2==1){
            return true;
        }
        else{
            flag1 = 0;
            flag2 = 0;
        }
    }
    return false;
}

int main(){
    int temp[] = {1,2,3,NULL,4};
    int length = sizeof(temp)/sizeof(temp[0]);
    struct node* root = createFromArray(temp,length);
    //Display(root,0);
    int res = isCousins(root, 2, 3);
    printf("result: %d",res);
    return 1;
}