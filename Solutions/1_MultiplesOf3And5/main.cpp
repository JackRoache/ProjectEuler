#include <iostream>

void print_usage()
{
    std::cout << "Usage: main <Count To>" << "\n";
}
long long get_sum_range(long begin, long end, int step) {
    long long sum = 0;

    for(; begin < end; begin += step)
        sum += begin;

    return sum;
}
int main(int argc, char *argv[])
{
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

    long long sum = 0;

    const int first = 3;
    const int second = 5;
    const int third = first * second;

    sum += get_sum_range(0, max, first);
    sum += get_sum_range(0, max, second);
    sum -= get_sum_range(0, max, third);

    std::cout << "Sum of 0 to " << max << " is " << sum << "\n";
    return 0;
}