// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHelper.h"
#include "Algo/RandomShuffle.h"

FString UGameHelper::GenerateRandomNumber()
{
	FString NewRandomNumber = "";

	TArray<int32> NumberList{ 1,2,3,4,5,6,7,8,9 };
	Algo::RandomShuffle(NumberList);
	
	for (int i = 0; i < 3; ++i)
	{
		NewRandomNumber += FString::FromInt(NumberList[i]);
	}

	return NewRandomNumber;
}

FString UGameHelper::CheckGuess(const FString& Guess, const FString& Answer)
{
    // 입력값이 3자리 숫자인지 확인
    if (Guess.Len() != 3 || !Guess.IsNumeric())
    {
        return TEXT("3자리만 입력해");
    }

    int Index = -1;
    int32 Strikes = 0, Balls = 0;
    for (int32 i = 0; i < 3; i++)
    {
        if (Guess.FindChar(Answer[i], Index))
        {
            if (Guess[i] == Answer[i])
            {
                Strikes++;
            }
            else
            {
                Balls++;
            }
        }
    }

    int32 OutCount = 3 - Strikes - Balls;

    if (OutCount == 3)
    {
        return Guess + TEXT(" : 아웃");
    }

    if (Strikes == 3)
    {
        return Guess + TEXT(" : 3 스트라이크 정답입니다!");
    }

    return Guess + FString::Printf( TEXT(" : %d 스트라이크/ %d 볼"), Strikes, Balls);

}
