#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <string>

// 1. 基本模板别名
template<typename T>
using Vec = std::vector<T>;

template<typename K, typename V>
using Map = std::map<K, V>;

template<typename T>
using SharedPtr = std::shared_ptr<T>;

template<typename T>
using UniquePtr = std::unique_ptr<T>;

// 2. 带默认参数的模板别名
template<typename T, typename Allocator = std::allocator<T>>
using Vector = std::vector<T, Allocator>;

template<typename T>
using SharedVector = SharedPtr<Vec<T>>;

// 3. 模板别名用于简化复杂类型
template<typename Key, typename Value>
using MultiMap = std::multimap<Key, Value>;

template<typename T>
using StringMap = Map<std::string, T>;

template<typename T>
using IntMap = Map<int, T>;

// 4. 模板别名用于类型萃取
template<typename T>
using RemoveConst = std::remove_const_t<T>;

template<typename T>
using RemoveReference = std::remove_reference_t<T>;

template<typename T>
using Decay = std::decay_t<T>;

// 5. 模板别名用于函数类型
template<typename ReturnType, typename... Args>
using Function = ReturnType(*)(Args...);

template<typename T>
using Comparator = bool(*)(const T&, const T&);

// 6. 模板别名用于嵌套类型
template<typename Container>
using ValueType = typename Container::value_type;

template<typename Container>
using Iterator = typename Container::iterator;

template<typename Container>
using ConstIterator = typename Container::const_iterator;

// 示例函数
template<typename T>
void printContainer(const T& container, const std::string& name = "")
{
    if (!name.empty())
    {
        std::cout << name << ": ";
    }
    
    for (const auto& elem : container)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// 使用模板别名的函数
template<typename T>
SharedPtr<Vec<T>> createSharedVector(std::initializer_list<T> init)
{
    return std::make_shared<Vec<T>>(init);
}

template<typename T>
void processMap(const StringMap<T>& map)
{
    for (const auto& pair : map)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main()
{
    std::cout << "=== 模板别名示例 ===" << std::endl;
    
    // 1. 基本模板别名
    {
        Vec<int> intVec = {1, 2, 3, 4, 5};
        Vec<std::string> strVec = {"Hello", "World", "C++"};
        
        Map<std::string, int> scores;
        scores["Alice"] = 95;
        scores["Bob"] = 87;
        scores["Charlie"] = 92;
        
        printContainer(intVec, "Vec<int>");
        printContainer(strVec, "Vec<string>");
        
        std::cout << "Map scores:" << std::endl;
        for (const auto& pair : scores)
        {
            std::cout << "  " << pair.first << ": " << pair.second << std::endl;
        }
    }
    
    std::cout << "\n=== 智能指针别名 ===" << std::endl;
    
    // 2. 智能指针别名
    {
        SharedPtr<int> sharedInt = std::make_shared<int>(42);
        UniquePtr<std::string> uniqueStr = std::make_unique<std::string>("Unique");
        
        std::cout << "SharedPtr<int>: " << *sharedInt << std::endl;
        std::cout << "UniquePtr<string>: " << *uniqueStr << std::endl;
        
        // 使用简化后的类型创建共享向量
        SharedVector<double> sharedVec = createSharedVector<double>({1.1, 2.2, 3.3});
        std::cout << "SharedVector<double>: ";
        for (const auto& val : *sharedVec)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "\n=== 复杂类型简化 ===" << std::endl;
    
    // 3. 复杂类型简化
    {
        StringMap<int> nameAge;
        nameAge["Alice"] = 25;
        nameAge["Bob"] = 30;
        nameAge["Charlie"] = 35;
        
        std::cout << "StringMap<int>:" << std::endl;
        processMap(nameAge);
        
        IntMap<std::string> idName;
        idName[1] = "First";
        idName[2] = "Second";
        idName[3] = "Third";
        
        std::cout << "IntMap<string>:" << std::endl;
        for (const auto& pair : idName)
        {
            std::cout << "  " << pair.first << ": " << pair.second << std::endl;
        }
    }
    
    std::cout << "\n=== 类型萃取别名 ===" << std::endl;
    
    // 4. 类型萃取别名
    {
        using ConstInt = const int;
        using NonConstInt = RemoveConst<ConstInt>;
        
        using LRefInt = int&;
        using RRefInt = int&&;
        using PlainInt1 = RemoveReference<LRefInt>;
        using PlainInt2 = RemoveReference<RRefInt>;
        
        using DecayedType = Decay<const int&>;
        
        std::cout << "RemoveConst<const int> is int: " 
                  << std::is_same_v<NonConstInt, int> << std::endl;
        std::cout << "RemoveReference<int&> is int: " 
                  << std::is_same_v<PlainInt1, int> << std::endl;
        std::cout << "RemoveReference<int&&> is int: " 
                  << std::is_same_v<PlainInt2, int> << std::endl;
        std::cout << "Decay<const int&> is int: " 
                  << std::is_same_v<DecayedType, int> << std::endl;
    }
    
    std::cout << "\n=== 函数类型别名 ===" << std::endl;
    
    // 5. 函数类型别名
    {
        // 函数指针别名
        Function<int, int, int> addFunc = [](int a, int b) { return a + b; };
        Function<double, double, double> mulFunc = [](double a, double b) { return a * b; };
        
        std::cout << "addFunc(3, 4) = " << addFunc(3, 4) << std::endl;
        std::cout << "mulFunc(2.5, 4.0) = " << mulFunc(2.5, 4.0) << std::endl;
        
        // 比较器别名
        Comparator<int> intComp = [](const int& a, const int& b) { return a < b; };
        std::cout << "intComp(3, 5) = " << intComp(3, 5) << std::endl;
        std::cout << "intComp(5, 3) = " << intComp(5, 3) << std::endl;
    }
    
    std::cout << "\n=== 嵌套类型别名 ===" << std::endl;
    
    // 6. 嵌套类型别名
    {
        Vec<int> numbers = {5, 3, 1, 4, 2};
        
        // 使用嵌套类型别名
        ValueType<Vec<int>> value = numbers[0];
        Iterator<Vec<int>> it = numbers.begin();
        ConstIterator<Vec<int>> constIt = numbers.cbegin();
        
        std::cout << "ValueType<Vec<int>>: " << value << std::endl;
        std::cout << "First element via iterator: " << *it << std::endl;
        std::cout << "First element via const_iterator: " << *constIt << std::endl;
    }
    
    std::cout << "\n=== 模板别名的优势 ===" << std::endl;
    std::cout << "1. 简化复杂类型声明" << std::endl;
    std::cout << "2. 提高代码可读性" << std::endl;
    std::cout << "3. 便于类型重构" << std::endl;
    std::cout << "4. 支持模板元编程" << std::endl;
    std::cout << "5. 可以创建类型别名模板" << std::endl;
    
    return 0;
}