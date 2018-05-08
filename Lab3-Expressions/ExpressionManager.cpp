#include "ExpressionManager.h"
#include <cctype>

using namespace std;

const char ExpressionManager::LEFT_PAREN = '(';
const char ExpressionManager::LEFT_BRACE = '[';
const char ExpressionManager::LEFT_BRACKET = '{';
const char ExpressionManager::RIGHT_PAREN = ')';
const char ExpressionManager::RIGHT_BRACE = ']';
const char ExpressionManager::RIGHT_BRACKET = '}';
const string ExpressionManager::PARENS = "([{)]}";
    
const char ExpressionManager::PLUS = '+';
const char ExpressionManager::MINUS = '-';
const char ExpressionManager::MULTIPLY = '*';
const char ExpressionManager::DIVIDE = '/';
const char ExpressionManager::MOD = '%';
const string ExpressionManager::OPERATORS = "+-*/%";

bool isOperator(string str)
{
    if (str.size() == 1)
    {
        return ExpressionManager::OPERATORS.find(str) != string::npos;
    }
    return false;
}

bool isParen(string str)
{
    if (str.size() == 1)
    {
        return ExpressionManager::PARENS.find(str) != string::npos;
    }
    return false;
}

bool isNumber(string str)
{
    for (int i = 0; i < str[i]; i++)
    {
        if (!isdigit(str[i])) {return false;}
    }
    return true;
}

int evaluate(int left, int right, char ch)
{
    int ans(0);
    
    switch (ch)
    {
        case ExpressionManager::PLUS:
            ans = left + right;
            break;
        case ExpressionManager::MINUS:
            ans = left - right;
            break;
        case ExpressionManager::MULTIPLY:
            ans = left * right;
            break;
        case ExpressionManager::DIVIDE:
            if (right != 0) 
            {
                ans = left / right;
            }
            break;
        case ExpressionManager::MOD:
            ans = left % right;
            break;
        default:
            break;
    }
    
    return ans;
}

int precedence (string str)
{
    int pos, precedence (-1);
    pos = ExpressionManager::PARENS.find(str);
    if (pos != string::npos)
    {
        if (pos > 2)
        {
            precedence = 3;
        }
        else
        {
            precedence = 0;
        }
    }
    else
    {
        pos = ExpressionManager::OPERATORS.find(str);
        
        if (pos != string::npos)
        {
            if (pos > 1)
            {
                precedence = 2;
            }
            else 
            {
                precedence = 1;
            }
        }
    }
    return precedence;
}

void processOperator (stack<string> & ops, stringstream & postfix, string str)
{
    int prec;
    if (ops.empty())
    {
        ops.push(str);
    }
    else
    {
        prec = precedence (str);
        if (prec == 3)
        {
            while (ops.size() && (precedence(ops.top()) != 0))
            {
                postfix << ops.top() << " ";
                ops.pop();
            }
            ops.pop();
        }
        else if (prec > precedence(ops.top()) || prec == 0)
        {
            ops.push(str);
        }
        else 
        {
            while (ops.size() && (prec <= precedence(ops.top())))
            {
                postfix << ops.top() << " ";
                ops.pop();
            }
            ops.push(str);
        }
    }
}

/*
* Checks whether an expression is balanced on its parentheses
*
* - The given expression will have a space between every number or operator
*
* @return true if expression is balanced
* @return false otherwise
*/
bool ExpressionManager::isBalanced(string expression)
{
    std::stack<char> parenStack;
    bool balanced = true;
    int index = 0;
    
    while (index < expression.size() && balanced)
    {
        switch (expression[index])
        {
            case LEFT_PAREN:
                parenStack.push(expression[index]);
                break;
            case LEFT_BRACE:
                parenStack.push(expression[index]);
                break;
            case LEFT_BRACKET:
                parenStack.push(expression[index]);
                break;
            case RIGHT_PAREN:
                if(!parenStack.empty())
                {
                    if(parenStack.top() != LEFT_PAREN) {balanced = false;}
                    parenStack.pop();
                }
                else
                {
                    balanced = false;
                }
                break;
            case RIGHT_BRACE:
                if(!parenStack.empty())
                {
                    if(parenStack.top() != LEFT_BRACE) {balanced = false;}
                    parenStack.pop();
                }
                else
                {
                    balanced = false;
                }
                break;
            case RIGHT_BRACKET:
                if(!parenStack.empty())
                {
                    if(parenStack.top() != LEFT_BRACKET) {balanced = false;}
                    parenStack.pop();
                }
                else
                {
                    balanced = false;
                }
            default:
                break;
        }
        
        index++;
    }
    
    return balanced && parenStack.empty();
}

/**
* Converts a postfix expression into an infix expression
* and returns the infix expression.
*
* - The given postfix expression will have a space between every number or operator.
* - The returned infix expression must have a space between every number or operator.
* - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
* - Check lab requirements for what will be considered invalid.
*
* return the string "invalid" if postfixExpression is not a valid postfix expression.
* otherwise, return the correct infix expression as a string.
*/
string ExpressionManager::postfixEvaluate(string postfixExpression)
{
    stack<int> ops;
    stringstream ss(postfixExpression);
    string token, str("invalid");
    int left(0), right(0);
    
    while (ss>>token)
    {
        if (isNumber(token))
        {
            ops.push(stoi(token, nullptr));
        }
        else if (isOperator(token))
        {
            if (ops.size() > 1)
            {
                right = ops.top();
                ops.pop();
                left = ops.top();
                ops.pop();
                if (token[0] != DIVIDE || right != 0)
                {
                    ops.push(evaluate(left, right, token[0]));
                }
                else
                {
                    return str;
                }
            }
            else
            {
                return str;
            }
        }
        else 
        {
            return str;
        }
    }
    
    if (ops.size() == 1)
    {
        str = to_string(ops.top());
        ops.pop();
    }
    
    return str;
}

/*
* Evaluates a postfix expression returns the result as a string
*
* - The given postfix expression will have a space between every number or operator.
* - Check lab requirements for what will be considered invalid.
*
* return the string "invalid" if postfixExpression is not a valid postfix Expression
* otherwise, return the correct evaluation as a string
*/
string ExpressionManager::postfixToInfix(string postfixExpression)
{
    stack<string> ops;
    stringstream ss(postfixExpression);
    string token, str("invalid");
    string left, right;

    while (ss>>token)
    {
        if (isNumber(token))
        {
            ops.push(token);
        }
        else if (isOperator(token))
        {
            if (ops.size() > 1)
            {
                right = ops.top();
                ops.pop();
                left = ops.top();
                ops.pop();
                ops.push("( " + left + " " + token + " " + right + " )");
            }
            else
            {
                return str;
            }
        }
        else 
        {
            return str;
        }
    }
    
    if (ops.size() == 1)
    {
        str = ops.top();
        ops.pop();
    }
    
    return str;
}

/*
* Converts an infix expression into a postfix expression
* and returns the postfix expression
*
* - The given infix expression will have a space between every number or operator.
* - The returned postfix expression must have a space between every number or operator.
* - Check lab requirements for what will be considered invalid.
*
* return the string "invalid" if infixExpression is not a valid infix expression.
* otherwise, return the correct postfix expression as a string.
*/
string ExpressionManager::infixToPostfix(string infixExpression)
{
    string str("invalid"), token, prevToken("+");
    stringstream ss(infixExpression), postfix;
    stack<string> ops;
    
    if (isBalanced(ss.str()))
    {
        while (ss >> token)
        {
            if (isNumber(token) && !isNumber(prevToken))
            {
                postfix << token << " ";
                // cout << "Number token: " << token << endl;
            }
            else if ((isOperator(token) && !isOperator(prevToken)) || isParen(token))
            {
                // cout << "Operator token: " << token << endl;
                processOperator(ops, postfix, token);
            }
            else
            {
                return str;
            }
            prevToken = token;
            // cout << "postfix: " << postfix.str() << endl;
        }
    }
    while (ops.size())
    {
        postfix << ops.top() << " ";
        ops.pop();
    }
    // if (ops.size() == 1)
    // {
    //     postfix << ops.top();
    //     ops.pop();
    // }
    
    if (postfixEvaluate(postfix.str()) == "invalid")
    {
        return str;
    }
    
    if ((postfix.str()).size())
    {
        str = postfix.str();
        if (*(str.end()-1) == ' ')
        {
            cout << "there's still a space at the end" << endl;
            str.pop_back();
        }
        else
        {
            cout << *(str.end()-1) << "|";
        }
    }
    
    return str;
}