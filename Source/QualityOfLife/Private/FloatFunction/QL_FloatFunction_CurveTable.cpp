#include "FloatFunction/QL_FloatFunction_CurveTable.h"

float UQL_FloatFunction_CurveTable::Eval_Implementation(float Value)
{
	return RowHandle.Eval(Value, "FloatFunction_CurveTable");
}
