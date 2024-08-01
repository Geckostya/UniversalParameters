#include "FloatProvider/UP_FloatProvider_Counter.h"

float UUP_FloatProvider_Counter::GetValue_Implementation() 
{
	return BaseValue += Delta;
}
