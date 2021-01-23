#include <iostream>
#include <ctime>



void picture(){
     std::cout << R"(       *         .              *            _.---._      
                             ___   .            ___.'       '.   *
        .              _____[LLL]______________[LLL]_____     \
                      /     [LLL]              [LLL]     \     |
                     /____________________________________\    |    .
                      )==================================(    /
     .      *         '|I .-. I .-. I .--. I .-. I .-. I|'  .'
                  *    |I |+| I |+| I |. | I |+| I |+| I|-'`       *
                       |I_|+|_I_|+|_I_|__|_I_|+|_I_|+|_I|      .
              .       /_I_____I_____I______I_____I_____I_\
                       )================================(   *
       *         _     |I .-. I .-. I .--. I .-. I .-. I|          *
                |u|  __|I |+| I |+| I |<>| I |+| I |+| I|    _         .
           __   |u|_|uu|I |+| I |+| I |~ | I |+| I |+| I| _ |U|     _
       .  |uu|__|u|u|u,|I_|+|_I_|+|_I_|__|_I_|+|_I_|+|_I||n|| |____|u|
          |uu|uu|_,.-' /I_____I_____I______I_____I_____I\`'-. |uu u|u|__
          |uu.-'`      #############(______)#############    `'-. u|u|uu|
         _.'`              ~"^"~   (________)   ~"^"^~           `'-.|uu|
      ,''          .'    _                             _ `'-.        `'-.
  ~"^"~    _,'~"^"~    _( )_                         _( )_   `'-.        ~"^"~
      _  .'            |___|                         |___|      ~"^"~     _
    _( )_              |_|_|          () ()          |_|_|              _( )_
    |___|/\/\/\/\/\/\/\|___|/\/\/\/\/\|| ||/\/\/\/\/\|___|/\/\/\/\/\/\/\|___|
    |_|_|\/\/\/\/\/\/\/|_|_|\/\/\/\/\/|| ||\/\/\/\/\/|_|_|\/\/\/\/\/\/\/|_|_|
    |___|/\/\/\/\/\/\/\|___|/\/\/\/\/\|| ||/\/\/\/\/\|___|/\/\/\/\/\/\/\|___|
    |_|_|\/\/\/\/\/\/\/|_|_|\/\/\/\/\/[===]\/\/\/\/\/|_|_|\/\/\/\/\/\/\/|_|_|
    |___|/\/\/\/\/\/\/\|___|/\/\/\/\/\|| ||/\/\/\/\/\|___|/\/\/\/\/\/\/\|___|
    |_|_|\/\/\/\/\/\/\/|_|_|\/\/\/\/\/|| ||\/\/\/\/\/|_|_|\/\/\/\/\/\/\/|_|_|
    |___|/\/\/\/\/\/\/\|___|/\/\/\/\/\|| ||/\/\/\/\/\|___|/\/\/\/\/\/\/\|___|
~""~|_|_|\/\/\/\/\/\/\/|_|_|\/\/\/\/\/|| ||\/\/\/\/\/|_|_|\/\/\/\/\/\/\/|_lc|~""~
   [_____]            [_____]                       [_____]            [_____]  )" << std::endl;

     std::cout << "\n You are robber sneaking inside a manshion\n";
}
void introdcution(int level){

   

    std::cout << "\nYou see a level " << level << " security door with a combination..\n";
    std::cout << "In order to get to the secret vault you have to enter ";
    std::cout << "certain combination codes...\n";

}
bool StartGame(int levels)
{
    
   
     const int firstCode = rand() % (3 * levels) + 1;  // random generated number
     const int secondCode = rand()  % (3 * levels) + 1; // increases range with levels
     const int thirdCode = rand()  % (3 * levels) + 1;
  
    int firstGuess,secondGuess,thirdGuess,guessSum, guessProduct;
    

    const int sumCode = firstCode + secondCode + thirdCode;   // sum of codes
    const int product = firstCode * secondCode * thirdCode; // product of codes

   
    std::cout << "* There are 3 numbers in the code.\n";
    std::cout << "* The codes add-up to: " << sumCode  << std::endl; 
     std::cout << "* The codes multiply together and give: " << product << std::endl; 
     std::cin >> firstGuess >> secondGuess >> thirdGuess;
     guessSum = firstGuess + secondGuess + thirdGuess;
     guessProduct = firstGuess * secondGuess * thirdGuess;
     std::cout << "You entered: " << firstGuess << " " << secondGuess << " " << thirdGuess << std::endl;

     // check the guess
     if(guessSum == sumCode && guessProduct == product)
     {
         std::cout << " you guessed right!\n";
         return true;
     }
     
     else
     {
         std::cout << "*** Becareful!!! Try entering the code again! *** " << std::endl;
         return false;
     }
}

int main() {
      std::string answer;
do{ // loop if they want to play again

  
    int life = 3; // 3 tries per level
    srand(time(NULL));
      

        int currentLevel = 1; 
         const int maxLevel = 10;  // max level


    picture();  // manshion

 bool bLvlCompleted;
        while(currentLevel <= maxLevel)  // loops until we get till max level
        {
           
       
         introdcution(currentLevel);
         bLvlCompleted = StartGame(currentLevel);
         std::cin.clear(); // clears error
         std::cin.ignore(); // discard the buffer
          if(bLvlCompleted == false)
            {
                life = life - 1;
                  if(life == 0)
                {
                    std::cout << "\n*** YOU HAVE TRIGGERED THE ALARM!!! RUN AWAY!! ***\n";
                    break;
                 }   
            }
            else if(bLvlCompleted == true)
            {
                life = 3; // restarts the health
            }

          if (bLvlCompleted)  // returns true
        {
            ++currentLevel;
            std::cout << " Great Job! you passed " << currentLevel << "!\n"; 
            // increasing level difficulty
        }
        else if(currentLevel == maxLevel){
            std::cout << "Congrats You made it to the secret vault and see stash of cash! \n";
        }
        }
        
     std::cout << "Do you want to play again? [Y/N]: ";
     std::cin >> answer;   

}  
while(answer == "Y" || answer =="y");

    return 0;
}