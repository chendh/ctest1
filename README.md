# 2026計算機程式範例ver4

## 全域變數
- Scope: 此檔案後續所有函式皆可讀取 (若有跨檔連動可用 extern)
- Lifetime: 整個程式執行期間

## 區域變數
- Scope: 僅限 testFunction() 內部 (外部無法直接存取)
- Lifetime: 整個程式執行期間 (即使函式結束，數值依然保留！)

## 靜態區域變數
- Scope: 僅限 testFunction() 內部 (外部無法直接存取)
- Lifetime: 整個程式執行期間 (即使函式結束，數值依然保留！)

```C
#include <iostream>

// 1. 全域變數
// Scope: 此檔案後續所有函式皆可讀取 (若有跨檔連動可用 extern)
// Lifetime: 整個程式執行期間
int globalVar = 100;

void testFunction() {
    // 2. 區域變數
    // Scope: 僅限 testFunction() 內部
    // Lifetime: 每次呼叫 testFunction() 時建立，函式結束即銷毀
    int localVar = 1;

    // 3. 靜態區域變數
    // Scope: 僅限 testFunction() 內部 (外部無法直接存取)
    // Lifetime: 整個程式執行期間 (即使函式結束，數值依然保留！)
    static int staticVar = 1;

    localVar++;
    staticVar++;
    globalVar++;

    std::cout << "localVar: " << localVar << " | staticVar: " << staticVar << std::endl;
}

int main() {
    testFunction(); // 輸出: localVar: 2 | staticVar: 2
    testFunction(); // 輸出: localVar: 2 | staticVar: 3  <-- staticVar 保留了上次的狀態！
    testFunction(); // 輸出: localVar: 2 | staticVar: 4

    // std::cout << localVar;   // 錯誤！超出 Scope，無法存取
    // std::cout << staticVar;  // 錯誤！靜態區域變數雖然生命週期仍在，但 Scope 僅限於 testFunction 內部
    std::cout << "globalVar is: " << globalVar;
    return 0;
}
```