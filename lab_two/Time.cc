#include "Time.h"


bool is_valid(Time const& time){
    return (time.hh < 24 && time.hh >= 0 && 
    time.ss < 60 && time.ss >= 0 &&
    time.mm < 60 && time.mm >= 0);
}

bool is_am(Time const& time){
    bool is_morning{false};
    if (is_valid(time)){
        if (time.hh < 12){
            is_morning = true;
        }
    }
    return is_morning;
}

int number_mod(int const& num_one, int const& num_two){
    int qoutient = num_one/num_two;
    // quotent * divisor + remainder
    return num_one - (qoutient * num_two);
}

void validate_secs_add(Time& time){
    if (time.ss > 59){
        int minutes = time.ss/60;
        time.ss = number_mod(time.ss,60);
        time.mm = time.mm + minutes;
        if(time.mm > 59){
            int hour = time.mm/60;
            time.mm = number_mod(time.mm,60);
            time.hh = time.hh + hour;
            if(time.hh > 23){
                time.hh = number_mod(time.hh, 24);
            }
        }
    }
}

void validate_secs_sub(Time& time){
    if (time.ss < 0){
        int minutes = std::abs(time.ss/60);
        time.ss = number_mod(time.ss,60);
        time.mm = time.mm - minutes;
        if(time.mm < 0){
            int hour = std::abs(time.mm/60);
            time.mm = number_mod(time.mm,60);
            time.hh = time.hh - hour;
            if(time.hh < 0){
                time.hh = number_mod(time.hh, 24);
            }
        }
    }
}

// string manipulation functions 
std::string get_digit_string(int const& x){

    std::string string_num{};
    if (x < 10){
        string_num += "0";
    }
    string_num += std::to_string(x);
    return string_num;

}

std::string get_twelve_hour_time(Time const& time){
    // std::string time_string{};
    std::stringstream ss{};
    ss << std::setfill('0');
    if (is_am(time)){
        ss << std::setw(2) << time.hh;
        if(time.hh == 0){
            ss.str("");
            ss << 12;
        }
        ss << ":" << std::setw(2) << time.mm << ":" << std::setw(2) << time.ss << " am";
    }else{
        int hour = number_mod(time.hh,12);
        if (hour == 0){
            hour = 12;
        }
        ss << std::setw(2) << hour << ":" << std::setw(2) << time.mm << ":" << std::setw(2) << time.ss << " pm";
    }
    return ss.str();
}

std::string get_twenty_four_hour_time(Time const& time){
    std::stringstream ss{};
    ss << std::setfill('0');
    ss << std::setw(2) << time.hh << ":" << std::setw(2) << time.mm << ":" << std::setw(2) << time.ss;
    return ss.str();
}
std::string to_string(Time const& time, bool is_twelve_hours){
    // prints an empty string if the time is not valid
    std::string time_string{};
    if (is_valid(time)){
        time_string = get_twenty_four_hour_time(time);
        if (is_twelve_hours){
            time_string = get_twelve_hour_time(time);
        }
    }
    return time_string;
}

bool operator ==(Time const& time_one, Time const& time_two){
    return (time_one.hh == time_two.hh &&
            time_one.mm == time_two.mm &&
            time_one.ss == time_two.ss);
}

bool operator >(Time const& time_one, Time const& time_two){
    bool is_greater = false;
    if (time_one.hh > time_two.hh){
        is_greater = true;
    }

    if (time_one.hh == time_two.hh){
        if(time_one.mm > time_two.mm){
            is_greater = true;
        }
        if(time_one.mm == time_two.mm){
            if(time_one.ss > time_two.ss){
                is_greater = true;
            }
        }
    }
    return is_greater;
}

bool operator <(Time const& time_one, Time const& time_two){
    bool is_less = false;
    if (time_one.hh < time_two.hh){
        is_less = true;
    }

    if (time_one.hh == time_two.hh){
        if(time_one.mm < time_two.mm){
            is_less = true;
        }
        if(time_one.mm == time_two.mm){
            if(time_one.ss < time_two.ss){
                is_less = true;
            }
        }
    }

    return is_less;
}

bool operator !=(Time const& time_one, Time const& time_two){
    return !(time_one == time_two);
}

bool operator >=(Time const& time_one, Time const& time_two){
    return !(time_one < time_two);
}

bool operator <=(Time const& time_one, Time const& time_two){
    return !(time_one > time_two);
}

Time operator +(Time const& time_one, int const& secs){
    Time t1{time_one.hh,time_one.mm,time_one.ss};
    t1.ss += secs;
    validate_secs_add(t1);
    return t1;
}
Time operator -(Time const& time_one, int const& secs){
    Time t1{time_one.hh,time_one.mm,time_one.ss};
    t1.ss -= secs;
    validate_secs_sub(t1);
    return t1;
}

Time operator ++(Time& time_one){
    ++time_one.ss;
    validate_secs_add(time_one);
    return time_one;
}
Time operator ++(Time& time_one,int){
    Time old_time{time_one.hh,time_one.mm,time_one.ss};
    time_one.ss++;
    validate_secs_add(time_one);
    return old_time;
}
Time operator --(Time& time_one){
    --time_one.ss;
    validate_secs_sub(time_one);
    return time_one;
}
Time operator --(Time& time_one,int){
    Time old_time{time_one.hh,time_one.mm,time_one.ss};
    time_one.ss--;
    validate_secs_sub(time_one);
    return old_time;
}

std::ostream& operator<<(std::ostream& os, Time const& time){
    os << std::setfill('0');
    os << std::setw(2) <<time.hh << ":" << std::setw(2) << time.mm << ":"  << std::setw(2) << time.ss;
    return os;
}

std::istream& operator>>(std::istream& is, Time& time) {
    std::cout << "Enter valid time: " << std::flush;
    is >> time.hh;
    is.ignore(1000,':');
    is >> time.mm;
    is.ignore(1000,':');
    is >> time.ss;
    is.ignore(1000,'\n');
    if (!is_valid(time)){
        is.setstate(std::ios_base::failbit);
    }

    if (is.fail()){
        std::cout << "You entered an invlaid date" << std::endl;
        is.clear();
    }
    return is;
}