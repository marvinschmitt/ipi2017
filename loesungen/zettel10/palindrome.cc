#include "palindrome.h"

std::string reverse_string(std::string s)
{
    std::reverse(s.begin(), s.end());
    return s;
}


bool is_palindrome(std::string s)
{
    return s == reverse_string(s);
}

