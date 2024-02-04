#pragma once
#include <iosfwd>

namespace times {

class Time {
private:
  size_t seconds_;

public:
  Time(size_t seconds = 0) : seconds_(seconds) {}
  size_t get_time() const { return seconds_; };
};

class TimeSpan {
private:
  long int span_seconds_;

public:
  TimeSpan(long int seconds = 0) : span_seconds_(seconds) {}
  long int get_spantime() const { return span_seconds_; };
};

Time operator+(const Time &lhs, const TimeSpan &rhs);
Time operator-(const Time &lhs, const TimeSpan &rhs);

TimeSpan operator+(const TimeSpan &lhs, const TimeSpan &rhs);
TimeSpan operator-(const TimeSpan &lhs, const TimeSpan &rhs);
TimeSpan operator-(const Time &lhs, const Time &rhs);

std::ostream &operator<<(std::ostream &os, const Time &t);

bool operator==(const Time &lhs, const Time &rhs);
bool operator!=(const Time &lhs, const Time &rhs);
bool operator<(const Time &lhs, const Time &rhs);
bool operator>(const Time &lhs, const Time &rhs);
bool operator<=(const Time &lhs, const Time &rhs);
bool operator>=(const Time &lhs, const Time &rhs);

bool operator==(const TimeSpan &lhs, const TimeSpan &rhs);
bool operator!=(const TimeSpan &lhs, const TimeSpan &rhs);
bool operator<(const TimeSpan &lhs, const TimeSpan &rhs);
bool operator>(const TimeSpan &lhs, const TimeSpan &rhs);
bool operator<=(const TimeSpan &lhs, const TimeSpan &rhs);
bool operator>=(const TimeSpan &lhs, const TimeSpan &rhs);

namespace literals {

Time operator"" _d(unsigned long long days);
Time operator"" _h(unsigned long long hours);
Time operator"" _m(unsigned long long minutes);
Time operator"" _s(unsigned long long seconds);

} // namespace literals

} // namespace times