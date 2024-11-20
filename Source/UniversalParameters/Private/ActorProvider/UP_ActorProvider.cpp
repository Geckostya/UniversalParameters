// 


#include "ActorProvider/UP_ActorProvider.h"

AActor* UUP_ActorProvider::GetActor_BP()
{
	return GetActor(nullptr);
}

AActor* UUP_ActorProvider::GetActorWithContext_BP(const UObject* ContextObject)
{
	const auto Context = TryGetContextFromObject(ContextObject);
	return GetActor(Context.Get());
}

AActor* UUP_ActorProvider::GetActor(const FUP_EvaluationContext* Context)
{
	return nullptr;
}

UObject* UUP_ActorProvider::GetObject(const FUP_EvaluationContext* Context)
{
	return GetActor(Context);
}