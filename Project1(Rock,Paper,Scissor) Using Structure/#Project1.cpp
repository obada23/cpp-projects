#include <iostream>
using namespace std;

// obada samer dashuon

enum enGameChoice { Rock=1, Paper=2, Scissor=3 };

enum enWinner { Player=1, Computer=2, Draw=3 };

struct stRoundResult
{
    short roundNumber;
    enGameChoice playerChoice;
    enGameChoice computerChoice;
    enWinner winner;
    string winnerName;
};

struct stGameResult
{
    short numberOfRounds;
    short playerWinTimes;
    short computerWinTimes;
    short drawTimes;
    enWinner winner;
    string winnerName;
};

void resetScreen()
{
    system("clear");
}

int randomNumber(int from, int to)
{
    return rand()%(to-from+1)+from;
}

int readHowManyRounds()
{
    short roundsNumber;
    do
    {
        cout << "\t\t\t\t\t  How Many Rounds 1 to 10 ? ";
        cin >> roundsNumber;

    } while (roundsNumber<1||roundsNumber>10);

    cout << endl;
    return roundsNumber;
    
}

enGameChoice playerChoice()
{
    short choice;
    do
    {
        cout << "\t\t\t\t\t  Your Choice: [1]:Rock, [2]:Paper, [3]:Scissor ? ";
        cin >> choice;

    } while (choice<1||choice>3);

    cout << endl;
    
    return enGameChoice(choice);
    
}

enGameChoice computerChoice()
{
    return (enGameChoice)randomNumber(1,3);    
}

enWinner whoWonTheRound(stRoundResult roundInfo)
{
    if(roundInfo.computerChoice==roundInfo.playerChoice)
        return Draw;

    switch(roundInfo.playerChoice)
    {
        case Rock    :    if(roundInfo.computerChoice == Paper) return Computer; break;
        case Paper   :    if(roundInfo.computerChoice == Scissor) return Computer; break;
        case Scissor :    if(roundInfo.computerChoice == Rock) return Computer; break; 
    }

    return Player;
}

string getWinnerName(enWinner winner)
{
    string winnerName[3] = { "Player", "Computer", "Draw" };
    return winnerName[winner-1];
}

string choiceName(enGameChoice choice)
{
    string playerChoice[3] = { "Rock", "Paper", "Scissor" };
    return playerChoice[choice-1];
}

void showRoundResult(stRoundResult roundInfo)
{
    cout << "\t\t\t\t\t -------------Round[" << roundInfo.roundNumber << "]-----------------" << endl << endl;
    cout << "\t\t\t\t              Player Choice   :  " << choiceName(roundInfo.playerChoice) << endl << endl;
    cout << "\t\t\t\t              Computer Choice :  " << choiceName(roundInfo.computerChoice) << endl << endl;
    cout << "\t\t\t\t              Round Winner    :  [" << roundInfo.winnerName << "]" << endl << endl; 
    cout << "\t\t\t\t\t --------------------------------------" << endl << endl << endl;
}

void showGameOverScreen()
{
    
    cout << "\t\t\t\t---------------------------------------------------------" << endl<<endl;
    cout << "\t\t\t\t\t\t+++ \033[33mG\033[0m \033[31ma\033[0m \033[30mm\033[0m \033[34me\033[0m   \033[31mO\033[0m \033[31mv\033[0m \033[29me\033[0m \033[35mr\033[0m +++\t\t" << endl << endl;
    cout << "\t\t\t\t---------------------------------------------------------" << endl<<endl<<endl;
    
}

void showEndGameScreen()
{
    cout << "\t\t\t\t---------------------------------------------------------" << endl<<endl;
    cout << "\t\t\t\t\t\t+++ \033[33mE\033[0m \033[31mn\033[0m \033[30md\033[0m   \033[34mG\033[0m \033[31ma\033[0m \033[31mm\033[0m \033[29me\033[0m +++\t\t" << endl << endl;
    cout << "\t\t\t\t---------------------------------------------------------" << endl<<endl<<endl;
}

enWinner whoWinnerTheGame(short playerWinTimes, short computerWinTimes)
{
    if(computerWinTimes>playerWinTimes)
        return Computer;
    if(computerWinTimes<playerWinTimes)
        return Player;
    else
        return Draw;
}

stGameResult fillGameResult(short howManyRounds,short playerWinTimes,short computerWinTimes,short drawTimes)
{
    stGameResult gameInfo;
    gameInfo.numberOfRounds = howManyRounds;
    gameInfo.computerWinTimes = computerWinTimes;
    gameInfo.playerWinTimes = playerWinTimes;
    gameInfo.drawTimes = drawTimes;
    gameInfo.winner = whoWinnerTheGame(playerWinTimes,computerWinTimes);
    gameInfo.winnerName = getWinnerName(gameInfo.winner);
    
    return gameInfo;
}

stGameResult playGame(short howManyRounds)
{
    short playerWinTimes = 0, computerWinTimes = 0, drawTimes = 0;
    stRoundResult roundInfo;
    for(int gameRound=1;gameRound<=howManyRounds;gameRound++)
    {
        roundInfo.roundNumber = gameRound;
        cout << "\t\t\t\t\t  Round [" << roundInfo.roundNumber << "] begins:\n\n";
        roundInfo.playerChoice = playerChoice();
        roundInfo.computerChoice = computerChoice();
        roundInfo.winner = whoWonTheRound(roundInfo);
        roundInfo.winnerName = getWinnerName(roundInfo.winner);
        

        if(roundInfo.winner==Player)
            playerWinTimes++;
        else if(roundInfo.winner==Computer)
            computerWinTimes++;
        else
            drawTimes++;

        showRoundResult(roundInfo);

    }
    return fillGameResult(howManyRounds,playerWinTimes,computerWinTimes,drawTimes);
}

void printGameResult(stGameResult gameInfo)
{
    cout << "\t\t\t\t    ---------------[Game Results]---------------\n\n";
    cout << "\t\t\t\t               Game Rounds         :  " << gameInfo.numberOfRounds << endl << endl;
    cout << "\t\t\t\t               Player Win Times    :  " << gameInfo.playerWinTimes << endl << endl;
    cout << "\t\t\t\t               Computer Win Times  :  " << gameInfo.computerWinTimes << endl << endl;
    cout << "\t\t\t\t               Draw Times          :  " << gameInfo.drawTimes << endl << endl;
    cout << "\t\t\t\t               Final Winner        :  " << gameInfo.winnerName << endl << endl;
    cout << "\t\t\t\t    --------------------------------------------" << endl << endl;
}

void startGame()
{
    char playAgain;
    do
    {
        resetScreen();
        stGameResult gameResult = playGame(readHowManyRounds());
        showGameOverScreen();
        printGameResult(gameResult);

        cout << "\t\t\t\t\t  Do you want to play again? Y/N ";
        cin >> playAgain;
        cout << endl;

    } while (playAgain=='y'||playAgain=='Y');

    showEndGameScreen();
    
    
}

int main()
{
    srand((unsigned)time(NULL));

    startGame();

    return 0;
}