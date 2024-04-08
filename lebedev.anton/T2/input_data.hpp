#ifndef INPUT_DATA_HPP
#define INPUT_DATA_HPP

#include <string>

namespace lebedev
{
  struct Delimiter
  {
    char expected;
  };
  struct DoubleLit
  {
    double & data;
  };
  struct DoubleSci
  {
    double & data;
  };
  struct String
  {
    std::string & data;
  };

  std::istream & operator>>(std::istream & input, Delimiter && delimiter);
  std::istream & operator>>(std::istream & input, DoubleLit && dbl_lit);
  std::istream & operator>>(std::istream & input, DoubleSci && dbl_sci);
  std::istream & operator>>(std::istream & input, String && str);
}

#endif
