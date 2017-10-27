# malloc
A simple and thread-safe implementation of glibc function malloc(), free() and realloc().

For more informations see man malloc.

# Malloc functions
The malloc() function allocates size bytes and returns a pointer to the allocated memory. The memory is not initialized. If size is 0, then malloc() returns either NULL, or a unique pointer value that can later be successfully passed to free().

# Free functions
The free() function frees the memory space pointed to by ptr, which must have been returned by a previous call to malloc() or realloc(). Otherwise, or if free(ptr) has already been called before, undefined behavior occurs. If ptr is NULL, no operation is performed.

# Realloc functions
The realloc() function changes the size of the memory block pointed to by ptr to size bytes. The contents will be unchanged in the range from the start of the region up to the minimum of the old  and new sizes. If  the  new  size is larger than the old size, the added memory will not be initialized. If ptr is NULL, then the call is equivalent to malloc(size), for all values of size; if size is equal to zero, and ptr is not NULL, then the call is equivalent to free(ptr). Unless ptr is NULL, it must have been returned by an earlier call to malloc() or realloc(). If the area pointed to was moved, a free(ptr) is done.

# Compile
compiling:
    
    make
    
cleaning obj files:

    make clean
    
cleaning binary files:

    make fclean
    
    
cleaning all and compile:

    make re

# How to use it
You just need to upload your malloc library instead of the glibc malloc library with this command

    export LD_PRELOAD=./libmy_malloc.so

or execute your program with your malloc library

    LD_PRELOAD=./libmy_malloc.so ./a.out
