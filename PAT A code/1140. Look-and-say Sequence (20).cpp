#include <iostream>
#include <string>
std::string itos(int a){
    if(a == 0)
        return std::string("0");
    std::string ans,tmp;
    while(a){
        tmp = '0'+a%10;
        ans=tmp+ans;
        a/=10;
    }
    return ans;
}
std::string transfer(std::string a){
    if(a.empty()) return "";
    std::string ans;
    int left=0,right=0;
    while(left!=a.size()){
        right = left;
        while(right != a.size()&&a[right] == a[left]) right++;
        ans += a[left];
        ans += itos(right-left);
        left = right;
    }
    return ans;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    std::string D;
    std::cin >> D >> n;
    while(--n){
        D = transfer(D);
    }
        std::cout << D << "\n";
    return 0;
}