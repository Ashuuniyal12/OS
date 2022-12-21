#include<stdio.h>
#include<math.h>
int main()
{
    int head, totalHeadMovement = 0, n;
    printf("Enter the Number of Tracks in Request Queue : ");
    scanf("%d", &n);
    int sequence[n+1];
    printf("Enter the initial Head position : ");
    scanf("%d", &head);
    printf("Enter the Track Sequence from Request Queue : ");
    for(int i = 0; i < n; i++)
        scanf("%d", &sequence[i]);
    sequence[n] = head;

    // Sorting the sequence in ascending order
    for(int i = 0; i <=n; i++){
        for(int j = i+1; j <=n; j++){
            if(sequence[i] > sequence[j]){
                int temp = sequence[i];
                sequence[i] = sequence[j];
                sequence[j] = temp;
            }
        }
    }
    // Finding the index of head in the sequence
    int index;
    for(int i = 0; i <= n; i++){
        if(sequence[i] == head){
            index = i;
            break;
        }
    }

    printf("Enter the head movement direction (0 for left and 1 for right) : ");
    int direction;
    scanf("%d", &direction);

    printf("Seek Sequence is : \n");
    if(direction==0){
        printf("down \n");
        for(int i = index; i >= 0; i--){
            printf("%d\n", sequence[i]);
            totalHeadMovement += abs(head-sequence[i]);
            head = sequence[i];
        }
        for(int i = index+1; i<=n; i++){
            printf("%d\n", sequence[i]);
            totalHeadMovement += abs(head-sequence[i]);
            head = sequence[i];
        }
    }
    else{
        printf("up \n");
        for(int i = index; i <= n; i++){
            printf("%d\n", sequence[i]);
            totalHeadMovement += abs(head-sequence[i]);
            head = sequence[i];
        }
        for(int i = index-1; i >= 0; i--){
            printf("%d\n", sequence[i]);
            totalHeadMovement += abs(head-sequence[i]);
            head = sequence[i];
        }
    }
    printf("Total Head Movement = %d", totalHeadMovement);
}