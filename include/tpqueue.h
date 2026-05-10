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
    Item *next;
  };

  Item *head = nullptr;

  Item *create(const T &value) {
    Item *item = new Item;
    item->data = value;
    item->next = nullptr;
    return item;
  }

 public:
  void push(const T &value) {
    Item *item = create(value);

    if (head == nullptr) {
      head = item;
      return;
    }
    if (value.prior > head->data.prior) {
      item->next = head;
      head = item;
      return;
    }

    Item *curItem = head;
    while (curItem->next && curItem->next->data.prior >= value.prior) {
      curItem = curItem->next;
    }
    item->next = curItem->next;
    curItem->next = item;
  }

  T pop() {
    Item *temp = head;
    T value = temp->data;
    head = head->next;
    delete temp;

    return value;
  }
  ~TPQueue() {
    while (head) {
      Item *temp = head;
      head = head->next;
      delete temp;
    }
  }
};
#endif  // INCLUDE_TPQUEUE_H_
