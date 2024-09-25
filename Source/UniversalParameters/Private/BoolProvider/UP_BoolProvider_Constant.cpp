#include "BoolProvider/UP_BoolProvider_Constant.h"

bool UUP_BoolProvider_Constant::GetValue(const FUP_EvaluationContext* Context)
{
	return bValue;
}
