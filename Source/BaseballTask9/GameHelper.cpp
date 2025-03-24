// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHelper.h"
#include "Algo/RandomShuffle.h"

FString UGameHelper::GenerateRandomNumber()
{
	FString NewRandomNumber = "";

	TArray<int32> NumberList{ 1,2,3,4,5,6,7,8,9 };      //1~9까지 숫자를 담은 배열
	Algo::RandomShuffle(NumberList);        //배열을 무작위로 섞음
	
	for (int i = 0; i < 3; ++i)
	{
		NewRandomNumber += FString::FromInt(NumberList[i]);     //앞에서부터 3개 숫자 
	}

	return NewRandomNumber;     //랜덤한 중복없는 3개 숫자 생성
}

FString UGameHelper::CheckGuess(const FString& Guess, const FString& Answer)
{
    // 입력값이 3자리 숫자인지 확인
    if (Guess.Len() != 3 || !Guess.IsNumeric())
    {
        return TEXT("3자리만 입력해");
    }

    int Index = -1;     //찾은 위치 임시 저장용
    int32 Strikes = 0, Balls = 0;       //스트라이크, 볼 초기값 설정
    for (int32 i = 0; i < 3; i++)       //3자리 모두 검사
    {
        if (Guess.FindChar(Answer[i], Index))       //일치하는 숫자가 있는지 확인
        {
            if (Guess[i] == Answer[i])      //스트라이크 판정
            {
                Strikes++;
            }
            else        //볼 판정
            {
                Balls++;
            }
        }
    }

    int32 OutCount = 3 - Strikes - Balls;       //스트라이크, 볼 모두 아닌 경우는 아웃

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
