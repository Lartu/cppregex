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

- **`bool regexMatch(string text, string regex)`**
<br>returns `true` if `text` matches the `regex`, `false` otherwise.

- **`bool regexContains(string text, string regex)`**
<br>returns `true` if `text` contains a substring that matches `regex`, `false` otherwise.

- **`int regexIndex(string text, string regex)`**
<br>returns the position of the first substring of `text` that matches `regex`, `-1` if none was found.

- **`vector<int> regexIndices(string text, string regex)`**
<br>returns a vector if ints containing all the positions of the substrings of `text` that match `regex`. An empty 
`vector<int>` is returned if none was found.

- **`pair<int, unsigned int> regexIndexLength(string text, string regex)`**
<br>returns the position and length of the first substring of `text` that matches `regex`. `<-1, 0>` is returned if none was found.

- **`vector<pair<int, unsigned int>> regexIndicesLengths(string text, string regex)`**
<br>returns a vector of pairs of position and length of each substring of `text` that matches `regex`. An empty `vector<pair<int, unsigned int>>` is returned if none was found.

- **`string regexSearch(string text, string regex)`**
<br>returns the first substring of `text` that matches `regex`, `""` if none was found.

- **`vector<string> regexSearchAll(string text, string regex)`**
<br>returns all the substrings of `text` that match `regex`, an empty `vector<string>` is returned if none was found.

- **`string regexBefore(string text, string regex)`**
<br>returns all the text found in `text` before a substring that matched `regex` was found.

- **`string regexAfter(string text, string regex)`**
<br>returns all the text found in `text` after a substring that matched `regex` was found.

- **`string regexReplace(string text, string regex, string newValue)`**
<br>returns a copy of `text` with the first substring that matched `regex` replaced by `newValue`.

- **`string regexReplaceAll(string text, string regex, string newValue)`**
<br>returns a copy of `text` with the every substring that matched `regex` replaced by `newValue`.

## License
Cppregex is released under the MIT License so you are free to do whatever you want with it. Enjoy!
