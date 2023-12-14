#include <iostream>
#include <vector>
#include <cmath>

class CasioCalculator {
public:
    double add(const std::vector<long long>& numbers) {
        double result = 0;
        for (double num : numbers) {
            result += num;
        }
        return result;
    }

    double subtract(const std::vector<long long>& numbers) {
        double result = numbers[0];
        for (size_t i = 1; i < numbers.size(); ++i) {
            result -= numbers[i];
        }
        return result;
    }

    double multiply(const std::vector<long long>& numbers) {
        double result = 1;
        for (double num : numbers) {
            result *= num;
        }
        return result;
    }

    double divide(const std::vector<long long>& numbers) {
        if (numbers.size() < 2) {
            std::cerr << "Error: Insufficient operands for division." << std::endl;
            return 0; 
        }

        double result = numbers[0];
        for (size_t i = 1; i < numbers.size(); ++i) {
            if (numbers[i] != 0) {
                result /= numbers[i];
            } else {
                std::cerr << "Error: Division by zero." << std::endl;
                return 0; }
                
        }
        return result;
    }

    double square(double a) {
        return a * a;
    }

    double power(double base, double exponent) {
        return std::pow(base, exponent);
    }
};

int main() {
    CasioCalculator calculator;

    char operation;
    std::vector<long long> numbers;

    while (true) {
        std::cout << "Enter operation (+, -, *, /, ^, s to square, q to quit): ";
        std::cin >> operation;

        if (operation == 'q') {
            std::cout << "Exiting calculator." << std::endl;
            break;
        }

        if (operation == 's') {
            double operand;
            std::cout << "Enter number to square: ";
            std::cin >> operand;
            std::cout << "Result: " << calculator.square(operand) << std::endl;
        } else if (operation == '^') {
            double base, exponent;
            std::cout << "Enter base: ";
            std::cin >> base;
            std::cout << "Enter exponent: ";
            std::cin >> exponent;
            std::cout << "Result: " << calculator.power(base, exponent) << std::endl;
        } else {
            double operand;
            std::cout << "Enter operand (enter 0 to finish input): ";
            while (true) {
                std::cin >> operand;
                if (operand == 0) {
                    break;
                }
                numbers.push_back(operand);
            }

            switch (operation) {
                case '+':
                    std::cout << "Result: " << calculator.add(numbers) << std::endl;
                    break;
                case '-':
                    std::cout << "Result: " << calculator.subtract(numbers) << std::endl;
                    break;
                case '*':
                    std::cout << "Result: " << calculator.multiply(numbers) << std::endl;
                    break;
                case '/':
                    std::cout << "Result: " << calculator.divide(numbers) << std::endl;
                    break;
                default:
                    std::cerr << "Invalid operation. Please try again." << std::endl;
            }

            numbers.clear(); //remove cac tinh hieu dau vao khi done
        }
    }

    return 0;
}
