/**
 * TODO file documentation
 *
 * @author John Xie
 * @date 10/5/2019
 */

#ifndef TURTLEPROGRAM_H
#define TURTLEPROGRAM_H

#include <iostream>

using namespace std;

class TurtleProgram {
  friend ostream &operator<<(ostream &Out, const TurtleProgram &Tp);

public:
  TurtleProgram();
  explicit TurtleProgram(const string &Command);
  TurtleProgram(const string &Command, const string &Times);
  TurtleProgram(const TurtleProgram &Tp);
  virtual ~TurtleProgram();

  int getLength() const;
  string getIndex(const int &I) const;
  void setIndex(const int &I, const string &Str);

  bool operator==(const TurtleProgram &Rhs) const;
  bool operator!=(const TurtleProgram &Rhs) const;

  TurtleProgram &operator=(const TurtleProgram &Rhs);
  TurtleProgram operator+(const TurtleProgram &Tp) const;
  TurtleProgram &operator+=(const TurtleProgram &Tp);
  TurtleProgram operator*(const int &Times) const;
  TurtleProgram &operator*=(const int &Times);
protected:

private:
	string* Arr; //array of strings/commands
	int Length;
};

#endif // TURTLEPROGRAM_H
