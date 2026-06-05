#include <iostream>
#include <string>

// 命名空间示例
namespace MyLib
{
    class Logger
    {
    public:
        void log(const std::string& message)
        {
            std::cout << "[LOG] " << message << std::endl;
        }
        
        void error(const std::string& message)
        {
            std::cout << "[ERROR] " << message << std::endl;
        }
    };
    
    namespace Config
    {
        const int MAX_CONNECTIONS = 100;
        const std::string APP_NAME = "MyApp";
        
        void printConfig()
        {
            std::cout << "App: " << APP_NAME << std::endl;
            std::cout << "Max connections: " << MAX_CONNECTIONS << std::endl;
        }
    }
}

// 1. 类作用域中的using声明
class Base
{
public:
    int value;
    
    Base(int v = 0) : value(v) {}
    
    void show()
    {
        std::cout << "Base::show() - value: " << value << std::endl;
    }
    
    void display()
    {
        std::cout << "Base::display()" << std::endl;
    }
};

class Derived : public Base
{
public:
    // 使用using声明引入基类成员
    using Base::Base;  // 继承构造函数（C++11）
    using Base::value; // 引入基类成员变量
    
    // 隐藏基类的show函数，但保留display
    void show()
    {
        std::cout << "Derived::show() - value: " << value << std::endl;
    }
    
    // 使用using声明引入基类的display函数
    using Base::display;
};

// 2. 模板类中的using声明
template<typename T>
class Container
{
private:
    T data;
    
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    
    Container(const T& d) : data(d) {}
    
    reference get()
    {
        return data;
    }
    
    const_reference get() const
    {
        return data;
    }
};

int main()
{
    std::cout << "=== using声明示例 ===" << std::endl;
    
    // 1. 函数作用域中的using声明
    {
        using MyLib::Logger;
        using MyLib::Config::MAX_CONNECTIONS;
        using MyLib::Config::printConfig;
        
        Logger logger;
        logger.log("Application started");
        logger.error("Something went wrong");
        
        std::cout << "Max connections: " << MAX_CONNECTIONS << std::endl;
        printConfig();
    }
    
    std::cout << "\n=== 类作用域中的using声明 ===" << std::endl;
    
    // 2. 类作用域中的using声明
    {
        Base baseObj(10);
        baseObj.show();
        baseObj.display();
        
        Derived derivedObj(20);
        derivedObj.show();    // 调用Derived::show()
        derivedObj.display(); // 调用Base::display()（通过using声明）
        
        // 使用继承的构造函数
        Derived derivedObj2(30);
        derivedObj2.show();
    }
    
    std::cout << "\n=== 模板类中的using声明 ===" << std::endl;
    
    // 3. 模板类中的using声明
    {
        Container<int> intContainer(42);
        Container<std::string> strContainer("Hello");
        
        // 使用类型别名
        Container<int>::value_type intValue = intContainer.get();
        Container<std::string>::value_type strValue = strContainer.get();
        
        std::cout << "intContainer: " << intValue << std::endl;
        std::cout << "strContainer: " << strValue << std::endl;
        
        // 使用引用类型
        Container<int>::reference ref = intContainer.get();
        ref = 100;
        std::cout << "Modified intContainer: " << intContainer.get() << std::endl;
    }
    
    std::cout << "\n=== using声明的优势 ===" << std::endl;
    std::cout << "1. 精确控制引入的名称" << std::endl;
    std::cout << "2. 避免命名空间污染" << std::endl;
    std::cout << "3. 可以重载基类函数" << std::endl;
    std::cout << "4. 可以改变访问权限" << std::endl;
    
    return 0;
}