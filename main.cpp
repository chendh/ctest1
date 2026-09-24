#include <iostream>
#include <string>     // 使用 std::string 必備
#include <format>     // C++20 格式化字串 (若編譯器較舊可換成傳統 std::cout)
#include <algorithm>  // 使用 std::transform (大小寫轉換)
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    // 1. 宣告與初始化 (Initialization)
    std::string str1 = "Hello";
    std::string str2 = "World";

    // 2. 字串串接與長度 (Concatenation & Length)
    std::string fullStr = str1 + " " + str2 + "!";
    std::cout << "1 字串串接" << std::endl;
    std::cout << "完整字串: " << fullStr << std::endl;
    std::cout << "字串長度 (length): " << fullStr.length() << std::endl; // 或使用 fullStr.size()
    // std::cout << "是否為空 (empty): " << (fullStr.empty() ? "是" : "否") << std::endl;

    // 3. 搜尋與擷取子字串 (Search & Substring)
    std::cout << "\n--- 2. 搜尋與擷取 ---" << std::endl;
    std::string target = "World";
    size_t pos = fullStr.find(target); // 搜尋 "World" 出現的起始索引位置

    if (pos != std::string::npos) {
        std::cout << "找到 \"" << target << "\" 於索引位置: " << pos << std::endl;
        // substr(起始索引, 擷取長度)
        std::string sub = fullStr.substr(pos, 5);
        std::cout << "擷取出的子字串: " << sub << std::endl;
    } else {
        std::cout << "未找到子字串" << std::endl;
    }

    // 4. 替換與插入 (Replace & Insert)
    std::cout << "\n--- 3. 替換與修改 ---" << std::endl;
    std::string msg = "I like C Language.";
    // replace(起始位置, 替換長度, 新字串)
    msg.replace(7, 1, "C++"); 
    std::cout << "替換後: " << msg << std::endl;

    msg.append(" It is powerful."); // 末尾追加字串
    std::cout << "追加後: " << msg << std::endl;

    // 5. 大小寫轉換 (Case Conversion - 搭配 <algorithm>)
    std::cout << "\n--- 4. 大小寫轉換 ---" << std::endl;
    std::string upperStr = str1;
    // 將所有字元轉為大寫
    std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    std::cout << "轉大寫: " << upperStr << std::endl;

    // 6. C++ std::string 與 C-Style String (const char*) 轉換
    std::cout << "\n--- 5. 轉換為 C 語言風格字串 ---" << std::endl;
    const char* c_str = fullStr.c_str(); // 與舊版 C 語言 API 相容時使用
    std::cout << "C 風格字串指標內容: " << c_str << std::endl;

    // 7. C++20 格式化字串 (Format / Interpolation)
    std::cout << "\n--- 6. C++20 std::format 格式化輸出 ---" << std::endl;
    std::string name = "Alice";
    int score = 95;
    // 使用 std::format 進行字串插補/格式化
    // std::string formatted = std::format("學生 {} 的 C++ 測驗成績為: {} 分", name, score);
    // std::cout << formatted << std::endl;
    // std::cout << "學生" << name << "的C++測驗成績為：" << score << "分" << std::endl;
    std::cout << "The C++ score of " << name << " is "<< score << endl;
    return 0;
}