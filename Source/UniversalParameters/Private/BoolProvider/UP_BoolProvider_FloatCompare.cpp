#include "BoolProvider/UP_BoolProvider_FloatCompare.h"

#include "FloatProvider/UP_FloatProvider_Constant.h"

UUP_BoolProvider_FloatCompare::UUP_BoolProvider_FloatCompare(const FObjectInitializer& ObjectInitializer)
{
	FirstParam = ObjectInitializer.CreateDefaultSubobject<UUP_FloatProvider_Constant>(this, "FirstParam");
	SecondParam = ObjectInitializer.CreateDefaultSubobject<UUP_FloatProvider_Constant>(this, "SecondParam");
}

bool UUP_BoolProvider_FloatCompare::GetValue_Implementation() 
{
	const float FirstSafe = UUP_FloatProvider::GetValueSafe(FirstParam);
	const float SecondSafe = UUP_FloatProvider::GetValueSafe(SecondParam);
	
	switch (Operation) {
	case EUP_CompareOperation::Less:
		return FirstSafe <  SecondSafe;
		
	case EUP_CompareOperation::LessOrEqual:
		return FirstSafe <= SecondSafe;

	case EUP_CompareOperation::More:
		return FirstSafe >  SecondSafe;

	case EUP_CompareOperation::MoreOrEqual:
		return FirstSafe >= SecondSafe;

	case EUP_CompareOperation::Equal:
		return FirstSafe == SecondSafe;

	case EUP_CompareOperation::NotEqual:
		return FirstSafe != SecondSafe;

	default: ;
	}
	return false;
}
