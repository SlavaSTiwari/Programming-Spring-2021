#include <iostream>
#include <string>
#include <ctime>
#include "elem_types.h"
#include "dyarray.h"
#include "linklist.h"
#include "sequence.h"
#include "queue.h"
#include <assert.h>

// Functions for map:

template <class T, template <class M> class S>
Queue<T, S>* Create_queue(int Q_type, int Item_type);

int main()
{
    srand(time(0));

    int myArr[5] = {1,2,3,4,5};
    int myArr_2[3] = {2,3,4};

    int num;
    int (**func_array)(int) = new (int (*[3])(int));
    func_array[0] = inc_1;
    func_array[1] = inc_2;
    func_array[2] = inc_3;

    std::cout << "   =====Basic Queues=====   " << std::endl;

    auto* List_q = new Queue<char, ArraySequence>();
    List_q->Push('a');
    List_q->Push('b');
    List_q->Push('c');

    auto* Arr_q = new Queue<double, ArraySequence>();
    Arr_q->Push(1);
    Arr_q->Push(2);
    Arr_q->Push(3);

    std::cout << "\n   =====Basic Sequences=====   " << std::endl;

    Sequence<int> *Seq_1 = new ListSequence<int>(myArr_2, 3);

    Sequence<int> *Seq_2 = new ArraySequence<int>(myArr, 5);

    if(Seq_1 == Seq_2){
        std::cout << "Seq_1 is equal to Seq_2!" << std::endl;
    };

    Seq_1->Append(10);
    Seq_1->Print();

    std::cout << "\n   ===== Concating Seq_1 and Seq_2 =====" << std::endl;


    Seq_2 = Seq_2->Concat(Seq_1);
    Seq_2->Print();

    std::cout << "\n   ===== MAP =====" << std::endl;

    Sequence<int> *Seq_4 = Seq_2->Map(square);

    Seq_4->Print();

    std::cout << "\n   ===== WHERE =====" << std::endl;

    Sequence<int> *Seq_5 = Seq_2->Where(is_even);

    Seq_5->Print();

    std::cout << "\n ===== REDUCE =====" << std::endl;

    int red_res = Seq_2->Reduce(reduce_sum);


    std::cout << "Reducing Seq_2" << std::endl;
    Seq_2->Print();

    std::cout << "Result: " << red_res << std::endl;

    std::cout << "\n   === SubSequence Search ===" << std::endl;

    Sequence<int> *Seq_7 = new ArraySequence<int>(myArr, 5);

    if(Seq_2->Search(Seq_7)){
        std::cout << "Sub Sequence found!" << std::endl;
    }

    // Sequence of Functions:
    Sequence<int(*)(int)> *func_seq = new ListSequence<int (*)(int)>(func_array, 3);
    std::cout << "\nThe result of Function sequence: " << func_seq->Get(2)(4) << std::endl;

    std::cout << "\n   =====SEQUENCE OF SEQUENCE=====\n" << std::endl;

    Sequence<ArraySequence<int> > *Seq_of_seq = new ArraySequence<ArraySequence<int> >();

    ArraySequence<int> *Arr_Seq_1 = new ArraySequence<int>;

    Arr_Seq_1->Append(31);
    Arr_Seq_1->Append(65);
    Arr_Seq_1->Append(43);

    ArraySequence<int> *Arr_Seq_2 = new ArraySequence<int>;

    Arr_Seq_2->Append(13);
    Arr_Seq_2->Append(55);
    Arr_Seq_2->Append(34);

    ArraySequence<int> *Arr_Seq_3 = new ArraySequence<int>;

    Arr_Seq_3->Append(16);
    Arr_Seq_3->Append(75);
    Arr_Seq_3->Prepend(11);
    Arr_Seq_3->Append(98);

    int arr[5] = {52,567,17,43,86};
    ArraySequence<int> *Arr_Seq_4 = new ArraySequence<int>(arr, 5);

    Seq_of_seq->Append(*Arr_Seq_1);
    Seq_of_seq->Append(*Arr_Seq_2);
    Seq_of_seq->Append(*Arr_Seq_3);
    Seq_of_seq->Append(*Arr_Seq_4);

    Seq_of_seq->Print();

    return 0;
}


