// Testing availability of boost headers

#include <iostream>
#include <boost/math/distributions.hpp>

void test() {
  boost::math::binomial_distribution<double> d(10, 0.5);
}

extern bool checkOverflow(unsigned short x, unsigned short y) {
  // BAD: comparison is always false due to type promotion https://codeql.github.com/codeql-query-help/cpp/cpp-bad-addition-overflow-check/
  return (x + y < x);  
}

int x = atoi(argv[1]);
int y = atoi(argv[2]);
checkOverflow(x,y);
