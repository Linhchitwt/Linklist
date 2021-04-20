#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data; // du lieu
    struct node *pNext ; //con tro
};
typedef struct node NODE;
struct list
{
    NODE *pHead; //node dau ds
    NODE *pTail; //node cuoi danh sach
};
typedef struct list LIST;
void khoitao(LIST &l){
    l.pHead = NULL;
    l.pTail = NULL;
}
NODE *ktNODE (int x){
    NODE *p = new NODE;
    if ( p == NULL){
        printf("Het bo nho\n");
        return NULL;
    }
    p -> data = x;
    p -> pNext = NULL;
    return p;   
}
void addfist(LIST &l, NODE *p){
    if (l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void addlast(LIST &l, NODE *p){
    if (l.pHead = NULL){
        l.pHead = l.pTail = p;
    }
    else 
    {
       l.pTail->pNext = p ;
        l.pTail = p;
    }
}
void output(LIST l){
    for (NODE *k = l.pHead; k != NULL ; k = k ->pNext){
        printf ("%d ", k->data);
    }
}
int max(LIST l){
    int max;
    max = l.pHead->data;
    for (NODE *k = l.pHead; k != NULL ; k = k ->pNext){
        if (k->data > max){
            max = k->data;
        }
    }
    return max;
}
int main (){
    LIST l;
    khoitao(l);
    int n; 
    printf("n = ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        printf("Nhap vao so nguyen :");
        scanf("%d", &x);  
    NODE *p = ktNODE(x);
    addfist(l,p);}
    printf("DSLK : ");
    output(l);
    printf("\nMAX = %d", max(l));
}