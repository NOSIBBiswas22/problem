#include <stdio.h>
#include <math.h>

int main() {
    int adults, children, days, roomType;
    int roomRate, totalRooms, extraChildren, totalCost;
    
    // ইনপুট নেওয়া
    printf("Adults সংখ্যা: ");
    scanf("%d", &adults);
    
    printf("Children সংখ্যা: ");
    scanf("%d", &children);
    
    printf("Days সংখ্যা: ");
    scanf("%d", &days);
    
    printf("Room Type (1/2/3): ");
    scanf("%d", &roomType);
    
    // রুম টাইপ অনুযায়ী রেট নির্ধারণ
    int roomVarient[] = {2000, 4000, 5000};
    
    if (roomType < 1 || roomType > 3) {
        printf("Invalid Room Type!\n");
        return 1;
    }
    
    roomRate = roomVarient[roomType - 1];
    
    // Adults এর জন্য প্রয়োজনীয় রুম সংখ্যা (প্রতি রুমে ২ জন adult)
    totalRooms = (int)ceil((double)adults / 2);
    
    // প্রতি রুমে free capacity (adult না থাকলে child বসতে পারে)
    int occupiedByAdults = adults;
    int freeSpots = totalRooms * 2 - occupiedByAdults;
    
    // Free children (যারা free spots এ বসবে)
    int freeChildren = (children <= freeSpots) ? children : freeSpots;
    
    // Extra children (free spots এর বাইরে)
    int extraChildrenCount = children - freeChildren;
    
    // ম্যাক্স extra children capacity
    int maxExtraChildren = totalRooms * 2;
    
    // যদি extra children সীমা অতিক্রম করে, তাহলে নতুন রুম add করতে হবে
    if (extraChildrenCount > maxExtraChildren) {
        // অতিরিক্ত children দের জন্য নতুন রুম লাগবে
        // প্রতি নতুন রুমে 4 জন child থাকতে পারবে (2 free + 2 extra)
        int remainingChildren = extraChildrenCount - maxExtraChildren;
        int additionalRooms = (int)ceil((double)remainingChildren / 4);
        totalRooms += additionalRooms;
        
        // নতুন calculation
        freeSpots = totalRooms * 2 - occupiedByAdults;
        freeChildren = (children <= freeSpots) ? children : freeSpots;
        extraChildrenCount = children - freeChildren;
    }
    
    // এক্সট্রা চার্জ ক্যালকুলেশন
    int extraCharge = extraChildrenCount * 500;
    
    // মোট খরচ
    totalCost = (totalRooms * roomRate * days) + (extraCharge * days);
    
    // রেজাল্ট দেখানো
    printf("\n=== বিলিং সামারি ===\n");
    printf("Adults: %d\n", adults);
    printf("Children: %d (Free: %d, Extra: %d)\n", children, freeChildren, extraChildrenCount);
    printf("প্রয়োজনীয় রুম: %d\n", totalRooms);
    printf("রুম রেট (প্রতি রাত): %d টাকা\n", roomRate);
    printf("Extra Children চার্জ: %d টাকা/দিন\n", extraCharge);
    printf("মোট দিন: %d\n", days);
    printf("\n*** মোট পেমেন্ট: %d টাকা ***\n", totalCost);
    
    return 0;
}