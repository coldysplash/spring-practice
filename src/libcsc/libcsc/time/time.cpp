#include <libcsc/time/time.hpp>

#include <iostream>

namespace times {

Time operator+(const Time &lhs, const TimeSpan &rhs) {
  return lhs.get_time() + rhs.get_spantime();
}

Time operator-(const Time &lhs, const TimeSpan &rhs) {
  return lhs.get_time() - rhs.get_spantime();
}

TimeSpan operator+(const TimeSpan &lhs, const TimeSpan &rhs) {
  return lhs.get_spantime() + rhs.get_spantime();
}

TimeSpan operator-(const TimeSpan &lhs, const TimeSpan &rhs) {
  return lhs.get_spantime() - rhs.get_spantime();
}

TimeSpan operator-(const Time &lhs, const Time &rhs) {
  return static_cast<long int>(lhs.get_time() - rhs.get_time());
}

std::ostream &operator<<(std::ostream &os, const Time &t) {
  const size_t all_secs = t.get_time();
  const size_t days = all_secs / static_cast<size_t>((24 * 3600));
  const size_t hours = (all_secs / 3600) - (days * 24);
  const size_t minutes = (all_secs % 3600) / 60;
  const size_t seconds = all_secs % 60;

  return os << days << "d " << hours << "h " << minutes << "m " << seconds
            << "s\n";
}

/* comparison operators for class Time */
bool operator==(const Time &lhs, const Time &rhs) {
  return lhs.get_time() == rhs.get_time();
}
bool operator!=(const Time &lhs, const Time &rhs) {
  return lhs.get_time() != rhs.get_time();
}
bool operator<(const Time &lhs, const Time &rhs) {
  return lhs.get_time() < rhs.get_time();
}
bool operator>(const Time &lhs, const Time &rhs) {
  return lhs.get_time() > rhs.get_time();
}
bool operator<=(const Time &lhs, const Time &rhs) {
  return lhs.get_time() <= rhs.get_time();
}
bool operator>=(const Time &lhs, const Time &rhs) {
  return lhs.get_time() >= rhs.get_time();
}

/* comparison operators for class TimeSpan */
bool operator==(const TimeSpan &lhs, const TimeSpan &rhs) {
  return lhs.get_spantime() == rhs.get_spantime();
}
bool operator!=(const TimeSpan &lhs, const TimeSpan &rhs) {
  return lhs.get_spantime() != rhs.get_spantime();
}
bool operator<(const TimeSpan &lhs, const TimeSpan &rhs) {
  return lhs.get_spantime() < rhs.get_spantime();
}
bool operator>(const TimeSpan &lhs, const TimeSpan &rhs) {
  return lhs.get_spantime() > rhs.get_spantime();
}
bool operator<=(const TimeSpan &lhs, const TimeSpan &rhs) {
  return lhs.get_spantime() <= rhs.get_spantime();
}
bool operator>=(const TimeSpan &lhs, const TimeSpan &rhs) {
  return lhs.get_spantime() >= rhs.get_spantime();
}

namespace literals {

Time operator"" _d(unsigned long long days) { return {days * 24 * 3600}; }
Time operator"" _h(unsigned long long hours) { return {hours * 3600}; }
Time operator"" _m(unsigned long long minutes) { return {minutes * 60}; }
Time operator"" _s(unsigned long long seconds) { return {seconds}; }

} // namespace literals

} // namespace times