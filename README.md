# malloc
A simple and thread-safe implementation of glibc function malloc()

# Compile
> *make*

# How to use it
You just need to upload your malloc library instead of the glibc malloc library with this command

> *export LD_PRELOAD=./libmy_malloc.so*

or execute your program with your malloc library

> *LD_PRELOAD=./libmy_malloc.so ./a.out*
