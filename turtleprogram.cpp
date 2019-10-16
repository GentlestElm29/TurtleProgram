/**
 * TODO file documentation
 *
 * @author John Xie
 * @date 10/4/2019
 */

#include "turtleprogram.h"
#include <cassert>


TurtleProgram::TurtleProgram() 
{
	Arr = nullptr;
	Length = 0;
}

TurtleProgram::TurtleProgram(const string &Command) 
{
	if (Command.length() == 0)
	{
		Arr = nullptr;
		Length = 0;
		return;
	}

	int Counter = 0;
	for (char I : Command)
	{
		if (I == ' ')
		{
			Counter++;
		}
	}

	Counter++;
	Length = Counter;

	Arr = new string[Length];
	
	string Input;
	int Index = 0;

	for (char I : Command)
	{
		if (I == ' ')
		{
			Arr[Index] = Input;
			Input = "";
			Index++;
			
		}
		else
		{
			Input += I;
		}
	}
	Arr[Index] = Input; //last value
}

TurtleProgram::TurtleProgram(const string& Command, const string& Times)
{
	if (Command.length() == 0 || Times.length() == 0)
	{
		Arr = nullptr;
		Length = 0;
		return;
	}
	
	Length = 2;
	Arr = new string[Length];

	Arr[0] = Command;
	Arr[1] = Times;
}

TurtleProgram::TurtleProgram(const TurtleProgram &Tp) 
{
	Length = Tp.getLength();
	Arr = new string[Length];

	for (int I = 0; I < Length; I++)
	{
		Arr[I] = Tp.getIndex(I);
	}
}

// accessors
int TurtleProgram::getLength() const 
{
	return Length;
}
string TurtleProgram::getIndex(const int &I) const 
{
	if (I < Length)
	{
		return Arr[I];
	}

	return nullptr;
}

// mutators
void TurtleProgram::setIndex(const int &I, const string &Str) 
{
	if (I < Length)
	{
		Arr[I] = Str;
	}
}

// equality
bool TurtleProgram::operator!=(const TurtleProgram &Rhs) const 
{
	if (Length != Rhs.getLength())
	{
		return true;
	}
	
	for (int I = 0; I < Rhs.getLength(); I++)
	{
		if (Arr[I] != Rhs.getIndex(I))
		{
			return true;
		}
	}
	return false;
}

bool TurtleProgram::operator==(const TurtleProgram &Rhs) const 
{
	if (Length != Rhs.getLength())
	{
		return false;
	}

	for (int I = 0; I < Rhs.getLength(); I++)
	{
		if (Arr[I] != Rhs.getIndex(I))
		{
			return false;
		}
	}
	return true;
}

// + and +=
TurtleProgram TurtleProgram::operator+(const TurtleProgram &Tp) const 
{
  string CombinedCommands;

  for (int I = 0; I < Length; I++)
  {
	  CombinedCommands += this->getIndex(I);
	  CombinedCommands += " ";
  }

  for (int I = 0; I < Tp.getLength(); I++)
  {
	  CombinedCommands += Tp.getIndex(I);
	  if (I != Tp.getLength() - 1)
	  {
		  CombinedCommands += " ";
	  }
  }

  return TurtleProgram(CombinedCommands); //Bigger
}

TurtleProgram &TurtleProgram::operator+=(const TurtleProgram &Tp) 
{
	int TempLength = Length + Tp.getLength();
	auto* TempArray = new string[TempLength];

	for (int I = 0; I < Length; I++)
	{
		TempArray[I] = this->getIndex(I);
	}

	for (int I = 0; I < Tp.getLength(); I++)
	{
		TempArray[Length + I] = Tp.getIndex(I);
	}

	delete[] Arr;

	Arr = TempArray;
	Length = TempLength;

	return *this;
}

// * and *=
TurtleProgram TurtleProgram::operator*(const int &Times) const 
{
  assert(Times > 0);

  string CombinedCommands;

  for (int J = 0; J < Times; J++)
  {
	  for (int I = 0; I < Length; I++)
	  {
		  CombinedCommands += this->getIndex(I);

		  if (J == Times - 1 && I == Length - 1)
		  {
			  break; //last string space not added
		  }

		  CombinedCommands += " ";
	  }
  }

  return TurtleProgram(CombinedCommands); //Bigger
}

TurtleProgram &TurtleProgram::operator*=(const int &Times) 
{
  assert(Times > 0);

  int TempLength = Times * Length;

  auto* TempArray = new string[TempLength];
  int Index = 0;

  for (int J = 0; J < Times; J++)
  {
	  for (int I = 0; I < Length; I++)
	  {
		  TempArray[Index] = this->getIndex(I);
		  Index++;
	  }
  }
  
  delete[] Arr;

  Arr = TempArray;
  Length = TempLength;

  return *this;
}

TurtleProgram &TurtleProgram::operator=(const TurtleProgram &Rhs) // copy assignment
{ 
	auto* TempArray = new string[Rhs.getLength()];

	for (int I = 0; I < Rhs.getLength(); I++)
	{
		TempArray[I] = Rhs.getIndex(I);
	}

	delete[] Arr;

	Arr = TempArray;
	Length = Rhs.getLength();

	return *this;
}

TurtleProgram::~TurtleProgram() 
{
	delete[] Arr;
	Length = 0;
}

// --------------------------------------------------------------------------
// operator<<
// Overloaded output operator for class Array
ostream &operator<<(ostream &Out, const TurtleProgram &Tp) 
{
	Out << "[";

	for (int I = 0; I < Tp.getLength(); I++)
	{
		Out << Tp.getIndex(I);
		if (I == Tp.getLength() - 1)
		{
			break;
		}

		Out << " ";
	}

	Out << "]";
	return Out;                      // e.g., enables cout << x << y;
}
