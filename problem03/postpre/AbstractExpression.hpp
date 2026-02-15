#ifndef _ABSTRACT_EXPRESSION_HPP_
#define _ABSTRACT_EXPRESSION_HPP_

#include <string>

class AbstractExpression {

    public:
        /** Determine if a character is a valid operator.
         * @param ch character to check for operator
         * @return true if ch is one of +,-,/,*, false otherwise */ 
        static bool isOperator(char ch) {
            return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
        }

        /** Determine if the string s is a valid prefix expression.
         * A valid expression must contain only operators and symbolic (alpha) variables,
         * and must follow the correct prefix grammar <operator> <prefix> <prefix>.
         * @param s string expression
         * @return true if s is a valid prefix expression, false if not */
        static bool isPre(const std::string& s) {
            // end of prefix expression must be length-1
            int endChar = endPre(s, 0);
            return (endChar == (s.length()-1));
        }

        /** Determine if the string s is a valid postfix expression.
         * A valid expression must contain only operators and symbolic (alpha) variables,
         * and must follow the correct postfix grammar <postfix> <postfix> <operator>.
         * @param s string expression
         * @return true if s is a valid postfix expression, false if not */
        static bool isPost(const std::string& s) {
            // "end" of postfix expression must be 0
            int firstChar = endPost(s, s.size() - 1);
            return (firstChar == 0);
        }

        /** Set the current expression from a prefix expression string.
         * @param pre string prefix expression
         * @post the current instance's expression is updated
         * @throws std::invalid_argument if the prefix expression is invalid */
        virtual void setFromPrefix(const std::string& pre) = 0;

        /** Set the current expression from a postfix expression string.
         * @param post string postfix expression
         * @post the current instance's expression is updated
         * @throws std::invalid_argument if the postfix expression is invalid */
        virtual void setFromPostfix(const std::string& post) = 0;

        /** Get the current expression in prefix form.
         * @return the current instance's expression as a prefix string */
        virtual std::string getPrefix() const = 0;

        /** Get the current expression in postfix form.
         * @return the current instance's expression as a postfix string */
        virtual std::string getPostfix() const = 0;

    protected:

        /** Return index to the end of a valid prefix expression or subexpression
         * given the index of the first character. 
         * For example, endPre("+ab",0) returns 2.
         * Passing in an operand will return the input index.
         * @param s string prefix expression
         * @param first index of the first character of the expression
         * @return index of the end of the prefix expression, or -1 if an input is invalid */
        static int endPre(const std::string& s, int first) {
            int last = s.length()-1;

            if ((first > last)) {
                return -1;
            }

            char ch = s[first];
            if (isalpha(ch)) {
                return first;
            } else {
                if (isOperator(ch)) {
                int firstEnd = endPre(s, first+1);
                if (firstEnd > -1) {
                    return endPre(s, firstEnd+1);
                } else {
                    return -1;
                }
                } else {
                return -1;
                }
            }
        }

        /** Return index to the "end" of a valid postfix expression or subexpression
         * given the index of the last character. Note that because
         * postfix expressions are formatted <postfix> <postfix> <operator>
         * the end of the expression is where the first <postfix> starts.
         * For example, endPost("ab+",2) returns 0.
         * Passing in an operand will return the input index.
         * @param s string postfix expression
         * @param last index of the last character of the expression
         * @return index of the end of the postfix expression, or -1 if an input is invalid */
        static int endPost(const std::string& s, int last) {
            int first = 0;
            if ((first > last)) {
                return -1;
            }

            char ch = s[last];
            if (isalpha(ch)) {
                return last;
            } else {
                if (isOperator(ch)) {
                int lastEnd = endPost(s, last - 1);
                if (lastEnd > -1) {
                    return endPost(s, lastEnd - 1);
                } else {
                    return -1;
                }
                } else {
                return -1;
                }
            }
        }

};

#endif 
