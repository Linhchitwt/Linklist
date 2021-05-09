// hoạt động theo cơ chế fifo : first in first out ( vào trước thì ra trước)
#include <iostream>
#include <conio.h>
using namespace std;
struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;
struct queue
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct queue QUEUE;
void InitQueue(QUEUE &q){
    q.pHead = NULL;
    q.pTail = NULL;
}
NODE *pDeclare(int &x){
    NODE *p = new NODE;
    if (p == NULL){
        cout <<"Khong du bo nho de cap phat";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}
bool IsEmpty(QUEUE q){
    // kiem tra xem ds co rong k?
    if (q.pHead == NULL){
        return true;
    }
    return false;
}
bool PushQueue(QUEUE &q, int &x,NODE *p){
    //thêm vào ở cuối danh sách
    p = pDeclare(x);
    if(p == NULL){
        return false;
    }
    if (IsEmpty(q) == true){
        q.pHead= q.pTail = p;
        return true;
    }
    else{
        q.pTail->pNext = p;
        q.pTail = p;
        }
        return true;
}
bool PopQueue(QUEUE &q, int &y){
    // Lấy ra ở đầu và xóa đi
    if (IsEmpty(q) == true){
        return false;
    }
    else{
       NODE *p = q.pHead;
        y = p->data;
        q.pHead = q.pHead->pNext;
        delete(p);
        }
     return true;
}
bool TopQueue(QUEUE &q, int &k){
    if (IsEmpty(q) == true){
        return false;
    }
        k = q.pHead->data;
        return true;
}
void Output(QUEUE q, int &y){
    cout <<"Danh sach la : ";
    while (IsEmpty(q) == false)
    {
        PopQueue(q,y);
        cout <<y<<" ";
    }  
}
void Menu(QUEUE &q, NODE *p){
     int choose;
    while (true)
    {
        system("cls");
    cout <<"..........................MENU..........................\n";
    cout <<" ====> 1. Them phan tu vao Queue \n";
    cout <<" ====> 2. Xuat phan tu ra man hinh\n";
    cout <<" ====> 3. Xem phan tu dau Queue\n";
    cout <<" ====> 0. Ket thuc chuong trinh \n";
    cout <<"...........................END..........................\n";
    cout <<"Nhap lua chon cua ban : ";
    cin >> choose;
    switch (choose)
    {
        case 0 :{
            break;
        }
        case 1 :
        {
            int x;
            cout <<"Nhap vao phan tu can them : ";
            cin >> x;
            PushQueue(q,x,p);
            break;
        }
        case 2 :
        {
            int y;
            Output(q,y);
            cout <<endl;
            system("pause");
            break;
        }
        case 3 :
        {
            int k;
            cout <<"Phan tu dau danh sach la : ";
            TopQueue(q,k);
            cout <<k<<"\n";
            system("pause");
            break;
        }
        default :
        {
            break;
        }
    }
}
}
int main(){
    QUEUE q;
    InitQueue(q);
    NODE *p = new NODE;
    Menu(q,p);
    system("pause");
    return 0;
}
