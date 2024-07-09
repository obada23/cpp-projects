#include <iostream>
using namespace std;

enum enQuestionLevel { Easy=1, Med=2, Hard=3, Mix=4 };
enum enOperationType { Add=1, Sub=2, Mul=3, Div=4, MixO=5 };

struct stQuestion
{
    int number1;
    int number2;
    enOperationType opType;
    enQuestionLevel level;
    int correctAnswer;
    int playerAnswer;
    bool answerResult;

};

struct stQuizz
{
    stQuestion questionList[100];
    short numberOfQuestions;
    enQuestionLevel level;
    enOperationType opType;
    short numberOfWrongAnswer;
    short numberOfRightAnswer;
    bool isPass;
};

short readHowManyQuestions()
{
    short numberOfQuestions;
    do
    {
        cout << "How many Questions do you want to answer ? ";
        cin >> numberOfQuestions;
        cout << endl;

    } while (numberOfQuestions<1||numberOfQuestions>10);
    return numberOfQuestions;
    
}

enQuestionLevel readQuestionLevel()
{
    short questionLevel;
    do
    {
        cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
        cin >> questionLevel;
        cout << endl;

    } while (questionLevel<1||questionLevel>4);
    return enQuestionLevel(questionLevel);
    
}

enOperationType readOperationType()
{
    short opType;
    do
    {
       cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
       cin >> opType;
       cout << endl;

    } while (opType<1||opType>5);
    
}

short randomNumber(short from, short to)
{
    return rand()%(to-from+1)+from;
}

short simpleCalculater(int number1, int number2, enOperationType opType)
{
    switch(opType)
    {
        case Add : { return number1+number2; break; }
        case Sub : { return number1-number2; break; }
        case Mul : { return number1*number2; break; }
        default : { return number1/number2; break; }
    }
}

stQuestion generateQuestion(enQuestionLevel questionLevel, enOperationType opType)
{
    stQuestion question;
    if(questionLevel== Mix)
        questionLevel = (enQuestionLevel)randomNumber(1,3);
    if(opType == MixO)
        opType = (enOperationType)randomNumber(1,4);

    question.opType = opType;
    question.level = questionLevel;

    switch(questionLevel)
    {
        case Easy : 
        {
            question.number1 = randomNumber(1,10);
            question.number2 = randomNumber(1,10);
            question.correctAnswer = simpleCalculater(question.number1,question.number2,question.opType);
            return question;
            break;
        }

        case Med : 
        {
            question.number1 = randomNumber(10,50);
            question.number2 = randomNumber(10,50);
            question.correctAnswer = simpleCalculater(question.number1,question.number2,question.opType);
            return question;
            break;

        }

        case Hard : 
        {
            question.number1 = randomNumber(50,100);
            question.number2 = randomNumber(50,100);
            question.correctAnswer = simpleCalculater(question.number1,question.number2,question.opType);
            return question;
            break;
        }
    }

}

void generateQuizzQuestion(stQuizz &quizz)
{
    for(short question=0;question<quizz.numberOfQuestions;question++)
    {
        quizz.questionList[question] = generateQuestion(quizz.level,quizz.opType);
    }
}

getOpTypeSymbol(enOperationType opType)
{
    char operationType[4] = {'+', '-', '*', '/'};
    return operationType[opType-1];
}

void printTheQuestion(stQuizz &quizz,short questionNumber)
{
    cout << "\n";
    cout << "Question [" << questionNumber+1 << "/" << quizz.numberOfQuestions << "] \n\n";
    cout << quizz.questionList[questionNumber].number1 << endl;
    cout << quizz.questionList[questionNumber].number2 << " ";
    cout << getOpTypeSymbol(quizz.questionList[questionNumber].opType);
    cout << "\n----------" << endl;
}

void askAndCorrectQuestionListAnswers(stQuizz &quizz)
{
    for(short questionNumber = 0; questionNumber < quizz.numberOfQuestions; questionNumber++)
    {
        printTheQuestion(quizz,questionNumber);
    }
}

void playMathGame()
{
    stQuizz quizz;
    quizz.numberOfQuestions = readHowManyQuestions();
    quizz.level = readQuestionLevel();
    quizz.opType = readOperationType();

    generateQuizzQuestion(quizz);
    askAndCorrectQuestionListAnswers(quizz);
}
void resetScreen()
{
    system("clear");
}
void startGame()
{
    char playAgain;
    do
    {
        resetScreen();
        playMathGame();
        cout << endl << "Do you want to play again? Y/N? ";
        cin >>playAgain;

    } while (playAgain=='Y'||playAgain=='y');

}
int main()
{
    srand((unsigned)time(NULL));
    startGame();
    return 0;
}