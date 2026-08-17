#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char orderNames[50][50];
float orderPrices[50];
int orderCount = 0;
float totalBill = 0;

void printLine() {
    printf("  ==============================\n");
}

void printDash() {
    printf("  ------------------------------\n");
}

void addItem(char name[], float price) {
    strcpy(orderNames[orderCount], name);
    orderPrices[orderCount] = price;
    orderCount++;
    totalBill += price;
    printf("\n  >> %-20s added!\n", name);
    printf("  >> Running Total  : Rs. %.2f\n", totalBill);
}

void viewOrder() {
    int i;
    if (orderCount == 0) {
        printf("\n  Your order is empty!\n");
        return;
    }
    printf("\n");
    printLine();
    printf("           YOUR ORDER\n");
    printLine();
    for (i = 0; i < orderCount; i++) {
        printf("  %d. %-22s Rs. %.2f\n", i+1, orderNames[i], orderPrices[i]);
    }
    printDash();
    printf("  Subtotal          : Rs. %.2f\n", totalBill);
    printLine();
}

void removeItem() {
    int choice, i;
    if (orderCount == 0) {
        printf("\n  Your order is empty!\n");
        return;
    }
    viewOrder();
    printf("\n  Enter item number to remove (0 to cancel): ");
    scanf("%d", &choice);

    if (choice == 0) return;
    choice--;

    if (choice < 0 || choice >= orderCount) {
        printf("  Invalid choice!\n");
        return;
    }

    totalBill -= orderPrices[choice];
    printf("\n  >> %s removed!\n", orderNames[choice]);

    for (i = choice; i < orderCount - 1; i++) {
        strcpy(orderNames[i], orderNames[i+1]);
        orderPrices[i] = orderPrices[i+1];
    }
    orderCount--;
    printf("  >> New Total      : Rs. %.2f\n", totalBill);
}

void applyOffer(float *grandTotal) {
    float discount = 0;
    printf("\n");
    printDash();
    printf("        *** OFFER APPLIED ***\n");
    printDash();

    if (totalBill >= 499) {
        discount = totalBill * 0.15;
        *grandTotal -= discount;
        printf("  Order above Rs.499!\n");
        printf("  15%% discount : -Rs. %.2f\n", discount);
    } else if (totalBill >= 299) {
        discount = totalBill * 0.10;
        *grandTotal -= discount;
        printf("  Order above Rs.299!\n");
        printf("  10%% discount : -Rs. %.2f\n", discount);
    } else if (totalBill >= 199) {
        discount = totalBill * 0.05;
        *grandTotal -= discount;
        printf("  Order above Rs.199!\n");
        printf("   5%% discount : -Rs. %.2f\n", discount);
    }
    printDash();
}

void checkout() {
    int i, modChoice, mod, pay;
    float gst, grandTotal;

    if (orderCount == 0) {
        printf("\n  Your order is empty!\n");
        return;
    }

    viewOrder();

    printf("\n  CHECKOUT MENU\n");
    printDash();
    printf("  1. Confirm & Pay\n");
    printf("  2. Modify Order\n");
    printf("  3. Cancel Order\n");
    printDash();
    printf("  Choice: ");
    scanf("%d", &modChoice);

    if (modChoice == 2) {
        printf("\n  MODIFY ORDER\n");
        printDash();
        printf("  1. Add More Items\n");
        printf("  2. Remove an Item\n");
        printDash();
        printf("  Choice: ");
        scanf("%d", &mod);
        if (mod == 2) removeItem();
        printf("\n  Returning to Main Menu...\n");
        return;

    } else if (modChoice == 3) {
        orderCount = 0;
        totalBill = 0;
        printf("\n  Order cancelled! Come back soon.\n");
        return;

    } else if (modChoice != 1) {
        printf("  Invalid choice!\n");
        return;
    }

    // calculate bill
    gst        = totalBill * 0.05;
    grandTotal = totalBill + gst;

    // print receipt
    printf("\n");
    printLine();
    printf("        SYMBIEAT RECEIPT\n");
    printLine();
    for (i = 0; i < orderCount; i++) {
        printf("  %-24s Rs. %.2f\n", orderNames[i], orderPrices[i]);
    }
    printDash();
    printf("  Subtotal          : Rs. %.2f\n", totalBill);
    printf("  GST (5%%)          : Rs. %.2f\n", gst);

    if (totalBill >= 199) {
        applyOffer(&grandTotal);
    }

    printDash();
    printf("  TOTAL PAYABLE     : Rs. %.2f\n", grandTotal);
    printLine();

    // payment method
    printf("\n  SELECT PAYMENT METHOD\n");
    printDash();
    printf("  1. Cash\n");
    printf("  2. Card\n");
    printf("  3. UPI\n");
    printDash();
    printf("  Choice: ");
    scanf("%d", &pay);

    printf("\n");
    printLine();
    printf("         PAYMENT CONFIRMED\n");
    printLine();
    if      (pay == 1) printf("  Method            : CASH\n");
    else if (pay == 2) printf("  Method            : CARD\n");
    else if (pay == 3) printf("  Method            : UPI\n");
    else               printf("  Method            : CASH\n");
    printf("  Amount Paid       : Rs. %.2f\n", grandTotal);
    printf("  Status            : PAID\n");
    printDash();
    printf("  Thank you for dining with us!\n");
    printf("  Please collect at the counter.\n");
    printLine();

    // reset
    orderCount = 0;
    totalBill  = 0;

    // next order prompt
    char next;
    printf("\n  Press Y for new order, N to exit: ");
    scanf(" %c", &next);
    if (next == 'y' || next == 'Y') {
        printf("\n  Starting new order...\n");
    } else {
        printf("\n");
        printLine();
        printf("  Goodbye! Visit us again!\n");
        printLine();
        exit(0);
    }
}

void burgerMenu() {
    int choice;
    printf("\n");
    printLine();
    printf("             BURGERS\n");
    printLine();
    printf("  1. Veg Whopper      Rs. 159\n");
    printf("  2. Paneer Blaster   Rs. 189\n");
    printf("  3. Chicken Crispy   Rs. 249\n");
    printf("  4. Chicken Royale   Rs. 299\n");
    printf("  5. Back\n");
    printDash();
    printf("  Choice: ");
    scanf("%d", &choice);

    if      (choice == 1) addItem("Veg Whopper", 159);
    else if (choice == 2) addItem("Paneer Blaster", 189);
    else if (choice == 3) addItem("Chicken Crispy", 249);
    else if (choice == 4) addItem("Chicken Royale", 299);
    else if (choice == 5) return;
    else printf("  Invalid choice!\n");
}

void sidesMenu() {
    int choice;
    printf("\n");
    printLine();
    printf("              SIDES\n");
    printLine();
    printf("  1. French Fries     Rs.  89\n");
    printf("  2. Onion Rings      Rs.  99\n");
    printf("  3. Nuggets (6pc)    Rs. 129\n");
    printf("  4. Choco Lava Cake  Rs. 109\n");
    printf("  5. Back\n");
    printDash();
    printf("  Choice: ");
    scanf("%d", &choice);

    if      (choice == 1) addItem("French Fries", 89);
    else if (choice == 2) addItem("Onion Rings", 99);
    else if (choice == 3) addItem("Nuggets (6pc)", 129);
    else if (choice == 4) addItem("Choco Lava Cake", 109);
    else if (choice == 5) return;
    else printf("  Invalid choice!\n");
}

void drinksMenu() {
    int choice;
    printf("\n");
    printLine();
    printf("             DRINKS\n");
    printLine();
    printf("  1. Coke             Rs.  59\n");
    printf("  2. Sprite           Rs.  59\n");
    printf("  3. Mango Shake      Rs.  99\n");
    printf("  4. Water Bottle     Rs.  20\n");
    printf("  5. Back\n");
    printDash();
    printf("  Choice: ");
    scanf("%d", &choice);

    if      (choice == 1) addItem("Coke", 59);
    else if (choice == 2) addItem("Sprite", 59);
    else if (choice == 3) addItem("Mango Shake", 99);
    else if (choice == 4) addItem("Water Bottle", 20);
    else if (choice == 5) return;
    else printf("  Invalid choice!\n");
}

void showOffers() {
    printf("\n");
    printLine();
    printf("          TODAY'S OFFERS\n");
    printLine();
    printf("  Order above Rs.199  ->  5%% OFF\n");
    printf("  Order above Rs.299  -> 10%% OFF\n");
    printf("  Order above Rs.499  -> 15%% OFF\n");
    printDash();
    printf("  * Discount applied at checkout\n");
    printLine();
}

int main() {
    int choice;

    printf("\n");
    printLine();
    printf("     WELCOME TO SYMBIEAT CAFE!\n");
    printf("         Self Order Kiosk\n");
    printDash();
    printf("    Burgers | Sides | Drinks\n");
    printLine();

    do {
        printf("\n  MAIN MENU\n");
        printDash();
        printf("  1. Burgers\n");
        printf("  2. Sides\n");
        printf("  3. Drinks\n");
        printf("  4. View Order\n");
        printf("  5. Checkout\n");
        printf("  6. View Offers\n");
        printf("  7. Exit\n");
        printDash();
        printf("  Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: burgerMenu(); break;
            case 2: sidesMenu();  break;
            case 3: drinksMenu(); break;
            case 4: viewOrder();  break;
            case 5: checkout();   break;
            case 6: showOffers(); break;
            case 7:
                printf("\n");
                printLine();
                printf("  Goodbye! Visit us again!\n");
                printLine();
                break;
            default:
                printf("  Invalid choice! Try again.\n");
        }

    } while (choice != 7);

    return 0;
}
