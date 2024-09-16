#include <iostream>
using namespace std;

class TollBooth {
private:
    unsigned int totalCars;       
    unsigned int payingCars;       
    unsigned int nonPayingCars;    
    double totalMoney;             

public:

    TollBooth() {
        totalCars = 0;
        payingCars = 0;
        nonPayingCars = 0;
        totalMoney = 0.0;
    }

    void payingCar() {
        totalCars++;
        payingCars++;
        totalMoney += 0.50;
    }

    void nopayCar() {
        totalCars++;
        nonPayingCars++;
    }

    void printOnConsole() const {
        cout << "Total cars passed: " << totalCars << endl;
        cout << "Total paying cars: " << payingCars << endl;
        cout << "Total non-paying cars: " << nonPayingCars << endl;
        cout << "Total money collected: $" << totalMoney << endl;
    }
};

int main() {
    TollBooth tollbooth; 

    tollbooth.payingCar();
    tollbooth.nopayCar();
    tollbooth.payingCar();
    tollbooth.payingCar();
    tollbooth.payingCar();
    tollbooth.nopayCar();
    tollbooth.payingCar();

    tollbooth.printOnConsole();

    return 0;
}