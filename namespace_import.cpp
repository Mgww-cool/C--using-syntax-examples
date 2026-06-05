#include <iostream>
#include <vector>
#include <string>

// 自定义命名空间
namespace Math
{
    const double PI = 3.14159265358979323846;
    
    double square(double x)
    {
        return x * x;
    }
    
    double cube(double x)
    {
        return x * x * x;
    }
}

namespace Graphics
{
    struct Point
    {
        double x;
        double y;
        
        Point(double x = 0, double y = 0) : x(x), y(y) {}
    };
    
    void printPoint(const Point& p)
    {
        std::cout << "(" << p.x << ", " << p.y << ")";
    }
}

// 1. using声明 - 引入单个名称
using Math::PI;
using Math::square;
using Graphics::Point;
using Graphics::printPoint;

// 2. using指令 - 引入整个命名空间
using namespace std;

int main()
{
    // 使用using声明引入的名称
    cout << "使用using声明引入的名称:" << endl;
    cout << "PI = " << PI << endl;
    cout << "square(5) = " << square(5) << endl;
    
    // 使用using声明引入的自定义类型
    Point p1(3.0, 4.0);
    cout << "Point p1 = ";
    printPoint(p1);
    cout << endl;
    
    // 使用using指令引入的命名空间
    cout << "\n使用using指令引入的命名空间:" << endl;
    
    // 直接使用cout、endl等，无需std::前缀
    vector<int> numbers = {1, 2, 3, 4, 5};
    string message = "Hello, World!";
    
    cout << "vector: ";
    for (const auto& n : numbers)
    {
        cout << n << " ";
    }
    cout << endl;
    
    cout << "string: " << message << endl;
    
    // 3. 在函数内部使用using声明
    cout << "\n在函数内部使用using声明:" << endl;
    using Math::cube;
    cout << "cube(3) = " << cube(3) << endl;
    
    // 4. 在代码块中使用using指令
    {
        using namespace Graphics;
        Point p2(5.0, 6.0);
        cout << "在代码块中创建的点: ";
        printPoint(p2);
        cout << endl;
    }
    
    return 0;
}