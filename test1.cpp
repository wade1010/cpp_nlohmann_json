#include <iostream>
#include <iomanip>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
// 2.1、由值创建json对象
int main()
{
    // 方式一:直接构造
    json j =
        {
            {"pi", 3.141},
            {"happy", true},
            {"name", "Niels"},
            {"nothing", nullptr},
            {"answer", {{"everything", 42}}},
            {"list", {1, 0, 2}},
            {"object", {{"currency", "USD"}, {"value", 42.99}}}};

    // add new values
    j["new"]["key"]["value"] = {"another", "list"};

    // count elements
    auto s = j.size();
    j["size"] = s;

    // pretty print with indent of 4 spaces
    std::cout << std::setw(4) << j << '\n';

    // 方式一:赋值构造
    json j2;
    j2["name"] = "tester";
    j2["age"] = 37;
    j2["score"] = 34231.2;
    j2["is_nb"] = true;                                  // 布尔值
    j2["array"] = {"array_value1", "array_value2"};      // 数组
    j2["school"]["name"] = "c++ school";                 // 对象中元素值
    j2["friends"] = {{"name", "bob"}, {"is_nb", false}}; // 对象

    std::cout << std::setw(4) << j2 << std::endl;
}