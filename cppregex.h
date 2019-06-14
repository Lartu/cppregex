// +-----------------------------------------+
// | CPPREGEX C++ STD::REGEX WRAPPER LIBRARY |
// |  by Martín del Río (github.com/lartu)   |
// +-----------------------------------------+
// |     Released under the MIT License      |
// |                  2019                   |
// +-----------------------------------------+

#include <string>
#include <regex>
#include <vector>

// regexMatch(text, regex) -> bool
// returns true if the text matches the regex, false otherwise.
bool regexMatch(std::string _text, std::string _regex){
    std::regex _r(_regex);
    return std::regex_match(_text, _r);
}

// regexContains(text, regex) -> bool
// returns true if the text contains a substring that matches the
// given regex.
bool regexContains(std::string _text, std::string _regex){
    std::regex _r(_regex);
    return std::regex_search(_text, _r);
}

// regexIndex(text, regex) -> int
// returns the position of the substring that matches the given regex,
// -1 if none was found.
int regexIndex(std::string _text, std::string _regex){
    std::smatch m;
    std::regex _r(_regex);
    std::regex_search(_text, m, _r);
    if(m.empty()) return -1;
    return m.position();
}

// regexIndices(text, regex) -> vector<int>
// returns a vector of ints containing all the positions of the substrings
// that match the given regex. Empty if none was found.
std::vector<int> regexIndices(std::string _text, std::string _regex){
    std::regex _r(_regex);
    std::vector<int> ret;
    for(auto it = std::sregex_iterator(_text.begin(), _text.end(), _r); it != std::sregex_iterator(); ++it){
        ret.push_back(it->position());
    }
    return ret;
}

// regexIndexLength(text, regex) -> pair<int, unsigned int>
// returns the position of the substring that matches the given regex,
// and its length. <-1, 0> if none was found.
std::pair<int, unsigned int> regexIndexLength(std::string _text, std::string _regex){
    std::smatch m;
    std::regex _r(_regex);
    std::regex_search(_text, m, _r);
    if(m.empty()) return std::make_pair(-1, 0);
    return std::make_pair(m.position(), m.length());
}

// regexIndicesLengths(text, regex) -> vector<pair<int, unsigned int>>
// returns a vector of pair<int, unsigned int> containing all the positions and lengths
// of the substrings that match the given regex. Empty if none was found.
std::vector<std::pair<int, unsigned int>> regexIndicesLengths(std::string _text, std::string _regex){
    std::regex _r(_regex);
    std::vector<std::pair<int, unsigned int>> ret;
    for(auto it = std::sregex_iterator(_text.begin(), _text.end(), _r); it != std::sregex_iterator(); ++it){
        ret.push_back(std::make_pair(it->position(), it->length()));
    }
    return ret;
}

// regexSearch(text, regex) -> string
// returns the first substring in text that matches the passed regex.
// Empty string returned if the regex didn't match anything.
std::string regexSearch(std::string _text, std::string _regex){
    std::smatch m;
    std::regex _r(_regex);
    std::regex_search(_text, m, _r);
    if(m.empty()) return "";
    return m.str();
}

// regexSearchAll(text, regex) -> vector<string>
// returns a vector of strings containing all the substrings in text that
// matched the passed regex. Empty if the regex didn't match anything.
std::vector<std::string> regexSearchAll(std::string _text, std::string _regex){
    std::regex _r(_regex);
    std::vector<std::string> ret;
    for(auto it = std::sregex_iterator(_text.begin(), _text.end(), _r); it != std::sregex_iterator(); ++it){
        ret.push_back(it->str());
    }
    return ret;
}

// regexBefore(text, regex) -> string
// returns all the text found before a regex match was found.
// Empty if nothing matched the regex.
std::string regexBefore(std::string _text, std::string _regex){
    std::smatch m;
    std::regex _r(_regex);
    std::regex_search(_text, m, _r);
    if(m.empty()) return "";
    return m.prefix().str();
}

// regexAfter(text, regex) -> string
// returns all the text found after a regex match was found.
// Empty if nothing matched the regex.
std::string regexAfter(std::string _text, std::string _regex){
    std::smatch m;
    std::regex _r(_regex);
    std::regex_search(_text, m, _r);
    if(m.empty()) return "";
    return m.suffix().str();
}

// regexReplace(text, regex, newValue) -> string
// returns a string with the first match of the regex in text replaced by newValue.
std::string regexReplace(std::string _text, std::string _regex, std::string newValue){
    std::regex _r(_regex);
    return std::regex_replace (_text,_r,newValue,std::regex_constants::format_first_only);
}

// regexReplaceAll(text, regex, newValue) -> string
// returns a string with all matches of the regex in text replaced by newValue.
std::string regexReplaceAll(std::string _text, std::string _regex, std::string newValue){
    std::regex _r(_regex);
    return std::regex_replace (_text,_r,newValue);
}
