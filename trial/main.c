#include "pushswap.h"


int main(int argc,char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int size;

    stack_b=NULL;
    stack_a=NULL;
    init_stack_a(argc,argv,&stack_a);
    size = ft_stack_size(stack_a);
    execute_strategy(argc, argv, &stack_a, &stack_b,  size);
    //quick_sort_a(&stack_a,&stack_b,size);
    print_stack(stack_a);
}