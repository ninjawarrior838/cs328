
class RangeErr
{
  public:
    RangeErr(const int& index) : subscript(index) {}
    int badSubscript() const { return subscript; }

  private:
    int subscript;
};
