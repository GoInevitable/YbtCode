#include <iostream>
#include <string>
using namespace std;
int main() {
    string n;
    int s;
    cin >> n >> s;
    for (int i = 0; i < s; ++i) {
        int j;
        for (j = 0; j < n.size() - 1; ++j) {
            if (n[j] > n[j + 1]) {
                break;
            }
        }
        n.erase(j, 1);
    }
    int head = 0;
    while (head < n.size() && n[head] == '0') {
        ++head;
    }
    if(n.size()==0){
        cout<<0;
        return 0;
    }
    for(int i=head;i<=n.size();i++){
        cout<<n[i];
    }
    return 0;
}