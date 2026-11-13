#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <stdexcept>

#include "Student.h"
#include <fstream>
#include <sstream>

template <typename T>
class DynamicArray
{
private:
    T *data;
    int capacity;
    int size;

    void resize()
    {
        capacity = capacity * 2;
        T *newData = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DynamicArray()
    {
        capacity = 2;
        size = 0;
        data = new T[capacity];
    }
    DynamicArray(const DynamicArray &other)
    {
        capacity = other.capacity;
        size = other.size;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }
    DynamicArray &operator=(const DynamicArray &other)
    {
        if (this == &other)
        {
            return *this;
        }
        T *newData = new T[other.capacity];

        for (int i = 0; i < other.size; i++)
        {
            newData[i] = other.data[i];
        }
        delete[] data;

        data = newData;
        size = other.size;
        capacity = other.capacity;
        return *this;
    }
    ~DynamicArray()
    {
        delete[] data;
    }
    int getSize() const
    {
        return size;
    }
    int getCapacity() const
    {
        return capacity;
    }
    void insert(T value)
    {
        if (size == capacity)
        {
            resize();
        }
        data[size] = value;
        size++;
    }
    void display() const
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "Student ID:" << data[i].studentID << std::endl;
            std::cout << "Name:" << data[i].name << std::endl;
            std::cout << "Course:" << data[i].course << std::endl;
            std::cout << "Marks:" << data[i].marks << std::endl;
            std::cout << "-------------------" << std::endl;
        }
    }
    void removeAt(int index)
    {
        if (index < 0 || index >= size)
        {
            std::cout << "Invalid position!" << std::endl;
            return;
        }
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }
    int search(int studentID) const
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i].studentID == studentID)
            {
                return i;
            }
        }
        return -1;
    }
    T get(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Invalid index!");
        }
        return data[index];
    }
    bool saveToFile(const std::string &filename) const
    {
        std::ofstream file(filename);

        if (!file)
        {
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            file << data[i].studentID << "|"
                 << data[i].name << "|"
                 << data[i].course << "|"
                 << data[i].marks << std::endl;
        }

        file.close();
        return true;
    }
    bool loadFromFile(const std::string &filename)
    {
        std::ifstream file(filename);

        if (!file)
        {
            return false;
        }

        std::string line;

        while (std::getline(file, line))
        {
            std::stringstream ss(line);

            std::string id, name, course, marks;

            if (!std::getline(ss, id, '|') ||
                !std::getline(ss, name, '|') ||
                !std::getline(ss, course, '|') ||
                !std::getline(ss, marks))
            {
                continue;
            }

            try
            {
                T student;
                student.studentID = std::stoi(id);
                student.name = name;
                student.course = course;
                student.marks = std::stod(marks);

                insert(student);
            }
            catch (...)
            {
                continue;
            }
        }

        file.close();
        return true;
    }
};
#endif
