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

Time operator+(Time ltime, TimeSpan rtime);
Time operator-(Time ltime, TimeSpan rtime);

TimeSpan operator+(TimeSpan ltime, TimeSpan rtime);
TimeSpan operator-(TimeSpan ltime, TimeSpan rtime);
TimeSpan operator-(Time ltime, Time rtime);

std::ostream &operator<<(std::ostream &os, const Time &t);

} // namespace times