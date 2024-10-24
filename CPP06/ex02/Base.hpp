#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <time.h>
#include <stdlib.h>
class A;
class B;
class C;
 
class Base
{
	 public:
		Base() {};
		virtual ~Base(){};
		static Base * generate(void);
		static void identify(Base* p);
		static void identify(Base& p);
	 private:
};

class A : public Base{};

class B : public Base{};

class C : public Base{};

#endif
