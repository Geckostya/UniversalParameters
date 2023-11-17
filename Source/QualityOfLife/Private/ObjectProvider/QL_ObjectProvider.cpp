// 


#include "ObjectProvider/QL_ObjectProvider.h"

UObject* UQL_ObjectProvider::GetObject_Implementation()
{
	return nullptr;
}

UObject* UQL_ObjectProvider::GetObjectSafe(UQL_ObjectProvider* Provider)
{
	return Provider ? Provider->GetObject() : nullptr;
}
