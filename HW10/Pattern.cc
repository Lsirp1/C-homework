#include "Pattern.h"

Pattern::Pattern(std::string p, int c)
    : pattern(p), count(c), cumulativeProb(0.0) {}

Pattern::Pattern()
    : pattern(""), count(0), cumulativeProb(0.0) {}

std::string Pattern::getPattern() const { return pattern; }
int Pattern::getCount() const { return count; }
double Pattern::getCumulative() const { return cumulativeProb; }

void Pattern::setPattern(const std::string& p) { pattern = p; }
void Pattern::setCount(int c) { count = c; }
void Pattern::setCumulative(double cp) { cumulativeProb = cp; }
