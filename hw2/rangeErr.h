/*
  Filename   : rangeErr.h
  Class      : CS328 Spring 2013
  Assignment : Program 2
  Programmer : Kyle jamison
  Date       : 2/17/2013

  A simple range error class that is called if a incorrect subscript
  is used

*/

class RangeErr
{
  public:
    RangeErr(const int& index) : subscript(index) {}
    ~RangeErr() {}
    int badSubscript() const { return subscript; }

  private:
    int subscript;
};
