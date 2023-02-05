#ifndef SQUID_HPP
#define SQUID_HPP

class Squid
{
public:
  Squid();
  float getWidth() const;
  float getHeight() const;
  int getPoints() const;

private:
  float width_;
  float height_;
  int points_;
};

#endif
