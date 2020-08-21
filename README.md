<div style='text-align: center;' align='center'>
    <img style='max-width: 300px;' src='logo.png'/>
</div>

# YSHARP - For Fun Coders
> Founder : Yehan Wasura. Developed this language at the age of 16 (Year 2020).

> A C-like scripting language. Advanced version of all Ysharp v1, v3 & v6 (These version are written in Python)

> Main Reason of Developing : To Encourage Sri Lankans and to develop my skills

# Donation & Contributions

Give me a support if you like, 

``` 
  try to contribute and my contacts are :
       Email : yehantest@gmail.com / contact@yehanwasura.ml
       Instagram : <a href="instagram.com/official.yehanwasura.lk">official.yehanwasura.lk</a>
       Whatsapp : +94 0762679048
       YouTube : https://www.youtube.com/channel/UCzK8p9qKo7hygzsZtshJC_g
       
       Support Me Via Paypal : https://paypal.me/cyberrex599
       Support Me Via Patreon : https://patreon.com/yehanwasura
 ```      
 
## Example program
> Here is a small program that iterates and writes the contents of a list:
```C
list fruits = [
    "apple",
    "banana",
    "pear",
    "lemon"
];

iterate fruits with void @(string fruit) { write(fruit) };
```

## Linking a C program
> Ysharp can execute functions written in C.
> To load a function written in C, you can use the `cload` method, to load
> a function from a shared object file (`.so`). Example:
```C
cload("librequests.so", "httpget");

string response = httpget("http://example.org")

write(response)
```
> Here, the `httpget` function was loaded from the `librequests.so` file.
> Read more about how to write C methods for Ysharp [here](CLOAD.md).

## Available Data types
> Here is a list of implemented data types:
* list
* int
* bool
* float
* char
* string
* object
* source

### List example
```C
list colors = [
    "red",
    "green",
    "blue"
];
```

#### Built-in list methods
##### Add
> To add an item to a list:
```C
list names = [];

names.add("yehan");
```
### Remove
> To remove an item from a list by index
```C
list names = ["yehan"];

names.remove(0);
```

### Int example
> Everyone knows what an integer is.
```C
int age = 16;
```

### Bool example
> Everyone knows what an boolean is.
```C
bool x = 10 > 3;
```

### Float example
> Everyone knows what an float is.
```C
float x = 0.5;
```

### Char example
```C
char c = 'a';
```

### String example
> Everyone knows what a string is.
```C
string name = "Yehan Wasura";
```

### Object example
> Objects are sort of what you think they are.
```C
object person = {
    string name = "yehan";
    int age = 16;
};

write(person.name);
```

### Source example
> Sources are basically objects that represents a parsed source code.
```C
source s = include("examples/functions.ys");
```
> To have Ysharp interpret the source, simply use the built-in `visit` method:
```C
visit(s);
```

## Built-in methods
* write
* writex
* include
* visit
* fopen
* fputs
* fclose
* input
* time
* free
* cload

### write
> Prints what ever you gives it, example:
```C
write("hello world");
```

### writex
> Prints the adress of a value, example:
```C
object person = {string name = "Yehan Wasura";};

writex(person);
```

### include
> Loads an external source file, example:
```C
source s = include("examples/functions.ys");
```

### visit
> Visits and executes a source, example:
```C
source s = include("examples/functions.ys");
visit(s);
```

### fopen
> Open a file, here is an example to read the contents of a file:
```C
object file = fopen("examples/functions.ys", "r");
string x = file.read();

write(x);
fclose(file);
```

### fputs
> Write string to file, example:
```C
object file = fopen("myfile.txt", "w+");

fputs("hello world", file);
fclose(file);
```

### fclose
> Close file, example:
```C
object file = fopen("myfile.txt", "w+");
fclose(file);
```

### input
> Read from user input, stdin:
```C
string a = input("Say something: ");

write("You said: " + a);
```

### time
> Get current timestamp
```C
object stamp = time();

write(stamp.seconds);
```

### free
> Deallocates a variable, example:
```
string x = "hello";
free(x);
```

## Anonymous functions
> To define an anonymous function, name it `@`; like this:
```C
void somefunction(void func)
{
    func();
}

somefunction(void @(){ print("Hello from anonymous function"); });
```

## Available statements
* new
* iterate
* break
* continue
* while
* for

### new example
```C
object get_person(string name)
{
    object o = {
        string name;    
    };

    o.name = name;

    return o;
}

object person = new get_person("Hanna");
```
> The `new` statement will always return a new address of whatever is to the
> right of the statement.

### iterate example
```C
void char_iterator(char c)
{
    write(c);
}

void list_iterator(string name)
{
    write(name);
}

string x = "yehan wasura";
list y = ["yehan", "jenul", "wasura"];

iterate x with char_iterator;
iterate y with list_iterator;
```

### iterate with index example
```C
list fruits = ["banana", "apple", "pear"]

void fruit_iterator(string name, int index)
{
    write(index);
}

iterate fruits with fruit_iterator;
```

### while example
```C
int x = 0;
while (x < 10)
{
    write(x);
    x += 1;
}
```

### for example
```C
for (int i = 0; i < 10; i+=1)
{
    write(i);
}
```

## Available locals & globals / constants
* this

### This example
> The `this` variable exists within local scopes.
> Accessing `this` within a function will return the address of that function:
```C
void myfunc()
{
    write(this);
}

myfunc();  // 0x55824ee44970
```
> Accessing `this` within a function inside an object will return the address
> of the object:
```C
object person =
{
    void myfunc()
    {
        write(this);
    }
}

person.myfunc();  // { object }
```

## Compositions
> Ysharp now also support compositions, like this:
```C
int add_2(int x)
{
    return x + 2;
}

int remove_1(int x)
{
    return x - 1;
}

int mycomp(int x) =
    add_2, remove_1;

int x = mycomp(10);

write(x);
```

## Notes
### Lists
> This might not be obvious, but lists can contain any sort of value. Example:
```C
list cool_stuff = [
    "this is a string",
    { string x = "Wow, this is an object"; },
    [
        "a string in a list in a list"
    ]
];
```

## Installing Ysharp
> To install Ysharp on your system, simple run:
```bash
make && sudo make install
```
```cmd
mingw32-make
```
or

```cmd
mingw64-make
```

## Extensions

> To use an extension please have a look [here](CLOAD.md)

# Donation & Contributions

Give me a support if you like, 

``` 
  try to contribute and my contacts are :
       Email : yehantest@gmail.com / contact@yehanwasura.ml
       Instagram : <a href="instagram.com/official.yehanwasura.lk">official.yehanwasura.lk</a>
       Whatsapp : +94 0762679048
       YouTube : https://www.youtube.com/channel/UCzK8p9qKo7hygzsZtshJC_g
       
       Support Me Via Paypal : https://paypal.me/cyberrex599
       Support Me Via Patreon : https://patreon.com/yehanwasura
 ```      

ThankYou

