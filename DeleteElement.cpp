#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;
struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;
void Init(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
NODE *pDeclare(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        printf("Het bo nho de cap phat");
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}
void AddElementFirst(LIST &l, NODE *q)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = q;
    }
    else
    {
        q->pNext = l.pHead;
        l.pHead = q;
    }
}
void AddElementLast(LIST &l, NODE *q)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = q;
    }
    else
    {
        l.pTail->pNext = q;
        l.pTail = q;
    }
}
void DSLK(LIST &l, int &n)
{
    printf("Nhap n = ");
    scanf("%d", &n);
    Init(l);
    for (int i = 0; i < n; i++)
    {
        float x;
        printf("Nhap vao so thu %d = ", i + 1);
        scanf("%f", &x);
        NODE *p = pDeclare(x); // khởi tạo 1 con trỏ p
        AddElementLast(l, p);  // thêm các phần tử đã nhập trở thành 1 danh sách liên kết
    }
}
void Output(LIST &l)
{
    printf("Danh sach la : ");
    for (NODE *i = l.pHead; i != NULL; i = i->pNext)
    {
        printf("%d ", i->data);
    }
}
void DeleteElementFirst(LIST &l, NODE *p, int &n)
{
    if (n == 0)
    {
        printf("Khong co phan tu nao de xoa\n");
        return;
    }
    else
    {
        if (n == 1)
        {
            delete (l.pTail);
            l.pHead = l.pTail = p = NULL;
            printf("Da xoa het cac phan tu!\n");
            return;
        }
        else
        {
            NODE *q = l.pHead;
            l.pHead = l.pHead->pNext;
            delete (q);
        }
        Output(l);
    }
}
void DeleteElementLast(LIST &l, NODE *p, int &n)
{
    if (n == 0)
    {
        printf("Khong co phan tu nao de xoa!\n");
        return;
    }
    else if (n == 1)
    {
        delete (l.pTail);
        l.pHead = l.pTail = NULL;
        printf("Da xoa het cac phan tu!\n");
        return;
    }
    else
    {
        for (NODE *i = l.pHead; i != NULL; i = i->pNext)
        {
            if (i->pNext == l.pTail)
            {               
                delete (l.pTail);              
                i->pNext = NULL;
                i = l.pTail;
                break;                        
            }
        }
        Output(l);
    }
}
void Inputq(int &q)
{
    printf("Nhap vao phan tu q = ");
    scanf("%d", &q);
}
void DeleteBehindq(LIST &l, NODE *p, int n)
{
   if (n == 0){
       return;
   }
   else {
     int q ;
     Inputq(q);
        NODE *g = new NODE;
    for (NODE *i = l.pHead; i != NULL; i= i->pNext)
    {
        for (NODE *j = i->pNext  ; j != NULL; j = j->pNext)
        {      
        if (i->data == q ){
            NODE *h = j;
            i->pNext = j->pNext;
            delete(h);
            break;
        }
        g = i;
    }
    }
    Output(l);
   }
}
void InPut_k(int &k){
    printf("Nhap vao vi tri k can xoa : k = ");
    scanf("%d", &k);
}
void Input_m(int &m){
    printf("Nhap vao vi tri m can kiem tra : m = ");
    scanf("%d", &m);
}
void ValueIn_m(LIST &l, int &m, int &n){
    //kiem tra gia tri tai vi tri m
    Input_m(m);
    if (m <= 0 || m > n){
        printf("Khong co gia tri tai vi tri can kiem tra !");
        return;
    }
    else{
    int location = 0;
    NODE *g = new NODE;
    for(NODE *i = l.pHead ; i != NULL; i=i->pNext){
        location ++;
        if(location == m){
            printf("Gia tri la: %d", i->data);
            return;
        }
        }
    }
}
void ReleaseMemory(LIST &l){
    // giai phong bo nho cho cac con tro
    for (NODE *i = l.pHead; i != NULL; i= i->pNext)
    {
        i = l.pHead;
        l.pHead = l.pHead->pNext;
        delete(i);
    }  
}
void DeleteElement_k(LIST &l, NODE *p, int &n, int &k){
    // xóa 1 phần tử tại vị trí k
    if(n == 0){
        printf("Khong co phan tu nao de xoa!!");
        return;
    }
    InPut_k(k);
    if (k == 1){
        DeleteElementFirst(l,p,n);
        return;
    }
    else if (k == n){
        DeleteElementLast(l,p,n);
        return;
    }
    else if (k <= 0 || k > n){
        printf("Nhap sai vi tri, hay kiem tra lai!");
        return;
    }
    else{
     int  location = 0; 
   for (NODE *i = l.pHead; i != NULL; i = i->pNext)
    {
        location++;
        NODE *g = new NODE; //node g để giữ mối liên kết trước node có vị trí k
        if (location == k-1){ // tại vị trí = k-1 thì 
            i->pNext = i->pNext->pNext; // cho node thứ k-1 liên kết với node thứ k+1
            delete(g); // xóa g (lúc này node g đang ở vị trí k)
            break; // dừng và thoát
        }
    g = i; // nếu location chưa = k thì cứ cho g tiếp tục chạy
     }
    Output(l);
}
}
void ChangeValue(LIST &l){
    // thay đổi các giá trị b thành giá trị c
    if (l.pHead == NULL){
        printf("Khong co gia tri nao de thay doi!!");
        return;
    }
    else {
    int b,c;
    printf("Nhap vao gia tri can thay doi: b = ");
    scanf("%d", &b);
    printf("Thay doi thanh gia tri c = ");
    scanf("%d", &c);
    for (NODE *i = l.pHead; i != NULL ; i = i->pNext)
    {
       if(i->data == b){
           i->data = c;
       }
    }
    Output(l);
    }
}
int main()
{
    LIST l;
    int n,q,k,m;
    NODE *p = new NODE;
    DSLK(l, n);
    //Output(l);
    //DeleteElementFirst(l,p,n);
    //DeleteElementLast(l, p, n);
    //DeleteBehindq(l,p,n);
    DeleteElement_k(l,p,n,k);
    //ValueIn_m(l,m,n);
    //ChangeValue(l);
    //ReleaseMemory(l);
    return 0;
}