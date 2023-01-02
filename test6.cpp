#include <iostream>
#include <iomanip>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
// 2.4.3、json value和自定义对象
class person
{
public:
    person() {}
    person(std::string name, int age, double score) : m_name(name), m_age(age), m_score(score) {}

    void show()
    {
        std::cout << "person name=" << m_name << std::endl;
        std::cout << "person age=" << m_age << std::endl;
        std::cout << "person score=" << m_score << std::endl;
    }

    std::string m_name;
    int m_age;
    double m_score;
};

// 定义from_json(const json& j,T& value)函数，用于序列化
// json对象----->class对象
void from_json(const json &j, person &p) // 形参顺序不能变
{
    p.m_name = j["name"].get<std::string>();
    p.m_age = j["age"].get<int>();
    p.m_score = j["score"].get<double>();
}
// 定义to_json(json& j,const T& value)函数，用于反序列化
// class对象----->json对象
void to_json(json &j, const person &p) // 形参顺序不能变,要不然不能隐式转换,nlohmann json内部做了处理
{
    j["name"] = p.m_name;
    j["age"] = p.m_age;
    j["score"] = p.m_score;
}
// void to_json(json& j, const person& p)
// {
// 	j = json{ {"name", p.name}, {"address", p.address}, {"age", p.age} };
// }

// void from_json(const json& j, person& p) {
// 	j.at("name").get_to(p.name);
// 	j.at("address").get_to(p.address);
// 	j.at("age").get_to(p.age);
// }

int main()
{
    person p{"bob", 22, 95.6};
    std::cout << "to json,方式1:json=class隐式转换" << std::endl;
    json j1 = p;
    std::cout << "j1 = " << j1 << std::endl;

    std::cout << "to json,方式2:调用to_json函数" << std::endl;
    json j2;
    to_json(j2, p);
    std::cout << "j2 = " << j2 << std::endl;

    std::cout << "from json,方式1:调用from_json函数" << std::endl;
    j1["name"] = "new_bob";
    std::cout << "new j1 = " << j1 << std::endl;

    person new_p;
    from_json(j1, new_p);
    new_p.show();

    std::cout << "from json,方式2:调用.get()函数" << std::endl;
    // 像basic value一样通过get函数获取值，将其值直接赋值给自定义对象
    person new_p2 = j1.get<person>();
    new_p2.show();

    return EXIT_SUCCESS;
}