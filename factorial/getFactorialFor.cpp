#include <iostream>
#include <iomanip>

using namespace std;
int getFactorial () {
        int num;
        int result = 1;
        cout << "Please enter the number ";
        cin >> num;
        if (num == 0 || num == 1){
                cout << "The number " << num << " dont have any factorials\n";
                return 1;
        }
        for(int i = 1; i <= num; i++){
                result = result * i;
        }
        
        cout << "The " << num << " factorial is " << result;
        return result;
}
int main () {
        clock_t time;
        time = clock();
        getFactorial();
        time = clock() - time;
        cout << "\nThe time that the computer needs to solve the problem is: "
        << std::fixed << std::setprecision(5) << (float)time/CLOCKS_PER_SEC
        << " seconds" << endl;
}
