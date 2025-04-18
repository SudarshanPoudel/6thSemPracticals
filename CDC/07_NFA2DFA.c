#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_SYMBOLS 2

int nfa[3][MAX_SYMBOLS][MAX_STATES] = {
    {{0, 1}, {0}},    // From state 0: on 'a' -> 0,1, on 'b' -> 0
    {{2}, {1}},       // From state 1: on 'a' -> 2, on 'b' -> 1
    {{2}, {2}}        // From state 2: on 'a' -> 2, on 'b' -> 2
};

char symbols[MAX_SYMBOLS] = {'a', 'b'};
int dfa[100][MAX_SYMBOLS];
int dfa_states_set[100][MAX_STATES];
int dfa_states = 0;

typedef struct {
    int states[MAX_STATES];
    int count;
} StateSet;

StateSet move(StateSet s, int sym) {
    StateSet result = { .count = 0 };
    for (int i = 0; i < s.count; i++) {
        int state = s.states[i];
        for (int j = 0; j < MAX_STATES; j++) {
            if (nfa[state][sym][j] == 1) {
                int exists = 0;
                for (int k = 0; k < result.count; k++) {
                    if (result.states[k] == j) {
                        exists = 1;
                        break;
                    }
                }
                if (!exists) {
                    result.states[result.count++] = j;
                }
            }
        }
    }
    return result;
}

int state_exists(StateSet s) {
    for (int i = 0; i < dfa_states; i++) {
        if (memcmp(dfa_states_set[i], s.states, sizeof(s.states)) == 0) {
            return i;
        }
    }
    return -1;
}

void print_set(StateSet s) {
    printf("{ ");
    for (int i = 0; i < s.count; i++) {
        printf("%d ", s.states[i]);
    }
    printf("}");
}

int main() {
    StateSet start = {{0}, 1};
    dfa_states_set[dfa_states][0] = 0;  // State 0
    dfa_states++;
    
    for (int i = 0; i < dfa_states; i++) {
        for (int j = 0; j < MAX_SYMBOLS; j++) {
            StateSet next = move((StateSet){.states = {dfa_states_set[i][0]}, .count = 1}, j);
            int index = state_exists(next);
            if (index == -1 && next.count > 0) {
                memcpy(dfa_states_set[dfa_states], next.states, sizeof(next.states));
                dfa[i][j] = dfa_states++;
            } else {
                dfa[i][j] = index;
            }
        }
    }

    printf("\nDFA Transition Table:\n");
    printf("State\t");
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        printf("%c\t", symbols[i]);
    }
    printf("\n");

    for (int i = 0; i < dfa_states; i++) {
        print_set((StateSet){.states = {dfa_states_set[i][0]}, .count = 1});
        printf("\t");
        for (int j = 0; j < MAX_SYMBOLS; j++) {
            print_set((StateSet){.states = {dfa_states_set[dfa[i][j]][0]}, .count = 1});
            printf("\t");
        }
        printf("\n");
    }

    return 0;
}
