#include <iostream>
#include <vector>
#include <string>

// 1. 类型别名
using Int = int;
using String = std::string;
using IntVector = std::vector<int>;

// 2. 模板别名
template<typename T>
using Vec = std::vector<T>;

// 3. 命名空间引入
using std::cout;
using std::endl;

int main()
{
    // 使用类型别名
    Int num = 42;
    String name = "C++ using";
    IntVector numbers = {1, 2, 3, 4, 5};
    
    // 使用模板别名
    Vec<double> doubles = {1.1, 2.2, 3.3};
    
    // 使用引入的命名空间成员
    cout << "基本用法示例:" << endl;
    cout << "Int num = " << num << endl;
    cout << "String name = " << name << endl;
    
    cout << "IntVector: ";
    for (const auto& n : numbers)
    {
        cout << n << " ";
    }
    cout << endl;
    
    cout << "Vec<double>: ";
    for (const auto& d : doubles)
    {
        cout << d << " ";
    }
    cout << endl;
    
    return 0;
}