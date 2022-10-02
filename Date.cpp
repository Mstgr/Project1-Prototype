#include "Date.h"
#include <string>
#include <iostream> // delete later

using namespace std;
// default date
Date::Date(){
  day = 1;
  month = 1;
  year = 2021;
}

// set users date
Date::Date(int d, int m, int y) : day (d), month (m), year(y) {

  if (setDay(d)){
    if (setMonth(m)){
      if (setYear(y)){}
    }
  }
  else{
    Date();
  }
}


bool Date::setDay(int d){

  if (d >= 1 && d <=31){
    day = d;
    return true;
  }
  else
    return false;

}

bool Date::setMonth(int m){

  if (m >= 1 && m <= 12){
    if (day > 28 && m == 2){
      return false;
    }else{
      month = m;
      return true;
    }
  }
  else
    return false;
}

bool Date::setYear(int y){

  if (y == 2021 || y == 2022){
    year = y;
    return true;
  }
  else
    return false;
}

int Date::getDay(){
  return day;
}

int Date::getMonth(){
  return month;
}

int Date::getYear(){
  return year;
}


string Date::showDate(){
  string slash = "/";
  string zero = "0";
  string outDay = to_string(day);
  string outMonth = to_string(month);
  string outYear = to_string(year);
  string outDate;

  if (day > 9 && month > 9){
    outDate = outMonth + slash + outDay + slash + outYear;
  }
  else if (month < 10){
    outDate = zero + outMonth + slash + outDay + slash + outYear;
  }
  else if (day < 10){
    outDate = outMonth + slash + zero + outDay + slash + outYear;
  }
  else if (day < 10 && month < 10){
    outDate = zero + outMonth + slash + zero + outDay + slash + outYear;
  }
  return outDate;
}
