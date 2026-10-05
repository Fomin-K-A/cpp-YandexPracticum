#include <iostream>
#include <string>

void DoOliverTask(int count);
void DoPenelopeTask(int count);

void DoOliverTask(int count) {
  if (count % 2 != 0) {
    std::cout << "Transmit to Penelope\n";
    DoPenelopeTask(count);
  } else {
    for (int i = 0; i < count; i++) {
      std::cout << "Oliver: Hurrah!\n";
    }
  }
}

void DoPenelopeTask(int count) {
  if (count % 2 == 0) {
    std::cout << "Transmit to Oliver\n";
    DoOliverTask(count);
  } else {
    for (int i = 0; i < count; i++) {
      std::cout << "Penelope: Hurrah!\n";
    }
  }
}

int main() {
  std::string target;
  int count;
  std::cin >> target >> count;

  if (target == "Oliver") {
    DoOliverTask(count);
  } else if (target == "Penelope") {
    DoPenelopeTask(count);
  } else {
    std::cout << "Unknown addressee: " << target << std::endl;
  }
}