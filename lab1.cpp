// LAB - 1
// A C++ Program to Implement Lexical Analyzer
#include <iostream>
#include <string>
using namespace std;

// Function to check whether a character is a letter
bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           ch == '_';
}

// Function to check whether a character is a digit
bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

// Function to check whether a word is a keyword
bool isKeyword(string word)
{
    return word == "int" ||
           word == "float" ||
           word == "double" ||
           word == "char" ||
           word == "if" ||
           word == "else" ||
           word == "while" ||
           word == "for" ||
           word == "void" ||
           word == "return";
}

// Function to display a token
void printToken(string lexeme, string token)
{
    cout << "<" << lexeme << ", " << token << ">" << endl;
}

// Main function
int main()
{
    string input;
    string line;
    string name;
    int rollNumber;
    cout <<"Enter your Name and Roll Number:";
    cin>> name>>rollNumber;
    cout << "Hello, " << name << "! Your Roll Number is " << rollNumber << "." << endl;
    cout << "Lexical Analyzer" << endl;
    cout <<"Enter your code (type 'END' on a new line to finish):" << endl;
    cout << "-------------------------------" << endl << endl;

    // Read multiple lines
    while (true)
    {
        getline(cin, line);
        if (line == "END")
            break;
        input += line + "\n";
    }

    cout << "----------TOKENS------------" << endl << endl;

    size_t i = 0; // FIX: was int, compared against unsigned input.length()

    // Read input character by character
    while (i < input.length())
    {
        char ch = input[i];

        // 1. Ignore spaces, tabs and newlines
        if (ch == ' ' || ch == '\t' || ch == '\n')
        {
            i++;
        }
        // 2. Keyword or Identifier
        else if (isLetter(ch))
        {
            string word = "";
            while (i < input.length() &&
                   (isLetter(input[i]) || isDigit(input[i])))
            {
                word += input[i];
                i++;
            }
            if (isKeyword(word))
            {
                printToken(word, "KEYWORD");
            }
            else
            {
                printToken(word, "IDENTIFIER");
            }
        }
        // 3. Number
        else if (isDigit(ch))
        {
            string number = "";
            while (i < input.length() && isDigit(input[i]))
            {
                number += input[i];
                i++;
            }
            printToken(number, "NUMBER");
        }
        // 4. Assignment Operator
        else if (ch == '=')
        {
            // Check for ==
            if (i + 1 < input.length() && input[i + 1] == '=')
            {
                printToken("==", "EQUAL");
                i += 2;
            }
            else
            {
                printToken("=", "ASSIGN");
                i++;
            }
        }
        // 5. Arithmetic Operators
        else if (ch == '+')
        {
            printToken("+", "PLUS");
            i++;
        }
        else if (ch == '-')
        {
            printToken("-", "MINUS");
            i++;
        }
        else if (ch == '*')
        {
            printToken("*", "MULTIPLY");
            i++;
        }
        else if (ch == '/')
        {
            printToken("/", "DIVIDE");
            i++;
        }
        // 6. Relational Operators
        else if (ch == '<')
        {
            if (i + 1 < input.length() && input[i + 1] == '=')
            {
                printToken("<=", "LESS_EQUAL");
                i += 2;
            }
            else
            {
                printToken("<", "LESS_THAN");
                i++;
            }
        }
        else if (ch == '>')
        {
            if (i + 1 < input.length() && input[i + 1] == '=')
            {
                printToken(">=", "GREATER_EQUAL");
                i += 2;
            }
            else
            {
                printToken(">", "GREATER_THAN");
                i++;
            }
        }
        // 7. Semicolon
        else if (ch == ';')
        {
            printToken(";", "SEMICOLON");
            i++;
        }
        // 8. Parentheses
        else if (ch == '(')
        {
            printToken("(", "LEFT_PARENTHESIS");
            i++;
        }
        else if (ch == ')')
        {
            printToken(")", "RIGHT_PARENTHESIS");
            i++;
        }
        // 9. Curly Braces
        else if (ch == '{')
        {
            printToken("{", "LEFT_BRACE");
            i++;
        }
        else if (ch == '}')
        {
            printToken("}", "RIGHT_BRACE");
            i++;
        }
        // 10. Comma
        else if (ch == ',')
        {
            printToken(",", "COMMA");
            i++;
        }
        // 11. Unknown Character
        else
        {
            string unknown = "";
            unknown += ch;
            printToken(unknown, "UNKNOWN");
            i++;
        }
    }
    return 0;
}