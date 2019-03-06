#include <iostream>
#include "queue.hpp"


//-----------------Usual constructor-------------------------
template <typename T> QueueMyVersion<T>::QueueMyVersion(T var)
	: first_(new ElementOfQueue<T>(var))
{
	last_ = first_;
	size_ = 1;
}

//-----------------Constructor of copy one object into another-------------------------
template <typename T> QueueMyVersion<T>::QueueMyVersion(QueueMyVersion const & copy)
	: size_(copy.size_)
{
	ElementOfQueue<T> * time = copy.first_;
	while (time != 0)
	{
		this->push(time->variable_);
		time = time->prev_;
	}
}

//-----------------destructor-------------------------
template <typename T> QueueMyVersion<T>::~QueueMyVersion()
{
	first_ = 0;
	ElementOfQueue<T> * time = last_;
	while (last_ != 0)
	{
		last_ = last_->next_;
		delete time;
	}
}

//-----------------Method SWAP-------------------------
template <typename T> void QueueMyVersion<T>::swap(QueueMyVersion & copy)
{
	std::swap(size_,copy.size_);
	std::swap(first_,copy.fitst_);
	std::swap(last_,copy.last_);
}

//-----------------OPERATOR =-------------------------
template <typename T> QueueMyVersion<T> & QueueMyVersion<T>::operator=(QueueMyVersion const & copy)
{
	if (this != &copy)
	{
		QueueMyVersion(copy).swap(*this);
	}
	return *this;
}

//-----------------METHOD PUSH-------------------------
template <typename T> void QueueMyVersion<T>::push(T var)
{
	if (size_ != 0)
	{
		last_->next_ = new ElementOfQueue<T>(var);
		last_->next_->prev_ = last_;
		last_ = last_->next_;
	}
	else
	{
		first_ = new ElementOfQueue<T>(var);
		first_->next_ = 0;
		first_->prev_ = 0;
		last_ = first_;
	}
	size_++;
}

//---------------------METHOD FRONT----------------------------
template <typename T> ElementOfQueue<T> * QueueMyVersion<T>::front()
{
	return first_;
}

//---------------------METHOD BACK----------------------------
template <typename T> ElementOfQueue<T> * QueueMyVersion<T>::back()
{
	return last_;
}

//---------------------METHOD EMPTY----------------------------
template <typename T> bool QueueMyVersion<T>::empty() const
{
	return (size_ == 0);
}

//---------------------METHOD SIZE----------------------------
template <typename T> int QueueMyVersion<T>::size() const
{
	return size_;
}
