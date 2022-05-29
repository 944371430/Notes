#include "fmt/core.h"
#include <chrono>
#include <iostream>
#include <random>
using namespace std;
using namespace chrono;
using namespace fmt;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    mt19937 e{random_device{}()};
    char buffer[16];

    buffer[1] = 45;
    buffer[2] = 0;
    v8::format_to_n(buffer, 3, "0");
    cout << buffer << '\n';

    auto start = steady_clock::now();
    for (int i = 0; i < 10000000; ++i) {
        *v8::format_to_n(buffer, 15, "{}", e()).out = 0;
    }
    cout << buffer << '\n'
         << double(duration_cast<nanoseconds>(steady_clock::now() - start).count()) / 1e9 << '\n';

    start = steady_clock::now();
    for (int i = 0; i < 10000000; ++i) {
        snprintf(buffer, 15, "%d", e());
    }
    cout << buffer << '\n'
         << double(duration_cast<nanoseconds>(steady_clock::now() - start).count()) / 1e9 << '\n';

    start = steady_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        *std::format_to_n(buffer, 15, "{}", e()).out = 0;
    }
    cout << buffer << '\n'
         << double(duration_cast<nanoseconds>(steady_clock::now() - start).count()) / 1e9 << '\n';
}