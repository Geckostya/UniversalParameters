#include "BoolProvider/QL_BoolProvider_IsValid.h"

#include "ObjectProvider/QL_ObjectProvider.h"


bool UQL_BoolProvider_IsValid::GetValue_Implementation() 
{
	return IsValid(UQL_ObjectProvider::GetObjectSafe(ObjectProvider));
}
