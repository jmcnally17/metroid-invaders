#ifndef SQUID_HPP
#define SQUID_HPP

class Squid
{
public:
  Squid();
  float getWidth() const;
  float getHeight() const;

private:
  float width_;
  float height_;
};

#endif
