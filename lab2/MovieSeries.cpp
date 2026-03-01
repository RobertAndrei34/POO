#include "MovieSeries.h"
#include <cstdio>

MovieSeries::MovieSeries() : count_(0) {
    for (int i = 0; i < 16; i++) movies_[i] = nullptr;
}

void MovieSeries::init() {
    count_ = 0;
    for (int i = 0; i < 16; i++) movies_[i] = nullptr;
}

bool MovieSeries::add(Movie* m) {
    if (!m) return false;
    if (count_ >= 16) return false;
    movies_[count_++] = m;
    return true;
}

void MovieSeries::print() const {
    for (int i = 0; i < count_; i++) {
        const Movie* m = movies_[i];
        if (!m) continue;
        std::printf(
            "%s | year=%d | score=%.1f | length=%d | passed_years=%d\n",
            m->get_name(),
            m->get_year(),
            m->get_score(),
            m->get_length(),
            m->get_passed_years()
        );
    }
}

void MovieSeries::sort() {
  
    for (int i = 0; i < count_ - 1; i++) {
        for (int j = 0; j < count_ - 1 - i; j++) {
            int py1 = movies_[j]->get_passed_years();
            int py2 = movies_[j + 1]->get_passed_years();
            if (py1 < py2) {
                Movie* tmp = movies_[j];
                movies_[j] = movies_[j + 1];
                movies_[j + 1] = tmp;
            }
        }
    }
}
