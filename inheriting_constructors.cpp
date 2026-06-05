#include <iostream>
#include <string>
#include <vector>

// 1. 基本继承构造函数
class Base
{
public:
    int x;
    int y;
    
    Base() : x(0), y(0)
    {
        std::cout << "Base默认构造函数" << std::endl;
    }
    
    Base(int x) : x(x), y(0)
    {
        std::cout << "Base单参数构造函数: x=" << x << std::endl;
    }
    
    Base(int x, int y) : x(x), y(y)
    {
        std::cout << "Base双参数构造函数: x=" << x << ", y=" << y << std::endl;
    }
    
    Base(const Base& other) : x(other.x), y(other.y)
    {
        std::cout << "Base拷贝构造函数" << std::endl;
    }
    
    virtual ~Base() = default;
    
    virtual void print() const
    {
        std::cout << "Base: x=" << x << ", y=" << y << std::endl;
    }
};

// 2. 继承构造函数
class Derived : public Base
{
public:
    // 使用using声明继承所有构造函数
    using Base::Base;
    
    // 可以添加新的成员
    std::string name;
    
    // 可以重写虚函数
    void print() const override
    {
        std::cout << "Derived: x=" << x << ", y=" << y;
        if (!name.empty())
        {
            std::cout << ", name=" << name;
        }
        std::cout << std::endl;
    }
};

// 3. 多级继承
class GrandChild : public Derived
{
public:
    // 继承Derived的构造函数（包括从Base继承的）
    using Derived::Derived;
    
    int z;
    
    // 添加新的构造函数
    GrandChild(int x, int y, int z) : Derived(x, y), z(z)
    {
        std::cout << "GrandChild三参数构造函数: x=" << x << ", y=" << y << ", z=" << z << std::endl;
    }
    
    void print() const override
    {
        std::cout << "GrandChild: x=" << x << ", y=" << y << ", z=" << z << std::endl;
    }
};

// 4. 模板类继承构造函数
template<typename T>
class Container
{
protected:
    std::vector<T> data;
    
public:
    Container() = default;
    
    Container(size_t n, const T& value = T()) : data(n, value)
    {
        std::cout << "Container构造函数: size=" << n << std::endl;
    }
    
    Container(std::initializer_list<T> init) : data(init)
    {
        std::cout << "Container初始化列表构造函数" << std::endl;
    }
    
    virtual ~Container() = default;
    
    void print() const
    {
        std::cout << "Container: ";
        for (const auto& elem : data)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

template<typename T>
class SpecialContainer : public Container<T>
{
public:
    // 继承基类的构造函数
    using Container<T>::Container;
    
    // 添加新的构造函数
    SpecialContainer(const std::string& name, size_t n, const T& value = T())
        : Container<T>(n, value), name(name)
    {
        std::cout << "SpecialContainer构造函数: name=" << name << std::endl;
    }
    
    void print() const
    {
        if (!name.empty())
        {
            std::cout << name << ": ";
        }
        Container<T>::print();
    }
    
private:
    std::string name;
};

// 5. 继承构造函数与默认参数
class WithDefaults
{
public:
    int value;
    std::string text;
    
    WithDefaults(int v = 0, const std::string& t = "default") : value(v), text(t)
    {
        std::cout << "WithDefaults构造函数: value=" << value << ", text=" << text << std::endl;
    }
};

class InheritsDefaults : public WithDefaults
{
public:
    using WithDefaults::WithDefaults;
    
    void print() const
    {
        std::cout << "InheritsDefaults: value=" << value << ", text=" << text << std::endl;
    }
};

// 6. 继承构造函数与成员初始化
class WithMembers
{
public:
    int x;
    int y;
    std::string name;
    
    WithMembers(int x, int y, const std::string& name) : x(x), y(y), name(name)
    {
        std::cout << "WithMembers构造函数" << std::endl;
    }
};

class InheritsMembers : public WithMembers
{
public:
    int z;  // 新成员
    
    // 注意：继承构造函数不会初始化新成员
    using WithMembers::WithMembers;
    
    // 需要添加新的构造函数来初始化新成员
    InheritsMembers(int x, int y, const std::string& name, int z)
        : WithMembers(x, y, name), z(z)
    {
        std::cout << "InheritsMembers完整构造函数" << std::endl;
    }
    
    void print() const
    {
        std::cout << "InheritsMembers: x=" << x << ", y=" << y 
                  << ", name=" << name << ", z=" << z << std::endl;
    }
};

int main()
{
    std::cout << "=== 继承构造函数示例 ===" << std::endl;
    
    // 1. 基本继承构造函数
    {
        std::cout << "\n1. 基本继承构造函数:" << std::endl;
        
        Base base1;
        Base base2(10);
        Base base3(10, 20);
        
        Derived derived1;
        Derived derived2(30);
        Derived derived3(30, 40);
        
        derived1.print();
        derived2.print();
        derived3.print();
    }
    
    // 2. 多级继承
    {
        std::cout << "\n2. 多级继承:" << std::endl;
        
        GrandChild gc1;
        GrandChild gc2(1, 2);
        GrandChild gc3(1, 2, 3);
        
        gc1.print();
        gc2.print();
        gc3.print();
    }
    
    // 3. 模板类继承构造函数
    {
        std::cout << "\n3. 模板类继承构造函数:" << std::endl;
        
        Container<int> container1;
        Container<int> container2(5, 42);
        Container<int> container3{1, 2, 3, 4, 5};
        
        SpecialContainer<int> special1;
        SpecialContainer<int> special2(3, 100);
        SpecialContainer<int> special3{10, 20, 30};
        SpecialContainer<int> special4("MyContainer", 4, 7);
        
        container1.print();
        container2.print();
        container3.print();
        
        special1.print();
        special2.print();
        special3.print();
        special4.print();
    }
    
    // 4. 默认参数
    {
        std::cout << "\n4. 默认参数:" << std::endl;
        
        WithDefaults wd1;
        WithDefaults wd2(42);
        WithDefaults wd3(42, "custom");
        
        InheritsDefaults id1;
        InheritsDefaults id2(100);
        InheritsDefaults id3(100, "inherited");
        
        id1.print();
        id2.print();
        id3.print();
    }
    
    // 5. 成员初始化
    {
        std::cout << "\n5. 成员初始化:" << std::endl;
        
        // 注意：使用继承构造函数时，新成员z未初始化
        InheritsMembers im1(1, 2, "test");
        im1.print();  // z的值是未定义的
        
        // 使用完整构造函数
        InheritsMembers im2(1, 2, "test", 3);
        im2.print();
    }
    
    std::cout << "\n=== 继承构造函数注意事项 ===" << std::endl;
    std::cout << "1. 继承构造函数不会初始化派生类的新成员" << std::endl;
    std::cout << "2. 继承构造函数不会继承默认参数" << std::endl;
    std::cout << "3. 继承构造函数可以与派生类自己的构造函数共存" << std::endl;
    std::cout << "4. 继承构造函数不会继承拷贝/移动构造函数" << std::endl;
    std::cout << "5. 使用using声明可以继承多个构造函数" << std::endl;
    
    return 0;
}