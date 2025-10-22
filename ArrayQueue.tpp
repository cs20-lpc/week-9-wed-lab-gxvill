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
    delete[] buffer;           // delete the current array
	buffer = nullptr;
	maxSize = 0;
	frontIndex = -1;
	backIndex = -1;
	this->length = 0;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T> &copyObj)
{
    // TODO

    // iterate through the copyobj and copy to current buff
	maxSize = copyObj.maxSize;
	
	if(maxSize <= 0){
		this->length = 0;
		frontIndex = -1;
		backIndex = -1;
		return;
	}

    buffer = new T[maxSize];

	this->length = copyObj.length;

	if(this->length == 0){
		frontIndex = -1;
		backIndex = -1;
		return;
	}

	frontIndex = -1;
	backIndex = -1;
	for(int i = 0; i < this->length; i ++){
		if(frontIndex == -1) frontIndex = 0;
		buffer[i] = copyObj.buffer[i];
		backIndex++;
	}

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
        this->length = 0;
        backIndex = -1;
        frontIndex = -1;
        return;
    }

    // iterating through the list, left to right, and shifting each entry
    for (int i = 0; i < this->length - 1; ++i)
    {
        buffer[i] = buffer[i + 1];
    }
    this->length--;
    backIndex--;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T &elem)
{
    // TODO
    // adding an element to the back of the list

    if (this->length == maxSize) //if we are at the max size throw string
    {
        throw string("queue is full!");
    }
    buffer[this->length] = elem; // the next available space is where the element goes
	if(frontIndex == -1){ // if this is the first element update the frontIndex
		frontIndex = 0;
	}
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
