#include "cppregex.h"
#include <iostream>
#include <string>

using namespace std;

string myString;
string regex1;
string regex2;
string regex3;

int main(){

    // -- regexMatch Examples --
    // Checks if a string matches a given regex.
    cout << "regexMatch" << endl;

    myString = "Hi there! How are you? Hi!";
    regex1 = "(Hi)(.*)(you?)(.*)";
    regex2 = "Potato";
    regex3 = ".*H.. are you..*";

    cout << regexMatch(myString, regex1) << endl; // matches
    cout << regexMatch(myString, regex2) << endl; // doesn't match
    cout << regexMatch(myString, regex3) << endl; // matches



    // -- regexContains Examples --
    // Checks if a string contains a substring that matches
    // a given regex.
    cout << endl << "regexContains" << endl;

    myString = "Hi there! How are you? Hi!";
    regex1 = "H.. are";
    regex2 = "\\!*";
    regex3 = "era";

    cout << regexContains(myString, regex1) << endl; // contains
    cout << regexContains(myString, regex2) << endl; // contains
    cout << regexContains(myString, regex3) << endl; // doesn't contain



    // -- regexIndex Examples --
    // Returns the position of the substring that matches the given regex,
    // -1 if none was found.
    cout << endl << "regexIndex" << endl;

    myString = "You are using cppregex~!";
    regex1 = "c[p\\+]*regex";
    regex2 = "not found!";

    cout << regexIndex(myString, regex1) << endl; // will print 14
    cout << regexIndex(myString, regex2) << endl; // will print -1



    // -- regexIndices Examples --
    // returns a vector of ints containing all the positions of the
    // substrings that match the given regex. Empty if none was found.
    cout << endl << "regexIndices" << endl;

    myString = "Cppregex is awesome, don't you love c++regex?";
    regex1 = "[Cc][p\\+]*regex";

    cout << regexIndices(myString, regex1).size() << endl; // will print 2
    cout << regexIndices(myString, regex1)[0] << endl; // will print 0
    cout << regexIndices(myString, regex1)[1] << endl; // will print 36



    // -- regexIndexLength Examples --
    // returns the position of the substring that matches the given regex,
    // and its length. <-1, 0> if none was found.
    cout << endl << "regexIndexLength" << endl;

    myString = "You are using cppregex~!";
    regex1 = "c[p\\+]*regex";
    regex2 = "not found!";

    cout << regexIndexLength(myString, regex1).first << endl; // will print 14
    cout << regexIndexLength(myString, regex1).second << endl; // will print 8
    cout << regexIndexLength(myString, regex2).first << endl; // will print -1
    cout << regexIndexLength(myString, regex2).second << endl; // will print 0



    // -- regexIndicesLengths Examples --
    // returns a vector of pair<int, unsigned int> containing all the positions and lengths
    // of the substrings that match the given regex. Empty if none was found.
    cout << endl << "regexIndicesLengths" << endl;

    myString = "Cppregex is awesome, don't you love c+++regex?";
    regex1 = "[Cc][p\\+]*regex";

    cout << regexIndicesLengths(myString, regex1).size() << endl; // will print 2
    cout << regexIndicesLengths(myString, regex1)[0].first << endl; // will print 0
    cout << regexIndicesLengths(myString, regex1)[0].second << endl; // will print 8
    cout << regexIndicesLengths(myString, regex1)[1].first << endl; // will print 36
    cout << regexIndicesLengths(myString, regex1)[1].second << endl; // will print 9



    // -- regexSearch Examples --
    // returns the first substring in text that matches the passed regex.
    // Empty if the regex didn't match anything.
    cout << endl << "regexSearch" << endl;

    myString = "Cppregex is awesome, don't you love c++regex?";
    regex1 = "[Cc][p\\+]*regex";
    regex2 = "llama";

    cout << regexSearch(myString, regex1) << endl; // will print Cppregex
    cout << regexSearch(myString, regex2) << endl; // will print ""



    // -- regexSearchAll Examples --
    // returns a vector of strings containing all the substrings in text that
    // matched the passed regex. Empty if the regex didn't match anything.
    cout << endl << "regexSearchAll" << endl;

    myString = "Cppregex is awesome, don't you love c++regex? I love cpppppregex!";
    regex1 = "[Cc][p\\+]*regex";
    regex2 = "llama";

    cout << regexSearchAll(myString, regex1).size() << endl; // will print 3
    cout << regexSearchAll(myString, regex1)[0] << endl; // will print Cppregex
    cout << regexSearchAll(myString, regex1)[1] << endl; // will print c++regex
    cout << regexSearchAll(myString, regex1)[2] << endl; // will print cpppppregex
    cout << regexSearchAll(myString, regex2).size() << endl; // will print 0



    // -- regexBefore Examples --
    // returns all the text found before a regex match was found.
    // Empty if nothing matched the regex.
    cout << endl << "regexBefore" << endl;

    myString = "My llama is very fluffy!";
    regex1 = "llama";

    cout << regexBefore(myString, regex1) << endl; // will print "My "



    // -- regexAfter Examples --
    // returns all the text found after a regex match was found.
    // Empty if nothing matched the regex.
    cout << endl << "regexAfter" << endl;

    myString = "My llama is very fluffy!";
    regex1 = "llama";

    cout << regexAfter(myString, regex1) << endl; // will print " is very fluffy!"

    

    // -- regexReplace Examples --
    // returns a string with the first match of the regex in text replaced by newValue.
    cout << endl << "regexReplace" << endl;

    myString = "My llama is very fluffy! I love my llama!";
    regex1 = "(l*)(ama)";

    cout << regexReplace(myString, regex1, "cow") << endl;
    // will print "My cow is very fluffy! I love my llama!"



    // -- regexReplaceAll Examples --
    // returns a string with all matches of the regex in text replaced by newValue.
    cout << endl << "regexReplaceAll" << endl;

    myString = "My llama is very fluffy! I love my llama!";
    regex1 = "(l*)(ama)";

    cout << regexReplaceAll(myString, regex1, "cow") << endl;
    // will print "My cow is very fluffy! I love my cow!"

    return 0;
}
