#include "Node.h"
#include "Stack.h"
#include "Editor.h"

template<typename T>
void PrintList (ds::sn::Node<T>* list) {
  ds::sn::Node<T>* tmp = list;
  std::cout << "[";
  while (tmp != NULL) {
    std::cout << tmp->GetData() << (tmp->GetLink() != NULL ? " " : "");
    tmp = tmp->GetLink();
  }
  std::cout << "]\n";
}

// Question 1
ds::sn::Node<int>* Sum(ds::sn::Node<int>* oper1, ds::sn::Node<int>* oper2) {
  ds::sn::Node<int>* sum = NULL;
  ds::sn::Node<int>* oper1Tmp = oper1, *oper2Tmp = oper2, *sumTmp = sum;
  int remainder = 0;

  while (oper1Tmp != NULL || oper2Tmp != NULL) {
    int digitSum = 0;
    if (oper1Tmp != NULL) {
      digitSum += oper1Tmp->GetData();
      oper1Tmp = oper1Tmp->GetLink();
    }

    if (oper2Tmp != NULL) {
      digitSum += oper2Tmp->GetData();
      oper2Tmp = oper2Tmp->GetLink();
    }

    if (remainder > 0) {
      digitSum += remainder;
      remainder = 0;
    }

    if (digitSum >= 10) {
      remainder = digitSum / 10;
      digitSum %= 10;
    }

    if (sum == NULL) {
      sum = new ds::sn::Node<int>(digitSum);
      sumTmp = sum;
    } else {
      sumTmp->SetLink(new ds::sn::Node<int>(digitSum));
      sumTmp = sumTmp->GetLink();
    }
  }

  return sum;
}

template<typename T>
ds::sn::Node<T>* NumberToIntegerList(T num) {
  ds::sn::Node<T>* list = new ds::sn::Node<T>(num % 10);
  num /= 10;
  
  ds::sn::Node<T>* prev = list;
  while (num > 0) {
    ds::sn::Node<T>* tmp = new ds::sn::Node<T>(num % 10);
    prev->SetLink(tmp);
    prev = tmp;
    num /= 10;
  }

  return list;
}


int main() {
  ds::sn::Node<int>* oper1 = NumberToIntegerList(643);
  ds::sn::Node<int>* oper2 = NumberToIntegerList(81);
  ds::sn::Node<int>* sum = Sum(oper1, oper2);
  PrintList(sum);
  
  oper1 = NumberToIntegerList(100);
  oper2 = NumberToIntegerList(20);
  sum = Sum(oper1, oper2);
  PrintList(sum);

  Editor editor;
  editor.Read('F');
  editor.Read('o');
  editor.Read('o');
  std::cout << editor.Write();
  editor.Read('B');
  editor.Read('a');
  editor.Read('r');
  editor.Read('s');
  editor.Read('#');
  std::cout << editor.Write() << "\n";

  return 0;
}