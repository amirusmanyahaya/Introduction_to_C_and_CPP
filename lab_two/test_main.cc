#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Time.h"
#include <iostream>


TEST_CASE("Tesing Time Validation"){
    Time t1{10,45,50};
    Time t2{24,59,59};
    Time t3{-1,-1,-1};
    Time t4{0,0,0};
    Time t5{23,59,59};
    CHECK(is_valid(t1) == true);
    CHECK(is_valid(t2) == false);
    CHECK(is_valid(t3) == false);
    CHECK(is_valid(t4) == true);
    CHECK(is_valid(t5) == true);
}

TEST_CASE("Tesing is_am"){
    Time t1{10,45,50};
    Time t2{24,59,59};
    Time t3{-1,-1,-1};
    Time t4{0,0,0};
    Time t5{23,59,59};
    CHECK(is_am(t1) == true);
    CHECK(is_am(t2) == false);
    CHECK(is_am(t3) == false);
    CHECK(is_am(t4) == true);
    CHECK(is_am(t5) == false);
}

TEST_CASE("Tesing to_string"){
    Time t1{10,45,50};
    Time t2{24,59,59};
    Time t3{-1,-1,-1};
    Time t4{0,0,0};
    Time t5{23,59,59};
    CHECK(to_string(t1,true) == "10:45:50 am");
    CHECK(to_string(t2,true) == "");
    CHECK(to_string(t2) == "");
    CHECK(to_string(t3) == "");
    CHECK(to_string(t3, true) == "");
    CHECK(to_string(t4,true) == "12:00:00 am");
    CHECK(to_string(t4) == "00:00:00");
    CHECK(to_string(t5,true) == "11:59:59 pm");
    CHECK(to_string(t5) == "23:59:59");
}

TEST_CASE("Comparison Operators"){

    Time t1{00,00,00};
    Time t2{23,59,59};
    CHECK(t1 == t1);
    CHECK(t1 != t2);
    Time t3 = t1 + 1000;
    CHECK(t3 > t1);
    CHECK(t1 < t3);
    CHECK(t1 <= t3);
    CHECK(t3 >= t1);
    Time t4 = t3 - 1000;
    CHECK(t4 == t1);

}

TEST_CASE("Increment and decrement"){
    Time t1{23,59,59};
    Time t2{};
    CHECK(++t1 == t2);
    CHECK(--t1 == --t2);
    CHECK(t1++ != ++t2);
    CHECK(t1 == t2);
    CHECK(t1-- != --t2);
    Time t3{};
    std::cin >> t3;

}

