#include <stdio.h>

int main() {
    int hostGoals, guestGoals;
    
    scanf("%d %d", &hostGoals, &guestGoals);
    
    if ( hostGoals > guestGoals ) {
        printf("Home team wins\n");
    } else if ( guestGoals > hostGoals ) {
        printf("Away team wins\n");
    } else {
        printf("Draw\n");
    }
    
    return 0;
}
