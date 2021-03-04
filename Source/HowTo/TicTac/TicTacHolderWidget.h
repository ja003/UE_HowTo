// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TicTacHolderWidget.generated.h"

/**
 *
 */
UCLASS()
class HOWTO_API UTicTacHolderWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	FString currentSymbol = FString("X");
	std::vector<FString> grid;
	int rows;
	int columns;

	void CheckIfWin(int pStartRow, int pStartColumn)
	{
		const int win_points = 3;

		FString symbol = GetSymbol(pStartRow, pStartColumn);
		int points = 0;

		//down
		for (int r = pStartRow; r <= pStartRow + win_points; r++)
		{
			if (CompareSymbol(r, pStartColumn, symbol))
			{
				points++;
				if (points == win_points)
					GLog->Log("WIN " + symbol);
			}
			else
			{
				points = 0;
				break;
			}
		}
		//up
		for (int r = pStartRow; r >= pStartRow - win_points; r--)
		{
			if (CompareSymbol(r, pStartColumn, symbol))
			{
				points++;
				if (points == win_points)
					GLog->Log("WIN " + symbol);
			}
			else
			{
				points = 0;
				break;
			}
		}
		//left
		for (int c = pStartColumn; c >= pStartColumn - win_points; c--)
		{
			if (CompareSymbol(pStartRow, c, symbol))
			{
				points++;
				if (points == win_points)
					GLog->Log("WIN " + symbol);
			}
			else
			{
				points = 0;
				break;
			}
		}
		//right
		for (int c = pStartColumn; c <= pStartColumn + win_points; c++)
		{
			if (CompareSymbol(pStartRow, c, symbol))
			{
				points++;
				if (points == win_points)
					GLog->Log("WIN " + symbol);
			}
			else
			{
				points = 0;
				break;
			}
		}


		if (points == win_points)
			GLog->Log("WIN " + symbol);
	}

	bool CompareSymbol(int pRow, int pColumn, FString symbol)
	{
		FString s = GetSymbol(pRow, pColumn);
		return s == symbol;
	}


	int GetIndex(int pRow, int pColumn)
	{
		return pRow * columns + pColumn;
	}

	FString GetSymbol(int pRow, int pColums)
	{
		int index = GetIndex(pRow, pColums);
		if (index < 0 || index >= grid.size())
			return "";
		return grid[index];
	}


public:

	UFUNCTION(BlueprintCallable)
		void Init(int pRows, int pColumns)
	{
		this->rows = pRows;
		this->columns = pColumns;
		grid.resize(rows * columns);
	}

	UFUNCTION(BlueprintCallable)
	FString OnBtnClick(int row, int column)
	{
		GLog->Log(FString::FromInt(row) + ", " + FString::FromInt(column));
		FString currentSymbolCache = currentSymbol;
		grid[GetIndex(row, column)] = currentSymbol;
		CheckIfWin(row, column);
		currentSymbol = currentSymbol == "X" ? "Y" : "X";
		return currentSymbolCache;
	}

};
