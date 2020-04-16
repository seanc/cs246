#include <iostream>
#include <string>

template<class K,class V>
struct Map
{
	K keys[100];
	V values[100];
	int size;
};

template<class K,class V>
void Initialize(Map<K,V>& map)
{
	map.size = 0;
}

template<class K,class V>
void Put(Map<K,V>& map,const K& key,const V& value)
{
	int idx = 0;
	while (idx < map.size && map.keys[idx] != key) {
		idx++;
	}

	if (idx == map.size && map.size < 100) {
		map.keys[map.size] = key;
		map.values[map.size] = value;
		map.size++;
	}
	return;
}

template<class K,class V>
V& Get(Map<K,V>& map,const K& key)
{
	int idx = 0;
	while (idx < map.size && map.keys[idx] != key) {
		idx++;
	}

	if (idx == map.size && map.size < 100) {
		return map.values[map.size];
	} else {
		throw "Key Does Not Exists";
	}
}

template<class K,class V>
bool Contains(Map<K,V>& map,const K& key)
{
	int idx = 0;
	while (idx < map.size && map.keys[idx] != key) {
		idx++;
	}

	return idx == map.size && map.size < 100;
}

template<class K,class V>
void Remove(Map<K,V>& map,const K& key)
{
	int idx = 0;
	while (idx < map.size && map.keys[idx] != key) {
		idx++;
	}

	if (idx != map.size) {
		map.size -= 1;
		for (int i = idx; i < map.size; i++) {
			map.keys[i] = map.keys[i + 1];
			map.values[i] = map.values[i + 1];
		}
	}	
	return;
}

template<class K, class V>
void Print(Map<K, V>& map) {
	for (int i = 0; i < map.size; i++) {
		std::cout << map.keys[i] << " - " << map.values[i] << "\n";
	}
	std::cout << "---\n";
}

int main()
{
	Map<std::string, int> map;
	Initialize(map);
	Put(map, std::string("foo"), 1);
	Put(map, std::string("bar"), 2);
	Print(map);
	Remove(map, std::string("bar"));
	Remove(map, std::string("baz"));
	Print(map);

	Map<int, int> numMap;
	for (int i = 0; i < 20; i++) {
		Put(numMap, i, i + 1);
	}
	Print(numMap);
	for (int i = numMap.size; i >= 5; i--) {
		Remove(numMap, i);
	}
	Print(numMap);
	return 0;
}
