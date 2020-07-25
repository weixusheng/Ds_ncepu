#include<stdio.h>
#include<stdlib.h>

/*
int main(){
	int ad1,sum,move;
	scanf("%d %d %d", &ad1, &sum, &move);
	int hash[100000];
	int hash2[10000];
	int next[100000];
	int temp_ad,temp_id,temp_next;
	for(int i=0; i<sum; i++){	//input
		scanf("%d %d %d", &temp_ad, &temp_id, &temp_next);
		hash[temp_ad] = temp_id; //construct hash ad->id
		hash2[temp_id] = temp_ad;
		next[temp_id] = temp_next;
	}
	int list[100000] = {0};
	int cur = hash[ad1];
	list[0] = cur;
	for(int k=1; k<sum; k++){	//construct init_list
		list[k] = hash[next[cur]];
		cur = list[k];
	}
	int len = sum;
	int start = 0;
	int count;
	int temp_data;
	count = move/2;
	while(len > move){
		count = (move/2);
		for(int j=0; j<count; j++){
			temp_data = list[start+j];
			list[start+j] = list[start+move-1-j];
			list[start+move-1-j] = temp_data;
		}
		start = start+move;
		len = len-move;
	}
	//printf("start\n");
	for(int w=0; w<sum; w++){
		if(w!= sum-1)
			printf("%05d %d %05d\n", hash2[list[w]], list[w], hash2[list[w+1]]);
		else{
			printf("%05d %d -1", hash2[list[w]], list[w]);
		}
	}
	//fflush(stdin); 
    //printf("<------------outputend"); 
    //getchar();
	return 0;
}
*/

#define SWAPNODE(A, B) {Node temp = A; A = B; B = temp;}

typedef struct node{
    int addr;
    int data;
    int next;
}node, *Node;

int main()
{
    int A, N, K;
    node nodes[100000] = {0};
    Node np[100000] = {0}, *p;

    /* read */
    scanf("%d %d %d", &A, &N, &K);
    for(int i = 0; i < N; i++)
    {
        np[i] = nodes + i;
        scanf("%d %d %d", &np[i]->addr, &np[i]->data, &np[i]->next);
    }

    /* link the list */
    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
            if(np[j]->addr == (i ? np[i - 1]->next : A))
            {
                SWAPNODE(np[i], np[j]);
                break;
            }
        if(np[i]->next == -1)   /* there could be useless nodes */
            N = i + 1;
    }

    /* reverse the list */
    for(int i = 0; i < N / K; i++)
    {
        p = np + i * K;
        for(int j = 0; j < K / 2; j++)
            SWAPNODE(p[j], p[K - j - 1]);
    }

    /* print the list */
    for(int i = 0; i < N - 1; i++)
        printf("%05d %d %05d\n", np[i]->addr, np[i]->data, np[i + 1]->addr);
    printf("%05d %d -1\n", np[N - 1]->addr, np[N - 1]->data);

    return 0;
}






