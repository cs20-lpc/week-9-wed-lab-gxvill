template <typename T>
ArrayQueue<T>::ArrayQueue(int i)
{
    // TODO
    buffer = new T[i];
    maxSize = i;
    this->length = 0;

    // initializing to -1 since there are no elements
    frontIndex = -1;
    backIndex = -1;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T> &copyObj)
{
    copy(copyObj);
}

template <typename T>
ArrayQueue<T> &ArrayQueue<T>::operator=(const ArrayQueue<T> &rightObj)
{
    if (this != &rightObj)
    {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue()
{
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const
{
    // TODO
    if (this->length == 0)
    {
        throw string("back: error, queue is empty, cannot access the back");
    }

    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear()
{
    // TODO

    delete buffer;           // delete the current array
    buffer = new T[maxSize]; // create a new empty one with same max size
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T> &copyObj)
{
    // TODO

    // iterate through the copyobj and copy to current buff
    const ArrayQueue<int> *ptr = &copyObj;
    if (ptr->length == 0){
        this->length = ptr->length;
        return;
    }

    buffer = new T[ptr->length];
    this->length = ptr->length;

    maxSize = copyObj.maxSize;
    int count = 0;
    for (int i = 0; i < this->length; i++){
        buffer[i] = copyObj.buffer[i];
    }
    backIndex = this->length - 1;
    frontIndex = 0;
    return;
}

template <typename T>
void ArrayQueue<T>::dequeue()
{
    // TODO
    // dequeue should be happening from the front

    // since we are going from the front, we do need to overwrite the first var, if there is one

    if (this->length == 0)
    {
        backIndex = -1;
        frontIndex = -1;
        return;
    }
    if (this->length == 1){
        buffer[0] = 0;
        this->length = 0;
        backIndex = -1;
        frontIndex = -1;
        return;
    }

    // iterating through the list, left to right, and shifting each entry
    for (int i = 0; i < this->length; i++)
    {
        buffer[i] = buffer[i + 1];
    }
    backIndex--;
    this->length--;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T &elem)
{
    // TODO
    // adding an element to the back of the list

    if (this->length == maxSize)
    {
        throw string("queue is full!");
    }
    buffer[this->length] = elem;
    backIndex++;
    this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const
{
    // TODO
    if (this->length == 0)
    {
        throw string("front: error, queue is empty, cannot access the front");
    }
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const
{
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const
{
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const
{
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const
{
    return this->length == maxSize;
}
