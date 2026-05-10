// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
};

template<typename T>
class TPQueue {
private:
 struct Item {
 T data;
 Item* next;
 };
 Item* head;

public:
 TPQueue() : head(nullptr) {}

 void push(const T& value) {
   Item *item = new Item<T>(value)
   if (head == nullptr) {
     head = item;
     return;
   } else if (value.prior > head->data.prior) {
     item->next = head;
     head = item;
     return;
   } else {
     Item* curItem = head;
     while (curItem->next && curItem->next->data.prior >= value.prior) {
       curItem = curItem->next;
     }
     item->next = curItem->next;
     curItem->next = item;
   }
 }

 T pop() {
   if (!head) {
     throw std::runtime_error("Queue is empty");
   }
   
   Item* temp = head;
   T value = temp->data;
   head = head->next;
   delete temp;
   return value;
 }

 ~TPQueue() {
   while (head != nullptr) {
     Item<T>* temp = head;
     head = head->next;
     delete temp;
   }
 }
};

#endif  // INCLUDE_TPQUEUE_H_
