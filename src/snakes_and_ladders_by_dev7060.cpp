#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <ctime>

using namespace std;
int main() {
  srand((unsigned) time(0));
  int dice = 0;
  int board[101];
  for (int i = 1; i <= 100; i++) {
    board[i] = i;
  }
  int p1_pos = 1, p2_pos = 1;
  int n = 0;
  int player = 1;
  while (1) {
    system("clear");
    for (int i = 100; i >= 1; i--) {
      cout << setw(7);
      int flag = 1;
      if (p1_pos == i) {
        flag = 2;
        cout << "<P1>";
      }
      if (p2_pos == i) {
        flag = 2;
        cout << "<P2>";
      }
      if (flag != 2) {
        if (i == 3 || i == 10 || i == 27 || i == 56 || i == 61 || i == 72) {
          cout << "LD";
        } else if (i == 16 || i == 31 || i == 47 || i == 63 || i == 66 || i == 97) {
          cout << "SN";
        } else {
          cout << board[i];
        }
      }
      n++;
      if (n == 10) {
        n = 0;
        cout << "\n";
      }
    }
    if (dice != 0) {
      cout << "\n\tValue " << dice;
    }
    cout << "\n\tRoll the dice, player " << player << " ";
    getchar();
    dice = (rand() % 6) + 1;
    if (player == 1) {
      int temp2 = p1_pos;
      p1_pos += dice;
      if (p1_pos > 100) {
        p1_pos = temp2;
        player = 2;
        continue;
      }
      if (p1_pos == 100) {
        system("clear");
        cout << "Value " << dice << " ** Player 1 wins **";
        break;
      }
      int sp_evnt = 1;
      if (p1_pos == 3) {
        p1_pos = 39;
        sp_evnt = 2;
      } else if (p1_pos == 10) {
        p1_pos = 12;
        sp_evnt = 2;
      } else if (p1_pos == 27) {
        p1_pos = 53;
        sp_evnt = 2;
      } else if (p1_pos == 56) {
        p1_pos = 84;
        sp_evnt = 2;
      } else if (p1_pos == 61) {
        p1_pos = 99;
        sp_evnt = 2;
      } else if (p1_pos == 72) {
        p1_pos = 90;
        sp_evnt = 2;
      } else if (p1_pos == 16) {
        p1_pos = 13;
        sp_evnt = 3;
      } else if (p1_pos == 31) {
        sp_evnt = 3;
        p1_pos = 4;
      } else if (p1_pos == 47) {
        p1_pos = 25;
        sp_evnt = 3;
      } else if (p1_pos == 63) {
        p1_pos = 60;
        sp_evnt = 3;
      } else if (p1_pos == 66) {
        p1_pos = 52;
        sp_evnt = 3;
      } else if (p1_pos == 97) {
        p1_pos = 75;
        sp_evnt = 3;
      }
      if (p1_pos == p2_pos) {
        p2_pos = 1;
        sp_evnt = 2;
        player = 1;
        cout << "\n\tP2 replaced\n";
        sleep(1);
      } else {
        player = 2;
      }
      if (sp_evnt == 2) {
        cout << "\n\tLadder\n";
        player = 1;
        sleep(1);
      } else {
        player = 2;
      }
      if (sp_evnt == 3) {
        cout << "\n\tSnake\n";
        if (p2_pos == p1_pos) {
          p2_pos = 1;
          player = 1;
          cout << "\n\tP2 replaced\n";
        } else {
          player = 2;
        }
        sleep(1);
      }
      if (dice == 6) {
        player = 1;
      }
    } else {
      int temp2 = p2_pos;
      p2_pos += dice;
      if (p2_pos > 100) {
        p2_pos = temp2;
        player = 1;
        continue;
      }
      if (p2_pos == 100) {
        system("clear");
        cout << "Value " << dice << " ** Player 2 wins **";
        break;
      }
      int sp_evnt = 1;
      if (p2_pos == 3) {
        p2_pos = 39;
        sp_evnt = 2;
      } else if (p2_pos == 10) {
        p2_pos = 12;
        sp_evnt = 2;
      } else if (p2_pos == 27) {
        p2_pos = 53;
        sp_evnt = 2;
      } else if (p2_pos == 56) {
        p2_pos = 84;
        sp_evnt = 2;
      } else if (p2_pos == 61) {
        p2_pos = 99;
        sp_evnt = 2;
      } else if (p2_pos == 72) {
        p2_pos = 90;
        sp_evnt = 2;
      } else if (p2_pos == 16) {
        p2_pos = 13;
        sp_evnt = 3;
      } else if (p2_pos == 31) {
        p2_pos = 4;
        sp_evnt = 3;
      } else if (p2_pos == 47) {
        p2_pos = 25;
        sp_evnt = 3;
      } else if (p2_pos == 63) {
        p2_pos = 60;
        sp_evnt = 3;
      } else if (p2_pos == 66) {
        p2_pos = 52;
        sp_evnt = 3;
      } else if (p2_pos == 97) {
        p2_pos = 75;
        sp_evnt = 3;
      }
      if (p2_pos == p1_pos) {
        p1_pos = 1;
        player = 2;
        cout << "\n\tP1 replaced\n";
        sleep(1);
        sp_evnt = 2;
      } else {
        player = 1;
      }
      if (sp_evnt == 2) {
        cout << "\n\tLadder\n";
        player = 2;
        sleep(1);
      } else {
        player = 1;
      }
      if (sp_evnt == 3) {
        cout << "\n\tSnake\n";
        if (p2_pos == p1_pos) {
          p1_pos = 1;
          player = 2;
          cout << "\n\tP1 replaced\n";
        } else {
          player = 1;
        }
        sleep(1);
      }
      if (dice == 6) {
        player = 2;
      }
    }
  }
  return 0;
}
