#include <string>
#include <cctype> // for isalpha
#include <stdexcept>

#include "Expression.hpp"

/* Default constructor */
Expression::Expression() 
{}

/* Public member functions */
void Expression::setFromPrefix(const std::string &pre)
{
  // TODO: check format
  if (isPre(pre) == false)
  {
    throw std::invalid_argument("invalid prefix expression");
  }
  // TODO: store prefix and postfix forms

  prefixExpression = pre;
  postfixExpression.clear();

  prefixToPostfix(prefixExpression, postfixExpression);
}

void Expression::setFromPostfix(const std::string &post)
{
  // TODO: check format
  if (isPost(post) == false)
  {
    throw std::invalid_argument("invalid postfix expression");
  }

  // TODO: store prefix and postfix forms

  postfixExpression = post;
  prefixExpression.clear();
  postfixToPrefix(postfixExpression, prefixExpression);

}

std::string Expression::getPrefix() const
{
    return prefixExpression;
}

std::string Expression::getPostfix() const
{
    return postfixExpression;
}

/* Private member functions */
void Expression::prefixToPostfix(const std::string &prefix, std::string &postfix) const {
  // from textbook section 6.3.3
  int end1, end2;
  char first_char = prefix[0];
  if(isOperator(first_char)) {
    // recursively parse expression
    end1 = endPre(prefix,1);
    end2 = endPre(prefix,end1+1);
    // operand/subexpression
    prefixToPostfix(prefix.substr(1,end1), postfix);
    // operand/subexpression
    prefixToPostfix(prefix.substr(end1+1,end2-end1), postfix);
    // operator
    postfix += first_char;
  } else {
    // operand
    postfix += first_char;
  }
}

void Expression::postfixToPrefix(const std::string &postfix, std::string &prefix) const {

  // TODO: recursive function
  int end1, end2;
  char last_char = postfix[postfix.length() - 1];

  if (isOperator(last_char))
  {
    prefix += last_char;

    end1 = endPost(postfix, postfix.length() - 2);
    end2 = endPost(postfix, end1-1);

    postfixToPrefix(postfix.substr(end2, end1 - end2), prefix);
    postfixToPrefix(postfix.substr(end1, postfix.length() - 1 - end1), prefix);
  }
  else prefix += last_char;

}


