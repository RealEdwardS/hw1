#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

// #include <iostream>

// Default constructor - Empty list
ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

// Destructor
ULListStr::~ULListStr()
{
  clear();
}

/**
 * Returns true if the list is empty, false otherwise
 *   - MUST RUN in O(1)
 */
bool ULListStr::empty() const
{
  return size_ == 0;
}

/**
 * Returns the current number of items in the list (NOT the number of nodes)
 *   - MUST RUN in O(1)
 */
size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

/**
 * Adds a new value to the back of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::push_back(const std::string& val){
  if (empty()){
    Item* newItem = new Item; 

    // Assign val to the first index of newItem
    newItem->val[0] = val;

    // Assign first to index 0
    newItem->first = 0;

    // Assign last to index 0 + 1
    newItem->last = 1; 

    // Assign prev and next of newItem to nullptr;
    newItem->prev = nullptr;
    newItem->next = nullptr; 

    // Assign tail and head to new item
    head_ = newItem;
    tail_ = newItem;
  }

  else if (!empty()){
    // If there is no more backroom in the current last item
    if (tail_->last == ARRSIZE){
      Item* newItem = new Item; 

      // Assign val to the first index of newItem
      newItem->val[0] = val;

      // Assign first to index 0
      newItem->first = 0;

      // Assign last to index 0 + 1
      newItem->last = 1;

      // Assign next of newItem to nulltpr
      // Assign prev of newItem to the current tail_
      newItem->next = nullptr;
      newItem->prev = tail_; 

      // Assign current tail_'s next to be newItem
      tail_->next = newItem; 

      // Redirect tail_ pointer to point to newItem
      tail_ = newItem;
    }

    // If there is backroom in the current last item
    else if (tail_->last < ARRSIZE){
      // Assign tail's val with the index of its last
      tail_->val[tail_->last] = val;

      // Increment last index value
      ++(tail_->last); 
    }
  }

  // Increment size
  ++(size_);

}

/**
 * Removes a value from the back of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_back(){
  // If empty,
  if (empty()){
    // If head is not nullptr, delete and assign to nullptr 
    if (head_ != nullptr){
      tail_ = nullptr;
      delete head_; 
    }

    // If tail is not nullptr, delete and assign to nullptr 
    if (tail_ != nullptr){
      delete tail_;
      head_ = nullptr; 
    }
    return; 
  }

  // Assign last value to null
  tail_->val[(tail_->last) - 1] = '\0';

  // Decrement last pointer of tail
  --(tail_->last);

  // If last goes to 0, then it's no longer the tail
  if (size_ == 1){
    delete tail_;
    tail_ = nullptr;
    head_ = nullptr; 
  }

  else if (tail_->last <= tail_->first){

    // If there exists more values in differnt items
    if (size_ > (tail_->last - tail_->first)){
      // Assign tail_ to the previous item
      tail_ = tail_->prev;

      // Delete the previous tail item
      delete tail_->next;

      // Set the current tail's next to nullptr 
      tail_->next = nullptr; 
    }

    // delete temp;
  }

  // Decrement size
  --(size_);


}

/**
 * Adds a new value to the front of the list.
 * If there is room before the 'first' value in
 * the head node add it there, otherwise, 
 * allocate a new head node.
 *   - MUST RUN in O(1)
 */
void ULListStr::push_front(const std::string& val){
  if (empty()){
    Item* newItem = new Item; 

    // Assign val to the last index of newItem
    newItem->val[ARRSIZE-1] = val;

    // Assign first to index 0
    newItem->first = ARRSIZE-1;

    // Assign last to index 0 + 1
    newItem->last = ARRSIZE; 

    // Assign prev and next of newItem to nullptr;
    newItem->prev = nullptr;
    newItem->next = nullptr; 

    // Assign tail and head to new item
    head_ = newItem;
    tail_ = newItem;
  }

  else if (!empty()){
    // If current head array has no more room in the front
    if (head_->first == 0){
      // std::cerr << "HELLO2" << std::endl;
      Item* newItem = new Item;

      // Assign val to last index of newItem
      newItem->val[ARRSIZE-1] = val;

      // Assign first to index ARRSIZE-1
      newItem->first = ARRSIZE - 1;

      // Assign last to ARRSIZE
      newItem->last = ARRSIZE; 

      // Assign next of newItem to current head_
      // Assign prev of newItem to nullptr
      newItem->next = head_; 
      newItem->prev = nullptr;

      // Assign current head_'s prev to be newItem
      head_->prev = newItem;

      // Redirect head_ pointer to point to newItem
      head_ = newItem;
    }

    // If there is frontroom in the current first item
    else if (head_->first > 0){
      // std::cerr << "HELLO" << std::endl;
      // Assign head's val with the index of one before its front
      head_->val[(head_->first) - 1] = val;

      // Decrement first index value
      --(head_->first);

    }
  }

  // Increment size
  ++(size_);
}

/**
 * Removes a value from the front of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_front(){
  // If empty
  if (empty()){

    // If head is not nullptr, delete and assign to nullptr 
    if (head_ != nullptr){
      tail_ = nullptr;
      delete head_; 
    }

    // If tail is not nullptr, delete and assign to nullptr 
    if (tail_ != nullptr){
      delete tail_;
      head_ = nullptr; 
    }
    return; 
  }

  // Assign first value to null

  head_->val[head_->first] = '\0';

  // Increment first pointer of head
  ++(head_->first);

  // If first exceeds last, then it's no longer the head
  if (head_->first >= head_->last){
    // Assign head_ to a temp val
    Item* temp = head_; 

    // If only one item, assign tail to nullptr
    if (tail_ == head_){
      tail_ = nullptr; 
    }
    
    // If there are more values in different items, assign head to next and tail to head
    if (size_ > (head_->last - head_->first)){
      head_ = head_->next;
      tail_ = head_; 
    }

    // Delete orignal head 
    delete temp;
  }
  
  // Decrement size
  --(size_);
}

/**
 * Returns a const reference to the back element
 *   - MUST RUN in O(1)
 */
std::string const & ULListStr::back() const{
  // If it's last element, return arrsize-1; 
  if (tail_->last >= ARRSIZE){
    return tail_->val[ARRSIZE-1];
  }

  return (tail_->val[tail_->last-1]);
}

/**
 * Returns a const reference to the front element
 *   - MUST RUN in O(1)
 */
std::string const & ULListStr::front() const{
  return (head_->val[head_->first]);
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

/** 
 * Returns a pointer to the item at index, loc,
 *  if loc is valid and NULL otherwise
 *   - MUST RUN in O(n) 
 */
std::string* ULListStr::getValAtLoc(size_t loc) const{
  // If location is not valid
  if (loc > size_-1){
    return nullptr; 
  }

  // Start index (index 0 may not be where list starts)
  size_t start = head_->first; 

  // Current item
  Item* currItem = head_; 

  // Current index
  size_t index = head_->first; 

  // Loop through until loc is reached, keeping in mind that 0 is not always the start 
  for (size_t i = start; i < (loc + start); ++i){
    // If index reaches last element of the item, go to next item and reset index
    if (index == currItem->last - 1){
      currItem = currItem->next; 
      index = currItem->first;
    }

    // Else iterate index
    else{
      ++index;
    }
  }

  // Index and current item should be matching
  return &(currItem->val[index]); 
}
