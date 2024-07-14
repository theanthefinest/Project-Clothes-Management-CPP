#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "cloth.h"

int main()
{
    Queue* q = CreateEmptyQueue();
    readFromCSV(q, "CLOTH_CSV.csv");
    string name, size, barcode, color, type;
    int quantity;
    float prize,p1;
    char option_menu;
    int option_update, option_search, option_display,p2;
    // enqueue(q, "namee", "123", "sizee", "colorr", "typee", 2, 5);
    // enqueue(q, "nameee", "1111", "sizeee", "colorrr", "typeee", 22, 52);
    // enqueue(q, "namee", "2222", "sizee", "colorr", "typee", 2, 5);
    // write_to_csv(q);

    while (1)
    {

        display_menu();
        cin >> option_menu;
        
        //Add new clothes to the store"
        if (option_menu == 'a')
        {
            // cout << "======================= Adding the clothes to the store ==============================" << endl;
            display_line();
            cout << "================== Adding the clothes to the store: =================="<<endl;

            // ask user for all information about the clothes
            name = ask_for_name(name);
            barcode = ask_for_barcode(barcode);
            size = ask_for_size(size);
            color = ask_for_color(color);
            type = ask_for_type(type);
            quantity = ask_for_quantity(quantity);
            prize = ask_for_price(prize);

            // ADD TO THE QUEUE
            enqueue(q, name, barcode, size, color, type, quantity, prize);

            // DATA ALSO NEED BE TO STORED IN1 CSV
            write_to_csv(q);
        }

        //Display the clothes in the store
        if (option_menu == 'b')
        {
            cout << endl;
            display_menu_of_display();
            cin >> option_display;

            //display all clothes
            if (option_display == 1)
            {
                Display_all(q);
            }

            //display clothes with price higher than an input p
            else if (option_display == 2)
            {
                p1=ask_for_inputp1(p1);
                Display_pricerhigherthan_p(q,p1);
            }

            //display clothes with price lower than an input p
            else if (option_display == 3)
            {
                p1=ask_for_inputp1(p1);
                Display_pricerlowerthan_p(q,p1);
            }

            //display clothes with quantity higher than an input p.
            else if (option_display == 4)
            {
                p2=ask_for_inputp1(p2);
                Display_quantity_higherthan_p(q,p2);
            }

            //display clothes with quatity lower than an input p
            else if (option_display == 5)
            {
                p2=ask_for_inputp1(p2);
                Display_quantity_lowerthan_p(q,p2);
            }
            else
            {
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            }

            
        }
        
        //Delete the clothes from the store
        else if (option_menu == 'c')
        {
            // delte from the queue
            cout << "Enter the barcode to delete from the store: ";
            cin >> barcode;
            dequeue(q, barcode);

            // let's re-write csv file
            write_to_csv(q);
        }
       
       //Search the clothes in the store
        else if (option_menu == 'd')
        {
            display_menu_of_search();
            cin >> option_search;
            cout << endl;

            //Search by name
            if (option_search == 1)
            {
                name = ask_for_name(name);
                Search_by_name(q, name);
            }

            //Search by barcode
            else if (option_search == 2)
            {
                barcode = ask_for_barcode(barcode);
                Search_by_barcode(q, barcode);
            }

            //Search by size
            else if (option_search == 3)
            {
                size = ask_for_size(size);
                Search_by_size(q, size);
            }

            //Search by color
            else if (option_search == 4)
            {
                color = ask_for_color(color);
                Search_by_color(q, color);
            }

            //Search by type
            else if (option_search == 5)
            {
                type = ask_for_type(type);
                Search_by_type(q, type);
            }

            //Search by quantity
            else if (option_search == 6)
            {
                quantity = ask_for_quantity(quantity);
                Search_by_quantity(q, quantity);
            }

            //Search by price
            else if (option_search == 7)
            {
                prize = ask_for_price(prize);
                Search_by_price(q, prize);
            }
            else
            {
                cout << "Invalid choice. Please enter a number from 1 to 7." << endl;
            }
        }
        
        //Update the the clothes' information by the Barcode
        else if (option_menu == 'e')
        {

            // display the options for updating information
            display_menu_of_updte();
            cin >> option_update;
            cout << endl;

            //update only name
            if (option_update == 1)
            {
                barcode = ask_for_barcode(barcode);
                Update_name(q, barcode);
            }
            //update only barcode
            else if (option_update == 2)
            {
                barcode = ask_for_barcode(barcode);
                Update_barcode(q, barcode);
            }
            //update only size
            else if (option_update == 3)
            {
                barcode = ask_for_barcode(barcode);
                Update_size(q, barcode);
            }

            //update only color
            else if (option_update == 4)
            {
                barcode = ask_for_barcode(barcode);
                Update_color(q, barcode);
            }

            //update only type
            else if (option_update == 5)
            {
                barcode = ask_for_barcode(barcode);
                Update_type(q, barcode);
            }

            //update only quantity
            else if (option_update == 6)
            {
                barcode = ask_for_barcode(barcode);
                Update_quantity(q, barcode);
            }

            //update only price
            else if (option_update == 7)
            {
                barcode = ask_for_barcode(barcode);
                Update_price(q, barcode);
            }
            //update all information
            else if (option_update == 8)
            {
                barcode = ask_for_barcode(barcode);
                Update_all_information(q, barcode);
            }
            else
            {
                cout << "Invalid choice. Please enter a number from 1 to 8." << endl;
            }

            // data in csv need to be re-write after updating in queue
            write_to_csv(q);
        }

        //exit
        else if (option_menu == 'f')
        {
            cout << "Thank you for using our system" << endl;
            break;
        }
    }
}