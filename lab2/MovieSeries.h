#pragma once
#include "Movie.h"

class MovieSeries {
private:
    Movie* movies_[16];
    int count_;

public:
    MovieSeries();

    void init();

    bool add(Movie* m);

    void print() const;

    void sort();
};
