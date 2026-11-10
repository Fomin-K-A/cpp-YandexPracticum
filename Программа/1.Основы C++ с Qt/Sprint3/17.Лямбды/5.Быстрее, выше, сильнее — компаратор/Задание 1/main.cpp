#include <algorithm>
#include <cassert>
#include <format>
#include <iostream>
#include <vector>
#include <string>

// День будет начинаться в 9 утра.
static const int MORNING_OFFSET = 9 * 60;

struct Task {
  std::string name;  // Название задачи.
  int duration;      // Длительность задачи в минутах.
  int index;         // Индекс очерёдности задачи.
};

void PrintTask(const Task& task, int current_time) {
  int real_time = current_time + MORNING_OFFSET;
  int hours = real_time / 60;
  int minutes = real_time % 60;
  std::cout << std::format("{:02}:{:02} - {}", hours, minutes, task.name)
            << std::endl;
}

auto comparator = [](Task lhs, Task rhs) {
  if (lhs.index != rhs.index) {
    return lhs.index < rhs.index;
  }
  return lhs.name < rhs.name;
};


std::vector<Task> BuildTimetableFor(const std::vector<Task>& source_tasks) {
  std::vector<Task> sorted_tasks = source_tasks;
  std::sort(sorted_tasks.begin(), sorted_tasks.end(), comparator);
  return sorted_tasks;
}

void PrintTimetable(const std::vector<Task>& tasks) {
  int current_time = 0;
  for (int i = 0; i < tasks.size(); i++) {
    PrintTask(tasks[i], current_time);
    current_time = current_time + tasks[i].duration;
  }
}

void ProcessTimetable(const std::vector<Task>& tasks) {
  PrintTimetable(BuildTimetableFor(tasks));
}

int main() {
  std::vector<Task> tasks;
  int duration;
  int index;

  while (std::cin >> index >> duration >> std::ws) {
    std::string name;
    std::getline(std::cin, name);
    tasks.push_back(Task{.name = name, .duration = duration, .index = index});
  }

  ProcessTimetable(tasks);
}