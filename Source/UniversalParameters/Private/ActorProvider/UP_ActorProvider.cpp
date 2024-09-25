// 


#include "ActorProvider/UP_ActorProvider.h"

AActor* UUP_ActorProvider::GetActor_BP()
{
	return GetActor(nullptr);
}

AActor* UUP_ActorProvider::GetActor(const FUP_EvaluationContext* Context)
{
	return nullptr;
}

UObject* UUP_ActorProvider::GetObject(const FUP_EvaluationContext* Context)
{
	return GetActor(Context);
}