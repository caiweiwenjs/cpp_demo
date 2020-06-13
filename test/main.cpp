#include <iostream>
#include <string>

int main() {
    std::string str;
    int ss[256] = {0};
    while (std::cin >> str) {
        auto l = str.length();
        for (auto i = l - 1;i >= 0;i--) {
            if (ss[str[i] - '0'] == 0) {
                std::cout << str[i];
                ss[str[i] - '0'] = 1;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
