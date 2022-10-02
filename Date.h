#ifndef DATE_H_
#include <string>

class Date{

private:
  int day   = {1};
  int month = {1};
  int year  = {2021};

public:
    Date();
    Date(int, int, int);
    bool setDay(int);
    bool setMonth(int);
    bool setYear(int);
    int getDay();
    int getMonth();
    int getYear();
    std::string showDate();
};


#endif
