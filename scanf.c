#include <stdio.h>

int main()
{
    int val;
    int ret = scanf("%d", &val);
    printf("ret=%d\n", ret);
    printf("val=%d\n", val);
    char str[10];
    scanf("%s", str);
    printf("%s\n", str);
    return 0;
}