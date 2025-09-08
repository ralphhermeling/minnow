# C++ Guidelines

In particular, we would like you to:
CS144: Introduction to Computer Networking Winter 2025
� Use the language documentation at https://en.cppreference.com as a resource. (We’d
recommend you avoid cplusplus.com which is more likely to be out-of-date.)
� Never use malloc() or free().
� Never use new or delete.
� Essentially never use raw pointers (*), and use “smart” pointers (unique ptr or
shared ptr) only when necessary. (You will not need to use these in CS144.)
� Avoid templates, threads, locks, and virtual functions. (You will not need to use these
in CS144.)
� Avoid C-style strings (char *str) or string functions (strlen(), strcpy()). These
are pretty error-prone. Use a std::string instead.
� Never use C-style casts (e.g., (FILE *)x). Use a C++ static cast if you have to (you
generally will not need this in CS144).
� Prefer passing function arguments by const reference (e.g.: const Address & address).
� Make every variable const unless it needs to be mutated.
� Make every method const unless it needs to mutate the object.
� Avoid global variables, and give every variable the smallest scope possible.
� Before handing in an assignment, run cmake --build build --target tidy for
suggestions on how to improve the code related to C++ programming practices, and
cmake --build build --target format to format the code consistently.

