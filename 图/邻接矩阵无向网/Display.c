#include"AMGraph.c"

int main(void)
{
    AMGraph G;
    InitAMGraph(&G, 3, 2);
    CreateAMGraph(&G);
    DisplayAMGraph(&G);
    return 0;
}