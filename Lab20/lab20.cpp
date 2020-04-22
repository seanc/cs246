#include <iostream>
#include <string>
#include "Node.h" //Node()
#include "Pair.h" //Pair()
#include "Iterator.h" //Iterator(), PairIterator()
#include "Set.h" //Set()
#include "List.h" //Vector(), LinkedList()
#include "Map.h" //Map()

int DuplicatesSum(ds::da::Vector<int>& data)
{
	ds::da::Map<int, int> occur;
	int sum = 0;
	
	for (int i = 0; i < data.Size(); i++) {
		if (occur.Contains(data[i])) {
			if (occur.Get(data[i]) > 1) {
				continue;
			} else {
				occur.Get(data[i])++;
				sum += data[i];
			}
		} else {
			occur.Put(data[i], 1);
		}
	}

	return sum;
}

ds::sn::Set<int> MaximumCongruenceClass(ds::da::Vector<int>& data,int m)
{
	ds::da::Map<int, ds::sn::Set<int>> remainer_divisor;
	ds::sn::Set<int> longestSubset;

	if (m < 0) {
		return ds::sn::Set<int>();
	}

	for (int i = 0; i < data.Size(); i++) { 
		int remainder = data[i] % m;
		if (remainer_divisor.Contains(remainder)) {
			remainer_divisor.Get(remainder).Insert(data[i]);
		} else {
			ds::sn::Set<int> subset;
			subset.Insert(data[i]);
			remainer_divisor.Put(remainder, subset);
		}
	}

	if (m > 0) {
		ds::da::PairIterator<int, ds::sn::Set<int>>* it = remainer_divisor.ToIterator();
		while (it->HasNext()) {
			ds::Pair<int, ds::sn::Set<int>> tmp = it->Next();
			if (tmp.GetValue().Size() > longestSubset.Size()) {
				longestSubset = tmp.GetValue();
			}

			if (tmp.GetValue().Size() == longestSubset.Size()) {
				longestSubset = (longestSubset.ToIterator()->Next() % 3) > tmp.GetKey() ? tmp.GetValue() : longestSubset;
			}
		}
	}

	return longestSubset;
}

int main()
{
	ds::da::Vector<int> data;
	int NUMS_LENGTH = 7;
	int nums[NUMS_LENGTH] = { 1, 2, 2, 3, 2, 4, 1 };
	for (int i = 0; i < NUMS_LENGTH; i++) {
		data.Insert(nums[i]);
	}
	std::cout << DuplicatesSum(data) << "\n";

	ds::da::Vector<int> data1;
	int NUMS1_LENGTH = 11;
	int nums1[NUMS1_LENGTH] = {1,3,2,2,5,4,5,2,10,9,8};
	for (int i = 0; i < NUMS1_LENGTH; i++) {
		data1.Insert(nums1[i]);
	}

	std::cout << MaximumCongruenceClass(data1, 3);
	return 0;
}
