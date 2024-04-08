# ft_printf - personal implementation of the libc printf() in C

## 3rd project in my 42 cursus

The goal of this project is to write a simplified personal implementation in C of the output utility function printf() from the standard C library.<br>
It allowed me to explore the concept of variable arguments list and to discover how this so often-used function works.<br>
The result is a library that can be used in other C projects (I don't know why someone would prefer this implementation instead of the original one though...).<br>
<br>
| Project Name | ft_printf |
| :-: | :-: |
| Description | Custom version of the libc printf function |
| Technologies | <a href="#"><img alt="C" src="https://custom-icon-badges.demolab.com/badge/C-03599C.svg?logo=c-in-hexagon&logoColor=white&style=for-the-badge"></a> |
| External libraries | malloc(), free(), write(), va_start(), va_arg(), va_copy(), va_end() |

## Usage
#### Build the library
```
git clone https://github.com/GSantoine/ft_printf.git
cd ft_printf
make
```
#### Use the library
Since this a library, you can link it inside the Makefile of your project like so :
```
$(CC) $(CFLAGS) -Lft_printf -lftprintf -c $< -o $@
```
#### Use the function like this
```c
int main(int ac, char **av)
{
  ft_printf("this is :%d\n", 42);
  return 0;
}
```
