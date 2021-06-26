#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "sequence.h"
template <class T, template <class M> class S>
class Queue {
    private:
        Sequence<T> *seq;
        int Length=0;
    public:
        Queue(){ // Constructor
           seq = new S<T>();
           Length = 0;
        }

        T Pop(){
            if (this->isEmpty()){
                std::cout << "Underflow\nProgram Terminated" << std::endl;
                exit(EXIT_FAILURE);
            }
            T last = seq->GetLast();
            seq->Delete_last();
            this->Length--;
            return last;
        }

        void Push(const T& item) {
            std::cout << "Adding to Queue: " << item << std::endl;
            seq->Prepend(item);
            this->Length++;
        }

        const T GetFront() {
            if (isEmpty()){
                std::cout << "Underflow\nProgram Terminated" << std::endl;
                exit(EXIT_FAILURE);
            }
            return seq->GetLast();
        }

        const T GetBack(){
            if (isEmpty()){
                std::cout << "Underflow\nProgram Terminated" << std::endl;
                exit(EXIT_FAILURE);
            }
            return seq->GetFirst();
        }

        void LookAt(int index){
            if(index >= seq->GetLength()) {
                std::cout << "\nERROR: <in class: Queue>: 'peekAt()': INDEX OUT OF RANGE" << std::endl;
                exit(EXIT_FAILURE);
            }
            else {
                std::cout << seq->Get(index) << std::endl;
            }
        }

        bool operator ! (){
            if(this == nullptr){
                return true;
            }
            return false;
        }

        bool operator == (const Queue<T, Sequence> &Seq) const{
            return false;
        }

        int GetSize() const{
            return seq->GetLength()*sizeof(T);
        }
        bool isEmpty() const{
            return (this->GetSize() == 0);
        }
        bool isFull() const{
            return (this->GetSize() == Length*sizeof(T));
        }
        int GetLength() const{
            return seq->GetLength();
        }
        void Print(){
            seq->Print();
        }
};

#endif // QUEUE_H_INCLUDED
