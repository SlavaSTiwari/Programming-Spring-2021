#include <iostream>
#include <string>
#include <ctime>
#include "elem_types.h"
#include "dyarray.h"
#include "linklist.h"
#include "sequence.h"
#include "queue.h"

// Functions for map:

int main()
{
    srand(time(0));
    int choice, type_queue, type_sequence_1, type_sequence_2, type_queue_func, type_seq_func;

    while(1) {
        std::cout << "     ==MAIN MENU==\n" << std::endl;
        std::cout << "Choose an option:\n1. Queue\n2. Sequence\n3. Quit\nChoose an option: ";
        choice = choose(1,3);
        switch(choice){
        case 1: //  -----QUEUE START-----  //
            std::cout << "Choose type of Queue:\n1. ArrayQueue\n2. ListQueue\n3. Return\nChoose an option: ";
            type_queue = choose(1,3);
            switch(type_queue){
            case 1: // ARRAY SEQUENCE
                std::cout << "\n   -----ARRAY QUEUE-----\n" << std::endl;
                std::cout << "Choose an option:\n1. Integer\n2. Complex number\n3. Function\n4. Student\n5. Teacher\nYour choice: ";
                type_queue_func = choose(1,5);
                switch(type_queue_func){
                case 1:{
                    auto *que_1 = new Queue<int, ArraySequence>();
                    int x;
                    while(1){
                        std::cout << "Perform an operation:\n1. Push\n2. Pop\n3. Print\n4. Exit program\nYour choice: ";
                        int que_1_choice = choose(1, 4);
                        switch(que_1_choice){
                        case 1:
                            std::cout << "Push item: ";
                            std::cin >> x;
                            que_1->Push(x);
                            break;
                        case 2:
                            x = que_1->Pop();
                            std::cout << "Popped item: " << x << std::endl;
                            break;

                        case 3:
                            std::cout << "\nPrinting the Queue:" << std::endl;
                            que_1->Print();
                            std::cout << std::endl;
                            break;
                        case 4:
                            std::cout << "\n\t--Exiting program--" << std::endl;
                            exit(EXIT_FAILURE);
                        }
                    }
                    break;
                }
                case 2:{
                    auto *que_1 = new Queue<Complex, ArraySequence>();
                    double real, imag;
                    while(1){
                        std::cout << "Perform an operation:\n1. Push\n2. Pop\n3. Print\n4. Exit program\nYour choice: ";
                        int que_1_choice = choose(1, 4);
                        switch(que_1_choice){
                        case 1:{
                            std::cout << "Push item: " << std::endl;
                            std::cout << "Real part: ";
                            std::cin >> real;
                            std::cout << "Imaginary part: ";
                            std::cin >> imag;
                            Complex x(real, imag);
                            que_1->Push(x);
                            break;
                        }
                        case 2:{
                            Complex x = que_1->Pop();
                            std::cout << "Popped item: " << x << std::endl;
                            break;
                        }
                        case 3:
                            std::cout << "\nPrinting the Queue:" << std::endl;
                            que_1->Print();
                            std::cout << std::endl;
                            break;
                        case 4:
                            std::cout << "\n\t--Exiting program--" << std::endl;
                            exit(EXIT_FAILURE);
                        }
                    }
                    break;
                }
                case 3: {
                    auto *que_1 = new Queue<int (*)(int), ArraySequence>();
                    que_1->Push(inc_1);
                    que_1->Push(inc_2);
                    que_1->Push(inc_3);
                    que_1->Push(times_2);
                    que_1->Push(square);
                    while(1){
                        std::cout << "Perform an operation:\n1. Pop and Apply Function to int\n2. Print\n3. Exit program\nYour choice: ";
                        int que_1_choice = choose(1, 3);
                        switch(que_1_choice){
                        case 1:{
                            int item;
                            std::cout << "Enter Int to pass to the popped function: ";
                            std::cin >> item;
                            int x = que_1->Pop()(item);
                            std::cout << "Popped item: " << x << std::endl;
                            break;
                        }
                        case 2:
                            std::cout << "\nPrinting the Queue:" << std::endl;
                            for(int i=0; i<que_1->GetLength(); i++){
                                que_1->LookAt(i);
                            }
                            //que_1->Print();
                            std::cout << std::endl;
                            break;
                        case 3:
                            std::cout << "\n\t--Exiting program--" << std::endl;
                            exit(EXIT_FAILURE);
                        }
                    }
                    break;
                }
                case 4: {
                    auto *que_1 = new Queue<Student, ArraySequence>();
                    std::string F_name, L_name, B_date, Stud_ID;
                    while(1){
                        std::cout << "Perform an operation:\n1. Push\n2. Pop\n3. Print\n4. Exit program\nYour choice: ";
                        int que_1_choice = choose(1, 4);
                        switch(que_1_choice){
                        case 1:{
                            std::cout << "Method of entry:\n1. Manual Entry\n2. Randomize\nYour choice: ";
                            int Entry = choose(1,2);
                            if(Entry==1){
                                std::cout << "First name: ";
                                std::cin >> F_name;
                                std::cout << "Last name: ";
                                std::cin >> L_name;
                                std::cout << "Birth date: ";
                                std::cin >> B_date;
                                std::cout << "Student ID: ";
                                std::cin >> Stud_ID;
                                Student x(F_name, L_name, B_date, Stud_ID);
                                que_1->Push(x);
                            }
                            else{
                                Student x;
                                x.Randomize();
                                std::cout << "Randomizing the Student" << std::endl;
                                que_1->Push(x); ////////////////////////////////////////
                            }
                            break;
                        }
                        case 2:{
                            Student x = que_1->Pop();
                            std::cout << "Popped item: " << x << std::endl;
                            break;
                        }
                        case 3:
                            std::cout << "\nPrinting the Queue:" << std::endl;
                            for(int i=0; i<que_1->GetLength(); i++){
                                que_1->LookAt(i);
                            }
                            //que_1->Print();
                            std::cout << std::endl;
                            break;
                        case 4:
                            std::cout << "\n\t--Exiting program--" << std::endl;
                            exit(EXIT_FAILURE);
                        }
                    }
                    break;
                }
                case 5: {
                    auto *que_1 = new Queue<Teacher, ArraySequence>();
                    std::string F_name, L_name, B_date, Teach_ID;
                    while(1){
                        std::cout << "Perform an operation:\n1. Push\n2. Pop\n3. Print\n4. Exit program\nYour choice: ";
                        int que_1_choice = choose(1, 4);
                        switch(que_1_choice){
                        case 1:{
                            std::cout << "Method of entry:\n1. Manual Entry\n2. Randomize\nYour choice: ";
                            int Entry = choose(1,2);
                            if(Entry==1){
                                std::cout << "First name: ";
                                std::cin >> F_name;
                                std::cout << "Last name: ";
                                std::cin >> L_name;
                                std::cout << "Birth date: ";
                                std::cin >> B_date;
                                std::cout << "Student ID: ";
                                std::cin >> Teach_ID;
                                Teacher x(F_name, L_name, B_date, Teach_ID);
                                que_1->Push(x);
                            }
                            else{
                                Teacher x;
                                x.Randomize();
                                std::cout << "Randomizing the Student" << std::endl;
                                que_1->Push(x); ////////////////////////////////////////
                            }
                            break;
                        }
                        case 2:{
                            Teacher x = que_1->Pop();
                            std::cout << "Popped item: " << x << std::endl;
                            break;
                        }
                        case 3:
                            std::cout << "\nPrinting the Queue:" << std::endl;
                            for(int i=0; i<que_1->GetLength(); i++){
                                que_1->LookAt(i);
                            }
                            //que_1->Print();
                            std::cout << std::endl;
                            break;
                        case 5:
                            std::cout << "\n\t--Exiting program--" << std::endl;
                            exit(EXIT_FAILURE);
                        }
                    }

                    break;
                }
                }
                break;

            case 2: // LIST SEQUENCE
                std::cout << "\n   -----LIST QUEUE-----\n" << std::endl;
                std::cout << "Choose an option:\n1. Integer\n2. Complex number\n3. Function\n4. Student\n5. Teacher\nYour choice:";
                type_queue_func = choose(1,6);
                switch(type_queue_func){
                case 1: {
                    auto *que_1 = new Queue<int, ListSequence>();
                    int x;
                    while(1){
                        std::cout << "Perform an operation:\n1. Push\n2. Pop\n3. Print\n4. Exit program\nYour choice: ";
                        int que_1_choice = choose(1, 4);
                        switch(que_1_choice){
                        case 1:
                            std::cout << "Push item: ";
                            std::cin >> x;
                            que_1->Push(x);
                            break;
                        case 2:
                            x = que_1->Pop();
                            std::cout << "Popped item: " << x << std::endl;
                            break;

                        case 3:
                            std::cout << "\nPrinting the Queue:" << std::endl;
                            que_1->Print();
                            std::cout << std::endl;
                            break;
                        case 4:
                            std::cout << "\n\t--Exiting program--" << std::endl;
                            exit(EXIT_FAILURE);
                        }
                    }
                    break;
                }
                case 2: {
                    auto *que_1 = new Queue<Complex, ArraySequence>();
                    double real, imag;
                    while(1){
                        std::cout << "Perform an operation:\n1. Push\n2. Pop\n3. Print\n4 Exit program\nYour choice: ";
                        int que_1_choice = choose(1, 4);
                        switch(que_1_choice){
                        case 1:{
                            std::cout << "Push item: ";
                            std::cout << "Real part: ";
                            std::cin >> real;
                            std::cout << "Imaginary part: ";
                            std::cin >> imag;
                            Complex x(real, imag);
                            que_1->Push(x);
                            break;
                        }
                        case 2:{
                            Complex x = que_1->Pop();
                            std::cout << "Popped item: " << x << std::endl;
                            break;
                        }
                        case 3:
                            std::cout << "\nPrinting the Queue:" << std::endl;
                            que_1->Print();
                            std::cout << std::endl;
                            break;
                        case 4:
                            std::cout << "\n\t--Exiting program--" << std::endl;
                            exit(EXIT_FAILURE);
                        }
                    }
                    break;
                }
                case 3: {
                    auto *que_1 = new Queue<int (*)(int), ListSequence>();
                    que_1->Push(inc_1);
                    que_1->Push(inc_2);
                    que_1->Push(inc_3);
                    que_1->Push(times_2);
                    que_1->Push(square);
                    while(1){
                        std::cout << "Perform an operation:\n1. Pop and Apply Function to int\n2. Print\n3. Exit program\nYour choice: ";
                        int que_1_choice = choose(1, 3);
                        switch(que_1_choice){
                        case 1:{
                            int item;
                            std::cout << "Enter Int to pass to the popped function: ";
                            std::cin >> item;
                            int x = que_1->Pop()(item);
                            std::cout << "Popped item: " << x << std::endl;
                            break;
                        }
                        case 2:
                            std::cout << "\nPrinting the Queue:" << std::endl;
                            for(int i=0; i<que_1->GetLength(); i++){
                                que_1->LookAt(i);
                            }
                            //que_1->Print();
                            std::cout << std::endl;
                            break;
                        case 3:
                            std::cout << "\n\t--Exiting program--" << std::endl;
                            exit(EXIT_FAILURE);
                        }
                    }
                    break;
                }
                case 4: {
                    auto *que_1 = new Queue<Student, ListSequence>();
                    std::string F_name, L_name, B_date, Stud_ID;
                    while(1){
                        std::cout << "Perform an operation:\n1. Push\n2. Pop\n3. Print\n4. Exit program\nYour choice: ";
                        int que_1_choice = choose(1, 4);
                        switch(que_1_choice){
                        case 1:{
                            std::cout << "Method of entry:\n1. Manual Entry\n2. Randomize\nYour choice: ";
                            int Entry = choose(1,2);
                            if(Entry==1){
                                std::cout << "First name: ";
                                std::cin >> F_name;
                                std::cout << "Last name: ";
                                std::cin >> L_name;
                                std::cout << "Birth date: ";
                                std::cin >> B_date;
                                std::cout << "Student ID: ";
                                std::cin >> Stud_ID;
                                Student x(F_name, L_name, B_date, Stud_ID);
                                que_1->Push(x);
                            }
                            else{
                                std::cout << "Randomizing the Student" << std::endl;
                                Student x;
                                x.Randomize();
                                que_1->Push(x);
                            }
                            break;
                        }
                        case 2:{
                            Student x = que_1->Pop();
                            std::cout << "Popped item: " << x << std::endl;
                            break;
                        }
                        case 3:
                            std::cout << "\nPrinting the Queue:" << std::endl;
                            for(int i=0; i<que_1->GetLength(); i++){
                                que_1->LookAt(i);
                            }
                            //que_1->Print();
                            std::cout << std::endl;
                            break;
                        case 4:
                            std::cout << "\n\t--Exiting program--" << std::endl;
                            exit(EXIT_FAILURE);
                        }
                    }
                    break;
                }
                case 5: {
                    auto *que_1 = new Queue<Teacher, ListSequence>();
                    std::string F_name, L_name, B_date, Teach_ID;
                    while(1){
                        std::cout << "Perform an operation:\n1. Push\n2. Pop\n3. Print\n4. Exit program\nYour choice: ";
                        int que_1_choice = choose(1, 4);
                        switch(que_1_choice){
                        case 1:{
                            std::cout << "Method of entry:\n1. Manual Entry\n2. Randomize\nYour choice: ";
                            int Entry = choose(1,2);
                            if(Entry==1){
                                std::cout << "First name: ";
                                std::cin >> F_name;
                                std::cout << "Last name: ";
                                std::cin >> L_name;
                                std::cout << "Birth date: ";
                                std::cin >> B_date;
                                std::cout << "Student ID: ";
                                std::cin >> Teach_ID;
                                Teacher x(F_name, L_name, B_date, Teach_ID);
                                que_1->Push(x);
                            }
                            else{
                                Teacher x;
                                x.Randomize();
                                std::cout << "Randomizing the Student" << std::endl;
                                que_1->Push(x); ////////////////////////////////////////
                            }
                            break;
                        }
                        case 2:{
                            Teacher x = que_1->Pop();
                            std::cout << "Popped item: " << x << std::endl;
                            break;
                        }
                        case 3:
                            std::cout << "\nPrinting the Queue:" << std::endl;
                            for(int i=0; i<que_1->GetLength(); i++){
                                que_1->LookAt(i);
                            }
                            //que_1->Print();
                            std::cout << std::endl;
                            break;
                        case 4:
                            std::cout << "\n\t--Exiting program--" << std::endl;
                            exit(EXIT_FAILURE);
                        }
                    }
                    break;
                }
                }
                break;
            case 3:
                break;
            }
        break;
            //  ----- END OF QUEUE -----  //

        case 2: //  -----Sequence-----   //
            std::cout << "Choose an option:\n1. Integer\n2. Complex number\n3. Function\n4. Student\n5. Teacher\n6. Return\nYour choice: ";
            type_seq_func = choose(1, 6);
            switch(type_seq_func){
            case 1:{ //   ----- INTEGER -----   //
                Sequence<int> *seq_1, *seq_2, *advanced_seq;
                int seq_1_mod_choice, seq_2_mod_choice, input, output, index, advanced_choice, concat_choice;
                std::cout << "Enter the type of 1st Sequence:\n1. Array Sequence\n2. List Sequence\nYour choice: ";
                type_sequence_1 = choose(1,2);
                if(type_sequence_1 == 1){ seq_1 = new ArraySequence<int>(); }
                else{ seq_1 = new ListSequence<int>(); }

                std::cout << "Enter the type of 2nd Sequence:\n1. Array Sequence\n2. List Sequence\nYour choice: ";
                type_sequence_2 = choose(1,2);
                if(type_sequence_2 == 1){ seq_2 = new ArraySequence<int>(); }
                else{ seq_2 = new ListSequence<int>(); }

                while(1){
                    std::cout << "\n----- OPERATIONS MENU -----" << std::endl;
                    std::cout << "\nSelect an operation:\n1. Modify Sequence 1\n2. Modify Sequence 2\n3. Advanced operation\n4. Exit program\nYour choice: ";
                    int mod_choice = choose(1,4);
                    switch(mod_choice){
                    case 1:
                        do{
                            std::cout << "\n----- SEQUENCE 1 -----" << std::endl;
                            std::cout << "\n Select an operation for Sequence 1:\n1. Append\n2. Prepend\n3. Print\n4. Get Length of Sequence\n5. Get ITEM at index\n6. Delete first item\n7. Delete last item\n8. Return\nYour choice: ";
                            seq_1_mod_choice = choose(1,8);
                            switch(seq_1_mod_choice){
                            case 1:
                                std::cout << "Enter a value: ";
                                std::cin >> input;
                                seq_1->Append(input);
                                break;
                            case 2:
                                std::cout << "Enter a value: ";
                                std::cin >> input;
                                seq_1->Prepend(input);
                                break;
                            case 3:
                                std::cout << "\nPrinting Sequence 1:" << std::endl;
                                seq_1->Print();
                                break;
                            case 4:
                                std::cout << "\nLength of Sequence 1: " << seq_1->GetLength() << "\n" << std::endl;
                                break;
                            case 5:
                                std::cout << "\nEnter a valid index: ";
                                index = choose(0,seq_1->GetLength());
                                output = seq_1->Get(index);
                                std::cout << "Item at index '" << index << "' is: " << output << std::endl;
                                break;
                            case 6:
                                std::cout << "Deleting ITEM at first index." << std::endl;
                                seq_1->Delete_first();
                                break;
                            case 7:
                                std::cout << "Deleting ITEM at last index." << std::endl;
                                seq_1->Delete_last();
                                break;
                            }
                        }while(seq_1_mod_choice != 8);
                        break;
                    case 2:
                        do{
                            std::cout << "\n----- SEQUENCE 2 -----" << std::endl;
                            std::cout << "\nSelect an operation for Sequence 2:\n1. Append\n2. Prepend\n3. Print\n4. Get Length of Sequence\n5. Get ITEM at index\n6. Delete first item\n7. Delete last item\n8. Return\nYour choice: ";
                            seq_2_mod_choice = choose(1,8);
                            switch(seq_2_mod_choice){
                            case 1:
                                std::cout << "Enter a value: ";
                                std::cin >> input;
                                seq_2->Append(input);
                                break;
                            case 2:
                                std::cout << "Enter a value: ";
                                std::cin >> input;
                                seq_2->Prepend(input);
                                break;
                            case 3:
                                std::cout << "\nPrinting Sequence 2:" << std::endl;
                                seq_2->Print();
                                break;
                            case 4:
                                std::cout << "\nLength of Sequence 2: " << seq_2->GetLength() << "\n" << std::endl;
                                break;
                            case 5:
                                std::cout << "\nEnter a valid index: ";
                                index = choose(0,seq_2->GetLength());
                                output = seq_2->Get(index);
                                std::cout << "Item at index '" << index << "' is: " << output << std::endl;
                                break;
                            case 6:
                                std::cout << "Deleting ITEM at first index." << std::endl;
                                seq_2->Delete_first();
                                break;
                            case 7:
                                std::cout << "Deleting ITEM at last index." << std::endl;
                                seq_2->Delete_last();
                                break;
                            }
                        }while(seq_2_mod_choice != 8);
                        break;
                    case 3:
                        int map_seq_choice, map_func_choice, where_seq_choice, where_func_choice, red_result, reduce_seq_choice, reduce_func_choice, subseq_choice;
                        do{
                            std::cout << "\n----- ADVANCED OPERATIONS-----\n" << std::endl;
                            std::cout << "1. Map\n2. Where\n3. Reduce\n4. Search for SEQ_1 in SEQ_2\n5. Concatenate\n6. Get a Subsequence\n7. Return\nYour choice: ";
                            advanced_choice = choose(1,7);
                            switch(advanced_choice){
                            case 1: // MAP
                                std::cout << "Choose a Sequence to MAP:\n1. Sequence 1\n2. Sequence 2\nYour choice: ";
                                map_seq_choice = choose(1,2);

                                std::cout << "Choose a function to map:\n1. Add 1\n2. Add 2\n3. Add 3\n4. Times 2\n5. Square\nYour choice: ";
                                map_func_choice = choose(1,5);

                                if(map_seq_choice == 1){
                                    switch(map_func_choice){
                                    case 1:
                                        seq_1 = seq_1->Map(inc_1);
                                        break;
                                    case 2:
                                        seq_1 = seq_1->Map(inc_2);
                                        break;
                                    case 3:
                                        seq_1 = seq_1->Map(inc_3);
                                        break;
                                    case 4:
                                        seq_1 = seq_1->Map(times_2);
                                        break;
                                    case 5:
                                        seq_1 = seq_1->Map(square);
                                        break;
                                    }
                                    seq_1->Print();
                                }
                                else{
                                    switch(map_func_choice){
                                    case 1:
                                        seq_2 = seq_2->Map(inc_1);
                                        break;
                                    case 2:
                                        seq_2 = seq_2->Map(inc_2);
                                        break;
                                    case 3:
                                        seq_2 = seq_2->Map(inc_3);
                                        break;
                                    case 4:
                                        seq_2 = seq_2->Map(times_2);
                                        break;
                                    case 5:
                                        seq_2 = seq_2->Map(square);
                                        break;
                                    }
                                    seq_2->Print();
                                }
                            break;
                            case 2: // WHERE
                                std::cout << "Choose a Sequence for WHERE:\n1. Sequence 1\n2. Sequence 2\nYour choice: ";
                                where_seq_choice = choose(1,2);

                                std::cout << "Choose a function for WHERE:\n1. Less than 3\n2. Equal to 4\n3. Greater than 3\n4. is Even\n5. is Odd\nYour choice: ";
                                where_func_choice = choose(1,5);

                                if(where_seq_choice == 1){
                                    switch(where_func_choice){
                                    case 1:
                                        advanced_seq = seq_1->Where(less_than_three);
                                        break;
                                    case 2:
                                        advanced_seq = seq_1->Where(equal_to_four);
                                        break;
                                    case 3:
                                        advanced_seq = seq_1->Where(greater_than_three);
                                        break;
                                    case 4:
                                        advanced_seq = seq_1->Where(is_even);
                                        break;
                                    case 5:
                                        advanced_seq = seq_1->Where(is_odd);
                                        break;
                                    }
                                    advanced_seq->Print();
                                }
                                else{
                                    switch(where_func_choice){
                                    case 1:
                                        advanced_seq = seq_2->Where(less_than_three);
                                        break;
                                    case 2:
                                        advanced_seq = seq_2->Where(equal_to_four);
                                        break;
                                    case 3:
                                        advanced_seq = seq_2->Where(greater_than_three);
                                        break;
                                    case 4:
                                        advanced_seq = seq_2->Where(is_even);
                                        break;
                                    case 5:
                                        advanced_seq = seq_2->Where(is_odd);
                                        break;
                                    }
                                    advanced_seq->Print();
                                }
                            break;
                            case 3: // REDUCE:
                                std::cout << "Choose a Sequence to REDUCE:\n1. Sequence 1\n2. Sequence 2\nYour choice: ";
                                reduce_seq_choice = choose(1,2);

                                std::cout << "Choose a function for REDUCE:\n1. Add\n2. Multiply\n3. Greatest Value\nYour choice: ";
                                reduce_func_choice = choose(1,3);

                                if(reduce_seq_choice == 1){
                                    switch(reduce_func_choice){
                                    case 1:
                                        red_result = seq_1->Reduce(reduce_sum);
                                        break;
                                    case 2:
                                        red_result = seq_1->Reduce(reduce_product);
                                        break;
                                    case 3:
                                        red_result = seq_1->Reduce(reduce_greater);
                                        break;
                                    }
                                    std::cout << red_result << std::endl;
                                }
                                else{
                                    switch(reduce_func_choice){
                                    case 1:
                                        red_result = seq_2->Reduce(reduce_sum);
                                        break;
                                    case 2:
                                        red_result = seq_2->Reduce(reduce_product);
                                        break;
                                    case 3:
                                        red_result = seq_2->Reduce(reduce_greater);
                                        break;
                                    }
                                    std::cout << red_result << std::endl;
                                }
                            break;
                            case 4:
                                if(seq_2->Search(seq_1)){
                                    std::cout << "Subsequence found!" << std::endl;
                                }
                                else{
                                    std::cout << "Subsequence not found" << std::endl;
                                }
                            break;
                            case 5:
                                std::cout << "Choose an option for concatenation:\n1. Sequence 1 + Sequence 2\n2. Sequence 2 + Sequence 1\nEnter your choice: ";
                                concat_choice = choose(1,2);
                                if(concat_choice == 1){
                                    seq_1->Concat(seq_2);
                                }
                                else{
                                    seq_2->Concat(seq_1);
                                }
                            break;
                            case 6:
                                int start_ind, end_ind;
                                std::cout << "Choose a Sequence for slicing:\n1. Sequence 1\n2. Sequence 2\nYour choice:";
                                subseq_choice = choose(1,2);
                                if(subseq_choice == 1){
                                    std::cout << "Choose the start index: ";
                                    start_ind = choose(0, seq_1->GetLength());
                                    std::cout << "Choose the end index: ";
                                    end_ind = choose(start_ind, seq_1->GetLength());
                                    advanced_seq = seq_1->GetSubsequence(start_ind, end_ind);
                                }
                                else{
                                    std::cout << "Choose the start index: ";
                                    start_ind = choose(0, seq_2->GetLength());
                                    std::cout << "Choose the end index: ";
                                    end_ind = choose(start_ind, seq_2->GetLength());
                                    advanced_seq = seq_2->GetSubsequence(start_ind, end_ind);
                                }
                                std::cout << "Printing the subsequence:" << std::endl;
                                advanced_seq->Print();
                            break;
                            }
                        }while(advanced_choice != 7);

                        break;

                    case 4:
                        std::cout << "\n\t--Exiting program--" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                }
                break;
                } //   ===== INTEGER END =====   //
            case 2: { //   ----- COMPLEX START -----   //
                Sequence<Complex> *seq_1, *seq_2, *advanced_seq;
                int real, imag, seq_1_mod_choice, seq_2_mod_choice, index, advanced_choice, concat_choice;
                std::cout << "Enter the type of 1st Sequence:\n1. Array Sequence\n2. List Sequence\nYour choice: ";
                type_sequence_1 = choose(1,2);
                if(type_sequence_1 == 1){ seq_1 = new ArraySequence<Complex>(); }
                else{ seq_1 = new ListSequence<Complex>(); }

                std::cout << "Enter the type of 2nd Sequence:\n1. Array Sequence\n2. List Sequence\nYour choice: ";
                type_sequence_2 = choose(1,2);
                if(type_sequence_2 == 1){ seq_2 = new ArraySequence<Complex>(); }
                else{ seq_2 = new ListSequence<Complex>(); }

                while(1){
                    std::cout << "\n----- OPERATIONS MENU -----" << std::endl;
                    std::cout << "\nSelect an operation:\n1. Modify Sequence 1\n2. Modify Sequence 2\n3. Advanced operation\n4. Exit program\nYour choice: ";
                    int mod_choice = choose(1,4);
                    switch(mod_choice){
                    case 1:
                        do{
                            std::cout << "\n----- SEQUENCE 1 -----" << std::endl;
                            std::cout << "\n Select an operation for Sequence 1:\n1. Append\n2. Prepend\n3. Print\n4. Get Length of Sequence\n5. Get ITEM at index\n6. Delete first item\n7. Delete last item\n8. Return\nYour choice: ";
                            seq_1_mod_choice = choose(1,8);
                            switch(seq_1_mod_choice){
                            case 1:{
                                std::cout << "Enter a value: " << std::endl;
                                std::cout << "Real part: ";
                                std::cin >> real;
                                std::cout << "Imaginary part: ";
                                std::cin >> imag;
                                Complex input(real, imag);
                                seq_1->Append(input);
                                break;
                            }
                            case 2:{
                                std::cout << "Enter a value: " << std::endl;
                                std::cout << "Real part: ";
                                std::cin >> real;
                                std::cout << "Imaginary part: ";
                                std::cin >> imag;
                                Complex input(real, imag);
                                seq_1->Prepend(input);
                                break;
                            }
                            case 3:
                                std::cout << "\nPrinting Sequence 1:" << std::endl;
                                seq_1->Print();
                                break;
                            case 4:
                                std::cout << "\nLength of Sequence 1: " << seq_1->GetLength() << "\n" << std::endl;
                                break;
                            case 5:{
                                std::cout << "\nEnter a valid index: ";
                                index = choose(0,seq_1->GetLength());
                                Complex output = seq_1->Get(index);
                                std::cout << "Item at index '" << index << "' is: " << output << std::endl;
                                break;
                            }
                            case 6:
                                std::cout << "Deleting ITEM at first index." << std::endl;
                                seq_1->Delete_first();
                                break;
                            case 7:
                                std::cout << "Deleting ITEM at last index." << std::endl;
                                seq_1->Delete_last();
                                break;
                            }
                        }while(seq_1_mod_choice != 8);
                        break;
                    case 2:
                        do{
                            std::cout << "\n----- SEQUENCE 2 -----" << std::endl;
                            std::cout << "\nSelect an operation for Sequence 2:\n1. Append\n2. Prepend\n3. Print\n4. Get Length of Sequence\n5. Get ITEM at index\n6. Delete first item\n7. Delete last item\n8. Return\nYour choice: ";
                            seq_2_mod_choice = choose(1,8);
                            switch(seq_2_mod_choice){
                            case 1: {
                                std::cout << "Enter a value: " << std::endl;
                                std::cout << "Real part: ";
                                std::cin >> real;
                                std::cout << "Imaginary part: ";
                                std::cin >> imag;
                                Complex input(real, imag);
                                seq_2->Append(input);
                                break;
                            }
                            case 2:{
                                std::cout << "Enter a value: " << std::endl;
                                std::cout << "Real part: ";
                                std::cin >> real;
                                std::cout << "Imaginary part: ";
                                std::cin >> imag;
                                Complex input(real, imag);
                                seq_2->Prepend(input);
                                break;
                            }
                            case 3:
                                std::cout << "\nPrinting Sequence 2:" << std::endl;
                                seq_2->Print();
                                break;
                            case 4:
                                std::cout << "\nLength of Sequence 2: " << seq_2->GetLength() << "\n" << std::endl;
                                break;
                            case 5:{
                                std::cout << "\nEnter a valid index: ";
                                index = choose(0,seq_2->GetLength());
                                Complex output = seq_2->Get(index);
                                std::cout << "Item at index '" << index << "' is: " << output << std::endl;
                                break;
                            }
                            case 6:
                                std::cout << "Deleting ITEM at first index." << std::endl;
                                seq_2->Delete_first();
                                break;
                            case 7:
                                std::cout << "Deleting ITEM at last index." << std::endl;
                                seq_2->Delete_last();
                                break;
                            }
                        }while(seq_2_mod_choice != 8);
                        break;
                    case 3:
                        int subseq_choice;
                        do{
                            std::cout << "\n----- ADVANCED OPERATIONS-----\n" << std::endl;
                            std::cout << "1. Search for SEQ_1 in SEQ_2\n2. Concatenate\n3. Get a Subsequence\n4. Return\nYour choice: ";
                            advanced_choice = choose(1,4);
                            switch(advanced_choice){
                            case 1:
                                if(seq_2->Search(seq_1)){
                                    std::cout << "Subsequence found!" << std::endl;
                                }
                                else{
                                    std::cout << "Subsequence not found" << std::endl;
                                }
                            break;
                            case 2:
                                std::cout << "Choose an option for concatenation:\n1. Sequence 1 + Sequence 2\n2. Sequence 2 + Sequence 1\nEnter your choice: ";
                                concat_choice = choose(1,2);
                                if(concat_choice == 1){
                                    seq_1->Concat(seq_2);
                                }
                                else{
                                    seq_2->Concat(seq_1);
                                }
                            break;
                            case 3:
                                int start_ind, end_ind;
                                std::cout << "Choose a Sequence for slicing:\n1. Sequence 1\n2. Sequence 2\nYour choice:";
                                subseq_choice = choose(1,2);
                                if(subseq_choice == 1){
                                    std::cout << "Choose the start index: ";
                                    start_ind = choose(0, seq_1->GetLength());
                                    std::cout << "Choose the end index: ";
                                    end_ind = choose(start_ind, seq_1->GetLength());
                                    advanced_seq = seq_1->GetSubsequence(start_ind, end_ind);
                                }
                                else{
                                    std::cout << "Choose the start index: ";
                                    start_ind = choose(0, seq_2->GetLength());
                                    std::cout << "Choose the end index: ";
                                    end_ind = choose(start_ind, seq_2->GetLength());
                                    advanced_seq = seq_2->GetSubsequence(start_ind, end_ind);
                                }
                                std::cout << "Printing the subsequence:" << std::endl;
                                advanced_seq->Print();
                            break;
                            }
                        }while(advanced_choice != 4);

                        break;

                    case 4:
                        std::cout << "\n\t--Exiting program--" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                }
                break;
                }//   ===== COMPLEX END =====   //
            case 3:{
                Sequence<int(*)(int)> *seq_1, *advanced_seq;
                int real, imag, seq_1_mod_choice, index, func_choice, val;

                int (**func_array)(int) = new (int (*[5])(int));
                func_array[0] = inc_1;
                func_array[1] = inc_2;
                func_array[2] = inc_3;
                func_array[3] = times_2;
                func_array[4] = square;

                std::cout << "Enter the type of 1st Sequence:\n1. Array Sequence\n2. List Sequence\nYour choice: ";
                type_sequence_1 = choose(1,2);
                if(type_sequence_1 == 1){ seq_1 = new ArraySequence<int(*)(int)>(func_array, 5); }
                else{ seq_1 = new ListSequence<int(*)(int)>(func_array, 5); }

                while(1){
                    std::cout << "Choose an operation:\n1. Use a Function\n2. Exit\nYour Choice: ";
                    seq_1_mod_choice = choose(1,2);
                    switch(seq_1_mod_choice){
                    case 1:
                        std::cout << "Choose a function:\n1. Add 1\n2. Add 2\n3. Add 3\n4. Multiply by 2\n5. Square\nEnter your choice: ";
                        func_choice = choose(1,5);
                        std::cout << "Enter an INT value: ";
                        std::cin >> val;
                        std::cout << "\nThe result is: " << seq_1->Get(func_choice-1)(val) << "\n" <<  std::endl;
                        break;
                    case 2:
                        std::cout << "\n\t--Exiting program--" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                }
                break;
            }//   ===== FUNCTION END =====   //
            case 4:{ //   ----- STUDENT START -----   //
                Sequence<Student> *seq_1, *seq_2, *advanced_seq;
                int real, imag, seq_1_mod_choice, seq_2_mod_choice, index, advanced_choice, concat_choice;
                std::string F_name, L_name, Stud_ID, B_date;
                std::cout << "Enter the type of 1st Sequence:\n1. Array Sequence\n2. List Sequence\nYour choice: ";
                type_sequence_1 = choose(1,2);
                if(type_sequence_1 == 1){ seq_1 = new ArraySequence<Student>(); }
                else{ seq_1 = new ListSequence<Student>(); }

                std::cout << "Enter the type of 2nd Sequence:\n1. Array Sequence\n2. List Sequence\nYour choice: ";
                type_sequence_2 = choose(1,2);
                if(type_sequence_2 == 1){ seq_2 = new ArraySequence<Student>(); }
                else{ seq_2 = new ListSequence<Student>(); }

                while(1){
                    std::cout << "\n----- OPERATIONS MENU -----" << std::endl;
                    std::cout << "\nSelect an operation:\n1. Modify Sequence 1\n2. Modify Sequence 2\n3. Advanced operation\n4. Exit program\nYour choice: ";
                    int mod_choice = choose(1,4);
                    switch(mod_choice){
                    case 1:
                        do{
                            std::cout << "\n----- SEQUENCE 1 -----" << std::endl;
                            std::cout << "\n Select an operation for Sequence 1:\n1. Append\n2. Prepend\n3. Print\n4. Get Length of Sequence\n5. Get ITEM at index\n6. Delete first item\n7. Delete last item\n8. Return\nYour choice: ";
                            seq_1_mod_choice = choose(1,8);
                            switch(seq_1_mod_choice){
                            case 1:{
                                std::cout << "Method of entry:\n1. Manual Entry\n2. Randomize\nYour choice: ";
                                int Entry = choose(1,2);
                                if(Entry==1){
                                    std::cout << "First name: ";
                                    std::cin >> F_name;
                                    std::cout << "Last name: ";
                                    std::cin >> L_name;
                                    std::cout << "Birth date: ";
                                    std::cin >> B_date;
                                    std::cout << "Student ID: ";
                                    std::cin >> Stud_ID;
                                    Student input(F_name, L_name, B_date, Stud_ID);
                                    seq_1->Append(input);
                                }
                                else{
                                    Student input;
                                    input.Randomize();
                                    std::cout << "Randomizing the Student" << std::endl;
                                    seq_1->Append(input);
                                }
                                break;
                            }
                            case 2:{
                                std::cout << "Method of entry:\n1. Manual Entry\n2. Randomize\nYour choice: ";
                                int Entry = choose(1,2);
                                if(Entry==1){
                                    std::cout << "First name: ";
                                    std::cin >> F_name;
                                    std::cout << "Last name: ";
                                    std::cin >> L_name;
                                    std::cout << "Birth date: ";
                                    std::cin >> B_date;
                                    std::cout << "Student ID: ";
                                    std::cin >> Stud_ID;
                                    Student input(F_name, L_name, B_date, Stud_ID);
                                    seq_1->Append(input);
                                }
                                else{
                                    Student input;
                                    input.Randomize();
                                    std::cout << "Randomizing the Student" << std::endl;
                                    seq_1->Append(input);
                                }
                                break;
                            }
                            case 3:
                                std::cout << "\nPrinting Sequence 1:" << std::endl;
                                seq_1->Print();
                                break;
                            case 4:
                                std::cout << "\nLength of Sequence 1: " << seq_1->GetLength() << "\n" << std::endl;
                                break;
                            case 5:{
                                std::cout << "\nEnter a valid index: ";
                                index = choose(0,seq_1->GetLength());
                                Student output = seq_1->Get(index);
                                std::cout << "Item at index '" << index << "' is: " << output << std::endl;
                                break;
                            }
                            case 6:
                                std::cout << "Deleting ITEM at first index." << std::endl;
                                seq_1->Delete_first();
                                break;
                            case 7:
                                std::cout << "Deleting ITEM at last index." << std::endl;
                                seq_1->Delete_last();
                                break;
                            }
                        }while(seq_1_mod_choice != 8);
                        break;
                    case 2:
                        do{
                            std::cout << "\n----- SEQUENCE 2 -----" << std::endl;
                            std::cout << "\nSelect an operation for Sequence 2:\n1. Append\n2. Prepend\n3. Print\n4. Get Length of Sequence\n5. Get ITEM at index\n6. Delete first item\n7. Delete last item\n8. Return\nYour choice: ";
                            seq_2_mod_choice = choose(1,8);
                            switch(seq_2_mod_choice){
                            case 1: {
                                std::cout << "Method of entry:\n1. Manual Entry\n2. Randomize\nYour choice: ";
                                int Entry = choose(1,2);
                                if(Entry==1){
                                    std::cout << "First name: ";
                                    std::cin >> F_name;
                                    std::cout << "Last name: ";
                                    std::cin >> L_name;
                                    std::cout << "Birth date: ";
                                    std::cin >> B_date;
                                    std::cout << "Student ID: ";
                                    std::cin >> Stud_ID;
                                    Student input(F_name, L_name, B_date, Stud_ID);
                                    seq_2->Append(input);
                                }
                                else{
                                    Student input;
                                    input.Randomize();
                                    std::cout << "Randomizing the Student" << std::endl;
                                    seq_2->Append(input);
                                }
                                break;
                            }
                            case 2:{
                                std::cout << "Method of entry:\n1. Manual Entry\n2. Randomize\nYour choice: ";
                                int Entry = choose(1,2);
                                if(Entry==1){
                                    std::cout << "First name: ";
                                    std::cin >> F_name;
                                    std::cout << "Last name: ";
                                    std::cin >> L_name;
                                    std::cout << "Birth date: ";
                                    std::cin >> B_date;
                                    std::cout << "Student ID: ";
                                    std::cin >> Stud_ID;
                                    Student input(F_name, L_name, B_date, Stud_ID);
                                    seq_2->Append(input);
                                }
                                else{
                                    Student input;
                                    input.Randomize();
                                    std::cout << "Randomizing the Student" << std::endl;
                                    seq_2->Append(input);
                                }
                                break;
                            }
                            case 3:
                                std::cout << "\nPrinting Sequence 2:" << std::endl;
                                seq_2->Print();
                                break;
                            case 4:
                                std::cout << "\nLength of Sequence 2: " << seq_2->GetLength() << "\n" << std::endl;
                                break;
                            case 5:{
                                std::cout << "\nEnter a valid index: ";
                                index = choose(0,seq_2->GetLength());
                                Student output = seq_2->Get(index);
                                std::cout << "Item at index '" << index << "' is: " << output << std::endl;
                                break;
                            }
                            case 6:
                                std::cout << "Deleting ITEM at first index." << std::endl;
                                seq_2->Delete_first();
                                break;
                            case 7:
                                std::cout << "Deleting ITEM at last index." << std::endl;
                                seq_2->Delete_last();
                                break;
                            }
                        }while(seq_2_mod_choice != 8);
                        break;
                    case 3:
                        int subseq_choice;
                        do{
                            std::cout << "\n----- ADVANCED OPERATIONS-----\n" << std::endl;
                            std::cout << "1. Search for SEQ_1 in SEQ_2\n2. Concatenate\n3. Get a Subsequence\n4. Return\nYour choice: ";
                            advanced_choice = choose(1,4);
                            switch(advanced_choice){
                            case 1:
                                if(seq_2->Search(seq_1)){
                                    std::cout << "Subsequence found!" << std::endl;
                                }
                                else{
                                    std::cout << "Subsequence not found" << std::endl;
                                }
                            break;
                            case 2:
                                std::cout << "Choose an option for concatenation:\n1. Sequence 1 + Sequence 2\n2. Sequence 2 + Sequence 1\nEnter your choice: ";
                                concat_choice = choose(1,2);
                                if(concat_choice == 1){
                                    seq_1->Concat(seq_2);
                                }
                                else{
                                    seq_2->Concat(seq_1);
                                }
                            break;
                            case 3:
                                int start_ind, end_ind;
                                std::cout << "Choose a Sequence for slicing:\n1. Sequence 1\n2. Sequence 2\nYour choice:";
                                subseq_choice = choose(1,2);
                                if(subseq_choice == 1){
                                    std::cout << "Choose the start index: ";
                                    start_ind = choose(0, seq_1->GetLength());
                                    std::cout << "Choose the end index: ";
                                    end_ind = choose(start_ind, seq_1->GetLength());
                                    advanced_seq = seq_1->GetSubsequence(start_ind, end_ind);
                                }
                                else{
                                    std::cout << "Choose the start index: ";
                                    start_ind = choose(0, seq_2->GetLength());
                                    std::cout << "Choose the end index: ";
                                    end_ind = choose(start_ind, seq_2->GetLength());
                                    advanced_seq = seq_2->GetSubsequence(start_ind, end_ind);
                                }
                                std::cout << "Printing the subsequence:" << std::endl;
                                advanced_seq->Print();
                            break;
                            }
                        }while(advanced_choice != 4);

                        break;

                    case 4:
                        std::cout << "\n\t--Exiting program--" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                }
                break;
            } //   ===== STUDENT END =====   //
        case 5:{ //   ----- TEACHER START -----   //
            Sequence<Teacher> *seq_1, *seq_2, *advanced_seq;
                int real, imag, seq_1_mod_choice, seq_2_mod_choice, index, advanced_choice, concat_choice;
                std::string F_name, L_name, Teach_ID, B_date;
                std::cout << "Enter the type of 1st Sequence:\n1. Array Sequence\n2. List Sequence\nYour choice: ";
                type_sequence_1 = choose(1,2);
                if(type_sequence_1 == 1){ seq_1 = new ArraySequence<Teacher>(); }
                else{ seq_1 = new ListSequence<Teacher>(); }

                std::cout << "Enter the type of 2nd Sequence:\n1. Array Sequence\n2. List Sequence\nYour choice: ";
                type_sequence_2 = choose(1,2);
                if(type_sequence_2 == 1){ seq_2 = new ArraySequence<Teacher>(); }
                else{ seq_2 = new ListSequence<Teacher>(); }

                while(1){
                    std::cout << "\n----- OPERATIONS MENU -----" << std::endl;
                    std::cout << "\nSelect an operation:\n1. Modify Sequence 1\n2. Modify Sequence 2\n3. Advanced operation\n4. Exit program\nYour choice: ";
                    int mod_choice = choose(1,4);
                    switch(mod_choice){
                    case 1:
                        do{
                            std::cout << "\n----- SEQUENCE 1 -----" << std::endl;
                            std::cout << "\n Select an operation for Sequence 1:\n1. Append\n2. Prepend\n3. Print\n4. Get Length of Sequence\n5. Get ITEM at index\n6. Delete first item\n7. Delete last item\n8. Return\nYour choice: ";
                            seq_1_mod_choice = choose(1,8);
                            switch(seq_1_mod_choice){
                            case 1:{
                                std::cout << "Method of entry:\n1. Manual Entry\n2. Randomize\nYour choice: ";
                                int Entry = choose(1,2);
                                if(Entry==1){
                                    std::cout << "First name: ";
                                    std::cin >> F_name;
                                    std::cout << "Last name: ";
                                    std::cin >> L_name;
                                    std::cout << "Birth date: ";
                                    std::cin >> B_date;
                                    std::cout << "Student ID: ";
                                    std::cin >> Teach_ID;
                                    Teacher input(F_name, L_name, B_date, Teach_ID);
                                    seq_1->Append(input);
                                }
                                else{
                                    Teacher input;
                                    input.Randomize();
                                    std::cout << "Randomizing the Student" << std::endl;
                                    seq_1->Append(input);
                                }
                                break;
                            }
                            case 2:{
                                std::cout << "Method of entry:\n1. Manual Entry\n2. Randomize\nYour choice: ";
                                int Entry = choose(1,2);
                                if(Entry==1){
                                    std::cout << "First name: ";
                                    std::cin >> F_name;
                                    std::cout << "Last name: ";
                                    std::cin >> L_name;
                                    std::cout << "Birth date: ";
                                    std::cin >> B_date;
                                    std::cout << "Student ID: ";
                                    std::cin >> Teach_ID;
                                    Teacher input(F_name, L_name, B_date, Teach_ID);
                                    seq_1->Append(input);
                                }
                                else{
                                    Teacher input;
                                    input.Randomize();
                                    std::cout << "Randomizing the Student" << std::endl;
                                    seq_1->Append(input);
                                }
                                break;
                            }
                            case 3:
                                std::cout << "\nPrinting Sequence 1:" << std::endl;
                                seq_1->Print();
                                break;
                            case 4:
                                std::cout << "\nLength of Sequence 1: " << seq_1->GetLength() << "\n" << std::endl;
                                break;
                            case 5:{
                                std::cout << "\nEnter a valid index: ";
                                index = choose(0,seq_1->GetLength());
                                Teacher output = seq_1->Get(index);
                                std::cout << "Item at index '" << index << "' is: " << output << std::endl;
                                break;
                            }
                            case 6:
                                std::cout << "Deleting ITEM at first index." << std::endl;
                                seq_1->Delete_first();
                                break;
                            case 7:
                                std::cout << "Deleting ITEM at last index." << std::endl;
                                seq_1->Delete_last();
                                break;
                            }
                        }while(seq_1_mod_choice != 8);
                        break;
                    case 2:
                        do{
                            std::cout << "\n----- SEQUENCE 2 -----" << std::endl;
                            std::cout << "\nSelect an operation for Sequence 2:\n1. Append\n2. Prepend\n3. Print\n4. Get Length of Sequence\n5. Get ITEM at index\n6. Delete first item\n7. Delete last item\n8. Return\nYour choice: ";
                            seq_2_mod_choice = choose(1,8);
                            switch(seq_2_mod_choice){
                            case 1: {
                                std::cout << "Method of entry:\n1. Manual Entry\n2. Randomize\nYour choice: ";
                                int Entry = choose(1,2);
                                if(Entry==1){
                                    std::cout << "First name: ";
                                    std::cin >> F_name;
                                    std::cout << "Last name: ";
                                    std::cin >> L_name;
                                    std::cout << "Birth date: ";
                                    std::cin >> B_date;
                                    std::cout << "Student ID: ";
                                    std::cin >> Teach_ID;
                                    Teacher input(F_name, L_name, B_date, Teach_ID);
                                    seq_2->Append(input);
                                }
                                else{
                                    Teacher input;
                                    input.Randomize();
                                    std::cout << "Randomizing the Student" << std::endl;
                                    seq_2->Append(input);
                                }
                                break;
                            }
                            case 2:{
                                std::cout << "Method of entry:\n1. Manual Entry\n2. Randomize\nYour choice: ";
                                int Entry = choose(1,2);
                                if(Entry==1){
                                    std::cout << "First name: ";
                                    std::cin >> F_name;
                                    std::cout << "Last name: ";
                                    std::cin >> L_name;
                                    std::cout << "Birth date: ";
                                    std::cin >> B_date;
                                    std::cout << "Student ID: ";
                                    std::cin >> Teach_ID;
                                    Teacher input(F_name, L_name, B_date, Teach_ID);
                                    seq_2->Append(input);
                                }
                                else{
                                    Teacher input;
                                    input.Randomize();
                                    std::cout << "Randomizing the Student" << std::endl;
                                    seq_2->Append(input);
                                }
                                break;
                            }
                            case 3:
                                std::cout << "\nPrinting Sequence 2:" << std::endl;
                                seq_2->Print();
                                break;
                            case 4:
                                std::cout << "\nLength of Sequence 2: " << seq_2->GetLength() << "\n" << std::endl;
                                break;
                            case 5:{
                                std::cout << "\nEnter a valid index: ";
                                index = choose(0,seq_2->GetLength());
                                Teacher output = seq_2->Get(index);
                                std::cout << "Item at index '" << index << "' is: " << output << std::endl;
                                break;
                            }
                            case 6:
                                std::cout << "Deleting ITEM at first index." << std::endl;
                                seq_2->Delete_first();
                                break;
                            case 7:
                                std::cout << "Deleting ITEM at last index." << std::endl;
                                seq_2->Delete_last();
                                break;
                            }
                        }while(seq_2_mod_choice != 8);
                        break;
                    case 3:
                        int subseq_choice;
                        do{
                            std::cout << "\n----- ADVANCED OPERATIONS-----\n" << std::endl;
                            std::cout << "1. Search for SEQ_1 in SEQ_2\n2. Concatenate\n3. Get a Subsequence\n4. Return\nYour choice: ";
                            advanced_choice = choose(1,4);
                            switch(advanced_choice){
                            case 1:
                                if(seq_2->Search(seq_1)){
                                    std::cout << "Subsequence found!" << std::endl;
                                }
                                else{
                                    std::cout << "Subsequence not found" << std::endl;
                                }
                            break;
                            case 2:
                                std::cout << "Choose an option for concatenation:\n1. Sequence 1 + Sequence 2\n2. Sequence 2 + Sequence 1\nEnter your choice: ";
                                concat_choice = choose(1,2);
                                if(concat_choice == 1){
                                    seq_1->Concat(seq_2);
                                }
                                else{
                                    seq_2->Concat(seq_1);
                                }
                            break;
                            case 3:
                                int start_ind, end_ind;
                                std::cout << "Choose a Sequence for slicing:\n1. Sequence 1\n2. Sequence 2\nYour choice:";
                                subseq_choice = choose(1,2);
                                if(subseq_choice == 1){
                                    std::cout << "Choose the start index: ";
                                    start_ind = choose(0, seq_1->GetLength());
                                    std::cout << "Choose the end index: ";
                                    end_ind = choose(start_ind, seq_1->GetLength());
                                    advanced_seq = seq_1->GetSubsequence(start_ind, end_ind);
                                }
                                else{
                                    std::cout << "Choose the start index: ";
                                    start_ind = choose(0, seq_2->GetLength());
                                    std::cout << "Choose the end index: ";
                                    end_ind = choose(start_ind, seq_2->GetLength());
                                    advanced_seq = seq_2->GetSubsequence(start_ind, end_ind);
                                }
                                std::cout << "Printing the subsequence:" << std::endl;
                                advanced_seq->Print();
                            break;
                            }
                        }while(advanced_choice != 4);

                        break;

                    case 4:
                        std::cout << "\n\t--Exiting program--" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                }
            break;
        } //   ===== TEACHER END =====   //
            }
        break;
                //   ===== SEQUENCE ENDS HERE =====   //
        case 3:
            std::cout << "\n  ==QUITING==\n" << std::endl;
            return 0;
        }

    }

}



