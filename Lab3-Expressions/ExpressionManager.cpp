#include "ExpressionManager.h"

using namespace std;

const char ExpressionManager::LEFT_PAREN = '(';
const char ExpressionManager::LEFT_BRACE = '[';
const char ExpressionManager::LEFT_BRACKET = '{';
const char ExpressionManager::RIGHT_PAREN = ')';
const char ExpressionManager::RIGHT_BRACE = ']';
const char ExpressionManager::RIGHT_BRACKET = '}';

const char ExpressionManager::PLUS = '+';
const char ExpressionManager::MINUS = '-';
const char ExpressionManager::MULTIPLY = '*';
const char ExpressionManager::DIVIDE = '/';
const char ExpressionManager::MOD = '%';

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
string ExpressionManager::postfixToInfix(string postfixExpression)
{
    return "";
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
string ExpressionManager::postfixEvaluate(string postfixExpression)
{
    return "";
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
    return "";
}