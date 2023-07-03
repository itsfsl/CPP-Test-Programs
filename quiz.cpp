#include <iostream>

int main()
{
    std::string questions[] =   {"Q1. What comes after A?",
                                 "Q2. What comes after B?",
                                 "Q3. What comes after C?",
                                 "Q4. What comes after D?",
                                 "Q5. What comes after E?"};

    std::string options[][5] = {{"A. B", "B. C", "C. D", "D. E"},
                                {"A. C", "B. D", "C. E", "D. F"},
                                {"A. D", "B. E", "C. F", "D. G"},
                                {"A. E", "B. F", "C. G", "D. H"},
                                {"A. F", "B. G", "C. H", "D. I"}};

    char answerKey[] = {'A', 'A', 'A', 'A', 'A'};

    int quesSize = sizeof(questions)/sizeof(questions[0]);
    
    char guess;
    int score;

    for (int i = 0; i < quesSize; i++)
    {
        std::cout << "****************" << '\n';
        std::cout << questions[i] << '\n';
        std::cout << "****************" << '\n';

        for (int j = 0; j < sizeof(options[i])/sizeof(options[i][0]) - 1; j++)
        {
            std::cout << options[i][j] << '\n';
        }

        std::cout << "Enter your guess: ";
        std::cin >> guess;
        guess = toupper(guess);

        if (guess == answerKey[i])
        {
            std::cout << "Correct!" << '\n';
            score++;
        }
        else
        {
            std::cout << "Incorrect!" << '\n';
        }
    }

    std::cout << "\nCorrect Guesses: " << score << '\n';
    std::cout << "Total Questions: " << quesSize << '\n';
    std::cout << "Score: " << (score/(double)quesSize)*100 << "%";
    return 0;
}

