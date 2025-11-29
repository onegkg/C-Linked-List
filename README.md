# LinkedList - Professional Development Project

A C implementation of a generic linked list data structure built to practice memory management in C.

## Still To Do
- Write a free_list() function
- Add unit testing

## Skills Demonstrated

### Memory Management
- Dynamic memory allocation using `malloc()` and `free()`
- Proper error handling for allocation failures
- Memory leak prevention through careful cleanup

### C Programming Fundamentals
- Struct design and typedef usage for clean abstractions
- Header file organization and include guards
- Function documentation with Doxygen-style comments
- Error code handling and return value conventions

### Software Engineering Practices
- Separation of interface from implementation 
- Defensive programming with NULL pointer checks
- Consistent coding style and naming conventions
- CMake build system configuration

### Code Quality
- Comprehensive error handling with meaningful return codes
- Edge case consideration (empty lists, invalid indices, NULL inputs)
- Resource cleanup in failure scenarios
- Clear, maintainable code structure

## Technical Details

- **Language**: C (C11 standard)
- **Build System**: CMake
- **Architecture**: Modular design with separate header and implementation files
- **Data Storage**: Generic void* pointers for type flexibility
- **Memory Safety**: Explicit allocation/deallocation with error handling

## Learning Objectives

This project serves as a foundation for understanding:
- Low-level memory management concepts
- Data structure implementation from scratch
- C programming best practices
- Software design patterns and abstractions
