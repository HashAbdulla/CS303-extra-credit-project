#include "functions.h"

//function definitions

// STACK FUNCTIONS //

//checks if the character is an opening paranthesis
bool isOpeningParenthesis(char c) {
    return c == '(' || c == '{' || c == '[';
}

// checks if the character is closing paranthesis
bool isClosingParenthesis(char c) {
    return c == ')' || c == '}' || c == ']';
}

// function check if a pair of opening and closing parentheses match.
bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}
// Function to check if the parentheses in the given expression are balanced.
bool balancedParentheses(const std::string& expression) {
    stack<char> stack;

    for (char c : expression) {
        if (isOpeningParenthesis(c)) {
            stack.push(c);
        } else if (isClosingParenthesis(c)) {
            if (stack.empty() || !isMatchingPair(stack.top(), c)) {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}
// function to assign precedence values to operators for the infix to postfix conversion
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        default:
            return -1;
    }
}
//Converts the infix expression to a postfix expression.
string infixToPostfix(const string& infix) {
    string postfix;
    stack<char> stack;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (isOpeningParenthesis(c)) {
            stack.push(c);
        } else if (isClosingParenthesis(c)) {
            while (!stack.empty() && !isMatchingPair(stack.top(), c)) {
                postfix += stack.top();
                stack.pop();
            }
            if (!stack.empty()) {
                stack.pop();
            }
        } else {
            while (!stack.empty() && getPrecedence(c) <= getPrecedence(stack.top())) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

// count characters
// function to count the number of digits, letters, and symbols in a string
string countCharacters(const string& str) {
    int digits = 0, letters = 0, symbols = 0;

    for (char c : str) {
        if (isdigit(c)) {
            ++digits;
        } else if (isalpha(c)) {
            ++letters;
        } else {
            ++symbols;
        }
    }

    ostringstream oss;
    oss << "Digits: " << digits << "\nLetters: " << letters << "\nSymbols: " << symbols;
    return oss.str();
}

// a function that outputs an entered string in reverse using a stack.
string reverseString(const string& str) {
    stack<char> s;
    for (char c : str) {
        s.push(c);
    }

    string reversed;
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}


