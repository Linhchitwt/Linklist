#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;
// tạo node đầu và cuối
struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;
void Init(LIST &l){
    l.pHead = NULL;
    l.pTail = NULL;
}
// dùng để tạo 1 node bất kì
NODE *pDeclare(int x){
    NODE *p = new NODE;
    if (p == NULL){
        printf("Het bo nho de cap phat");
        return NULL;
    }
        p->data = x;
        p->pNext = NULL;
        return p;
}
// thêm 1 phần tử vào đầu danh sách
void AddElementFirst(LIST &l,NODE *q){
    if (l.pHead == NULL){
        l.pHead = l.pTail = q;
    }
    else {
        q->pNext = l.pHead; 
        l.pHead = q;
    }
}
// thêm 1 phần tử vào cuối danh sách
void AddElementLast(LIST &l, NODE *q){
    if (l.pHead == NULL){
        l.pHead = l.pTail = q;
    }
    else {
        l.pTail->pNext= q;
        l.pTail = q;
    }
}
int Input(int k){
    printf("Nhap vao vi tri k can them = ");
    scanf ("%d", &k);
    return k;

}
void Output(LIST &l){
    printf("Danh sach la : ");
    for (NODE *i = l.pHead; i != NULL; i= i->pNext){
        printf("%d ", i->data);
    }
}

void DSLK(LIST &l, int &n){
    int x;
    printf("Nhap vao so phan tu n = ");
    scanf("%d", &n);
    Init(l);
    for (int i = 0; i <n; i++){     
        printf ("Nhap vao phan tu thu %d = ",i+1);
        scanf("%d", &x);
        NODE *p = pDeclare(x); // mối x sẽ tạo ra 1 node p tương ứng
        AddElementLast(l,p); // thêm vào sau để tạo ra 1 danh sách lk
    }
}

void AddElement(LIST &l, NODE *p,NODE *q, int &n){
    int k, location;
    location = Input(k);
    // nếu danh sách rỗng và vị trí k = 1 hoặc danh sách khác rỗng mà vị trí là 1 thì thêm vào đầu
       if ((l.pHead == NULL && location == 1) || location == 1){
            AddElementFirst(l,q);
        }
    else if (location == n+1){     //th không thuộc trong khoảng số phần tử của danh sách
        // neu muon them p vao cuoi danh sach  
        AddElementLast(l,q);
    }
    else if (location >= 2 && location <= n){
        int m=0;
        NODE *g = new NODE; //tạo 1 node g mới để giữ các mối liên kết phía trước node có vị trí = k
       for ( NODE *i = l.pHead ; i!= NULL; i= i->pNext){
           m ++;
           // đếm m đến khi nào gặp vị trí thì dừng, thao tác thêm 1 phần tử phía trước phần tử có vị trí k
           if (m == location){
               NODE *h = pDeclare(q->data);
               h->pNext=i;
                g->pNext = h;
               // sau khi thêm thì dừng vòng lặp để tránh hiện tượng lặp thêm q vô hạn tại vị trí k
                break;
           }
           g = i;
       }
    }
    else {
        printf ("\n=> Khong the them vao danh sach \n");
    }
}
int main(){
    LIST l;
    int n;
    DSLK(l,n);
     int j;
    printf("Nhap vao gia tri q = ");
    scanf("%d", &j);
    NODE *p = new NODE;
    NODE *q = pDeclare(j);
    AddElement(l,p,q,n); 
    Output(l);
   return 0;
}
