#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <cctype>
#include <sstream>
#include <stack>

using namespace std;

//signatures of functions

bool isOpeningParenthesis(char c);

bool isClosingParenthesis(char c);

bool isMatchingPair(char opening, char closing);

bool balancedParentheses(const std::string& expression);

int getPrecedence(char op);

string infixToPostfix(const string& infix);


string countCharacters(const string& str);


string reverseString(const string& str);




