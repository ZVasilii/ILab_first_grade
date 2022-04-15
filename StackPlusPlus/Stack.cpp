/**   \brief   This program is a model of Stack
 *    (Visit Wikipedia for more information)
 *    https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
 *
      \author  Zaitsev Vasilii, MIPT
      \version 5.0
      \date    November 2019

      \warning Use the  stack functions in following order:
      ***
             check_errors = Stack.<FUNCTION_NAME>;
             if (!check_errors) Stack.ERRORMANAGE(Stack.<OK FUNCTION>);
      ***
             You can use different data types in this stack
      ***

*/



#include "STACK_FUNCTIONS_DECLARATION.h"


int main()
{
    bool check_errors = false;
    StackDyn_t<DATATYPE> Stack;    ///Creating stack

    Stack.INTRODUCTION();

    ///Testing function INIT

    check_errors = Stack.STACK_INIT();
    if (!check_errors)
         Stack.ERRORMANAGE(Stack.OK_W_O_SIZE());

    ///Testing functionallity of stack

    Stack.UNIT_TEST();

    ///Testing function DESTROY

    check_errors = Stack.STACK_DESTROY();
    if (!check_errors) 
          Stack.ERRORMANAGE(Stack.OK_W_O_SIZE_POINTER());

    return 0;
}

