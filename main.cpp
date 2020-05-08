#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pizza {
protected:
    unsigned int size;
    unsigned int salt;
    unsigned int cheese;
public :
    virtual string getName() const = 0;

    virtual unsigned int getPrice() const = 0;

    virtual unsigned int addSalt() const = 0;

    virtual unsigned int addCheese() const = 0;

    virtual unsigned int getSize() const = 0;

    virtual unsigned int howAdd() const = 0;
};

class Peperoni : public Pizza {
public:
    Peperoni(unsigned int size, unsigned int salt, unsigned int cheese) {
        this->size = size;
        this->salt = salt;
        this->cheese = cheese;
    }

    string getName() const override {
        return "Peperoni";
    }

    unsigned int addCheese() const override {
        return cheese;
    }

    unsigned int addSalt() const override {
        return salt;
    }

    unsigned int getSize() const override {
        return size;
    }

    unsigned int howAdd() const override {
        return (salt*5)+(cheese*7) ;
    }

    unsigned int getPrice() const override {
        return 250+4*size+howAdd();
    }

};

class Hawaii : public Pizza {
public:
    Hawaii(unsigned int size, unsigned int salt, unsigned int cheese) {
        this->size = size;
        this->salt = salt;
        this->cheese = cheese;
    }

    string getName() const override {
        return "Hawaii";
    }

    unsigned int addCheese() const override {
        return cheese;
    }

    unsigned int addSalt() const override {
        return salt;
    }

    unsigned int getSize() const override {
        return size;
    }

    unsigned int howAdd() const override {
        return salt+(cheese*15) ;
    }

    unsigned int getPrice() const override {
        return 300+size+howAdd();
    }

};

class Margarita : public Pizza {
public:
    Margarita(unsigned int size, unsigned int salt, unsigned int cheese) {
        this->size = size;
        this->salt = salt;
        this->cheese = cheese;
    }

    string getName() const override {
        return "Margarita";
    }

    unsigned int addCheese() const override {
        return cheese;
    }

    unsigned int addSalt() const override {
        return salt;
    }

    unsigned int getSize() const override {
        return size;
    }

    unsigned int howAdd() const override {
        return (salt*2)+(cheese*4) ;
    }

    unsigned int getPrice() const override {
        return 200+2*size+howAdd();
    }

};

class Classic : public Pizza {
public:
    Classic(unsigned int size, unsigned int salt, unsigned int cheese) {
        this->size = size;
        this->salt = salt;
        this->cheese = cheese;
    }

    string getName() const override {
        return "Classic";
    }

    unsigned int addCheese() const override {
        return cheese;
    }

    unsigned int addSalt() const override {
        return salt;
    }

    unsigned int getSize() const override {
        return size;
    }

    unsigned int howAdd() const override {
        return (salt*6)+(cheese*20) ;
    }

    unsigned int getPrice() const override {
        return 200+10*size+howAdd();
    }

};

class Roman : public Pizza {
public:
    Roman(unsigned int size, unsigned int salt, unsigned int cheese) {
        this->size = size;
        this->salt = salt;
        this->cheese = cheese;
    }

    string getName() const override {
        return "Roman";
    }

    unsigned int addCheese() const override {
        return cheese;
    }

    unsigned int addSalt() const override {
        return salt;
    }

    unsigned int getSize() const override {
        return size;
    }

    unsigned int howAdd() const override {
        return salt*10 +cheese ;
    }

    unsigned int getPrice() const override {
        return 180+size*2+howAdd()*2;
    }

};

class ThreeCheese : public Pizza {
public:
    ThreeCheese(unsigned int size, unsigned int salt, unsigned int cheese) {
        this->size = size;
        this->salt = salt;
        this->cheese = cheese;
    }

    string getName() const override {
        return "ThreeCheese";
    }

    unsigned int addCheese() const override {
        return cheese;
    }

    unsigned int addSalt() const override {
        return salt;
    }

    unsigned int getSize() const override {
        return size;
    }

    unsigned int howAdd() const override {
        return salt*10 ;
    }

    unsigned int getPrice() const override {
        return 300+size+howAdd();
    }

};

class Mushroom : public Pizza {
public:
    Mushroom(unsigned int size, unsigned int salt, unsigned int cheese) {
        this->size = size;
        this->salt = salt;
        this->cheese = cheese;
    }

    string getName() const override {
        return "Mushroom";
    }

    unsigned int addCheese() const override {
        return cheese;
    }

    unsigned int addSalt() const override {
        return salt;
    }

    unsigned int getSize() const override {
        return size;
    }

    unsigned int howAdd() const override {
        return cheese*100 ;
    }

    unsigned int getPrice() const override {
        return 150+size*3+howAdd();
    }

};

class Order {

    vector <const Pizza *> products;

public:
    void add(const Pizza *pizza) {
        products.push_back(pizza);
    }

    void print() {
        unsigned int total = 0;
        size_t size = products.size();

        if (size == 0) {
            cout << "We look forward to see you next time";
        } else {
            for (size_t i = 0, size = products.size(); i < size; i++) {
                cout << (i + 1) << ". " << products[i]->getName()<< endl;
                cout<<"Size :  " <<  products[i]->getSize() <<
                ",  salt - " <<
                 products[i]->addSalt() << ",  cheese - "
                << products[i]->addCheese() << ". Price - "
                << products[i]->getPrice() << endl;

               total = total + products[i]->getPrice();
            }
            cout << " Total price : " << total << endl;
        }
    }
};

int main() {
    int choice;
    unsigned int  size, salt, cheese;
    cout << "-----------MENU------------" << endl;
    cout << "1.      Peperoni     " << endl;
    cout << "2.      Hawaii       " << endl;
    cout << "3.      Margarita    " << endl;
    cout << "4.      Classic      " << endl;
    cout << "5.      Roman        " << endl;
    cout << "6.      ThreeCheese  " << endl;
    cout << "7.      Mushroom     " << endl;

    Order order;

    cout << "Are you ready to place an order? Choose your pizza " << endl;
    cin >> choice;
    while ((choice > 0) && (choice < 8)) {
        cout << "Choose a pizza size :" << endl;
        cout << "1.Small = 25 "<<endl
             << "2.Medium = 30"<<endl
             << "3.Large = 35"<<endl
             << "4.Extralarge = 40"<<endl;
        cin >> size ;
        switch (size) {
            case 1:
                size = 25;
                break;
            case 2:
                size = 30;
                break;
            case 3:
                size = 35;
                break;
            case 4:
                size = 40;
                break;
            default:
                cout << "For those who could not decide, we give the largest pizza " << endl;
                size = 40;
        }
        cout << "Do you want to add salt or cheese? " << endl;
        cin >>  salt >> cheese;

        switch (choice) {
            case 1:
                order.add(new Peperoni (size, salt, cheese));
                break;
            case 2:
                order.add(new Hawaii (size, salt, cheese));
                break;
            case 3:
                order.add(new Margarita (size, salt, cheese));
                break;
            case 4:
                order.add(new Classic (size, salt, cheese));
                break;
            case 5:
                order.add(new Roman (size, salt, cheese));
                break;
            case 6:
                order.add(new ThreeCheese (size, salt, cheese));
                break;
            case 7:
                order.add(new Mushroom (size, salt, cheese));
                break;
        }
        
        cout<< "Smt else?"<<endl;
        cin >> choice;
    }
    order.print();
    return 0;
}


