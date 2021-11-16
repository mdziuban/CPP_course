#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a secure remote server of difficulty " << Difficulty;
    std::cout << "\nYou need to enter the correct code to gain access to these files.\n\n";
}


bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The sum of the numbers is: " << CodeSum << std::endl;
    std::cout << "+ The product of the number is: " << CodeProduct  << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the user guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Access Granted. Difficulty level increased. ***";
        return true;
    }
    else 
    {
        std::cout << "\n*** That is the incorrect code.  Try again! ***";
        return false;
    }

}

int main()
{
    //This is the main function and does a bunch of nonsense.
    /*This is a multiline comment 
    about nothing*/
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while(LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clears errors
        std::cin.ignore(); //discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "\n*** Congratulations, you have completed the mission! ***";
    return 0;
}