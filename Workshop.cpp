#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>

             // Colors
	const WORD colors[] =
		{
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
        0x10A,0x20B,0x30C,0x40D,0x50E,0x60F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6,
		};
		
	HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
	WORD   index   = 0;
	
		CONSOLE_SCREEN_BUFFER_INFO csbi;
   
                
             std::random_device randomKG;  //Will be used to obtain a seed for the random number engine
             std::mt19937 generator(randomKG()); //Standard mersenne_twister_engine seeded with rd()
             std::uniform_real_distribution<> disRawAluminiumKG(0.362,5.642);
                
             std::vector<std::string>::iterator iterationAluminium1;
             std::vector<std::string>::iterator iterationAluminium2;
class Metals{
private:
//Aluminium private variables
   std::string rawAluminiumName = "Raw Alumininum";
   std::string aluminiumName = "Aluminium";
   double numberRawOfAluminium = 0.000;
   double numberOfAluminium = 0.000;
   
   int numberOfRolledAluminium = 0;
    
    
   
protected:
    void passMetalName(void);
    std::string metalContainerName[1];
    std::string oreContainerName[1];
    
// Aluminium protected variables
    void storeMetalAluminium();
    void storeOreAluminium();
    std::vector<std::string> rolledAluminiumContainer1;
    std::vector<std::string> rolledAluminiumContainer2;
    
            std::string cut1;
            std::string cut2;
            bool cut1Set = false;
            bool cut2Set = false;
public:
//Aluminium
    void setAluminiumName();
    std::string getAluminiumName();
    void showAluminium();
    
    void setRawAluminiumName();
    std::string getRawAluminiumName();
    void showRawAluminium();
    void passRawAluminiumKG();
    
    void meltRawAluminium();
    void gatherRawAluminium();
    void useAluminiumCutter();
    
    void useMetalRoller();
    void RolledAluminiumContainerFunction(std::string xCut,std::string yCut);
    void showRolledAluminiumDimensions();
    void useAluminiumRoller();
    
    //Junk Parts
    int aluminiumWireCount = 0;
    int aluminiumPipeCount = 0;
    int aluminiumTransformerCount = 0;
    int aluminiumSheetCount = 0;
    int electrolyticCapacitorCount = 0;
// Mains
    void __MetalIventory();
};
Metals *METALS = new Metals;
//Protected
    void Metals::passMetalName(){
        metalContainerName[0] = aluminiumName;
        oreContainerName[0] = rawAluminiumName;
        //-NOTE Pass More metalNames
    }
    void Metals::storeMetalAluminium(){
        this->numberOfAluminium++;
    }
    void Metals::storeOreAluminium(){
        this->numberRawOfAluminium += (disRawAluminiumKG(generator));
    }
//Public
    void Metals::setAluminiumName(){
        passMetalName();
    }
    std::string Metals::getAluminiumName(){
        return metalContainerName[0];
    }
    void Metals::showAluminium(){
                
            std::cout << getAluminiumName() << '\n';
            std::cout << numberOfAluminium << '\n';
        
    }
    void Metals::setRawAluminiumName(){
        passMetalName();
    }
    std::string Metals::getRawAluminiumName(){
        return oreContainerName[0];
    }
    void Metals::showRawAluminium(){
            
            std::cout << getRawAluminiumName() << '\n';
            std::cout << std::setprecision(3) << numberRawOfAluminium << "kg\n";
        
    }
    void Metals::passRawAluminiumKG(){
        std::cout << std::setprecision(3) << disRawAluminiumKG(generator) << "kg\n";
        numberRawOfAluminium += (disRawAluminiumKG(generator));
    }
    
    void Metals::meltRawAluminium(){
        std::cout << rawAluminiumName << std::endl;
        printf("Melting");
        for (int i = 0;i < 7;i++){
            sleep(1);
            printf(".");
        }
        printf("Melting Complete!\n");
        if (numberRawOfAluminium > 1){
        this->numberOfAluminium++;
        this->numberRawOfAluminium -= 1.00;
        METALS->getAluminiumName();
        METALS->showAluminium();
        }
    }
    
    void Metals::gatherRawAluminium(){
        char gatherButton;
        gatherButton = getch();
        switch(gatherButton){
            case 't':
                printf("Gathering Aluminium");
                for (int i =0;i < 4;i++){
                    sleep(1);
                    printf(".");
                }
               std::cout << "\nYou found ";
               METALS->passRawAluminiumKG();
               std::cout << "Of 'Raw Aluminium'";
                
        }
    }
    void Metals::useAluminiumCutter(){
            
            bool aluminiumCutterOn = false;
            
            printf("Enter the dimesions for the aluminium cut\n");
            printf("To power on machine press o\n");
            char turnAluminiumCutterOn;
            char setDimensions;
            turnAluminiumCutterOn = getch();
            switch(turnAluminiumCutterOn){
                
                case 'o':
                    aluminiumCutterOn = true;
                    sleep(1);
                    printf("Machine is on!\n");

                while(aluminiumCutterOn){
                    printf("To set horizontal dimensions press x\n");
                    printf("To set vertical dimensions press z\n");
                    printf("To cut the metal press k\n");
                    printf("To Exit press ~\n");
                    cut1Set = false;
                    cut2Set = false;
                    setDimensions = getch();
                    switch(setDimensions){
                        case 'x':
                                printf("Horizontal cut\n");
                                std::cin >> cut1;
                                printf("Horizontal Dimesion: ");
                                std::cout << cut1 << std::endl;
                                std::cout << std::endl;
                                cut1Set = true;
                                
                                break;
                        case 'z':
                                printf("Vertical cut\n");
                                std::cin >> cut2;
                                printf("Vertical Dimesion:");
                                std::cout << cut2;
                                std::cout << std::endl;
                                cut2Set = true;
                                
                                break;
                        case 'k':
                        if(aluminiumSheetCount > 0){
                                sleep(1);
                                printf("Machine Cutting\n");
                                std::cout << "Cutting Dimensions" << cut1 << 'x' << cut2 << std::endl;
                                
                                sleep(2);
                                printf("Horizontal cut\n");
                                sleep(2);
                                printf("Vertical cut\n");
                                sleep(1);
                                std::cout << "Cut Complete...\n";
                                std::cout << "Press any key to continue.\n";
                                RolledAluminiumContainerFunction(cut1,cut2);
                                aluminiumSheetCount--;
                                
                                getch();
                                }
                            else{
                                printf("You dont have any Aluminium Sheets");
                            }
                                break;
                        case '`':
                                aluminiumCutterOn = false;
                                break;
                    }
                }
                
        }
    }
    void Metals::RolledAluminiumContainerFunction(std::string xCut,std::string yCut){
            xCut = cut1;
            yCut = cut2;
            rolledAluminiumContainer1.push_back(cut1);
            rolledAluminiumContainer2.push_back(cut2);
        
            
    }
    void Metals::showRolledAluminiumDimensions(){
        iterationAluminium1 = rolledAluminiumContainer1.begin();
        iterationAluminium2 = rolledAluminiumContainer2.begin();
        printf("Aluminium Sheet Dimensions...\n");
        printf("++++Horizontal     Vectical++++\n");
        for(iterationAluminium1 = rolledAluminiumContainer1.begin();iterationAluminium1 < rolledAluminiumContainer1.end();iterationAluminium1++){
            std::cout << "\tHorizonalDimensions :" << *iterationAluminium1 << std::endl;
        }
        for(iterationAluminium2 = rolledAluminiumContainer2.begin();iterationAluminium2 < rolledAluminiumContainer2.end();iterationAluminium2++){
            std::cout << "\tVerticalDimesions :" << *iterationAluminium2 << std::endl;
        }
    }
    void Metals::useAluminiumRoller(){
       if (numberOfAluminium > 0){
        sleep(1);
        printf("Using Aluminium Roller\n");
        sleep(1);
        printf("Sheet Dimensions: 1000x1000\n");
        printf("Rolling Aluminium Sheet");
        for (int i = 0;i < 3;i++){
            printf(".");
            sleep(1);
        }
        printf("\nSheet Rolled\n");
        aluminiumSheetCount++;
        numberOfAluminium--;
       }
    }
    void Metals::__MetalIventory(){
        METALS->setAluminiumName();
        METALS->getAluminiumName();
        METALS->showAluminium();
        
        METALS->setRawAluminiumName();
        METALS->getRawAluminiumName();
        METALS->showRawAluminium();
        
        METALS->showRolledAluminiumDimensions();
    }
class Money{
protected:
        void passMoney();
        
public:
        double moneyVar = 2025.35;
        void showMoney();
};
Money *CASH = new Money;
//Protected Variables
    void Money::passMoney(){
        SetConsoleTextAttribute(hstdout, 0xA);
        std::cout << std::fixed;
        std::cout << std::setprecision(2) << '$' << this->moneyVar << '\n'; 
        SetConsoleTextAttribute(hstdout, 0x7);
    }
//Public Variables
    void Money::showMoney(){
        passMoney();
    }
class Junkyard : private Metals, private Money{
private:
    std::string junkNames[5] = {"Aluminium Wire","Aluminium Pipe","Aluminiumn Transformer", "Electrolytic Capacitor","Aluminium Sheet"};
protected:
    void passJunkNames();
    
public:
    void displayPersonalParts();
    void displayJunk();
    void selectJunk();
    void sellParts();
};
Junkyard *JUNK = new Junkyard;
//Private Varaibles

//Protected Variables
    void Junkyard::passJunkNames(){
            std::cout << '\t' << junkNames[0];
            SetConsoleTextAttribute(hstdout, 0xA);
            std::cout << "  $1.50" << '\n';
            SetConsoleTextAttribute(hstdout, 0x7);
            std::cout << '\t' << junkNames[1];
            SetConsoleTextAttribute(hstdout, 0xA);
            std::cout << "  $3.50" << '\n';
            SetConsoleTextAttribute(hstdout, 0x7);
            std::cout << '\t' << junkNames[2];
            SetConsoleTextAttribute(hstdout, 0xA);
            std::cout << "  $5.50" << '\n';
            SetConsoleTextAttribute(hstdout, 0x7);
            std::cout << '\t' << junkNames[3];
            SetConsoleTextAttribute(hstdout, 0xA);
            std::cout << "  $2.50" << '\n';
            SetConsoleTextAttribute(hstdout, 0x7);
            std::cout << '\t' << junkNames[4];
            SetConsoleTextAttribute(hstdout, 0xA);
            std::cout << "  $11.50" << '\n';
            SetConsoleTextAttribute(hstdout, 0x7);
            
            
    }
//Public Variables
    void Junkyard::displayPersonalParts(){
        SetConsoleTextAttribute(hstdout, 0xD);
        printf("+=======Displaying Parts=======+\n");
        SetConsoleTextAttribute(hstdout, 0x7);
        std::cout << "Aluminium Sheets: " << this->aluminiumSheetCount << '\n';
        std::cout << "Aluminium Wires: " << this->aluminiumWireCount << '\n';
        std::cout << "Aluminium Pipes: " << this->aluminiumPipeCount << '\n';
        std::cout << "Aluminium Transformers: " << this->aluminiumTransformerCount << '\n';
        std::cout << "Electrolytic Capacitors: " << this->electrolyticCapacitorCount << '\n';
        
    }
    void Junkyard::displayJunk(){
        SetConsoleTextAttribute(hstdout, 0xB);
        printf("+====JUNK YARD====+\n");
        SetConsoleTextAttribute(hstdout, 0x7);
        printf("Press M To select parts\n");
        printf("Press S To sell parts\n");
        passJunkNames();
    }
    void Junkyard::selectJunk(){
        printf("Press < or > to scroll through junk\nPress / to select junk\nPress ~ to exit\n");
        int i = 0;
        bool selectJunkLoop = true;
        while(selectJunkLoop){
        char selectJunkPart;
        selectJunkPart = getch();
        switch(selectJunkPart){
            
            case '.':
            
                 char right;
                    std::cout << this->junkNames[i] << '\n';
                    i++;
                    if (i >= 5){
                        i--;
                    }
                    switch(right){
                    case ';':
                        break;
                        break;
                 }
            
            break;
            case ',':
             
                char left;
                    std::cout << this->junkNames[i] << '\n';
                    i--;
                    if (i < 0){
                        i++;
                    }
                    switch(left){
                    case ';':
                        break;
                        break;
                }
            
            break;
            case '/':
                SetConsoleTextAttribute(hstdout, 0xA);
                std::cout << "bought ";
                SetConsoleTextAttribute(hstdout, 0x7);
                std::cout << this->junkNames[i] << '\n';
                if (junkNames[i] == junkNames[0]){
                    aluminiumWireCount++;
                    CASH->moneyVar -= 1.50;
                    if(moneyVar <= 0.00){
                        aluminiumWireCount--;
                    }
                }
                else if (this->junkNames[i] == junkNames[1]){
                    aluminiumPipeCount++;
                    CASH->moneyVar -= 3.50;
                    if(moneyVar <= 0.00){
                        aluminiumPipeCount--;
                    }
                }
                else if (this->junkNames[i] == junkNames[2]){
                    aluminiumTransformerCount++;
                    CASH->moneyVar -= 5.50;
                    if(moneyVar <= 0.00){
                        aluminiumTransformerCount--;
                    }
                }
                else if (this->junkNames[i] == junkNames[3]){
                    electrolyticCapacitorCount++;
                    CASH->moneyVar -= 2.50;
                    if(moneyVar <= 0.00){
                        electrolyticCapacitorCount--;
                    }
                }
                else if (this->junkNames[i] == junkNames[4]){
                    aluminiumSheetCount++;
                    CASH->moneyVar -= 11.50;
                    if(moneyVar <= 0.00){
                        aluminiumSheetCount--;
                    }
                }
                break;
                break;
            case '`':
                selectJunkLoop = false;
                break;
                break;
                
            }
        }
    }
    void Junkyard::sellParts(){
            CASH->moneyVar += 1.50  * aluminiumWireCount;
            CASH->moneyVar += 3.50  * aluminiumPipeCount;
            CASH->moneyVar += 5.50  * aluminiumTransformerCount;
            CASH->moneyVar += 2.50  * electrolyticCapacitorCount;
            CASH->moneyVar += 11.50 * aluminiumSheetCount; 
            
            aluminiumWireCount = 0;
            aluminiumPipeCount = 0;
            aluminiumTransformerCount = 0;
            electrolyticCapacitorCount = 0;
            aluminiumSheetCount = 0;
    }
int main(int argc, char **argv)
{
while(1){
getch();  
printf("Press ~ to open ===Menu===\n");
printf("Press 1 to Melt Metal.\n");
printf("Press T to Gather aluminium.\n");
printf("Press P to Use aluminium Cutter.\n");
printf("Press R to Use Roller\n");
printf("Press n to view JunkYard\n");    
        char metalIventoryButton;
        metalIventoryButton = getch();
 //-------------------------------------------- 
    switch(metalIventoryButton){
        case '`':
                METALS->__MetalIventory();
                JUNK->displayPersonalParts();
                break;
        
        case '1':
                METALS->meltRawAluminium();
                break;
                
        case 't':
                METALS->gatherRawAluminium();
                break;
                
        case 'p':
                METALS->useAluminiumCutter();
                break;
                
        case 'r':
                METALS->useAluminiumRoller();
                break;
                
        case '=':
                CASH->showMoney();
                break;
                
        case 'n':
                JUNK->displayJunk();
                char selectJunkParts;
                selectJunkParts = getch();
                switch(selectJunkParts){
                    case 'm':
                            JUNK->selectJunk();
                            break;
                            break;
                    case 's':
                            JUNK->sellParts();
                            break;
                            break;
                }
    }
    }
}
