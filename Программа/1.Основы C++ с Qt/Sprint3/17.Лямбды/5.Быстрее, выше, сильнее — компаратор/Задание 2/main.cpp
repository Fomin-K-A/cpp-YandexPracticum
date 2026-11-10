#include "student.h"

#include <algorithm>
#include <iostream>
#include <optional>
#include <vector>

template<typename Comparator>
void PrintTop(std::vector<Student> all_students, 
                       std::optional<int> max_top, 
                       Comparator comparator) {
    std::stable_sort(all_students.begin(), all_students.end(), comparator);
    if (!max_top.has_value()) {
        for (Student st : all_students) {
            std::cout << st << '\n';
        }
    }
    else {
        int size = std::min(max_top.value(), static_cast<int>(all_students.size()));
        for (int i = 0; i < size; i++) {
            std::cout << all_students[i] << '\n';
        }
    }
}

bool CompareSurnameAsc(const Student& s1, const Student& s2) {
    return s1.last_name < s2.last_name;
}

bool CompareSurnameDesc(const Student& s1, const Student& s2) {
    return s1.last_name > s2.last_name;
}

bool CompareMeanScoreDesc(const Student& s1, const Student& s2) {
    return s1.mean_score > s2.mean_score;
}

bool CompareBestScoreDesc(const Student& s1, const Student& s2) {
    int five_first = std::count(s1.all_scores.begin(), s1.all_scores.end(), 5);
    int five_second = std::count(s2.all_scores.begin(), s2.all_scores.end(), 5);
    return std::tie(five_first, s1.mean_score) > std::tie(five_second, s2.mean_score);
}

bool LexicographicalScoreCompare(const Student& s1, const Student& s2) {
    int five_first = 0;
    int five_second = 0;
    for (int n : s1.all_scores) {
        if (n == 5) {
            five_first++;
        }
    }
    for (int n : s2.all_scores) {
        if (n == 5) {
            five_second++;
        }
    }
    if (five_first != five_second) {
        return five_first > five_second;
    }
    return s1.mean_score > s2.mean_score;
}

int main() {
    std::vector<Student> students;
    Student student;
    while(std::cin >> student) {
        students.push_back(student);
    }
    std::cout << "- Топ студентов с компаратором CompareSurnameAsc" 
              << std::endl;
    PrintTop(students, std::nullopt, CompareSurnameAsc);
   
    std::cout << "- Топ-10 студентов с компаратором CompareSurnameDesc" 
              << std::endl;		
    PrintTop(students, 10, CompareSurnameDesc);
    
    std::cout << "- Топ-4 студентов с компаратором CompareMeanScoreDesc" 
              << std::endl;
    PrintTop(students, 4, CompareMeanScoreDesc);
    
    std::cout << "- Топ-3 студентов с компаратором LexicographicalScoreCompare" 
              << std::endl;
    PrintTop(students, 3, LexicographicalScoreCompare);
}