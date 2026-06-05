#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 1. 全局命名空间使用using指令（不推荐在头文件中使用）
using namespace std;

// 2. 自定义命名空间
namespace Database
{
    class Connection
    {
    public:
        void connect()
        {
            cout << "Database connected" << endl;
        }
        
        void query(const string& sql)
        {
            cout << "Executing: " << sql << endl;
        }
    };
    
    namespace Utils
    {
        void printHeader(const string& title)
        {
            cout << "=== " << title << " ===" << endl;
        }
        
        void printSeparator()
        {
            cout << "-------------------" << endl;
        }
    }
}

namespace Network
{
    class HttpClient
    {
    public:
        void get(const string& url)
        {
            cout << "GET: " << url << endl;
        }
        
        void post(const string& url, const string& data)
        {
            cout << "POST: " << url << " Data: " << data << endl;
        }
    };
}

// 3. 函数内部使用using指令
void databaseOperations()
{
    // 在函数内部使用using指令
    using namespace Database;
    using namespace Database::Utils;
    
    printHeader("Database Operations");
    
    Connection conn;
    conn.connect();
    conn.query("SELECT * FROM users");
    
    printSeparator();
}

void networkOperations()
{
    // 在函数内部使用using指令
    using namespace Network;
    
    Database::Utils::printHeader("Network Operations");
    
    HttpClient client;
    client.get("https://api.example.com/users");
    client.post("https://api.example.com/users", "{\"name\": \"John\"}");
    
    Database::Utils::printSeparator();
}

// 4. 代码块中使用using指令
void demonstrateScope()
{
    cout << "=== 作用域演示 ===" << endl;
    
    // 外层代码块
    {
        using namespace Database;
        
        Connection conn;
        conn.connect();
        
        // 内层代码块
        {
            using namespace Network;
            
            HttpClient client;
            client.get("https://internal.api.com");
        }
        
        // 这里仍然可以使用Database命名空间
        conn.query("SELECT * FROM products");
    }
    
    // 这里不能直接使用Database或Network命名空间
    // 需要使用完全限定名
    Database::Utils::printSeparator();
}

// 5. 命名空间别名结合using指令
namespace fs = std::filesystem; // C++17 命名空间别名

// 6. 避免命名冲突的示例
namespace A
{
    void print()
    {
        cout << "A::print()" << endl;
    }
}

namespace B
{
    void print()
    {
        cout << "B::print()" << endl;
    }
}

void demonstrateConflict()
{
    cout << "=== 命名冲突演示 ===" << endl;
    
    // 使用using指令可能导致命名冲突
    // using namespace A;
    // using namespace B;
    // print(); // 错误：对'print'的调用不明确
    
    // 解决方案1：使用完全限定名
    A::print();
    B::print();
    
    // 解决方案2：使用using声明
    {
        using A::print;
        print(); // 调用A::print()
    }
    
    {
        using B::print;
        print(); // 调用B::print()
    }
    
    Database::Utils::printSeparator();
}

int main()
{
    cout << "=== using指令示例 ===" << endl;
    
    // 使用全局using指令
    vector<int> numbers = {5, 2, 8, 1, 9};
    sort(numbers.begin(), numbers.end());
    
    cout << "Sorted numbers: ";
    for (const auto& n : numbers)
    {
        cout << n << " ";
    }
    cout << endl;
    
    // 调用函数
    databaseOperations();
    networkOperations();
    demonstrateScope();
    demonstrateConflict();
    
    cout << "=== using指令的最佳实践 ===" << endl;
    cout << "1. 避免在头文件中使用using指令" << endl;
    cout << "2. 优先使用using声明而非using指令" << endl;
    cout << "3. 在函数或代码块中限制using指令的作用域" << endl;
    cout << "4. 注意命名冲突问题" << endl;
    cout << "5. 考虑使用命名空间别名" << endl;
    
    return 0;
}