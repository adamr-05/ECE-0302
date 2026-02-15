#ifndef _EXPRESSION_HPP_
#define _EXPRESSION_HPP_

#include <string>

#include "AbstractExpression.hpp"

class Expression : public AbstractExpression {

    public:
        /** Only a default constructor is allowed, must use set methods
         * to set the expression, so we can specify whether the input string 
         * is in prefix or postfix notation. */
        Expression();

        void setFromPrefix(const std::string& pre);

        void setFromPostfix(const std::string& post);

        std::string getPrefix() const;

        std::string getPostfix() const;

    private:

        /** Convert the input prefix expression to postfix notation. 
         * @param prefix string prefix expression to convert
         * @param postfix string reference to store the postfix expression
         * @pre prefix is a valid expression (does not check)
         * @post postfix contains the converted expression */
        void prefixToPostfix(const std::string& prefix, std::string& postfix) const;

        /** Convert the input postfix expression to prefix notation. 
         * @param postfix string postfix expression to convert
         * @param prefix string reference to store the prefix expression
         * @pre postfix is a valid expression (does not check)
         * @post prefix contains the converted expression */
        void postfixToPrefix(const std::string& postfix, std::string& prefix) const;


        // TODO: members for stored expression

};

#endif 
