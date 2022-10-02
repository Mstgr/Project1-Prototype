

// Michael Steiger
#include <iostream>
#include <string>
#include "Date.h"
#include "calcDays.h"

using namespace std;

int main (){

  bool flag;
  char testResult;
  char testExposed;
  char secondDose;
  int dayTested;
  int monthTested;
  int yearTested;
  int dayExposed;
  int monthExposed;
  int yearExposed;
  string finalDate;


  Date date1;
  Date date2;
  Date datePositive, dateExposed, dateSecondDose;

  cout << "Please enter Test result? (P/N): ";
  cin >> testResult;
  while (testResult != 'P' && testResult != 'N'){
    cout << "Invalid input. Please enter P or N: ";
    cin >> testResult;
  }

  switch (testResult){

    // if positive
    case 'P':
      // Enter the day
      cout << "Enter the DAY you tested positive: ";
      cin >> dayTested;
      flag = datePositive.setDay(dayTested);
      while (flag == false){
        cout << "Invalid input. Please enter a valid input: ";
        cin >> dayTested;
        flag = datePositive.setDay(dayTested);
      }
      flag = false;

      // Enter the month
      cout << "Enter the MONTH you tested positive: ";
      cin >> monthTested;
      flag = datePositive.setMonth(monthTested);
      while (flag == false){
        cout << "Invalid input. Please enter a valid input: ";
        flag = datePositive.setMonth(monthTested);
      }
      flag = false;

      // Enter the year
      cout << "Enter the YEAR you tested positive: ";
      cin >> yearTested;
      flag = datePositive.setYear(yearTested);
      while (flag == false){
        cout << "Invalid input. Please enter a valid input: ";
        flag = datePositive.setYear(yearTested);
      }
      flag = false;

      cout << "Length of isolation: " << calcDays(datePositive) << " days" << endl;
      break;
    // done with case 1 positive

    // Exposed to positive case ??
    case 'N':
      cout << "Exposed to positive case (Y/N): ";
      cin >> testExposed;

      while (testExposed != 'Y' && testExposed != 'N'){
        cout << "Invalid input. Please enter Y or N: ";
        cin >> testExposed;
      }

      // if no (case 2)
      if (testExposed == 'N'){
        cout << "Length of isolation: " << calcDays() << " days" << endl;
      }

      // if yes
      else if (testExposed == 'Y'){
        // Enter day
        cout << "Enter the DAY exposed to positive case: ";
        cin >> dayExposed;
        flag = dateExposed.setDay(dayExposed);
        while (flag == false){
          cout << "Invalid input. Please enter a valid input: ";
          cin >> dayExposed;
          flag = dateExposed.setDay(dayExposed);
        }
        flag = false;

        // Enter the month
        cout << "Enter the MONTH exposed to positive case: ";
        cin >> monthExposed;
        flag = dateExposed.setMonth(monthExposed);
        while (flag == false){
          cout << "Invalid input. Please enter a valid input: ";
          flag = dateExposed.setMonth(monthExposed);
        }
        flag = false;

        // Enter the year
        cout << "Enter the YEAR exposed to positive case: ";
        cin >> yearExposed;
        flag = dateExposed.setYear(yearExposed);
        while (flag == false){
          cout << "Invalid input. Please enter a valid input: ";
          flag = dateExposed.setYear(yearExposed);
        }
        flag = false;

        cout << "Second vaccination dose received (Y/N): ";
        cin >> secondDose;

        while (secondDose != 'Y' && secondDose != 'N'){
          cout << "Invalid input. Please enter Y or N: ";
          cin >> secondDose;
        }
        // second dose????
        // NO SECOND DOSE if no (case 4.2)
        if (secondDose == 'N'){

          cout << "Vaccination status at time of exposure: not fully vaccinated" << endl;
          cout << "Length of isolation: " << calcDays() << endl;
        }
        //END SECOND DOSE
        // else meaning secondDose YES case 3 & 4.1
        else {
          //enter second dose date
          cout << "Enter the DAY of second dose: ";
          cin >> dayExposed;
          flag = dateSecondDose.setDay(dayExposed);
          while (flag == false){
            cout << "Invalid input. Please enter a valid input: ";
            cin >> dayExposed;
            flag = dateSecondDose.setDay(dayExposed);
          }
          flag = false;

          // Enter the month
          cout << "Enter the MONTH of second dose: ";
          cin >> monthExposed;
          flag = dateSecondDose.setMonth(monthExposed);
          while (flag == false){
            cout << "Invalid input. Please enter a valid input: ";
            flag = dateSecondDose.setMonth(monthExposed);
          }
          flag = false;

          // Enter the year
          cout << "Enter the YEAR of second dose: ";
          cin >> yearExposed;
          flag = dateSecondDose.setYear(yearExposed);
          while (flag == false){
            cout << "Invalid input. Please enter a valid input: ";
            flag = dateSecondDose.setYear(yearExposed);
          }
          flag = false;

          // END OF INPUT OF SECOND dose
          // NOW DETERMINE IF SECOND DOSE HAS BEEN GIVEN
          // AT LEAST 2 WEEKS AGO

            if (calcDays(dateExposed , dateSecondDose) <= 14){
                cout << "Vaccination status at time of exposure: not fully vaccinated" << endl;
                cout << "Length of isolation: 10 days" << endl;
            // IF IT HAS NOT BEEN GIVEN 2 WEEKS AGO
            // they aint fully vaccinated
            }else{
              cout << "Vaccination status at time of exposure: fully vaccinated" << endl;
              cout << "Length of isolation: 5 days" << endl;

            }

        }

      }
      break;
  }
  return 0;
}
