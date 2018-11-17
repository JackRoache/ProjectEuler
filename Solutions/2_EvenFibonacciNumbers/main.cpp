#include <iostream>
#include <vector>

void print_usage()
{
    std::cout << "Usage: main <max fib>" << "\n";
}
long long get_fibonacci(long long first, long long second)
{
    return first + second;
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return -1;
    }
    long max;
    try {
        max = std::stol(argv[1], nullptr, 10);
    } catch (const std::invalid_argument &e){
        std::cout << "Pass in valid positive integer" << "\n";
        print_usage();
        return -1;
    }

    long long first = 1;
    long long second = 1;
    long long answer = 0;
    long long sum = 0;

    do {
        if (answer % 2 == 0)
            sum += answer;

        answer = get_fibonacci(first, second);

        first = second;
        second = answer;
    } while (answer < max);

    std::cout << "The sum of even fib numbers below " << max << " is " << sum << "\n";
    return 0;
}