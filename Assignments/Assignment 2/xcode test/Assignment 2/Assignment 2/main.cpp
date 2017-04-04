/*
*
*   (c) 2017 John Keller
*
*/

#include <iostream>

using namespace std;


/*
 Function: calculatePopulation
 -----------------------------
 input: void
 output: void
 operations: Calculates a projected population
 */
void calculatePopulation(void)
{
    // Define the various rates (in seconds)
    int birthRate = 2;
    int deathRate = 7;
    int immRate = 24;
    
    int population = 318933342;
    int numberOfDays = 365;
    
    int finalPopulation = population + ((birthRate+immRate) * 60 * 24 * numberOfDays) - (deathRate * 60 * 24 * numberOfDays);
    
    cout << "The population is " << finalPopulation << "." << endl;
    
    return;
}


/*
 Function: secondsToTime
 -----------------------------
 input: void
 output: void
 operations: converts user-entered seconds to 24-hr time
 */
void secondsToTime(void)
{
    int input = 0;
    cout << "Enter seconds between 0 and 86400: ";
    cin >> input;
    
    if (input >= 0 && input <= 86400)
    {
        // Now to break out into hours minutes and seconds
        int hours = input / 60 / 60;
        int minutes = (input - (hours*60*60)) / 60;
        int seconds = input - (hours*60*60) - (minutes*60);
        
        cout << "The time is " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds." << endl;
    }
    else
    {
        cout << "Error, try again." << endl;
    }
    
    return;
}


/*
 Function: celsiusToFahrenheit
 -----------------------------
 input: void
 output: void
 operations: converts user-entered Fahrenheit value to Celsius
 */
void celsiusToFahrenheit(void)
{
    int celsius = 0;
    int fahrenheit = 0;
    
    cout << "Enter a temperature in celsius: ";
    cin >> celsius;
    
    fahrenheit = (celsius * 9 / 5) + 32;
    
    cout << celsius << " degrees in Celsius is " << fahrenheit << " degrees in Fahrenheit." << endl;
    
    return;
}

int main(void)
{
    // Problem 1
    calculatePopulation();
    
    // Problem 2
    secondsToTime();
    
    // Problem 3
    celsiusToFahrenheit();
    
    return 0;
}
