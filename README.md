# 42-Ft_printf
This project is pretty straightforward. You need to recode printf(). You will mainly learn how to use a varaible number of  arguments.

## Description
The third project of the "42" school.
The main goal of this project is to recode the famous "printf" function, without taking care of the buffer management, but using the same prototype.
int		ft_printf(const char *, ...);

We must implement the following conversions:
% / %c / %s / %p / %d / %i / %u / %d / %x / %X

###	What have I learned?
>Managing multiple files.

>Use of "ar" in the Makefile, and the purpose of it.
>Variadic function
>Data structure.
>Unary operator.

### What difficulties did I encounter?
_Many difficulties ;)_
At first and not sure where to start I decided to look at the actual code for the "printf" function. So I went to discover the famous Torvalds code on github :
```
https://github.com/torvalds/linux/blob/master/arch/x86/boot/printf.c
```
I learned a lot by studying his code. But trying to reproduce it, I found myself with gigantic "code standard issues". I had 2/3 files with more than 600 lines in them. But at school, we must have only 5 functions per file and each function must not exceed 25 lines.
I had to cut my code like a butcher.
Also, not wishing to use "malloc" to avoir potential memory leaks, my code is not very portative.

## Final Grade:
```diff
+ 100%
# (min to pass = 100%)
```


## Installation


## Usage