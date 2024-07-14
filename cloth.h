#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// Fully Functioned to manage the our AMS Clothes Store System


// function to display a line
void display_line()
{
    cout << endl
         << "======================================================================" << endl;
}

// function to display menu
void display_menu()
{
    cout << "======================================================================" << endl;
    cout << "                    Welcome to our AMS Clothes Sore " << endl;
    cout << "======================================================================" << endl;
    cout << "a. Add new clothes to the store" << endl;
    cout << "b. Display the clothes in the store" << endl;
    cout << "c. Delete the clothes from the store" << endl;
    cout << "d. Search the clothes in the store" << endl;
    cout << "e. Update the the clothes' information by the Barcode" << endl;
    cout << "f. To exit." << endl;
    cout << "Enter your option: ";
}

// function to display menu of display_option
void display_menu_of_display()
{
    cout << endl
         << "There are 5 options about updating the information:" << endl;
    cout << "Enter 1 to display all clothes." << endl;
    cout << "Enter 2 to display clothes with price higher than an input p." << endl;
    cout << "Enter 3 to display clothes with price lower than an input p." << endl;
    cout << "Enter 4 to display clothes with quantity higher than an input p." << endl;
    cout << "Enter 5 to display clothes with quatity lower than an input p." << endl;
    cout << "Enter your choice (1-5): ";
}

// function to display menu of update_option
void display_menu_of_updte()
{
    cout << endl
         << "There are 8 options about updating the information:" << endl;
    cout << "Enter number 1 to update only the name." << endl;
    cout << "Enter number 2 to update only the barcode." << endl;
    cout << "Enter number 3 to update only the size." << endl;
    cout << "Enter number 4 to update only the color." << endl;
    cout << "Enter number 5 to update only the type." << endl;
    cout << "Enter number 6 to update only quantity." << endl;
    cout << "Enter number 7 to update only price." << endl;
    cout << "Enter number 8 to update all information." << endl;
    cout << "Enter your choice (1-8): ";
}

// function to display menu of search_options
void display_menu_of_search()
{

    cout << endl
         << "Options for searching information:" << endl;
    cout << "1. Search by name." << endl;
    cout << "2. Search by barcode." << endl;
    cout << "3. Search by size." << endl;
    cout << "4. Search by color." << endl;
    cout << "5. Search by type." << endl;
    cout << "6. Search by quantity." << endl;
    cout << "7. Search by price." << endl;
    cout << "Enter your choice (1-7): ";
}

// funstion to ask user for clothes' name
string ask_for_name(string name)
{
    cout << "Enter the clothes' name: ";
    cin >> name;

    return name;
}

// funstion to ask user for clothes' barcode
string ask_for_barcode(string barcode)
{
    cout << "Enter the barcode of the cloth: ";
    cin >> barcode;

    return barcode;
}

// funstion to ask user for clothes' size
string ask_for_size(string size)
{
    cout << "Enter the size of the cloth: ";
    cin >> size;

    return size;
}

// funstion to ask user for clothes' type
string ask_for_type(string type)
{
    cout << "Enter the type: ";
    cin >> type;

    return type;
}

// funstion to ask user for clothes' color
string ask_for_color(string color)
{
    cout << "Enter the color: ";
    cin >> color;

    return color;
}

// funstion to ask user for clothes' quantity
int ask_for_quantity(int quantity)
{

    cout << "Enter the quantity: ";
    cin >> quantity;

    return quantity;
}

// funstion to ask user for clothes' price
float ask_for_price(int price)
{

    cout << "Enter the price: ";
    cin >> price;

    return price;
}

float ask_for_inputp1(float p1)
{
    cout << "Enter an input p: ";
    cin >> p1;

    return p1;
}

int ask_for_inputp1(int p2)
{
    cout << "Enter an input p: ";
    cin >> p2;

    return p2;
}

struct Clothes
{
    string name;
    string barcode;
    string size;
    string color;
    string type;
    int quantity;
    float prize;

    Clothes *next;
};

struct Queue
{
    int n;
    Clothes *front;
    Clothes *rear;
};

Queue *CreateEmptyQueue()
{
    Queue *q = new Queue();
    q->n = 0;
    q->front = NULL;
    q->rear = NULL;

    return q;
}

void write_to_csv(Queue* q, string filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Could not open the file!" << endl;
        return;
    }

    file << "Name,Barcode,Size,Color,Type,Quantity,Price\n";
    Clothes *temp = q->front;

    while (temp != nullptr) {
        file << temp->name << ','
             << temp->barcode << ','
             << temp->size << ','
             << temp->color << ','
             << temp->type << ','
             << temp->quantity << ','
             << temp->prize << '\n';
        temp = temp->next;
    }

    file.close();
    cout << "Data successfully written to the CSV file." << endl;
}


void enqueue(Queue *q, string name, string barcode, string size, string color, string type, int quantity, float prize)
{
    Clothes *newClothes = new Clothes();
    newClothes->name = name;
    newClothes->barcode = barcode;
    newClothes->size = size;
    newClothes->color = color;
    newClothes->type = type;
    newClothes->quantity = quantity;
    newClothes->prize = prize;

    newClothes->next = NULL;
    if (q->front == NULL)
    {
        q->front = newClothes;
        q->rear = newClothes;
    }
    else
    {
        q->rear->next = newClothes;
        q->rear = newClothes;
    }
    q->n++;
    cout << "The cloth was succesfully added!" << endl;
    display_line();
}

// Function to delete a cloth
void dequeue(Queue *q, string barcode) {
    if (q->front == NULL) {
        cout << "                The store is Empty                " << endl;
        return;
        }
        Clothes *current = q->front;
        Clothes *previous = NULL;
        while (current!= NULL && current->barcode!= barcode) {
             previous = current;
             current = current->next;
        }
        if (current == NULL) {
            cout << "                Barcode not found                " << endl;
            return;
        }
        if (previous == NULL) {
            q->front = current->next;
        } else {
            previous->next = current->next;
        }
        delete current;
        cout << "Delete from the store successfully!!!" << endl;
        q->n--;
}

// The function to write every data about the clothes to CSV file
void readFromCSV(Queue* q, string filename){
    ifstream file(filename);
    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string name, barcode, size, color, type;
        int quantity;
        float prize;
        getline(ss, name, ',');
        getline(ss, barcode, ',');
        getline(ss, size, ',');
        getline(ss, color, ',');
        getline(ss, type, ',');
        string quantityStr;
        getline(ss, quantityStr, ',');
        quantity = stoi(quantityStr);
        string prizeStr;
        getline(ss, prizeStr);
        prize = stof(prizeStr);
        enqueue(q, name, barcode, size, color, type, quantity, prize);
    }
    file.close();
}

// Function to display a element of the queue
void display_element(Clothes *tmp)
{
    cout << "\n";
    cout << "Name: " << tmp->name << endl;
    cout << "Barcode: " << tmp->barcode << endl;
    cout << "Size: " << tmp->size << endl;
    cout << "Color: " << tmp->color << endl;
    cout << "Type: " << tmp->type << endl;
    cout << "Quantity: " << tmp->quantity << endl;
    cout << "Price: $" << tmp->prize << endl;
    cout << "\n";
}

// Function to display all clothes
void Display_all(Queue *q)
{
    Clothes *tmp = q->front;
    display_line();

    cout << "                   Our Clothes in the Store                  " << endl;

    while (tmp != NULL)
    {
        display_element(tmp);
        tmp = tmp->next;
    }

    display_line();
}

// function to display clothes with pricer higher than input p
void Display_pricerhigherthan_p(Queue *q, float p)
{
    Clothes *mc = q->front;

    while (mc != NULL)
    {
        if (mc->prize > p)
        {
            cout << endl
                 << "           Clothes with price higher than an input p: " << endl;
            display_element(mc);
        }
        mc = mc->next;
    }
    display_line();
}

// function to display clothes with pricer lower than input p
void Display_pricerlowerthan_p(Queue *q, float p)
{
    Clothes *mc = q->front;

    while (mc != NULL)
    {
        if (mc->prize < p)
        {
            cout << endl
                 << "           Clothes with price lower than an input p:" << endl;
            display_element(mc);
        }
        mc = mc->next;
    }
    display_line();
}

// function to display clothes with quantity higher than input p
void Display_quantity_higherthan_p(Queue *q, int p)
{
    Clothes *mc = q->front;

    while (mc != NULL)
    {
        if (mc->quantity > p)
        {
            cout << endl
                 << "           Clothes with quantity higher than an input p:" << endl;
            display_element(mc);
        }
        mc = mc->next;
    }
    display_line();
}

// function to display clothes with quantity lower than input p
void Display_quantity_lowerthan_p(Queue *q, int p)
{
    Clothes *mc = q->front;

    while (mc != NULL)
    {
        if (mc->quantity < p)
        {
            cout << endl
                 << "           Clothes with quantity lower than an input p:" << endl;
            display_element(mc);
        }
        mc = mc->next;
    }
    display_line();
}

// function to update quatity by barcode
void Update_quantity(Queue *mq, string search_barcode)
{
    Clothes *mc = mq->front;
    int newquantity;

    display_line();

    while (mc != NULL)
    {
        if (search_barcode == mc->barcode)
        {
            cout << endl
                 << "Here is the current quantity of this cloth:" << mc->quantity << endl;
            cout << "Enter new quatity:";
            cin >> newquantity;
            mc->quantity = newquantity;
            cout << endl
                 << "Quatity was updated!" << endl;
            cout << "New Quantity:" << mc->quantity;
            break;
        }
        else if (search_barcode != mc->barcode)
        {
            cout << " There are no clothes with the entered barcode";
        }
        mc = mc->next;
    }
    display_line();
}

// function to update clothes' barcode by barcode
void Update_barcode(Queue *mq, string search_barcode)
{
    Clothes *mc = mq->front;
    string newbarcode;

    while (mc != NULL)
    {
        if (search_barcode == mc->barcode)
        {
            cout << endl
                 << "Here is the current barcode of this cloth:" << mc->barcode << endl;
            cout << "Pleaser enter new barcode:";
            cin >> newbarcode;
            mc->name = newbarcode;
            cout << endl
                 << "Barcode was successfully changed!" << endl;
            cout << "New Barcode:" << mc->barcode;
            break;
        }
        else if (search_barcode != mc->barcode)
        {
            cout << " There are no clothes with the entered barcode";
        }
        mc = mc->next;
    }
    display_line();
}

// function to update clothes' name by barcode
void Update_name(Queue *mq, string search_barcode)
{
    Clothes *mc = mq->front;
    string newname;

    while (mc != NULL)
    {
        if (search_barcode == mc->barcode)
        {
            cout << endl
                 << "Here is the current name of this cloth:" << mc->name << endl;
            cout << "Pleaser enter new name:";
            cin >> newname;
            mc->name = newname;
            cout << endl
                 << "Name was successfully changed!" << endl;
            cout << "New name:" << mc->name;
            break;
        }
        else if (search_barcode != mc->barcode)
        {
            cout << " There are no clothes with the entered barcode";
        }
        mc = mc->next;
    }
    display_line();
}

// function to update clothes' size by barcode
void Update_size(Queue *mq, string search_barcode)
{
    Clothes *mc = mq->front;
    string newsize;

    display_line();

    while (mc != NULL)
    {
        if (search_barcode == mc->barcode)
        {
            cout << endl
                 << "Here is the current size of this cloth:" << mc->size << endl;
            cout << "Enter new size:";
            cin >> newsize;
            mc->size = newsize;
            cout << endl
                 << "Size was successfully updated!" << endl;
            cout << "New size:" << mc->size;
            break;
        }
        else if (search_barcode != mc->barcode)
        {
            cout << " There are no clothes with the entered barcode";
        }
        mc = mc->next;
    }
    display_line();
}

// function to update clothes' color by barcode
void Update_color(Queue *mq, string search_barcode)
{
    Clothes *mc = mq->front;
    string newcolor;

    display_line();

    while (mc != NULL)
    {
        if (search_barcode == mc->barcode)
        {
            cout << endl
                 << "Here is the current color of this cloth:" << mc->color << endl;
            cout << "Enter new color:";
            cin >> newcolor;
            mc->color = newcolor;
            cout << endl
                 << "Color was successfully updated!" << endl;
            cout << "New color:" << mc->color;
            break;
        }
        else if (search_barcode != mc->barcode)
        {
            cout << " There are no clothes with the entered barcode";
        }
        mc = mc->next;
    }
    display_line();
}

// function to update clothes' type by barcode
void Update_type(Queue *mq, string search_barcode)
{
    Clothes *mc = mq->front;
    string newtype;

    display_line();

    while (mc != NULL)
    {
        if (search_barcode == mc->barcode)
        {
            cout << endl
                 << "Here is the current type of this cloth:" << mc->type << endl;
            cout << "Enter new type:";
            cin >> newtype;
            mc->type = newtype;
            cout << endl
                 << "Type of this cloth was successfully updated!" << endl;
            cout << "New type:" << mc->type;
            break;
        }
        else if (search_barcode != mc->barcode)
        {
            cout << " There are no clothes with the entered barcode";
        }
        mc = mc->next;
    }
    display_line();
}

// function to update clothes' price by barcode
void Update_price(Queue *mq, string search_barcode)
{
    Clothes *mc = mq->front;
    float newprice;

    display_line();

    while (mc != NULL)
    {
        if (search_barcode == mc->barcode)
        {
            cout << endl
                 << "Here is the current price of this cloth: $" << mc->prize << endl;
            cout << "Enter new price($):";
            cin >> newprice;
            mc->prize = newprice;
            cout << endl
                 << "The price of this cloth was successfully updated!" << endl;
            cout << "New price: $" << mc->prize;
            break;
        }
        else if (search_barcode != mc->barcode)
        {
            cout << " There are no clothes with the entered barcode";
        }
        mc = mc->next;
    }
    display_line();
}

// function to update all the information by barcode
void Update_all_information(Queue *mq, string search_barcode)
{

    Clothes *mc = mq->front;
    string newname, newsize, newbarcode, newcolor, newtype;
    int newquantity;
    float newprize;

    cout << endl
         << "======================================================================" << endl;

    while (mc != NULL)
    {
        if (search_barcode == mc->barcode)
        {
            // display the current informations
            cout << "Current information of this cloth:" << endl;
            display_element(mc);

            // ask for new information
            cout << endl
                 << "Pleaser enter new clothes' information:" << endl;
            newname = ask_for_name(newname);
            newbarcode = ask_for_barcode(newbarcode);
            newsize = ask_for_size(newsize);
            newcolor = ask_for_color(newcolor);
            newtype = ask_for_type(newtype);
            newquantity = ask_for_quantity(newquantity);
            newprize = ask_for_price(newprize);

            mc->name = newname;
            mc->barcode = newbarcode;
            mc->size = newsize;
            mc->color = newcolor;
            mc->type = newtype;
            mc->quantity = newquantity;
            mc->prize = newprize;

            cout << endl
                 << "###The information was updated!" << endl;
            cout << "###This is the new information:" << endl;
            display_element(mc);
            break;
        }
        else if (search_barcode != mc->barcode)
        {
            cout << " There are no clothes with the entered barcode";
        }
        mc = mc->next;
    }
    display_line();
}

// Function to search cloth by name
void Search_by_name(Queue *q, string search_name)
{
    Clothes *mc = q->front;
    int flag = 0;
    while (mc != NULL)
    {
        if (mc->name == search_name)
        {
            cout << endl
                 << "Clothes with searched name was found in the stock!" << endl;
            cout << "Here is the clothes' information with the searched name:" << endl;
            display_element(mc);
            flag = 1;
            break;
        }
        mc = mc->next;
    }
    if (flag == 0)
    {
        cout << "There is no clothes with this name";
    }
    display_line();
}

// Function to search cloth by barcode
void Search_by_barcode(Queue *q, string search_barcode)
{
    Clothes *mc = q->front;
    int flag = 0;
    while (mc != NULL)
    {
        if (mc->barcode == search_barcode)
        {
            cout << endl
                 << "Clothes with searched barcode was found in the stock!" << endl;
            cout << "Here is the clothes' information with the searched barcode:" << endl;
            display_element(mc);
            flag = 1;
            break;
        }
        mc = mc->next;
    }
    if (flag == 0)
    {
        cout << "There is no clothes with this barcode";
    }
    display_line();
}

// Function to search cloth by size
void Search_by_size(Queue *q, string search_size)
{
    Clothes *mc = q->front;
    int flag = 0;
    while (mc != NULL)
    {
        if (mc->size == search_size)
        {
            cout << endl
                 << "Clothes with searched size was found in the stock!" << endl;
            cout << "Here is the clothes' information with the searched size:" << endl;
            display_element(mc);
            flag = 1;
        }
        mc = mc->next;
    }
    if (flag == 0)
    {
        cout << "There is no clothes with this size";
    }
    display_line();
}

// Function to search cloth by color
void Search_by_color(Queue *q, string search_color)
{
    Clothes *mc = q->front;
    int flag = 0;
    while (mc != NULL)
    {
        if (mc->color == search_color)
        {
            cout << endl
                 << "Clothes with searched color was found in the stock!" << endl;
            cout << "Here is the clothes' information with the searched color:" << endl;
            display_element(mc);
            flag = 1;
        }
        mc = mc->next;
    }
    if (flag == 0)
    {
        cout << "There is no clothes with this color";
    }
    display_line();
}

// Function to search cloth by type
void Search_by_type(Queue *q, string search_type)
{
    Clothes *mc = q->front;
    int flag = 0;
    while (mc != NULL)
    {
        if (mc->type == search_type)
        {
            cout << endl
                 << "Clothes with searched type was found in the stock!" << endl;
            cout << "Here is the clothes' information with the searched type:" << endl;
            display_element(mc);
            flag = 1;
        }
        mc = mc->next;
    }
    if (flag == 0)
    {
        cout << "There is no clothes with this type";
    }
    display_line();
}

// Function to search cloth by quatity
void Search_by_quantity(Queue *q, int search_quantity)
{
    Clothes *mc = q->front;
    int flag = 0;
    while (mc != NULL)
    {
        if (mc->quantity == search_quantity)
        {
            cout << endl
                 << "Clothes with searched quatity was found in the stock!" << endl;
            cout << "Here is the clothes with the searched quatinty:" << endl;
            display_element(mc);
            flag = 1;
        }
        mc = mc->next;
    }
    if (flag == 0)
    {
        cout << "There is no clothes with this quantity";
    }
    display_line();
}

// Function to search cloth by price
void Search_by_price(Queue *q, float search_price)
{
    Clothes *mc = q->front;
    int flag = 0;
    while (mc != NULL)
    {
        if (mc->prize == search_price)
        {
            cout << endl
                 << "Clothes with searched price was found in the stock!" << endl;
            cout << "Here is the clothes with the searched price:" << endl;
            display_element(mc);
            flag = 1;
        }
        mc = mc->next;
    }
    if (flag == 0)
    {
        cout << "There is no clothes with this price";
    }
    display_line();
}