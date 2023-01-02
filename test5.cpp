#include <iostream>
#include <iomanip>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
// 2.4.2、json对象和文件输入输出转换
int main()
{
    // 从json文件中读取内容到json对象中
    std::ifstream in("./student_json.txt");
    if (!in.is_open())
    {
        std::cout << "open failed!" << std::endl;
        return EXIT_FAILURE;
    }
    json j;
    in >> j;
    in.close();
    std::cout << std::setw(4) << j << std::endl;

    // 输出json对象内容到文件中
    std::ofstream out("./new_student_json.txt");
    j["new_name"] = "new name";
    // 输出json对象到文件中，std::setw(4)用于设置增加打印空格
    out << std::setw(4) << j;
    out.close();

    return EXIT_SUCCESS;
}