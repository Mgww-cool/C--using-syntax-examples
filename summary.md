# C++ using 语法总结

## 1. 类型别名 (Type Alias)

### 基本语法
```cpp
using 新类型名 = 原类型名;
```

### 示例
```cpp
using Int = int;
using String = std::string;
using IntVector = std::vector<int>;
```

### 优势
- 提高代码可读性
- 简化复杂类型声明
- 便于类型重构

## 2. 模板别名 (Template Alias)

### 基本语法
```cpp
template<typename T>
using 别名 = 原模板类型<T>;
```

### 示例
```cpp
template<typename T>
using Vec = std::vector<T>;

template<typename T>
using SharedPtr = std::shared_ptr<T>;
```

### 优势
- 简化模板类型使用
- 支持模板元编程
- 比typedef更灵活

## 3. using声明 (Using Declaration)

### 基本语法
```cpp
using 命名空间::名称;
```

### 示例
```cpp
using std::cout;
using std::endl;
using std::vector;
```

### 特点
- 引入单个名称
- 精确控制命名空间
- 可以重载基类函数
- 可以改变访问权限

## 4. using指令 (Using Directive)

### 基本语法
```cpp
using namespace 命名空间;
```

### 示例
```cpp
using namespace std;
using namespace MyLibrary;
```

### 注意事项
- 引入整个命名空间的所有名称
- 可能导致命名冲突
- 不推荐在头文件中使用
- 建议在函数或代码块中限制作用域

## 5. 继承构造函数 (Inheriting Constructors)

### 基本语法
```cpp
class Derived : public Base
{
public:
    using Base::Base;
};
```

### 示例
```cpp
class Base
{
public:
    Base() {}
    Base(int x) {}
    Base(int x, int y) {}
};

class Derived : public Base
{
public:
    using Base::Base;  // 继承所有构造函数
};
```

### 注意事项
- 不会初始化派生类的新成员
- 不会继承默认参数
- 不会继承拷贝/移动构造函数

## 6. 最佳实践

### 推荐做法
1. **优先使用using声明**而非using指令
2. **避免在头文件中使用using指令**
3. **在函数或代码块中限制using指令的作用域**
4. **使用类型别名简化复杂类型**
5. **使用模板别名提高代码可读性**

### 不推荐做法
```cpp
// 不推荐：在全局作用域使用using指令
using namespace std;

// 推荐：使用using声明或完全限定名
using std::cout;
using std::endl;
// 或者
std::cout << "Hello" << std::endl;
```

## 7. 编译要求

所有示例都需要C++11或更高版本：
```bash
g++ -std=c++11 example.cpp -o example
```

## 8. 参考资料

- [C++ Reference - using declaration](https://en.cppreference.com/w/cpp/language/using_declaration)
- [C++ Reference - using directive](https://en.cppreference.com/w/cpp/language/using_directive)
- [C++ Reference - Type alias](https://en.cppreference.com/w/cpp/language/type_alias)