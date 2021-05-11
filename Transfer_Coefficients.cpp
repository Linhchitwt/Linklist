#include <iostream>
#include <conio.h>
#include <math.h>
#include <string.h>
#define max 100
using namespace std;
struct node
{
    int data;
    struct node* pNext;
};
typedef struct node NODE;
struct stack
{
    NODE* pTop;
};
typedef struct stack STACK;
void Init(STACK& s) {
    s.pTop = NULL;
}
NODE* pDeclare(int x) {
    NODE* p = new NODE;
    if (p == NULL) {
        cout << "Insufficient Memory!!!";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}
bool IsEmpty(STACK& s) {
    if (s.pTop == NULL) {
        return true; // danh sach rong
    }
    return false;
}
bool PushStack(STACK& s, int& x) {
    NODE* p = pDeclare(x);
    //them 1 phan tu vao dau stack
    if (p == NULL) {
        return false;
    }
    if (IsEmpty(s) == true) {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
    return true;
}

bool PopStack(STACK& s, int& x) {
    // lay ra phan tu dau (lay ra va huy)
    if (IsEmpty(s) == true) {
        return false;
    }
    else {
        NODE* p = s.pTop;
        x = p->data;
        s.pTop = s.pTop->pNext;
        delete(p);
        return true;
    }
}
bool TopStack(STACK& s, int& x) {
    //xem phan tu dau tien
    if (IsEmpty(s) == true) {
        return false;
    }
    else {
        x = s.pTop->data;
        return true;
    }
}
void Output(STACK s, int& x) {
    while (IsEmpty(s) == false)
    {
        PopStack(s, x);
        cout << x << " ";
    }
}
void Output_case4(STACK s, int& x) {
    while (IsEmpty(s) == false)
    {
        PopStack(s, x);
        if (x < 10) {
            cout << x;
        }
        if (x == 10) cout << 'A';
        if (x == 11) cout << 'B';
        if (x == 12) cout << 'C';
        if (x == 13) cout << 'D';
        if (x == 14) cout << 'E';
        if (x == 15) cout << 'F';
    }
}
void Input_system_number(int& n, int& k) {
    cout << "Enter the system need convert n = ";
    cin >> n;
    cout << "Enter the number need convert k = ";
    cin >> k;
}
void AnySystem_Decimal(STACK& s, int& k, int& n, int& count) {
    int m;
    count = 0;
    if (n == 0 || n == 1) {
        return;
    }
    cout << k << " is converted to : ";
    m = k % 10;
    PushStack(s, m);
    k = k / 10;
    while (k > 0) {
        m = k % 10;
        PushStack(s, m);
        k = k / 10;
        count++;
    }
}
void Hexadecimal_Decimal(STACK& s, char ch[], int &count, int &m) {
    cout << "The number = ";
    fflush(stdin);
    cin >> ch;
    count = strlen(ch);
    cout << ch << " is converted to : ";
    for (int i = 0; i < count; i++){
        if (ch[i] == 'A'){
            m = 10;
        }
        else if(ch[i] == 'B'){
            m = 11;
        } 
        else if(ch[i] == 'C'){
            m = 12;
        }
        else if(ch[i] == 'D'){
            m = 13;
        }
        else if(ch[i] == 'E'){
            m = 14;
        }
        else if(ch[i] == 'F'){
            m = 15;
        }
        else if (ch[i]>= 48 && ch[i]<= 57 ){
            m = int(ch[i])-48;
        }
      //  if (ch[i] != '/0'){
            PushStack(s, m);
      //  }
    }
}
int NumberOf_DecimalSystem(int& n, STACK& s, int& count) {
    int sum = 0;
    int x;
    while (IsEmpty(s) == false && count >= 0) {
        PopStack(s, x);
        sum += pow(n, count) * x;
        count--;
    }
    return sum;
}
 int Hex_NumberOf_DecimalSystem(int& n, STACK& s, int& count) {
    int sum = 0;
    int x,b = 0;
    while (IsEmpty(s) == false && b <= count) {
        PopStack(s, x);
        sum += pow(n, b) * x;
        b++;
    }
    return sum;
} 
void Decimal_AnySystem(STACK& s, int& k, int& n) {
    // chỉ áp dụng cho hệ từ 2,3,... ,10 và hệ 16;
    int m;
    if (n == 0 || n == 1) {
        return;
    }
    cout << k << " is converted to : ";
    while (k != 0) {
        m = k % n;
        PushStack(s, m);
        k = k / n;
    }
}
void menu(STACK& s, int& x, NODE* p) {
    int choose;
    while (true)
    {
        system("cls");
        cout << "..........................MENU..........................\n";
        cout << " ====> 1. Add Element\n";
        cout << " ====> 2. Display the list on screen\n";
        cout << " ====> 3. Display the element first of Stack\n";
        cout << " ====> 4. Transfer Decimal_system(10) become any_system(n)\n";
        cout << " ====> 5. Transfer Any_system(n <= 10) become decimal_system(10)\n";
        cout << " ====> 6. Transfer Hexadecimal(n = 16) become decimal_system(10)\n";
        cout << " ====> 0. End program\n";
        cout << "...........................END..........................\n";
        cout << "Input your choose : ";
        cin >> choose;
        switch (choose)
        {
        case 0: {
            exit(0); }
        case 1: {
            cout << "Data of Element : ";
            cin >> x;
            PushStack(s, x);
            break; }
        case 2:
        { cout << "List : ";
        Output(s, x);
        cout << endl;
        system("pause");
        break; }
        case 3:
        {int y;
        cout << "The first element of Stack : ";
        TopStack(s, y);
        cout << x << "\n";
        system("pause");
        break; }
        case 4:
            // chuyen doi he 10 sang cac he nhap vao
        {
            int n, k;
            Input_system_number(n, k);
            if (n <= 10 || n == 16) {
                Decimal_AnySystem(s, k, n);
                Output_case4(s, x);
                cout << endl;
                system("pause");
                break;
            }
            else {
                cout << "Error n !!!" << endl;
                system("pause");
                break;
            }
        }
        case 5:
            // chuyen tu he bat ki sang he 10 (he thap phan)
        {
            int n, k, m, count;
            Input_system_number(n, k);
            AnySystem_Decimal(s, k, n, count);
            cout << NumberOf_DecimalSystem(n, s, count) << endl;
            system("pause");
            break;
        }
        case 6:
        {
            char *ch = new char;
            int m, count;
            int n = 16;
            Hexadecimal_Decimal(s,ch,count,m);
            cout<<Hex_NumberOf_DecimalSystem(n,s, count);
            cout << endl;
            fflush(stdin);
            delete(ch);
            system("pause");
            break;
        }
        default: {
            break;
        }
        }
    }
}
int main() {
    STACK s;
    int x;
    Init(s);
    NODE* p = new NODE;
    menu(s, x, p);
    system("pause");
    return 0;
}