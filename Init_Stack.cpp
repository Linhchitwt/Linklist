#include <iostream>
#include <conio.h>
using namespace std;
struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;
struct stack
{
    NODE *pTop;
};
typedef struct stack STACK;
void Init(STACK &s){
    s.pTop = NULL; 
}
NODE *pDeclare(int x){
    NODE *p = new NODE;
    if (p == NULL){
        cout <<"Khong du bo nho de cap phat";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}
bool IsEmpty(STACK &s){
    if (s.pTop == NULL){
        return true; // danh sach rong
    }
    return false;
}
bool PushStack(STACK &s, int &x){
        NODE *p = pDeclare(x);
      //them 1 phan tu vao dau stack
      if (p == NULL){
          return false;
      }
    if(IsEmpty(s) == true ){
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
    return true;
}

bool PopStack(STACK &s, int &x){
    // lay ra phan tu dau (lay ra va huy)
    if (IsEmpty(s) == true){
        return false;
    }
    else{
        NODE *p = s.pTop;
        x = p->data;
        s.pTop = s.pTop->pNext;
        delete(p);
        return true;
    }
}
bool TopStack(STACK &s, int &x){
    //xem phan tu dau tien
    if (IsEmpty(s)== true){
        return false;
    }
    else{
        x = s.pTop->data;
    return true;
    }
}
void Output(STACK s,int &x ){
    while (IsEmpty(s)== false)
    {
        PopStack(s,x);
        cout<<x<<" ";
    }  
}
void menu(STACK &s, int &x, NODE *p){
    int choose;
    while (true)
    {
        system("cls");
    cout <<"..........................MENU..........................\n";
    cout <<" ====> 1. Them phan tu \n";
    cout <<" ====> 2. Xuat phan tu ra man hinh\n";
    cout <<" ====> 3. Xem phan tu dau stack\n";
    cout <<" ====> 0. Ket thuc chuong trinh \n";
    cout <<"...........................END..........................\n";
    cout <<"Nhap lua chon cua ban : ";
    cin >> choose;
    switch (choose)
    {
    case 0 :{
        break;}
    case 1 :{
        cout <<"Nhap phan tu can them : ";
        cin >> x;
       PushStack(s,x);
        break;}
    case 2 :
   { cout <<"Danh sach la : ";
        Output(s,x);
        system("pause");
        break; }
    case 3 :
    {int y;
        cout<<"Phan tu dau danh sach la : ";
        TopStack(s,y);
        cout <<x<<"\n";
        system("pause");
        break;}
    default:{
        break;
        }
        }
    }
}
int main(){
    STACK s;
    int x;
    Init(s);
    NODE *p = new NODE;
    menu(s,x,p);
    system("pause");
    return 0;
}