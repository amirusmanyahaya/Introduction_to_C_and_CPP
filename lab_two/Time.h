#ifndef TIME_H
#define TIME_H
#include <string>
#include <cmath>
#include <iostream>
#include <iomanip>
struct Time {
    int hh{};
    int mm{};
    int ss{};
};

bool is_valid(Time const& time);
bool is_am(Time const& time);
int number_mod(int const& num_one, int const& num_two);
void add_secs(Time const& time, int const& secs);
Time subtract_secs(Time const& time, int const& secs);
std::string to_string(Time const& time, bool is_twelve_hours = false);
std::string get_digit_string(int const& x);
std::string get_twelve_hour_time(Time const& time);
std::string get_twenty_four_hour_time(Time const& time);
bool operator ==(Time const& time_one, Time const& time_two);
bool operator >(Time const& time_one, Time const& time_two);
bool operator <(Time const& time_one, Time const& time_two);
bool operator !=(Time const& time_one, Time const& time_two);
bool operator >=(Time const& time_one, Time const& time_two);
bool operator <=(Time const& time_one, Time const& time_two);
Time operator +(Time const& time_one, int const& secs);
Time operator -(Time const& time_one, int const& secs);
Time operator ++(Time& time_one);
Time operator ++(Time& time_one,int);
std::ostream& operator<<(std::ostream& os, Time const& time);
std::istream& operator>>(std::istream& is, Time& time);
Time operator --(Time& time_one);
Time operator --(Time& time_one,int);


#endif