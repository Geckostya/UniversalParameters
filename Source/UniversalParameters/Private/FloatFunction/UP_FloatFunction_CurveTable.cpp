#include "FloatFunction/UP_FloatFunction_CurveTable.h"

float UUP_FloatFunction_CurveTable::Eval_Implementation(float Value)
{
	return RowHandle.Eval(Value, "FloatFunction_CurveTable");
}
