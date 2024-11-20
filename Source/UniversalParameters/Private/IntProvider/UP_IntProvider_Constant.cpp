// Fill out your copyright notice in the Description page of Project Settings.


#include "IntProvider/UP_IntProvider_Constant.h"

int32 UUP_IntProvider_Constant::GetValue(const FUP_EvaluationContext* Context)
{
	return Value;
}
