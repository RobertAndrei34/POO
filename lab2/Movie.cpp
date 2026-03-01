#include "Movie.h"
#include <cstring>
#include <chrono>
#include <ctime>

Movie::Movie() : year_(0), score_(1.0), length_(0) {
    name_[0] = '\0';
}

bool Movie::set_name(const char* name) {
    if (!name) return false;

    std::size_t n = std::strlen(name);
    if (n > 256) return false;

    std::strcpy(name_, name);
    return true;
}

const char* Movie::get_name() const {
    return name_;
}

bool Movie::set_year(int year) {
   
    if (year < 1878) return false;
    year_ = year;
    return true;
}

int Movie::get_year() const {
    return year_;
}

bool Movie::set_score(double score) {
    if (score < 1.0 || score > 10.0) return false;
    score_ = score;
    return true;
}

double Movie::get_score() const {
    return score_;
}

bool Movie::set_length(int minutes) {
    if (minutes < 0) return false;
    length_ = minutes;
    return true;
}

int Movie::get_length() const {
    return length_;
}

int Movie::get_passed_years() const {
    using namespace std::chrono;

    auto now = system_clock::now();
    std::time_t t = system_clock::to_time_t(now);

    std::tm local_tm{};
#if defined(_MSC_VER)
    localtime_s(&local_tm, &t);
#else
    local_tm = *std::localtime(&t);
#endif

    int current_year = local_tm.tm_year + 1900;

    if (year_ <= 0) return 0;
    int diff = current_year - year_;
    return (diff < 0) ? 0 : diff;
}
