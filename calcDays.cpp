#include "Date.h"

//#include "calcDays.h"
#include <string>
#include <iostream>

using namespace std;

int calcDays(){
  return 0;
}
int calcDays(Date &a){
  return 5;
}

int calcDays(Date &a, Date &b){

  int dayDiff1;
  int dayDiff2;

  int localDay1   = a.getDay();
  int localMonth1 = a.getMonth();
  int localYear1  = a.getYear();

  int localDay2   = b.getDay();
  int localMonth2 = b.getMonth();
  int localYear2  = b.getYear();

  int monthsYear [13] = {0, 31, 28, 31, 30,
                            31, 30, 31, 30,
                            30, 31, 30, 31};


  if (localYear1 == localYear2){
    for (int i = 1; i < localMonth1; i++){

        dayDiff1 += monthsYear[localMonth1 - 1];
      }

      dayDiff1 += localDay1;



    for (int i = 1; i < localMonth2; i++){

        dayDiff2 += monthsYear[localMonth2 - 1];
    }

      dayDiff2 += localDay2;

      return dayDiff2 - dayDiff1;
  }else{
    for (int i = 1; i < localMonth1; i++){

        dayDiff1 += monthsYear[localMonth1 - 1];
      }

      dayDiff1 += localDay1;



    for (int i = 1; i < localMonth2; i++){

        dayDiff2 += monthsYear[localMonth2 - 1];
    }

      dayDiff2 += localDay2;

    if (localYear2 > 2021){
      dayDiff2 += 365;
    }

    if (localYear1 > 2021){
      dayDiff1 += 365;
    }
    return dayDiff2 - dayDiff1;
}
}
