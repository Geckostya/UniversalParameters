// 


#include "ActorProvider/QL_ActorProvider.h"

AActor* UQL_ActorProvider::GetActor_Implementation()
{
	return nullptr;
}

UObject* UQL_ActorProvider::GetObject_Implementation()
{
	return GetActor();
}

AActor* UQL_ActorProvider::GetActorSafe(UQL_ActorProvider* Provider)
{
	return Provider ? Provider->GetActor() : nullptr;
}
