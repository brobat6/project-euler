#include <bits/stdc++.h>
using namespace std;

/**
 * Random number generator (32-bit). 
 * For 64-bit, use mt19937_64
 * Usage: 
 * rng() (returns unsigned int, do abs(int(rng())))
 * shuffle(v.begin(), v.end(), rng);
*/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/**
 * Random number in the range [x, y]
*/
int random_number(int x, int y) {
    assert(x <= y);
    return abs(int(rng())) % (y - x + 1) + x;
}

int position;
vector <pair<int, int>> space;

void go_to_jail() {
    position = 10;
}

void advance_to_go() {
    position = 0;
}

void go_to_next_railway() {
    while(position != 5 && position != 15 && position != 25 && position != 35) {
        position = (position + 1) % 40;
    }
}

void go_to_next_utility() {
    while(position != 12 && position != 28) {
        position = (position + 1) % 40;
    }
}

void chance() {
    int x = random_number(1, 16);
    if(x == 1) {
        advance_to_go();
    } else if(x == 2) {
        go_to_jail();
    } else if(x == 3) {
        position = 11;
    } else if(x == 4) {
        position = 24;
    } else if(x == 5) {
        position = 39;
    } else if(x == 6) {
        position = 5;
    } else if(x == 7) {
        go_to_next_railway();
    } else if(x == 8) {
        go_to_next_railway();
    } else if(x == 9) {
        go_to_next_utility();
    } else if(x == 10) {
        position -= 3;
    }
}

void community_chest() {
    int x = random_number(1, 16);
    if(x == 1) {
        advance_to_go();
    } else if(x == 2) {
        go_to_jail();
    }
}

void execute_position() {
    if(position == 30) {
        go_to_jail();
    } else if(position == 7 || position == 22 || position == 36) {
        chance();
    } else if(position == 2 || position == 17 || position == 33) {
        community_chest();
    }
}

void roll_dice(int count_double_sixes) {
    space[position].first++;
    int dice_1 = random_number(1, 4);
    int dice_2 = random_number(1, 4);
    int roll = dice_1 + dice_2;
    if(roll == 8 && count_double_sixes == 2) {
        go_to_jail();
        return;
    }
    position = (position + roll) % 40;
    execute_position();
    if(roll == 8) {
        roll_dice(count_double_sixes + 1);
    }
}

void init_board() {
    position = 0;
    space.resize(40);
    for(int i = 0; i < 40; i++) {
        space[i] = {0, i};
    }
}

void print_result() {
    sort(space.begin(), space.end(), greater<pair<int, int>>());
    for(int i = 0; i < 40; i++) {
        cout << "Position : " << space[i].second << ", Landed : " << space[i].first << " times\n";
    }
}

int main() {

    init_board();
    for(int i = 0; i < 1000000; i++) {
        roll_dice(0);
    }
    print_result();

}
