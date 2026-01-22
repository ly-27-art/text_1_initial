#include <stdio.h>

// 汉诺塔递归函数
// n：圆盘数量；a：起始柱；b：目标柱；c：辅助柱
void hanoi(int n, char a, char b, char c) {
    // 终止条件：仅1个圆盘，直接从起始柱移到目标柱
    if (n == 1) {
        printf("%d: %c -> %c\n", n, a, b);
        return;
    }
    // 步骤1：将前n-1个圆盘从a移到c（借助b做辅助）
    hanoi(n - 1, a, c, b);
    // 步骤2：将第n个圆盘从a移到b（核心操作，输出步骤）
    printf("%d: %c -> %c\n", n, a, b);
    // 步骤3：将前n-1个圆盘从c移到b（借助a做辅助）
    hanoi(n - 1, c, b, a);
}

int main() {
    int n;          // 圆盘数量
    char start, dest, temp;  // 起始柱、目标柱、辅助柱

    // 读取圆盘数量
    scanf("%d", &n);
    // 读取三根柱子（开头加空格跳过换行符，避免读取错误）
    scanf(" %c %c %c", &start, &dest, &temp);

    // 调用汉诺塔函数：参数顺序为 圆盘数、起始柱、目标柱、辅助柱
    hanoi(n, start, dest, temp);

    return 0;
}