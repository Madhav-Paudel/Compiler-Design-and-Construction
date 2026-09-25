// LAB - 2
// A C++ Program to Implement Parser
#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;

// Token structure
struct Token
{
    string lexeme;
    string type;
};

// Parser Class
class Parser
{
private:
    Token tokens[100];
    int n;
    int pos;

public:
    // Constructor
    Parser(Token t[], int size)
    {
        n = size;
        pos = 0;
        for (int i = 0; i < n; i++)
        {
            tokens[i] = t[i];
        }
    }

    // Check current lexeme
    bool check(string word)
    {
        if (pos < n && tokens[pos].lexeme == word)
            return true;
        return false;
    }

    // Check current token type
    bool checkType(string type)
    {
        if (pos < n && tokens[pos].type == type)
            return true;
        return false;
    }

    // Move to next token
    void next()
    {
        pos++;
    }

    // Display syntax error
    void error(string message)
    {
        cout << "\nSyntax Error: " << message;
        if (pos < n)
        {
            cout << " Found <"
                 << tokens[pos].lexeme
                 << ", "
                 << tokens[pos].type
                 << ">";
        }
        cout << endl;
        exit(0);
    }

    // Grammar:
    // program -> function
    void program()
    {
        function();
        if (pos < n)
        {
            error("Unexpected token after program.");
        }
    }

    // Grammar:
    // function -> void ID ( ) { statements }
    void function()
    {
        // void
        if (check("void"))
            next();
        else
            error("Expected 'void'.");

        // Function name
        if (checkType("IDENTIFIER"))
            next();
        else
            error("Expected function name.");

        // (
        if (check("("))
            next();
        else
            error("Expected '('.");

        // )
        if (check(")"))
            next();
        else
            error("Expected ')'.");

        // {
        if (check("{"))
            next();
        else
            error("Expected '{'.");

        // Statements
        statements();

        // }
        if (check("}"))
            next();
        else
            error("Expected '}'.");
    }

    // Grammar:
    // statements -> statement*
    void statements()
    {
        while (pos < n && !check("}"))
        {
            statement();
        }
    }

    // Grammar:
    // statement -> declaration | assignment
    void statement()
    {
        // Declaration
        if (check("int") ||
            check("float") ||
            check("double") ||
            check("char"))
        {
            declaration();
        }
        // Assignment
        else if (checkType("IDENTIFIER"))
        {
            assignment();
        }
        else
        {
            error("Expected declaration or assignment.");
        }
    }

    // Grammar:
    // declaration -> type ID = expression ;
    void declaration()
    {
        type();

        // ID
        if (checkType("IDENTIFIER"))
            next();
        else
            error("Expected variable name.");

        // =
        if (check("="))
            next();
        else
            error("Expected '='.");

        // expression
        expression();

        // ;
        if (check(";"))
            next();
        else
            error("Expected ';'.");
    }

    // Grammar:
    // assignment -> ID = expression ;
    void assignment()
    {
        // ID
        if (checkType("IDENTIFIER"))
            next();
        else
            error("Expected identifier.");

        // =
        if (check("="))
            next();
        else
            error("Expected '='.");

        // expression
        expression();

        // ;
        if (check(";"))
            next();
        else
            error("Expected ';'.");
    }

    // Grammar:
    // type -> int | float | double | char
    void type()
    {
        if (check("int") ||
            check("float") ||
            check("double") ||
            check("char"))
        {
            next();
        }
        else
        {
            error("Expected data type.");
        }
    }

    // Grammar:
    // expression -> term ((+ | -) term)*
    void expression()
    {
        term();
        while (check("+") || check("-"))
        {
            next();
            term();
        }
    }

    // Grammar:
    // term -> factor ((* | /) factor)*
    void term()
    {
        factor();
        while (check("*") || check("/"))
        {
            next();
            factor();
        }
    }

    // Grammar:
    // factor -> ID | NUMBER | ( expression )
    void factor()
    {
        // Identifier
        if (checkType("IDENTIFIER"))
        {
            next();
        }
        // Number
        else if (checkType("NUMBER"))
        {
            next();
        }
        // ( expression )
        else if (check("("))
        {
            next();
            expression();
            if (check(")"))
                next();
            else
                error("Expected ')'.");
        }
        else
        {
            error("Expected identifier, number, or '('.");
        }
    }

    // Start Parser
    void parse()
    {
        program();
        cout << "\n------OUTPUT------" << endl << endl;
        cout << "PARSING SUCCESSFUL" << endl;
        cout << "The input follows the grammar." << endl;
    }
};

// MAIN FUNCTION
int main()
{
    Token tokens[100];
    int n;
     string name;
    int rollNumber;
  
    cout << "-------PARSER IMPLEMENTATION-------" << endl << endl;
    cout <<"Enter your Name and Roll Number:";
    cin>> name>>rollNumber;
    cout << "Hello, " << name << "! Your Roll Number is " << rollNumber << "." << endl;
    cout << "Enter number of tokens: " << endl;
    cin >> n;
    cout << endl;
    cout << "Enter tokens in the format:" << endl;
    cout << "lexeme token_type" << endl << endl;

    // Read tokens
    for (int i = 0; i < n; i++)
    {
        cin >> tokens[i].lexeme;
        cin >> tokens[i].type;
    }

    // Display tokens
    cout << endl << endl;
    cout << "-------Input Tokens:-------" << endl << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "<"
             << tokens[i].lexeme
             << ", "
             << tokens[i].type
             << ">"
             << endl;
    }

    // Create parser
    Parser parser(tokens, n);

    // Start parsing
    parser.parse();

    return 0;
}