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
  const long int all_secs = t.get_time();
  const long int days = all_secs / static_cast<long>(24 * 3600);
  const long int hours = (all_secs / 3600) - (days * 24);
  const long int minutes = (all_secs % 3600) / 60;
  const long int seconds = all_secs % 60;

  return os << days << "d " << hours << "h " << minutes << "m " << seconds
            << "s\n";
}

/* comparison operators for class Time */
bool operator==(const Time &lhs, const Time &rhs) noexcept {
  return lhs.get_time() == rhs.get_time();
}
bool operator<(const Time &lhs, const Time &rhs) noexcept {
  return lhs.get_time() < rhs.get_time();
}
bool operator!=(const Time &lhs, const Time &rhs) noexcept {
  return !(lhs == rhs);
}
bool operator>(const Time &lhs, const Time &rhs) noexcept {
  return (rhs < lhs);
}
bool operator<=(const Time &lhs, const Time &rhs) noexcept {
  return !(rhs < lhs);
}
bool operator>=(const Time &lhs, const Time &rhs) noexcept {
  return !(lhs < rhs);
}

/* comparison operators for class TimeSpan */
bool operator==(const TimeSpan &lhs, const TimeSpan &rhs) noexcept {
  return lhs.get_spantime() == rhs.get_spantime();
}
bool operator<(const TimeSpan &lhs, const TimeSpan &rhs) noexcept {
  return lhs.get_spantime() < rhs.get_spantime();
}
bool operator!=(const TimeSpan &lhs, const TimeSpan &rhs) noexcept {
  return !(lhs == rhs);
}
bool operator>(const TimeSpan &lhs, const TimeSpan &rhs) noexcept {
  return (rhs < lhs);
}
bool operator<=(const TimeSpan &lhs, const TimeSpan &rhs) noexcept {
  return !(rhs < lhs);
}
bool operator>=(const TimeSpan &lhs, const TimeSpan &rhs) noexcept {
  return !(lhs < rhs);
}

namespace literals {

Time operator"" _d(unsigned long long days) {
  return {static_cast<long>(days * 24 * 3600)};
}
Time operator"" _h(unsigned long long hours) {
  return {static_cast<long>(hours * 3600)};
}
Time operator"" _m(unsigned long long minutes) {
  return {static_cast<long>(minutes * 60)};
}
Time operator"" _s(unsigned long long seconds) {
  return {static_cast<long>(seconds)};
}

} // namespace literals

} // namespace times