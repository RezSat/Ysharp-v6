# Writing C methods for Ysharp
> As mentioned before, Ysharp can execute functions written in C, and you can
> load them using the `cload` method:
```C
cload("lib/pi.so", "getpi");
```

## Examples
> Lets say we want to write a method in C that gives us a float, and then
> we want to call this method from Ysharp.
> Here is how we write that method:
```C
// pi.c

#include <ysharp/src/include/AST.h>
#include <ysharp/src/include/dynamic_list.h>
#include <ysharp/src/include/runtime.h>


AST_T* getpi(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    AST_T* float_ast = init_ast(AST_FLOAT);
    float_ast->float_value = 3.14;

    return float_ast;
}
```
> Now, you can compile this code like so:
```bash
gcc -g -Wall -rdynamic -shared -fPIC -o pi.so pi.c
```

> Now you can use the created `pi.so` file in ysharp like this:
```C
cload("pi.so", "getpi");


float PI = getpi();
```
