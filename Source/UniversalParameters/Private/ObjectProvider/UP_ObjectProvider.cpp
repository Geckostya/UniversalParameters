// 


#include "ObjectProvider/UP_ObjectProvider.h"

UObject* UUP_ObjectProvider::GetObject_Implementation()
{
	return nullptr;
}

UObject* UUP_ObjectProvider::GetObjectSafe(UUP_ObjectProvider* Provider)
{
	return Provider ? Provider->GetObject() : nullptr;
}
