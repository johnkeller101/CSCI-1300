//
//  Name            John Keller
//  Recitation TA   Jason Zietz
//  Assignment #    3
//  Problem #       2
//

#include <iostream>

using namespace std;

void printEnergy(double A, double r, double H, double PR);
double energyCalculator(double A, double r, double H, double PR);
int calculateNumberHousesSupported(double array_avg,double household_avg);

int main() {
    // Declare variables
    double A = 0;
    double H = 0;
    double average = 0;
    // Predefined variables:
    double r = 0.10;
    double PR = 0.75;
    
    // Retrieve the inputs for A and H
    cout << "A: ";
    cin >> A;
    cout << "H: ";
    cin >> H;
    
    // Part A
    double calculated_energy = energyCalculator(A, r, H, PR);
    cout << "The average annual solar energy production is " << calculated_energy << "kWh." << endl;
    
    // Part C
    cout << "Enter household average: ";
    cin >> average;
    cout << calculateNumberHousesSupported(calculated_energy,average) << " houses can be supported." << endl;
    
    // Part B
    while (r < 0.36) {
        printEnergy(A, r, H, PR);
        r = r + 0.05; // Add 0.05 to the previous r value
    }
}

void printEnergy(double A, double r, double H, double PR) {
    // Prints a human-readable version of the calculated energy data
    cout << "The average annual solar energy for an efficiency of " <<  r << " is " <<  energyCalculator(A, r, H, PR)  << " kWh." << endl;
}

double energyCalculator(double A, double r, double H, double PR){
    /* Calculates energy data using the equation E = A * r * H * PR
     *  A is area of the solar array in meter square
     *  r is the solar panel efficiency in percentage
     *  H is the average solar radiation in kWh/m^2/year PR is the performance ratio (coefficient of loss)
     *      - usually between 0.5 and 0.9, with a default of 0.75
     */
    return A * r * H * PR;
}

int calculateNumberHousesSupported(double array_avg, double household_avg) {
    // Perform calculations and return values
    int number_of_houses = array_avg / household_avg;
    return number_of_houses;
}
