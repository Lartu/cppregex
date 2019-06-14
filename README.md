# 🦙 cppregex
Cppregex is a very simple, single header file, easy to use **C++11** std::regex
wrapper for lazy people that just want to use regex in C++ without having to
mingle with std::regex boilerplate code. In other words, a
**simple C++ regex library**.

Of course, this requires C++11 to work.

## How to use?
Include `cppregex.h` in your project and you are good to go.
This is `#include "cppregex.h"` for those of us that like to copy & paste.

## Documentation
Cpp regex includes the following functions:

#### bool regexMatch(string text, string regex)
Returns `true` if `text` matches the `regex`, `false` otherwise.
