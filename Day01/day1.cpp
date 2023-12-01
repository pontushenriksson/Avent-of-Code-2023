#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

char findFirstDigit(const std::string &line) {
  for (int i = 0; i < line.length(); ++i) {
    if (isdigit(line[i])) {
      return line[i];
    } else if (isalpha(line[i])) {
      if (line[i] == 'o' && line[i + 1] == 'n' && line[i + 2] == 'e') {
        return '1';
      } else if (line[i] == 't' && line[i + 1] == 'w' && line[i + 2] == 'o') {
        return '2';
      } else if (line[i] == 't' && line[i + 1] == 'h' && line[i + 2] == 'r' && line[i + 3] == 'e' && line[i + 4] == 'e') {
        return '3';
      } else if (line[i] == 'f' && line[i + 1] == 'o' && line[i + 2] == 'u' && line[i + 3] == 'r') {
        return '4';
      } else if (line[i] == 'f' && line[i + 1] == 'i' && line[i + 2] == 'v' && line[i + 3] == 'e') {
        return '5';
      } else if (line[i] == 's' && line[i + 1] == 'i' && line[i + 2] == 'x') {
        return '6';
      } else if (line[i] == 's' && line[i + 1] == 'e' && line[i + 2] == 'v' && line[i + 3] == 'e' && line[i + 4] == 'n') {
        return '7';
      } else if (line[i] == 'e' && line[i + 1] == 'i' && line[i + 2] == 'g' && line[i + 3] == 'h' && line[i + 4] == 't') {
        return '8';
      } else if (line[i] == 'n' && line[i + 1] == 'i' && line[i + 2] == 'n' && line[i + 3] == 'e') {
        return '9';
      } else if (line[i] == 'z' && line[i + 1] == 'e' && line[i + 2] == 'r' && line[i + 3] == 'o') {
        return '0';
      }
    }
  }
  return '\0';
}

char findLastDigit(const std::string &line) {
  for (int i = line.length() - 1; i >= 0; --i) {
    if (isdigit(line[i])) {
      return line[i];
    } else if (isalpha(line[i])) {
      if (line[i - 2] == 'o' && line[i - 1] == 'n' && line[i] == 'e') {
        return '1';
      } else if (line[i - 2] == 't' && line[i - 1] == 'w' && line[i] == 'o') {
        return '2';
      } else if (line[i - 4] == 't' && line[i - 3] == 'h' && line[i - 2] == 'r' && line[i - 1] == 'e' && line[i] == 'e') {
        return '3';
      } else if (line[i - 3] == 'f' && line[i - 2] == 'o' && line[i - 1] == 'u' && line[i] == 'r') {
        return '4';
      } else if (line[i - 3] == 'f' && line[i - 2] == 'i' && line[i - 1] == 'v' && line[i] == 'e') {
        return '5';
      } else if (line[i - 2] == 's' && line[i - 1] == 'i' && line[i] == 'x') {
        return '6';
      } else if (line[i - 4] == 's' && line[i - 3] == 'e' && line[i - 2] == 'v' && line[i - 1] == 'e' && line[i] == 'n') {
        return '7';
      } else if (line[i - 4] == 'e' && line[i - 3] == 'i' && line[i - 2] == 'g' && line[i - 1] == 'h' && line[i] == 't') {
        return '8';
      } else if (line[i - 3] == 'n' && line[i - 2] == 'i' && line[i - 1] == 'n' && line[i] == 'e') {
        return '9';
      } else if (line[i - 3] == 'z' && line[i - 2] == 'e' && line[i - 1] == 'r' && line[i] == 'o') {
        return '0';
      }
    }
  }
  return '\0';
}

int main() {
  std::ifstream inputFile("day1input.txt");
  std::ofstream outputFile("day1output.txt");
  std::string line;
  int sum = 0;

  if (!inputFile) {
    std::cerr << "Error opening input file." << std::endl;
    return 1;
  }

  if (!outputFile) {
    std::cerr << "Error opening output file." << std::endl;
    return 1;
  }

  while (std::getline(inputFile, line)) {
    std::cout << "Reading line: " << line << std::endl;

    char firstDigit = findFirstDigit(line);
    char lastDigit = findLastDigit(line);

    if (firstDigit != '\0' && lastDigit != '\0') {
      std::cout << "First Digit: " << firstDigit << ", Last Digit: " << lastDigit << std::endl;
      std::string concatenated = std::string(1, firstDigit) + std::string(1, lastDigit);
      sum += std::stoi(concatenated);
    } else {
      std::cout << "No valid digits found in line\n";
    }
  }

  std::cout << "Sum: " << sum << std::endl;
  outputFile << "Sum: " << sum << std::endl;

  inputFile.close();
  outputFile.close();

  return 0;
}