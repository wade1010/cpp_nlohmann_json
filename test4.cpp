#include <iostream>
#include <iomanip>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
// 2.4.1 json字符串序列化和反序列化
int main()
{
    // 两种方式,反序列化构建json对象
    // 方式1，通过"_json"实现反序列化
    json j1 = "{\"name\":\"tester1\",\"score\":88,\"money\":100000}"_json;
    // 使用原生字符串关键字R来避免转移字符
    auto temp = R"({"name":"tester2","score":188,"money":200000})";
    // 方式2,通过静态函数parse实现反序列化
    json j2 = json::parse(temp);

    std::cout << "反序列化" << std::endl;
    std::cout << "j1 =" << j1 << std::endl;
    std::cout << "j2 =" << j2 << std::endl;

    std::cout << "序列化" << std::endl;
    // 序列化(Serialization)：dump(number)，number为打印出的空格数
    auto j1_string = j1.dump();
    auto j2_string = j2.dump(4);
    std::cout << "j1_string=" << j1_string << std::endl;
    std::cout << std::endl;
    std::cout << "j2_string=" << j2_string << std::endl;

    return EXIT_SUCCESS;
}