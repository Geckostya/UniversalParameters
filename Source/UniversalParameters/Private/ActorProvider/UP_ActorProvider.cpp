// 


#include "ActorProvider/UP_ActorProvider.h"

AActor* UUP_ActorProvider::GetActor_Implementation()
{
	return nullptr;
}

UObject* UUP_ActorProvider::GetObject_Implementation()
{
	return GetActor();
}

AActor* UUP_ActorProvider::GetActorSafe(UUP_ActorProvider* Provider)
{
	return Provider ? Provider->GetActor() : nullptr;
}
