#include "BoolProvider/UP_BoolProvider_FloatCompare.h"

#include "FloatProvider/UP_FloatProvider_Constant.h"

UUP_BoolProvider_FloatCompare::UUP_BoolProvider_FloatCompare(const FObjectInitializer& ObjectInitializer)
{
	FirstParam = ObjectInitializer.CreateDefaultSubobject<UUP_FloatProvider_Constant>(this, "FirstParam");
	SecondParam = ObjectInitializer.CreateDefaultSubobject<UUP_FloatProvider_Constant>(this, "SecondParam");
}

bool UUP_BoolProvider_FloatCompare::CalcValue(const float FirstSafe, const float SecondSafe)
{
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


bool UUP_BoolProvider_FloatCompare::GetValue(const FUP_EvaluationContext* Context)
{
	const float FirstSafe = UUP_FloatProvider::GetValueSafe(FirstParam, Context);
	const float SecondSafe = UUP_FloatProvider::GetValueSafe(SecondParam, Context);

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

FString UUP_BoolProvider_FloatCompare::GetPreviewName_Implementation() const
{
	static const TMap<EUP_CompareOperation, FString> OperationToName = {{
			{EUP_CompareOperation::Less, TEXT("<")},
			{EUP_CompareOperation::LessOrEqual, TEXT("<=")},
			{EUP_CompareOperation::More, TEXT(">")},
			{EUP_CompareOperation::MoreOrEqual, TEXT(">=")},
			{EUP_CompareOperation::Equal, TEXT("==")},
			{EUP_CompareOperation::NotEqual, TEXT("!=")},
	}};
	const FString& OpName = OperationToName.FindChecked(Operation);
	return FString::Printf(TEXT("[%s %s %s]"), *GetPreviewNameSafe(FirstParam), *OpName, *GetPreviewNameSafe(SecondParam));
}