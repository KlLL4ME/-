#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    // Массив (гибкий)
    cout << "Массив:" << endl;
    vector<int> nums = {1, 2, 3};
    nums.push_back(4);
    for(int n : nums) cout << n << " ";
    cout << endl;
    
    // Стек
    cout << "\nСтек:" << endl;
    stack<string> s;
    s.push("первый");
    s.push("второй");
    cout << "Верхний: " << s.top() << endl;
    s.pop();
    cout << "Теперь верхний: " << s.top() << endl;
    
    return 0;
}
