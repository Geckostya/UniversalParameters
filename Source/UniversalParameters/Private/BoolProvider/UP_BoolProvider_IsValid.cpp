#include "BoolProvider/UP_BoolProvider_IsValid.h"

#include "ObjectProvider/UP_ObjectProvider.h"


bool UUP_BoolProvider_IsValid::GetValue_Implementation() 
{
	return IsValid(UUP_ObjectProvider::GetObjectSafe(ObjectProvider));
}
