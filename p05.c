#include <stdio.h>
#include <stdlib.h>

int* createDynArray(int n, int v)
{
    int* r = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        r[i] = v;
    }
    
    return r;
}

void printArray(int* beg, int* end)
{
    while (beg != end)
    {
        printf("%d ", *beg++);
    }
    printf("\n");
}

void reverse(int* beg, int* end)
{
    if (beg == end)
        return;
    
    for (;;)
    {
        if (--end == beg) break;
        
        int t = *beg;
        *beg = *end;
        *end = t;
        
        if (++beg == end) break;
    }
}

int main(void)
{
    printf("number of elements: ");
    
    int n;
    scanf("%d", &n);
    
    int* a = createDynArray(n, 0);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
    }
    
    reverse(a, a + n);
    
    printArray(a, a + n);
    
    free(a);
    
    return 0;
}