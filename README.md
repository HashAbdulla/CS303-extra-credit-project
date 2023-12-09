# CS303-extra-credit-project

This project was done by Hashim Abdulla & Mohamed Elgasim and it was due on 12/8/2023.

# Quick description
For this project, we went with option 4 which asked to implement a program that uses a stack to check if a given string of
parentheses is balanced. The program should be able to handle multiple types of parentheses, such as round, square, and curly brackets. We achieved this using functions and added extra functionalities which were to display the postfix version of the expression, to be able to input a string and see how many numbers,letters, and symbols were in it, and to see that string outputted in reverse using a stack. We implemented a GUI using QT as the cross-platform software needed to attain this. All source code which was used is included in the repo.

# GUI instructions
To launch the gui, the prerequisite is to be on windows. Then from the repository, download the zip file ("CS303Project-complete.zip") and extract it. Open the extracted folder then run "CS303Project.exe". The gui should run as all the needed dll's and files are in the folder.

# Instructions on how to use

![image](https://github.com/HashAbdulla/CS303-extra-credit-project/assets/113187737/cd5975bb-51d8-494d-8b33-a2535a3b9561)


The program isn't too complicated. Users can input a string or an infix expression into the "input string" box on the left and then click "check". The boxes on the right will then display whether the expression was balanced or not , and show the postfix version if it was. For the other 2 functionalities , users can input a string in the bottom input box then click on the "check" button in order to see the amount of digits,letters, and symbols and also a reversed version of the string on the right.


# Closer look on the logic behind the functions:

1) bool isOpeningParenthesis(char c): This function checks if the character c is an opening parenthesis. It returns true if c is ‘(’, ‘{’, or ‘[’, and false otherwise.

2) bool isClosingParenthesis(char c): This function checks if the character c is a closing parenthesis. It returns true if c is ‘)’, ‘}’, or ‘]’, and false otherwise.

3) bool isMatchingPair(char opening, char closing): This function checks if a pair of opening and closing parentheses match. It returns true if the opening and closing characters form a valid pair of parentheses, and false otherwise.

4) bool balancedParentheses(const std::string& expression): This function checks if the parentheses in the given expression are balanced. It uses a stack to keep track of the opening parentheses. If it encounters a closing parenthesis, it checks the top of the stack to see if it matches. If it does, it pops the opening parenthesis from the stack. If it doesn’t, or if the stack is empty, it returns false. If all parentheses are matched and the stack is empty at the end, it returns true.

5) int getPrecedence(char op): This function assigns precedence values to operators for the infix to postfix conversion. It returns 1 for ‘+’ and ‘-’, and 2 for ‘*’, ‘/’, and ‘%’. For any other character, it returns -1.

6) string infixToPostfix(const string& infix): This function converts an infix expression to a postfix expression. It uses a stack to keep track of the operators and parentheses. It scans the infix expression from left to right, and for each character, it does one of the following:

-If the character is an operand, it is added to the postfix expression.

-If the character is an opening parenthesis, it is pushed onto the stack.

-If the character is a closing parenthesis, it pops operators from the stack and adds them to the postfix expression until it encounters the matching opening parenthesis.

-If the character is an operator, it pops operators from the stack and adds them to the postfix expression until it encounters an operator with lower precedence or an opening parenthesis. Then it pushes the operator onto the stack.

-At the end, it pops any remaining operators from the stack and adds them to the postfix expression. The resulting postfix expression is returned.

7) string countCharacters(const string& str): This function counts the number of digits, letters, and symbols in a string. It iterates over each character in the string. If the character is a digit, it increments the digits counter. If the character is a letter, it increments the letters counter. For any other character, it increments the symbols counter. Finally, it returns a string that contains the counts of digits, letters, and symbols.

8) string reverseString(const string& str): This function reverses a string using a stack. It pushes each character of the string onto the stack. Then it pops each character from the stack and appends it to the reversed string. Since a stack is a last-in-first-out (LIFO) data structure, the characters are popped in reverse order, effectively reversing the string. The reversed string is then returned.


All of these functions return their results , then that result is converted to a QString class that can be shown in the GUI itself.


