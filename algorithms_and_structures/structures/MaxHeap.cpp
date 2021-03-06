// Heap v1 Required

// MaxHeap v0.0.2
template <typename T>
class MaxHeap: public Heap<T>{
private:

    void        siftUp(int index);

    void        siftDown(int index);

public:

    T           extract_max();

    T           get_max() const;
};

/******************************************************************************/

/****************************MAXHEAP*******************************************/

template <typename T>
void MaxHeap<T>::siftUp(int index){
    if(index >= this->size_)
        std::cerr << "Heap::siftUp : Wrong index\n";
    while(index && this->buffer_[index] > this->buffer_[(index - 1)/2]){
        T tmp = this->buffer_[index];
        this->buffer_[index] = this->buffer_[(index - 1)/2];
        this->buffer_[(index - 1)/2] = tmp;
        index = (index - 1)/2;
    }
}



template <typename T>
void MaxHeap<T>::siftDown(int index){
    if(index >= this->size_)
        std::cerr << "Heap::siftDown : Wrong index\n";
    int max = index;
    if(index*2 + 1 < this->size_ 
       && this->buffer_[index*2 + 1] > this->buffer_[max])
        max = index*2 + 1;
    if(index*2 + 2 < this->size_ 
       && this->buffer_[index*2 + 2] > this->buffer_[max])
        max = index*2 + 2;
    if(max != index){
        T tmp = this->buffer_[index];
        this->buffer_[index] = this->buffer_[max];
        this->buffer_[max] = tmp;
        siftDown(max);
    }
}



template <typename T>
T MaxHeap<T>::extract_max(){
    return this->extract_top();
}



template <typename T>
T MaxHeap<T>::get_max() const{
    return this->get_top();
}
