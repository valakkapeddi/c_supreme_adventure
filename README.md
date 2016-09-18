Just a collection of C things I tried.

--- Copying structs.
Assigning a struct variable to another variable performs a shallow copy just as a memcpy would, but might be better optimized.  If you have pointers to structs, assignment will only create an alias, so what you want in that situation is to explicitly memcpy.


