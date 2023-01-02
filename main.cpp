#include <iostream>
#include <iomanip>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
// 3.2、宏的使用
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
    // 类名，成员1，成员2，成员3
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(person, m_name, m_age, m_score);
};

int main()
{
    person p{"bob", 22, 95.6};
    std::cout << "调用宏实现:to json" << std::endl;
    json j = p;
    std::cout << j << std::endl;
    std::cout << std::endl;
    std::cout << j.dump() << std::endl;
    std::cout << "调用宏实现:from json" << std::endl;
    j["name"] = "new bob";
    person p2 = j;
    p2.show();

    return EXIT_SUCCESS;
}