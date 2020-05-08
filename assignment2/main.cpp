#include "Node.h"
template<typename T>
void PrintList (ds::sn::Node<T>* list) {
  ds::sn::Node<T>* tmp;
  tmp = list;
  std::cout << "[";
  while (tmp != NULL) {
    std::cout << tmp->GetData();
    tmp = tmp->GetLink();
  }
  std::cout << "]\n";
}

ds::sn::Node<int>* ReverseCopy(ds::sn::Node<int>* root)
{
    // ds::Node<T>* rootCopy = root;
    if (root == NULL) {
        return NULL;
    }

    if (root->GetLink() == NULL) {
        return root;
    }

    ds::sn::Node<int>* tmp = root;
    ds::sn::Node<int>* prev;
    ds::sn::Node<int>* next;

    while (tmp != NULL) {
        next = tmp->GetLink();
        tmp->SetLink(prev);
        prev = tmp;
        tmp = next;
    }
    
    return prev;
}

ds::sn::Node<int>* Sum(ds::sn::Node<int>* oper1, ds::sn::Node<int>* oper2) {
  ds::sn::Node<int>* sumList;
  ds::sn::Node<int>* prev;
  ds::sn::Node<int>* oper1Reverse = ReverseCopy(oper1);
  // ds::sn::Node<int>* oper2Reverse = ReverseCopy(oper2);
  int remainder;

  // PrintList(oper1Reverse);
  prev = oper1;
  while (prev != NULL) {
    std::cout << prev->GetData() << " ";
    prev = prev->GetLink();
  }

  // while (oper1Reverse != NULL || oper2Reverse != NULL) {
  //   int sum = 0;
  //   if (oper2Reverse != NULL) {
  //     sum += oper2Reverse->GetData();
  //     oper2Reverse = oper2Reverse->GetLink();
  //   }

  //   if (oper1Reverse != NULL) {
  //     sum += oper1Reverse->GetData();
  //     oper1Reverse = oper1Reverse->GetLink();
  //   }

  //   if (remainder > 0) {
  //     sum += remainder;
  //     remainder = 0;
  //   }

  //   if (sum > 10) {
  //     remainder = sum % 10;
  //     sum /= 10;
  //   }

  //   if (sumList->GetLink() == NULL) {
  //     sumList->SetData(sum);
  //     prev = sumList;
  //   } else {
  //     ds::sn::Node<int>* digitSum = new ds::sn::Node<int>(sum);
  //     prev->SetLink(digitSum);
  //     prev = digitSum;
  //   }
  // }

  return sumList;
}



ds::sn::Node<int> GenerateListFromNumber(int num) {
  ds::sn::Node<int> list;
  list.SetData(num % 10);
  num /= 10;
  
  ds::sn::Node<int>* prev = &list;
  while (num > 0) {
    ds::sn::Node<int>* tmp = new ds::sn::Node<int>(num % 10);
    prev->SetLink(tmp);
    prev = tmp;
    num /= 10;
  }

  return list;
}

int main() {
  ds::sn::Node<int>* oper1 = GenerateListFromNumber(643);
  ds::sn::Node<int>* oper2 = GenerateListFromNumber(81);

  // PrintList(oper1);

  ds::sn::Node<int>* sum = Sum(oper1, oper2);

  // PrintList(sum);
  return 0;
}