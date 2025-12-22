struct india{
    char player_name[50];
    int runs;
    int wickets;
};
int main(){
    struct india p[3];
    int i,j,max_run =-1,max_wicket=-1;
    for(i=0;i<3;i++){
        printf("Enter the player name, runs and wickets of player %d-->",i+1);
        scanf(" %[^\n]", p[i].player_name);  
        scanf("%d", &p[i].runs);
        scanf("%d", &p[i].wickets);
    }

    for(i=0;i<3;i++){
        if (p[i].runs > max_run){
            max_run = p[i].runs;
            j =i;
        }
    }
    printf("Details of player with highest runs:\n");
    printf("Player Name: %s\nRuns: %d\nWickets: %d\n",p[j].player_name,p[j].runs,p[j].wickets);

    for(i=0;i<3;i++){
        if (p[i].wickets > max_wicket){
            max_wicket = p[i].wickets;
            j =i;
        }
    }
    printf("Details of player with highest wickets:\n");
    printf("Player Name: %s\nRuns: %d\nWickets: %d\n",p[j].player_name,p[j].runs,p[j].wickets);
}