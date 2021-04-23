#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    float data;
    struct node *pNext;
};
typedef struct node NODE;
struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;
void Init(LIST &l){
    l.pHead= NULL;
    l.pTail = NULL;
}
NODE *pDeclare(float x){
    NODE *p = new NODE;
    if (p == NULL)
    {
        printf("Het bo nho");
        return NULL;
    }
    p->data= x;
    p->pNext = NULL;
    return p;
}
void AddLast(LIST &l, NODE *p){
    if (l.pHead == NULL){
        l.pHead = l.pTail = p ;   }
    else {
        l.pTail->pNext = p; //con trỏ của phần tử cuối = p
        l.pTail = p; // phần tử cuối = p
    }
}
void DSLK(LIST &l){
    int n;
     printf ("Nhap n = "); 
    scanf ("%d", &n);
    Init(l);
    for (int i = 0; i < n ; i++){
        float x;
        printf("Nhap vao so thu %d = ", i+1);
        scanf("%f", &x);
        NODE *p = pDeclare(x); // khởi tạo 1 con trỏ p 
        AddLast(l,p); // thêm các phần tử đã nhập trở thành 1 danh sách liên kết
    }
}
void AddFirst(LIST &l, NODE *p){
    if (l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else {
        p->pNext = l.pHead; // con trỏ của p lk với phần tử đầu
        l.pHead = p; // phần tử đầu = p
    }
}
int input(float &x){
    printf("Nhap vao phan tu q = ");
    scanf("%f", &x);
    return x;
}
void OutPut(LIST &l){
    printf("Danh sach la : ");
    for (NODE *k = l.pHead; k != NULL ; k = k ->pNext){
        printf ("%.1f ", k->data);
    }
}
/* void Inputp(){
    float b;
    printf("\nNhap vao p = ");
    scanf("%f", &b);
    NODE *p = pDeclare(b);
} */
void Addfirst1(LIST &l, NODE *p, float &x, NODE *q){
    if (l.pHead->data == q->data){
        AddFirst(l,p);
    }
}
void AddElementFront(LIST &l, NODE *p){
    float x;
    x = input(x);
    NODE *q = pDeclare(x);
    NODE *g = new NODE;
  /*   if (q->data == l.pHead->data && l.pHead->pNext== NULL ){
        AddFirst(l,p);
    }
    else { */
        for (NODE *k = l.pHead; k != NULL ; k = k ->pNext){
            if (k->data == q->data){
           /*  NODE *m = pDeclare((k-1)->data) ;              
            NODE *g = m->pNext; */
            NODE *h = pDeclare(p->data);
        h->pNext = k;
        g->pNext = h;
            }
        g = k;
        }
        Addfirst1(l,p,x,q);
   // }
}
int main(){
    LIST l;
    float x;
    DSLK(l);
    OutPut(l);
    float b;
    printf("\nNhap vao p = ");
    scanf("%f", &b);
    NODE *p = pDeclare(b);
    AddElementFront(l,p);
    OutPut(l);
    return 0;
}
