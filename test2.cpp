#include <iostream>
#include <iomanip>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
// 2.2、由json对象得到值
int main()
{
    json j =
        {
            {"pi", 3.141},
            {"happy", true},
            {"name", "Niels"},
            {"nothing", nullptr},
            {"answer", {{"everything", 42}}},
            {"list", {1, 0, 2}},
            {"object", {{"currency", "USD"}, {"value", 42.99}}}};

    auto name = j["name"].get<std::string>();
    std::cout << "name=" << name << std::endl;

    std::cout << std::endl;

    auto num1 = j["list"][0].get<int>();
    auto num2 = j["list"].at(1).get<int>();
    std::cout << "num1=" << num1 << std::endl;
    std::cout << "num2=" << num2 << std::endl;

    std::cout << std::endl;

    auto obj0 = j["object"]["currency"].get<std::string>();
    std::cout << "obj0=" << obj0 << std::endl;
    return EXIT_SUCCESS;
}