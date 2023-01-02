#include <iostream>
#include <iomanip>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
// 2.3、像STL container一样操作json value
int main()
{
    json j = {"a1", "a2"};

    j.push_back("a3");

    j.emplace_back("a4");

    std::cout << "j=" << j << std::endl;

    if (j.is_array() && !j.empty())
    {
        size_t size = j.size();
        std::cout << "j size:" << size << std::endl;

        std::string lastEle = j.at(size - 1).get<std::string>();
        std::cout << "j[size-1]:" << lastEle << std::endl;
        std::cout << std::endl;
    }

    //
    json j2 = {{"name", "bob"}, {"age", 12}};
    j2.push_back({"height", 123.2});
    j2.erase("age"); // 删除键值
    std::cout << "j2=" << j2 << std::endl;

    j2["height"] = 222.33; // 通过key修改value的值

    // 判断是否含有某个键值方式1
    if (j2.contains("height"))
    {
        auto height = j2["height"].get<double>();
        std::cout << "method1:height=" << height << std::endl;
    }

    // 判断是否含有某个键值方式二
    auto size = j2.count("height");
    if (size > 0)
    {
        auto height = j2["height"].get<double>();
        std::cout << "method2:height=" << height << std::endl;
    }

    // 判断是否含有某个键值方式三
    auto iter = j2.find("height");
    if (iter != j2.end())
    {
        auto height = j2["height"].get<double>();
        std::cout << "method3:height=" << height << std::endl;
    }

    // 遍历输出方式1
    std::cout << "遍历输出键值方式1" << std::endl;
    for (auto &item : j2.items())
    {
        std::cout << item.key() << ":" << item.value() << std::endl;
    }

    // 遍历输出方式2
    for (auto iter = j2.begin(); iter != j2.end(); ++iter)
    {
        std::cout << iter.key() << ":" << iter.value() << std::endl;
    }

    return EXIT_SUCCESS;
}