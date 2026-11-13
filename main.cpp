#include <iostream>
#include "Student.h"
#include "DynamicArray.h"
#include "Sorting.h"

using namespace std;
bool compareByMarks(const Student &a, const Student &b)
{
    return a.marks < b.marks;
}
int main()
{
    DynamicArray<Student> students;
    Student s1;

    s1.studentID = 101;
    s1.name = "Alice";
    s1.course = "Computer Science";
    s1.marks = 85.5;

    students.insert(s1);
    Student s2;
    s2.studentID = 102;
    s2.name = "Brian";
    s2.course = "Information Technology";
    s2.marks = 78.5;

    students.insert(s2);

    Student s3;
    s3.studentID = 103;
    s3.name = "Carol";
    s3.course = "Software Engineering";
    s3.marks = 90.0;

    students.insert(s3);

    cout << "Current size: " << students.getSize() << endl;
    cout << "Current capacity: " << students.getCapacity() << endl;
    if (students.saveToFile("students.txt"))
    {
        cout << "Students saved successfully!" << endl;
    }
    else
    {
        cout << "Error saving students!" << endl;
    }
    Student s4;
    s4.studentID = 104;
    s4.name = "David";
    s4.course = "Networking";
    s4.marks = 76.0;
    students.insert(s4);

    Student s5;
    s5.studentID = 105;
    s5.name = "Esther";
    s5.course = "Cyber Security";
    s5.marks = 88.5;
    students.insert(s5);
    Student s6;
    s6.studentID = 106;
    s6.name = "Frank";
    s6.course = "Database Systems";
    s6.marks = 82.0;
    students.insert(s6);

    Student s7;
    s7.studentID = 107;
    s7.name = "Grace";
    s7.course = "Software Engineering";
    s7.marks = 91.5;
    students.insert(s7);

    Student s8;
    s8.studentID = 108;
    s8.name = "Henry";
    s8.course = "Computer Science";
    s8.marks = 73.5;
    students.insert(s8);
    Student s9;
    s9.studentID = 109;
    s9.name = "Irene";
    s9.course = "Information Technology";
    s9.marks = 86.0;
    students.insert(s9);

    Student s10;
    s10.studentID = 110;
    s10.name = "James";
    s10.course = "Networking";
    s10.marks = 79.5;
    students.insert(s10);
    DynamicArray<Student> loadedStudents;

    if (loadedStudents.loadFromFile("students.txt"))
    {
        cout << "\nLoaded student records:" << endl;
        loadedStudents.display();
    }
    else
    {
        cout << "Error loading students!" << endl;
    }

    students.display();
    cout << "\nStudents sorted by marks using Insertion Sort:\n";

    Student insertionSorted[10];

    for (int i = 0; i < students.getSize(); i++)
    {
        insertionSorted[i] = students.get(i);
    }

    insertionSort(insertionSorted, 10, compareByMarks);

    for (int i = 0; i < 10; i++)
    {
        cout << insertionSorted[i].name << " - "
             << insertionSorted[i].marks << endl;
    }
    cout << "\nStudents sorted by marks using Quick Sort:\n";

    Student quickSorted[10];

    for (int i = 0; i < students.getSize(); i++)
    {
        quickSorted[i] = students.get(i);
    }

    quickSort(quickSorted, 0, 9, compareByMarks);

    for (int i = 0; i < 10; i++)
    {
        cout << quickSorted[i].name << " - "
             << quickSorted[i].marks << endl;
    }
    cout << "\nTesting Binary Search:\n";

    Student target{};
    target.marks = 99.0;

    int result = binarySearch(quickSorted, 10, target, compareByMarks);

    if (result != -1)
    {
        cout << "Student found: "
             << quickSorted[result].name << endl;
    }
    else
    {
        cout << "Student not found!" << endl;
    }
    cout << "\nTesting removal of first and last students:\n";

    DynamicArray<Student> removalTest = students;

    removalTest.removeAt(0);
    removalTest.removeAt(removalTest.getSize() - 1);

    cout << "Records remaining: " << removalTest.getSize() << endl;
    removalTest.display();
    cout << "\nTesting empty and one-record arrays:\n";

    DynamicArray<Student> edgeTest;

    cout << "Empty array size: " << edgeTest.getSize() << endl;

    Student singleStudent;
    singleStudent.studentID = 111;
    singleStudent.name = "Kevin";
    singleStudent.course = "Computer Science";
    singleStudent.marks = 80.0;

    edgeTest.insert(singleStudent);

    cout << "One-record array size: " << edgeTest.getSize() << endl;
    edgeTest.display();
    cout << "\nTesting duplicate marks:\n";

    Student duplicateTest[3];

    duplicateTest[0] = students.get(0);
    duplicateTest[1] = students.get(1);
    duplicateTest[2] = students.get(2);

    duplicateTest[0].marks = 80.0;
    duplicateTest[1].marks = 80.0;
    duplicateTest[2].marks = 90.0;

    insertionSort(duplicateTest, 3, compareByMarks);

    for (int i = 0; i < 3; i++)
    {
        cout << duplicateTest[i].name << " - "
             << duplicateTest[i].marks << endl;
    }
    cout << "\nTesting sorted and reversed input:\n";

    Student testArray[3];

    testArray[0] = students.get(0);
    testArray[1] = students.get(1);
    testArray[2] = students.get(2);

    // Already sorted input
    insertionSort(testArray, 3, compareByMarks);
    cout << "Sorted input processed successfully." << endl;

    // Reverse the array
    std::swap(testArray[0], testArray[2]);

    // Sort reversed input
    insertionSort(testArray, 3, compareByMarks);
    cout << "Reversed input processed successfully." << endl;
    return 0;
}
