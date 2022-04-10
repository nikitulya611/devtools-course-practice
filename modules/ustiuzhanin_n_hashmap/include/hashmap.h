// Copyright 2022 Ustiuzhanin Nikita

#ifndef USTIUZHANIN_HASHMAP
#define USTIUZHANIN_HASHMAP

#include <exception>
#include <string>

template<class T, class K>
class Record
{
public:

	Record(T mKey = nullptr, K mValue = nullptr) : key(mKey), value(mValue), isDeleted(false) {};
	Record(const Record<T, K>& rec)
	{
		key = rec.key;
		value = rec.value;
		isDeleted = false;
	}

	~Record() {};

	void setKey(T newKey)
	{
		key = newKey;
	}

	T getKey() const
	{
		return key;
	}

	void setValue(K newValue)
	{
		value = newValue;
	}

	K getValue() const
	{
		return value;
	}

	bool isDel()
	{
		return isDeleted;
	}

	void setDel(bool b)
	{
		isDeleted = b;
	}

	bool operator==(const Record<T, K>& rec)
	{
		return key == rec.key;
	}

	bool operator<(const Record<T, K>& rec)
	{
		return key < rec.key;
	}

	bool operator>(const Record<T, K>& rec)
	{
		return key > rec.key;
	}

	Record<T, K>& operator=(const Record<T, K>& rec)
	{
		key = rec.key;
		value = rec.value;
		return *this;
	}

	void clear()
	{
		key = nullptr;
		value = nullptr;
	}

private:
	T key;
	K value;
	bool isDeleted;
};

template<class T, class K>
class Hashmap
{
public:
	Hashmap(int size = 101) 
	{
		maxSize = size;
		this->size = 0;
		data = new K[maxSize];
	}

	virtual ~Hashmap()
	{
		delete[] data;
	}

	int size() const
	{
		return size;
	}

	bool isEmpty() const
	{
		return _size == 0;
	}

	bool isFull()
	{
		return _size == maxSize;
	}

	Hashmap& resize(int newSize)
	{
		Hashmap result(newSize);
		for (int i = 0; i < this->maxSize; i++)
		{
			result.data[i] = this->data[i];
		}

		*this = result;
		return *this;
	}

	void insert(Record<T, K>& rec)
	{
		//если таблица заполнена > 75% -> resize(maxSize * 2)
		if (double(this->dataCount) / this->maxSize > 0.75)
			resize(this->maxSize * 2);

		int index = std::hash<T>(rec.getKey());


		while (this->data[index].getKey() != nullptr)
		{
			if (this->data[index].getKey() == rec.getKey())
			{
				std::string problem = "Record with key \"" + rec.getKey() + "\" already exist";
				throw std::exception(problem.c_str());
			}

			index += prime;
		}

		this->data[index] = rec;
		this->data[index].setDel(false);
		this->dataCount++;
		return;
	}

	void insert(T key = nullptr, T value = 0)
	{
		Record<T, K> rec(key, value);
		insert(rec);
	}

	void erase(T key)
	{
		if (this->isEmpty())
			throw std::exception("Erase from empty table");

		int index = std::hash<T>(key);
		while (this->data[index].getKey() != key)
		{
			if (this->data[index].getKey() == nullptr)
				throw std::exception("Erase: Wrong key");
			index += prime;
		}

		this->data[index].clear();
		this->data[index].setDel(true);
		this->dataCount--;
	}

	K operator[](T key)
	{
		int index = std::hash<T>(key);
		while (this->data[index].getKey() != key)
		{
			if (this->data[index].getKey() == nullptr && !this->data[index].isDel())
				throw std::exception("Access: Wrong key");

			index += prime;
			index %= this->maxSize;
		}

		return this->data[index].getValue();
	}

private:
	Record<T, K>* data;
	int _size;
	int maxSize;

	const int prime = 1;

};

#endif // !USTIUZHANIN_HASHMAP
