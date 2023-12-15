#include "BST.h"


using namespace std;

struct Person{
    int id;
    string name;
    int age;

    Person(){
        id = 0;
        name = "";
        age = 0;
    }

    Person(int a, string b, int c){
        id = a;
        name = b;
        age = c;
    }


};


bool operator<(Person A, Person B){
    return A.id < B.id;
}

bool operator>(Person A, Person B){
    return A.id > B.id;
}

std::ostream& operator<<(std::ostream& os, const Person& obj){
    os << "id: " << obj.id << endl;
    os << "name: " << obj.name << endl;
    os << "age: " << obj.age << endl;
    os << "-----------------------------------";
    os << endl;

    return os;
}

int main()
{

    BST<Person> arv01;

    Person aluno1(0, "Leonardo Dias Pertuzzatti", 22);

    Person aluno2(1, "Lucas Dias Pertuzzatti", 21);

    Person aluno3(5, "Juliana Dias Pertuzzatti", 18);

    Person aluno4(2, "Joelma Dias", 50);

    Person aluno5(11, "Eleandro Pertuzzatti", 50);

    Person aluno6(8, "Azul", 5);

    std::vector<Person> test{aluno1, aluno2, aluno3, aluno4, aluno5, aluno6};

    Person teste[] = {aluno1, aluno2, aluno3,aluno4,aluno5, aluno6};

    std::vector<Person> teste3 = {{0, "Leonardo Dias Pertuzzatti", 22}};


    /* Apontando para o id */

    arv01.balance(teste,0,5);

    arv01.preorder();

    Person* aluno7 = arv01.search(1);

    BST<Person> arv02;
    arv02 = arv01;
    arv02.inorder();

    BST<Person> arv03({aluno1,aluno2});

    return 0;
}