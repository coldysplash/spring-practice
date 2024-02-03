#include <libcsc/time/time.hpp>

#include <iostream>

namespace times {

Time operator+(Time ltime, TimeSpan rtime) {
  return ltime.get_time() + rtime.get_spantime();
}

Time operator-(Time ltime, TimeSpan rtime) {
  return ltime.get_time() - rtime.get_spantime();
}

TimeSpan operator+(TimeSpan ltime, TimeSpan rtime) {
  return ltime.get_spantime() + rtime.get_spantime();
}

TimeSpan operator-(TimeSpan ltime, TimeSpan rtime) {
  return ltime.get_spantime() - rtime.get_spantime();
}

TimeSpan operator-(Time ltime, Time rtime) {
  return static_cast<long int>(ltime.get_time() - rtime.get_time());
}

std::ostream &operator<<(std::ostream &os, const Time &t) {
  const size_t all_secs = t.get_time();
  const size_t days = all_secs / static_cast<size_t>((24 * 60 * 60));
  const size_t hours = all_secs / 3600;
  const size_t minutes = (all_secs % 3600) / 60;
  const size_t seconds = all_secs % 60;

  return os << days << "d " << hours << "h " << minutes << "m " << seconds
            << "s\n";
}

} // namespace times