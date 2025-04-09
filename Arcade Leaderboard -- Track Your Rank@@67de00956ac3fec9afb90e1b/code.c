#include <stdio.h>

// Function prototype
void trackPlayerRanks(int ranked[], int n, int player[], int m, int result[]);

int remove_duplicates(int arr[], int n, int unique[]) {
    int j = 0;
    unique[j++] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            unique[j++] = arr[i];
        }
    }
    return j;
}

void trackPlayerRanks(int ranked[], int n, int player[], int m, int result[]) {
    int unique[n];
    int unique_size = remove_duplicates(ranked, n, unique);
    int index = unique_size - 1;

    for (int i = 0; i < m; i++) {
        int score = player[i];
        while (index >= 0 && score >= unique[index]) {
            index--;
        }
        result[i] = index + 2;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    int ranked[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ranked[i]);
    }

    scanf("%d", &m);
    int player[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &player[i]);
    }

    int result[m];
    trackPlayerRanks(ranked, n, player, m, result);

    for (int i = 0; i < m; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
