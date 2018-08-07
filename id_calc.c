#include <stdio.h>
#include <string.h>

int times[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int secret[11] = {1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2};

void validate(int numbers[]) {
  int sum = 0;
  for (int i = 0; i < 17; i++) {
    sum += numbers[i] * times[i];
  }
  int mod = sum % 11;
  if (secret[mod] == numbers[17]) {
    // print
    printf(
      "%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%c\n",
      numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5],
      numbers[6], numbers[7], numbers[8], numbers[9], numbers[10], numbers[11],
      numbers[12], numbers[13], numbers[14], numbers[15], numbers[16],
      numbers[17] == 10 ? 'X' : '0' + numbers[17]
    );
  }
}

int main(int argc, const char *argv[]) {
  if (strlen(argv[1]) != 18) {
    fputs("Argument must be 18 characters\n", stderr);
    return 1;
  }

  int numbers[18];

  for (int i = 0; i < 18; i++) {
    char c = argv[1][i];
    if (c >= '0' && c <= '9') {
      numbers[i] = c - '0';
    } else if (c == '*') {
      numbers[i] = -1;
    } else if (c == 'X') {
      numbers[i] = 10;
    }
  }

  // calculate year: numbers[8], numbers[9]
  for (int year = 30; year <= 99; year++) {
    // calculate month: numbers[10], numbers[11]
    for (int month = 1; month <= 12; month++) {
      // calculate date: numbers[12], numbers[13]
      for (int date = 1; date <= 31; date++) {
        numbers[8] = year / 10;
        numbers[9] = year % 10;
        numbers[10] = month / 10;
        numbers[11] = month % 10;
        numbers[12] = date / 10;
        numbers[13] = date % 10;
        validate(numbers);
      }
    }
  }

  return 0;
}

