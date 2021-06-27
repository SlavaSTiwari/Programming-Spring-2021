#include<iostream>
#include<ctime>
#include<random>
#include"Binary_tree.h"
#include"elem_types.h"

int main(){
    srand(time(0));

    std::cout << "\n===== BASIC TREE =====\n" << std::endl;
    BStree<int> *Dummy = new BStree<int>();

    Dummy->Insert_Item(1);
    Dummy->Insert_Item(34);
    Dummy->Insert_Item(3);
    Dummy->Insert_Item(10);
    Dummy->Insert_Item(47);
    Dummy->Insert_Item(8);
    Dummy->Insert_Item(288);

    Dummy->root = Dummy->Delete_At(10, Dummy->root);

    std::cout << "Height of the Dummy-tree is: " << Dummy->Get_height() << std::endl;

    std::cout << "\n ===Displaying whole tree===\n" << std::endl;
    Dummy->Display_tree();

    std::cout << "\n\nInorder print: " << std::endl;
    Dummy->Inorder_Print();

    std::cout << "Preorder print: " << std::endl;
    Dummy->Preorder_Print();

    std::cout << "Postorder print: " << std::endl;
    Dummy->Postorder_Print();


    std::cout << "\n===== EXTRACTING AND PRINTING SUBTREE =====\n" << std::endl;
    BStree<int> *Extract = Dummy->Extract_Subtree(3);
    Extract->Inorder_Print();


    std::cout << "\n===== MAPPING AND PRINTING A TREE =====\n" << std::endl;
    BStree<int> *Map_bst = Dummy->Map(times_2);
    Map_bst->Inorder_Print();


    /*std::cout << "\n===== WHERE-ING AND PRINTING A TREE =====\n" << std::endl;
    BStree<int> *Where_bst = Dummy->Where(greater_than_three);
    Where_bst->Inorder_Print();*/


    std::cout << "\n===== MERGING/REDUCING A TREE =====\n" << std::endl;
    int x = Dummy->Reduce(reduce_sum);
    std::cout << "Sum-Reduced item: " << x << std::endl;

    int y = Dummy->Reduce(reduce_product);
    std::cout << "Multiply-Reduced item: " << y << std::endl;

    int z = Dummy->Reduce(reduce_greater);
    std::cout << "Greatest-Reduced item: " << z << std::endl;


    std::cout << "\n===== MAKING AND PRINTING A 'STUDENT' TREE =====\n" << std::endl;
    BStree<Student> *Stud_tree = new BStree<Student>();
    Student stud_1;
    stud_1.Randomize();

    Student stud_2;
    stud_2.Randomize();

    Student stud_3;
    stud_3.Randomize();

    Student stud_4;
    stud_4.Randomize();

    Stud_tree->Insert_Item(stud_1);
    Stud_tree->Insert_Item(stud_2);
    Stud_tree->Insert_Item(stud_3);
    Stud_tree->Insert_Item(stud_4);

    Stud_tree->Inorder_Print();


    std::cout << "\n===== CONVERTING STRING TO A TREE =====\n" << std::endl;
    std::string str = "this is a test for tree!";
    std::cout << "Converting the string: " << str << std::endl;
    BStree<char> *Char_tree = String_to_tree(str);

    Char_tree->Display_tree();

    std::cout << "\n\nInorder print: " << std::endl;
    Char_tree->Inorder_Print();

    std::cout << "\n===== MILLION ELEMENT EXERCISE =====\n" << std::endl;
    BStree<int> *Million_tree = new BStree<int>();

    int i = 0, rand_num;
    for(i; i<1000000; i++){
        rand_num = rand()%1000000;
        Million_tree->Insert_Item(rand_num);
        if(i%100 == 0){
            Million_tree->Delete_Node(rand_num);
        }
    }
    std::cout << "Height of the Million-tree is: " << Million_tree->Get_height() << std::endl;

    return 0;
}
