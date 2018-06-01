#ifndef MENU_FUNCTION_H_INCLUDED
#define MENU_FUNCTION_H_INCLUDED

int menu();
int menu()
{
    int choice;
    bool repeatOne = true;
    std::cout << "1) Fight " << std::setw(5) << "2) Inventory " << std::setw(5) << "3) Attempt to Run " << " 4) Check Environment" <<  std::endl;
    while(repeatOne == true)
    {
        if (kbhit())
        {
            std::cin.clear();
        }
        //choice = rlutil::getkey();
        std::cin >> choice;
        if (choice  < 1 || choice > 4)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong choice doggo." << std::endl;
        }
        else
        {
            return choice;
        }
    }
}

#endif // MENU_FUNCTION_H_INCLUDED
