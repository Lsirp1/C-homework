#ifndef PATTERN_H
#define PATTERN_H

#include <string>

class Pattern {
private:
    std::string pattern;  
    int count;
    double cumulativeProb;

public:
    Pattern(std::string p, int c);
    Pattern();

    std::string getPattern() const;
    int getCount() const;
    double getCumulative() const;

    void setPattern(const std::string& p);
    void setCount(int c);
    void setCumulative(double cp);
};

#endif
