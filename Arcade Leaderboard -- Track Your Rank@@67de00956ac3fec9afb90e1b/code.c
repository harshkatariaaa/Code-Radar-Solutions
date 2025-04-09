#include <stdio.h>

int remove_duplicates(int arr[], int n, int unique[]) {
    int i, j = 0;
    unique[j++] = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            unique[j++] = arr[i];
        }
    }
    return j; // return new size
}

 {
    int n, m;
    scanf("%d", &n);

    int leaderboard[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &leaderboard[i]);
    }

    // Create unique leaderboard (Dense Ranking)
    int unique[n];
    int unique_size = remove_duplicates(leaderboard, n, unique);

    scanf("%d", &m);
    int scores[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &scores[i]);
    }

    int index = unique_size - 1;

    for (int i = 0; i < m; i++) {
        int player_score = scores[i];

        // Move up leaderboard while player_score >= current leaderboard score
        while (index >= 0 && player_score >= unique[index]) {
            index--;
        }

        printf("%d\n", index + 2); // index+2 due to 0-based indexing
    }

    return 0;
}
