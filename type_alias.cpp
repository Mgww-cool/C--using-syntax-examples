#include <iostream>
#include <vector>
#include <string>

// 1. 基本类型别名
using Int = int;
using String = std::string;
using Double = double;

// 2. 复杂类型别名
using IntVector = std::vector<int>;
using StringVector = std::vector<std::string>;
using Matrix = std::vector<std::vector<double>>;

// 3. 函数指针别名
using CompareFunc = bool(*)(int, int);
using MathFunc = double(*)(double, double);

// 4. 模板类型别名（C++11）
template<typename T>
using Vector = std::vector<T>;

template<typename T>
using SharedPtr = std::shared_ptr<T>;

// 示例函数
bool ascending(int a, int b)
{
    return a < b;
}

double add(double a, double b)
{
    return a + b;
}

int main()
{
    // 使用基本类型别名
    Int num = 42;
    String name = "C++ using";
    Double value = 3.14;
    
    std::cout << "基本类型别名示例:" << std::endl;
    std::cout << "Int num = " << num << std::endl;
    std::cout << "String name = " << name << std::endl;
    std::cout << "Double value = " << value << std::endl;
    
    // 使用复杂类型别名
    IntVector numbers = {1, 2, 3, 4, 5};
    StringVector words = {"Hello", "World", "C++"};
    Matrix matrix = {{1.0, 2.0}, {3.0, 4.0}};
    
    std::cout << "\n复杂类型别名示例:" << std::endl;
    std::cout << "IntVector: ";
    for (const auto& n : numbers)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    std::cout << "StringVector: ";
    for (const auto& s : words)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    
    // 使用函数指针别名
    CompareFunc comp = ascending;
    MathFunc mathOp = add;
    
    std::cout << "\n函数指针别名示例:" << std::endl;
    std::cout << "ascending(3, 5) = " << comp(3, 5) << std::endl;
    std::cout << "add(2.5, 3.5) = " << mathOp(2.5, 3.5) << std::endl;
    
    // 使用模板类型别名
    Vector<int> templateVec = {10, 20, 30};
    Vector<std::string> templateStrVec = {"Template", "Alias", "Example"};
    
    std::cout << "\n模板类型别名示例:" << std::endl;
    std::cout << "Vector<int>: ";
    for (const auto& n : templateVec)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Vector<std::string>: ";
    for (const auto& s : templateStrVec)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    
    return 0;
}