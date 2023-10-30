#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char input[100];
int i, l;

int E();
int EP();
int T();
int TP();
int F();

int main() {
    printf("\nRecursive descent parsing for the following grammar\n");
    printf("E -> T E'\n");
    printf("E' -> + T E' | epsilon\n");
    printf("T -> F T'\n");
    printf("T' -> * F T' | epsilon\n");
    printf("F -> (E) | id\n");

    printf("\nEnter the string to be checked: ");
    scanf("%s", input);
    i = 0;
    l = strlen(input);

    if (E() && i == l) {
        printf("\nString is accepted\n");
    } else {
        printf("\nString is not accepted\n");
    }

    return 0;
}

int E() {
    if (T()) {
        if (EP()) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int EP() {
    if (i < l && input[i] == '+') {
        i++;
        if (T()) {
            if (EP()) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 1;  // Epsilon production
    }
}

int T() {
    if (F()) {
        if (TP()) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int TP() {
    if (i < l && input[i] == '*') {
        i++;
        if (F()) {
            if (TP()) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 1;  // Epsilon production
    }
}

int F() {
    if (i < l && input[i] == '(') {
        i++;
        if (E()) {
            if (i < l && input[i] == ')') {
                i++;
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if (i < l && (isalpha(input[i]) || isdigit(input[i]))) {
        i++;
        return 1;
    } else {
        return 0;
    }
}

