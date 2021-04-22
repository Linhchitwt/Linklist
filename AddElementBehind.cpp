#include <stdio.h>
#include <stdlib.h>
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
        l.pTail->pNext = p; //con trỏ của phần tử đầu = p
        l.pTail = p; // phần tử đầu = p
    }
}
void input(float &x){
    printf("Nhap vao phan tu q = ");
    scanf("%f", &x);
}
void AddElementBehind(LIST &l, NODE *p){
    float x,h;
    input(x);
    NODE *q = pDeclare(x);
        if (q->data == l.pHead->data && l.pHead->pNext== NULL){
            AddLast(l,p);
            //nếu chỉ có 1 phần tử duy nhất và phần tử đó đúng = q thì sử dụng hàm thêm vào sau
        }
        else{
            // nếu không thì :
            // chạy hết vòng lặp
         for (NODE *k= l.pHead; k!= NULL; k = k->pNext){
             // giá trị trong k = trong q đã nhập
             if (q->data == k->data){
            // khởi tạo 1 con trỏ g là phần liên kết sau quả q (k)
        NODE *g = k->pNext;
        // khởi tạo 1 con trỏ h là phần liên kết trước của p
        NODE *h = pDeclare(p->data);
        h->pNext = g; // con trỏ h sẽ liên kết với g (g là phần tử sau q)
        k->pNext = h; // con trỏ k sẽ liên kết với h
             }
        }
    }
}
void OutPut(LIST &l){
    printf("Danh sach la : \n");
    for (NODE *k = l.pHead; k != NULL ; k = k ->pNext){
        printf ("%.1f ", k->data);
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
int main(){
    LIST l;
    float q,n,h;
    DSLK(l);
    OutPut(l);
     printf ("\nNhap p = "); 
    scanf ("%f", &h);
      NODE *p = pDeclare(h);
    AddElementBehind(l,p);
    OutPut(l);
    return 0;
}
