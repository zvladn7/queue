#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template <typename D> struct ElementOfQueue {
  ElementOfQueue(D var)
    : variable_(var)
  {
      next_ = 0;
      prev_ = 0;
  }
  D variable_;
  ElementOfQueue<D> * next_;
  ElementOfQueue<D> * prev_;
};

template <typename T> //= std::allocator<int> >
class QueueMyVersion {
public:
  QueueMyVersion(T var);                      // constructors
  QueueMyVersion(QueueMyVersion const & copy);
  virtual ~QueueMyVersion();             // destructor
  T front();                             // get access for first element
  T back();                              // get access for last added element
  bool empty();                          // check that quece empty or not
  int size();                            // return size of QUECE_H
  void push();                           // push new element into the end of quece
  void pop();                            // delete the first element in the quece
  void swap(QueueMyVersion & copy);      // this method is swapping two object
  QueueMyVersion &operator= (QueueMyVersion const & copy);


private:                                 // field which we can change only in this class
  ElementOfQueue<T> * first_;
  ElementOfQueue<T> * last_;
  int size_;
};

#endif /* QUEUE_H */
