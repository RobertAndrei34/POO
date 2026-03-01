#pragma once
#include <cstddef>

class Movie {
private:
    char name_[257]; 
    int year_;
    double score_;  
    int length_;      

public:
    Movie();

    bool set_name(const char* name);
    const char* get_name() const;

    bool set_year(int year);
    int get_year() const;
    bool set_score(double score);
    double get_score() const;

    bool set_length(int minutes);
    int get_length() const;

    int get_passed_years() const;
};
