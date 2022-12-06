
//Name: Hasnian Bharmal ID: 1001937588

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class code2_1001937588 
{

    enum ACTION 
    {
        DISPENSECHANGE, INSUFFICIENTCHANGE, INSUFFICIENTFUNDS, EXACTPAYMENT
    }

    public static void main(String[] args) throws FileNotFoundException 
    {
        ArrayList<String> Colors = new ArrayList<>();
        String temp_filename = args[0];
        char equal = '=';
        String filename = temp_filename.substring(temp_filename.indexOf(equal) + 1);

        int user_array[] = new int[2];
        System.out.println("Welcome to my Pencil Machine\n");
        final int pencilPrice = 60;
        Scanner sc = new Scanner(System.in);    
        String[] change_back = new String[2];
        ReadFile(user_array, Colors, filename);
        System.out.print(Colors);
        ArrayList<Character> Frog = new ArrayList<>();
        
        int choice = -1;
        do 
        {
            choice = PencilMenu();
            switch (choice) 
            {
                case 0:
                PrintWriter out = new PrintWriter(filename);
                out.printf("%d %d\n", user_array[0], user_array[1]);
                for (String write : Colors) 
                {
                    out.printf("%s ", write);
                }
                out.close();
                break;
                case 1:
                if(user_array[1] != 0 )
                {

                System.out.printf("A pencil costs %s\n", displayMoney(pencilPrice));
                System.out.print("How many pencils would you like to Purchase? ");
                int pencil_Quantity = sc.nextInt();
                while (pencil_Quantity > user_array[1] || pencil_Quantity < 1)
                {
                    System.out.print("Cannot Sell that quantity of pencils. Please renter quantity ");
                    pencil_Quantity = sc.nextInt();
                }

                Random rn = new Random();
                int index = rn.nextInt(Colors.size());
                int payment = pencil_Quantity * pencilPrice;
                System.out.printf("\n\nYour total is %s\n\n", displayMoney(payment));
                System.out.print("Enter your payment in cents ");
                int payment_recv = sc.nextInt();
                switch (buyPencils(pencilPrice, payment_recv, pencil_Quantity, user_array, change_back)) 
                {
                case DISPENSECHANGE:
                    System.out.printf("Here's your %s pencil and your change of %s\n\n", Colors.get(index), change_back[0]);
                    break;
                case INSUFFICIENTCHANGE:
                    System.out.print("The Pencil Dispenser does not have enough change and cannot accept\nyour payment\n");
                    break;
                case INSUFFICIENTFUNDS:
                    System.out.print("You did not enter a sufficient payment. No pencils for you\n\n");
                    break;
                case EXACTPAYMENT:
                    System.out.printf("Here's your %s pencils, Thank you for exact payment\n", Colors.get(index));
                    break;                
                }
                }
                else
                {
                    System.out.print("Pencil Dispenser is out of pencils");
                }
            
                break;
                case 2:
                int temp = user_array[1];
                System.out.printf("\n\nThe current inventory level is %d\n\n", temp);
                break;
                case 3:
                System.out.printf("\n\nThe current change level is %s\n\n", displayMoney(user_array[0]));
                break;
                default:
                System.out.println("Invalid menu option");
                break;
            }

        }while(choice!=0);

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
        int choice = -1;
        do 
        {
            try 
            {
                choice = user_in.nextInt();
            } catch (Exception e) 
            {
                choice = 'a';
                user_in.next();
            }
            if (choice < 0 || choice > 3) 
            {
                System.out.print("Invalid choice.  Please reenter ");
            }

        } while (choice < 0 || choice > 3);

        return choice;
    }

    public static ACTION buyPencils(int pencilPrice, int payment, int pencilQuantity, int array[], String change[]) 
    {
        int changeP = 0;
        int inventLvl = 1;
        ACTION c = ACTION.EXACTPAYMENT;
        int pay_req = pencilQuantity * pencilPrice;
        int change_bac = payment - pay_req;

        if (payment > 0 && change_bac > 0 && change_bac < array[0]) 
        {
            array[inventLvl] -= pencilQuantity;
            array[changeP] += payment;
            int chngback = payment - pay_req;
            array[changeP] = array[changeP] - chngback;
            change[0] = displayMoney(chngback);
            return ACTION.DISPENSECHANGE;

        } else if (payment > 0 && (payment - pay_req) > array[0]) 
        {
            return ACTION.INSUFFICIENTCHANGE;

        } else if (payment < pay_req) 
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

    public static void ReadFile(int pencil_array[], ArrayList<String> colors, String file_name) 
    {
        File fileIn = new File(file_name);
        Scanner inFileRead = null;
        try 
        {
            inFileRead = new Scanner(fileIn);
        } catch (Exception e) 
        {
            System.out.println("File not found...exiting");
            System.exit(0);
        }
        String line1 = inFileRead.nextLine();
        String line2 = inFileRead.nextLine();
        String line1_tokens[] = line1.split(" ");
        pencil_array[0] = Integer.parseInt(line1_tokens[0]);
        pencil_array[1] = Integer.parseInt(line1_tokens[1]);
        String line2_tokens[] = line2.split(" ");
        for (String it : line2_tokens) 
        {
            colors.add(it);
        }
        inFileRead.close();
    }

}
