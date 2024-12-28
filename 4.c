#include <stdio.h>

int isValidSudoku(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        int row[10] = {0};
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != 0 && row[board[i][j]] == 1) {
                return 0;
            }
            row[board[i][j]] = 1;
        }
    }

    for (int j = 0; j < 9; j++) {
        int col[10] = {0};
        for (int i = 0; i < 9; i++) {
            if (board[i][j] != 0 && col[board[i][j]] == 1) {
                return 0;
            }
            col[board[i][j]] = 1;
        }
    }

    for (int block = 0; block < 9; block++) {
        int subgrid[10] = {0};
        for (int i = block / 3 * 3; i < block / 3 * 3 + 3; i++) {
            for (int j = block % 3 * 3; j < block % 3 * 3 + 3; j++) {
                if (board[i][j] != 0 && subgrid[board[i][j]] == 1) {
                    return 0;
                }
                subgrid[board[i][j]] = 1;
            }
        }
    }

    return 1;
}

int main() {
    int sudoku[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (isValidSudoku(sudoku)) {
        printf("Valid Sudoku\n");
    } else {
        printf("Invalid Sudoku\n");
    }

    return 0;
}
#include <stdio.h>

struct Student {
    int studentID;
    char name[50];
    char grade;
    float marks[5];
    float averageMarks;
};

void calculateAverage(struct Student *student) {
    float totalMarks = 0.0;
    for (int i = 0; i < 5; i++) {
        totalMarks += student->marks[i];
    }
    student->averageMarks = totalMarks / 5;
}

void assignGrades(struct Student *student) {
    if (student->averageMarks >= 90) {
        student->grade = 'A';
    } else if (student->averageMarks >= 80) {
        student->grade = 'B';
    } else if (student->averageMarks >= 70) {
        student->grade = 'C';
    } else if (student->averageMarks >= 60) {
        student->grade = 'D';
    } else {
        student->grade = 'F';
    }
}

int main() {
    struct Student students[5];
    struct Student *studentPtr = students;

    for (int i = 0; i < 5; i++) {
        printf("Enter Student ID: ");
        scanf("%d", &studentPtr->studentID);
        printf("Enter Name: ");
        scanf("%s", studentPtr->name);

        printf("Enter marks for 5 subjects:\n");
        for (int j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &studentPtr->marks[j]);
        }

        calculateAverage(studentPtr);
        assignGrades(studentPtr);
        studentPtr++;
    }

    studentPtr = students;

    printf("\nStudent Information:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student ID: %d\n", studentPtr->studentID);
        printf("Name: %s\n", studentPtr->name);
        printf("Average Marks: %.2f\n", studentPtr->averageMarks);
        printf("Grade: %c\n", studentPtr->grade);
        printf("\n");
        studentPtr++;
    }

    return 0;
}
