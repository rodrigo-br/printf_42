# Printf 42 Project

## What is it?
<p>The goal of this project is to recode printf() using only the <a href="https://github.com/rodrigo-br/libft_42" target="_blank"><b>libft</b></a> and the <a href="https://man7.org/linux/man-pages/man3/stdarg.3.html" target="_blank">variadic functions</a>.</p>

<br>

### A few rules

<p>As most of 42's Projects, this one also have a few rules (such as the prohibition of the use of 
<span style="color:#33DAFF">for</span>,
<span style="color:#33DAFF"> VLA</span>,
<span style="color:#33DAFF"> global variables</span>
and others).</p> 

<br>

## How to use it

```Bash
git clone git@github.com:rodrigo-br/printf_42.git

cd printf_42/

make

touch main.c

echo '#include "ft_printf.h"' > main.c

(write a main)

cc main.c libftprintf.a && ./a.out
```

Suggestion of main:

```C
#include "ft_printf.h"

int main(void)
{
	//simple printf printing a decimal, a string and a char
	ft_printf("%d %s%c\n", 10, "little horses walking outside", '!');

	//testing the return value of the printf
	int value;
	value = ft_printf("%d %s%c\n", 10, "little horses walking outside", '!');
	ft_printf("%d\n", value);

	//some flags
	ft_printf("%5d %#010X %p %%\n", 1, 99999, free);
}
```