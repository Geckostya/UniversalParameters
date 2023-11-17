#include "BoolProvider/QL_BoolProvider_FloatCompare.h"

#include "FloatProvider/QL_FloatProvier_Constant.h"

UQL_BoolProvider_FloatCompare::UQL_BoolProvider_FloatCompare(const FObjectInitializer& ObjectInitializer)
{
	FirstParam = ObjectInitializer.CreateDefaultSubobject<UQL_FloatProvier_Constant>(this, "FirstParam");
	SecondParam = ObjectInitializer.CreateDefaultSubobject<UQL_FloatProvier_Constant>(this, "SecondParam");
}

bool UQL_BoolProvider_FloatCompare::GetValue_Implementation() 
{
	const float FirstSafe = UQL_FloatProvider::GetValueSafe(FirstParam);
	const float SecondSafe = UQL_FloatProvider::GetValueSafe(SecondParam);
	
	switch (Operation) {
	case EQL_CompareOperation::Less:
		return FirstSafe <  SecondSafe;
		
	case EQL_CompareOperation::LessOrEqual:
		return FirstSafe <= SecondSafe;

	case EQL_CompareOperation::More:
		return FirstSafe >  SecondSafe;

	case EQL_CompareOperation::MoreOrEqual:
		return FirstSafe >= SecondSafe;

	case EQL_CompareOperation::Equal:
		return FirstSafe == SecondSafe;

	case EQL_CompareOperation::NotEqual:
		return FirstSafe != SecondSafe;

	default: ;
	}
	return false;
}
