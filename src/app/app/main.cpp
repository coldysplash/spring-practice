#include <iostream>
#include <libcsc/time/time.hpp>

int main() {

  // const times::Time time_run_1 = 520;
  // const times::TimeSpan time_run_2 = 220;

  // const times::Time t_r = time_run_1 + time_run_2;

  // std::cout << t_r.get_time() << '\n';

  // const times::Time t = 12000;

  // std::cout << t;

  // const times::Time t_1 = 250;
  // const times::Time t_2 = 200;

  // const bool res = t_1 == t_2;
  // std::cout << res << '\n';

  using namespace times::literals;

  const auto t_d = 20_d;
  const auto t_h = 20_h;
  const auto t_m = 20_m;
  const auto t_s = 20_s;

  std::cout << t_d << '\n';
  std::cout << t_h << '\n';
  std::cout << t_m << '\n';
  std::cout << t_s << '\n';

  return 0;
}