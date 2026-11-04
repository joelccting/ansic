/**
 * Horowitz 書上很多用 for
 * 沒有初始化的情況下，條件為第一個檢驗的動作，若不合，則不會進入迴圈。
 * 若合，則按第三個參數規定執行，再按第二個參數的條件決定是否繼續執行。
 */
#include <stdio.h>

int main()
{
    int i = 9;

    /* The following two are equivalent */
#if 1
    while (i < 10)
    {
        printf("L%d: %d\n", __LINE__, i);
        ++i;
    }
#else
    for (; i < 10; ++i)
    {
        printf("L%d: %d\n", __LINE__, i);
    }
#endif
    printf("L%d: %d\n", __LINE__, i);
    return 0;
}