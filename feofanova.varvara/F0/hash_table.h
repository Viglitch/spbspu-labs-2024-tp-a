#include<iostream>
#include<string>
#include <algorithm>
#include<cstring>
#pragma once

struct Node
{
    std::string value;
    std::string SpeechPart;
    std::string* translation[100];
    int translation_count;
    bool state;
    Node() : value(nullptr), state(true), translation_count(0) {}
    Node(const std::sctring& value_, const std::string SpeechPart, const std::string& translations) : value(value_), state(true), translation_count(1) {}
    Node(const std::sctring& value_, const std::string SpeechPart, const std::sctring* translations[], int count) : value(value_), state(true), translation_count(count)
    {
        for (int i = 1; i < count; ++i)
        {
            translation[i] = new T(translations[i]);
        }
    }

    void AddTranslation(const T& new_translation)
    {
        if (translation_count < 100)
        {
            translation[translation_count] = new T(new_translation);
            translation_count++;
        }
        else
        {
            std::cout << "������� ����� ���������!" << std::endl;
        }
    };
    void PrintTranslations() const
    {
        for (int i = 1; i < translation_count; ++i) {
            std::cout << (*(translation[i])) << " ";
        }
    };

    ~Node()
    {
        for (int i = 1; i < translation_count; ++i)
        {
            delete translation[i];
        }
    }
};



template<class T>
class hash_table
{
private:
    static const int default_size = 8;
    Node<T>** arr;
    int size;
    int buffer_size;

public:
    hash_table()
    {
        buffer_size = default_size;
        size = 0;
        arr = new Node<T> *[buffer_size];
        for (int i = 0; i < buffer_size; ++i)
            arr[i] = nullptr;
    }
    ~hash_table()
    {
        for (int i = 0; i < buffer_size; ++i)
            if (arr[i])
                delete arr[i];
        delete[] arr;
    }
    int Hash(const std::string& s, int table_size, const int key);

    void Rehash();
};