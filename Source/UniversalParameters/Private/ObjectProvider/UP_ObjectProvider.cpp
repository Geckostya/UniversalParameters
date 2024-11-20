// 


#include "ObjectProvider/UP_ObjectProvider.h"

UObject* UUP_ObjectProvider::GetObject_BP()
{
	return GetObject(nullptr);
}

UObject* UUP_ObjectProvider::GetObjectWithContext_BP(const UObject* ContextObject)
{
	const auto Context = TryGetContextFromObject(ContextObject);
	return GetObject(Context.Get());
}
	
UObject* UUP_ObjectProvider::GetObject(const FUP_EvaluationContext* Context)
{
	return nullptr;
}
