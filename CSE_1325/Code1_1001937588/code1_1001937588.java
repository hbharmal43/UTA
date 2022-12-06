
//Name: Hasnian Bharmal ID: 1001937588
package code1_1001937588;

import java.util.Scanner;


public class code1_1001937588 {

    enum ACTION 
    {
        DISPENSECHANGE, INSUFFICIENTCHANGE, INSUFFICIENTFUNDS, EXACTPAYMENT
    }

    public static void main(String[] args)
    {
        System.out.println("Welcome to my Pencil Machine\n");
        final int pencilPrice = 60;
        int invent_lvl = 100;
        int change_lvl = 500;

        int user_array[] = { change_lvl, invent_lvl };
        Scanner sc = new Scanner(System.in);
        String[] change_back = new String[2];

        int choice = -1;

        do 
        {
            choice = PencilMenu();
            switch (choice) 
            {
                case 0:
                    break;
                case 1:
                    System.out.printf("A pencil costs %s\n", displayMoney(pencilPrice));
                    System.out.print("How many pencils would you like to Purchase? ");
                    int pencil_Quantity = sc.nextInt();
                    while (pencil_Quantity > user_array[1] || pencil_Quantity < 1) {
                        System.out.print("Cannot Sell that quantity of pencils. Please renter quantity ");
                        pencil_Quantity = sc.nextInt();
                    }
                    int payment = pencil_Quantity * pencilPrice;
                    System.out.printf("\n\nYour total is %s\n\n", displayMoney(payment));
                    System.out.print("Enter your payment in cents ");
                    int payment_recv = sc.nextInt();
                    switch (buyPencils(pencilPrice, payment_recv, pencil_Quantity, user_array, change_back)) {
                        case DISPENSECHANGE:
                            System.out.printf("Here's your pencil and your change of %s\n\n", change_back[0]);
                            break;
                        case INSUFFICIENTCHANGE:
                            break;
                        case INSUFFICIENTFUNDS:
                            System.out.print("You did not enter a sufficient payment. No pencils for you\n\n");
                            break;
                        case EXACTPAYMENT:
                            System.out.println("Here's your pencils, Thank you for exact payment");
                            break;
                    }
                    break;
                case 2:
                    System.out.printf("\n\nThe current inventory level is %d\n\n", user_array[1]);
                    break;
                case 3:
                    System.out.printf("\n\nThe current change level is %s\n\n", displayMoney(user_array[0]));
                    break;
                default:
                    System.out.println("Invalid menu option");
                    break;
            }

        } while (choice != 0);
    }

    public static String displayMoney(int cash) 
    {
        int Dollar = cash / 100;
        int cents = cash % 100;
        String in = "$" + String.valueOf(Dollar) + "." + String.valueOf(cents);
        return in;
    }

    public static int PencilMenu() 
    {
        System.out.println("\nPlease choose from the following options");
        System.out.println("\n\n0. No pencils for me today");
        System.out.println("1. Purchase pencils");
        System.out.println("2. Check inventory level");
        System.out.println("3. Check change level");
        Scanner user_in = new Scanner(System.in);
        System.out.print("\n\nChoice : ");
        int choice = user_in.nextInt();
        return choice;
    }

    public static ACTION buyPencils(int pencilPrice, int payment, int pencilQuantity, int array[], String change[]) 
    {
        int changeP = 0;
        int inventLvl = 1;
        ACTION c = ACTION.EXACTPAYMENT;
        int pay_req = pencilQuantity * pencilPrice;
        int total_change = array[0] + payment;
        int change_bac = payment - pay_req;
        if (payment > 0 && change_bac > 0 && change_bac < total_change) 
        {
            array[inventLvl] -= pencilQuantity;
            array[changeP] += payment;
            int chngback = payment - pay_req;
            array[changeP] = array[changeP] - chngback;
            change[0] = displayMoney(chngback);
            return ACTION.DISPENSECHANGE;
        } 
        else if (payment > 0 && change_bac > array[changeP]) 
        {
            return ACTION.INSUFFICIENTCHANGE;
        }
        else if (payment < pay_req) 
        {
            return ACTION.INSUFFICIENTFUNDS;
        } else if (payment > 0 && change_bac == 0) 
        {
            array[inventLvl] -= pencilQuantity;
            array[changeP] += payment;
            return ACTION.EXACTPAYMENT;
        }
        return c;
    }
}