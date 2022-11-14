#include <iostream>
#include <iomanip>
using namespace std;

int getFactorial(int num);

int main() {
        int num;
        cout << "Please enter the number ";
        cin >> num;
        clock_t time;
        time = clock();
        cout << "The " << num << " factorial is " << getFactorial(num);
        time = clock() - time;
        cout << "\nThe time that the computer needs to solve the problem is: " <<
        std::fixed << std::setprecision(5) << (float)time/CLOCKS_PER_SEC 
        << " seconds" << endl;

        return 0;
}

int getFactorial(int num) {
        if(num > 1) {
                return num * getFactorial(num - 1);
        }
        else {
                return 1;
        }
}

