#include <stdio.h>

int main() {
    int adults, children, days, roomType;
    int totalRooms, extraChildren, totalCost;
    int roomRate[3]={2000, 4000, 5000};
    
    scanf("%d %d %d %d", &adults, &children, &days, &roomType);
    
    // Required rooms for adults (2 adults per room)
    totalRooms = (adults + 1) / 2;
     
    // Free capacity per room (children can occupy if adults don't fill)
    int occupiedByAdults = adults;
    int freeSpots = totalRooms * 2 - occupiedByAdults;
    
    // Free children (those who fit in free spots)
    int freeChildren = (children <= freeSpots) ? children : freeSpots;
    
    // Extra children (beyond free spots)
    int extraChildrenCount = children - freeChildren;
    
    // Max extra children capacity
    int maxExtraChildren = totalRooms * 2;
    
        // If extra children exceed limit, add new rooms
    if (extraChildrenCount > maxExtraChildren) {
        // Each new room can accommodate 4 children (2 free + 2 extra)
        int remainingChildren = extraChildrenCount - maxExtraChildren;
        int additionalRooms = (remainingChildren + 3) / 4;
        totalRooms += additionalRooms;
        
        // Recalculate free spots
        freeSpots = totalRooms * 2 - occupiedByAdults;
        freeChildren = (children <= freeSpots) ? children : freeSpots;
        extraChildrenCount = children - freeChildren;
    }
    
    // Extra charge calculation
    int extraCharge = extraChildrenCount * 500;
    
    // Total cost
    totalCost = (totalRooms * roomRate[roomType-1] * days) + (extraCharge * days);
    
    // Display result
    printf("\nMinimum Bill: %d\n", totalCost);
    
    return 0;
}
