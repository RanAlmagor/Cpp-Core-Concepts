#include "I_Printable.h"

std::ostream& operator<<(std::ostream& os , const I_printable& obj)
{
	obj.print(os);
	return os;
}