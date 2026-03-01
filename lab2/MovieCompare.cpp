#include "MovieCompare.h"
#include <cstring>

static int cmp_int(int x, int y) {
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

static int cmp_double(double x, double y) {
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int movie_compare_name(const Movie& a, const Movie& b) {
    int r = std::strcmp(a.get_name(), b.get_name());
    if (r < 0) return -1;
    if (r > 0) return 1;
    return 0;
}

int movie_compare_year(const Movie& a, const Movie& b) {
    return cmp_int(a.get_year(), b.get_year());
}

int movie_compare_score(const Movie& a, const Movie& b) {
    return cmp_double(a.get_score(), b.get_score());
}

int movie_compare_length(const Movie& a, const Movie& b) {
    return cmp_int(a.get_length(), b.get_length());
}

int movie_compare_passed_years(const Movie& a, const Movie& b) {
    return cmp_int(a.get_passed_years(), b.get_passed_years());
}
