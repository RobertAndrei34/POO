#pragma once
#include <cstddef>

class Movie {
private:
    char name_[257];   // max 256 chars + '\0'
    int year_;
    double score_;     // 1..10
    int length_;       // minutes

public:
    Movie();

    // name (max 256 characters)
    bool set_name(const char* name);
    const char* get_name() const;

    // release year
    bool set_year(int year);
    int get_year() const;

    // IMDB score (1..10)
    bool set_score(double score);
    double get_score() const;

    // length in minutes
    bool set_length(int minutes);
    int get_length() const;

    // number of passed years since release (computed on each call)
    int get_passed_years() const;
};
