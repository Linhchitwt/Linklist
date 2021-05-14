#include <iostream>
#include <queue>
#include <string>
#define max 100
using namespace std;
int main() {
    int n;
    queue <int> qu;
    int arr[max];
    int k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    bool Check ; 
    qu.push(arr[0]);
    for (int i = 1; i < n; i++) {
        Check = true;
        for (int j = 0; j < i; j++) {
            // xét tất cả các trường hợp xem có bị lặp lại k
            if (arr[i] == arr[j] && i != j) {
                Check = false;
                break;
            }
        }
        // khi break ra tới đây, bool Check để bỏ phần tử arr đã lặp đi
        if (qu.size() < k && Check == true) {
            qu.push(arr[i]);
            // nhỏ hơn k và phần tử arr k bị lặp thì push
        }
        else {
            // ngược lại thì...(yêu cầu đề bài)
            if (Check == true) {
                qu.pop();
                qu.push(arr[i]);
            }
        }
    }
    while(!qu.empty()){
        cout << qu.front() << " ";
        qu.pop();
    }
}