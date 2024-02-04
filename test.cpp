#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

void function1(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        k++;
    }
}

int main() {
    long long n; // 数据规模
    while (1) {
        cout << "Input n: ";
        cin >> n;
        if (n == -1) {
            break;
        }
        milliseconds start_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );
        function1(n);
//        function2(n);
//        function3(n);
        milliseconds end_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );
        cout << "take times: " << milliseconds(end_time).count() - milliseconds(start_time).count()
            <<" ms"<< endl;
    }
    return 0;
}