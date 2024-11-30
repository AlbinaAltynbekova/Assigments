#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

template <typename T, size_t MaxSize>
class Stack {
private:
    T data[MaxSize];
    size_t top;

public:
    Stack() : top(0) {}

    void push(const T& value) {
        if (top >= MaxSize) throw std::overflow_error("Stack overflow");
        data[top++] = value;
    }

    T pop() {
        if (top == 0) throw std::underflow_error("Stack underflow");
        return data[--top];
    }

    bool isEmpty() const {
        return top == 0;
    }
};

double evaluatePostfix(const std::string& expression) {
    Stack<double, 100> stack;

    std::istringstream tokens(expression);
    std::string token;

    while (tokens >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            stack.push(std::stod(token));
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.isEmpty()) throw std::runtime_error("Invalid expression: missing operands");
            double operand2 = stack.pop();
            if (stack.isEmpty()) throw std::runtime_error("Invalid expression: missing operands");
            double operand1 = stack.pop();

            if (token == "+") stack.push(operand1 + operand2);
            else if (token == "-") stack.push(operand1 - operand2);
            else if (token == "*") stack.push(operand1 * operand2);
            else if (token == "/") {
                if (operand2 == 0) throw std::runtime_error("Division by zero");
                stack.push(operand1 / operand2);
            }
        } else {
            throw std::runtime_error("Invalid token in expression: " + token);
        }
    }

    if (stack.isEmpty()) throw std::runtime_error("Invalid expression: no result in stack");
    double result = stack.pop();
    if (!stack.isEmpty()) throw std::runtime_error("Invalid expression: too many operands");
    return result;
}

int main() {
    try {
        std::string expression;
        std::cout << "Enter a postfix expression: ";
        std::getline(std::cin, expression);

        double result = evaluatePostfix(expression);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
