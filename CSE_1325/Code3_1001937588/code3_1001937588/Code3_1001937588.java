//Name: Hasnain Bharmal
//ID: 1001937588
package code3_1001937588;

import java.util.Scanner;

public class Code3_1001937588 
{
    public static void main(String[] args) 
    {
        CokeMachine MyCokeMachine = new CokeMachine("CSE 1325 Coke Machine", 50, 500, 100);

        int choice = -1;
        Scanner dot = new Scanner(System.in);
        do 
        {
            choice = Cokemenu(MyCokeMachine.getMachineName());
            switch (choice) 
            {
                case 0:
                    if (MyCokeMachine.getNumberOfCokesSold() == 0) 
                    {
                        System.out.println("Are you sure you aren't really THIRSTY and need a coke");
                    } else 
                    {
                        System.out.println("Thanks for buying coke");
                    }

                    break;
                case 1:
                    System.out.printf("A coke costs %s\n", displayMoney(MyCokeMachine.getCokePrice()));
                    System.out.print("Insert Payment ");
                    int Coke_payment = dot.nextInt();
                    if(MyCokeMachine.getChangeLevel()== MyCokeMachine.getMaxChangeCapacity())
                    {
                        System.out.println("Unable to sell a Coke -  call 1800 WE DONT CARE to register a complaint...returning your payment");
                        break;
                    }
                    else
                    {
                        switch (MyCokeMachine.buyACoke(Coke_payment)) 
                        {
                            case DISPENSECHANGE:
                                System.out.printf("Here's your Coke and your change of %s\n\n",displayMoney(MyCokeMachine.getChangeDispensed()));
                                break;
                            case INSUFFICIENTCHANGE:
                                System.out.print(
                                        "The Coke Dispenser does not have enough change and cannot accept\nyour payment\n");
                                break;
                            case INSUFFICIENTFUNDS:
                                System.out.print("Insufficient payment...returning your payment\n\n");
                                break;
                            case EXACTPAYMENT:
                                System.out.printf("Thank you for exact payment\nHere's your Coke\n");
                                break;
                            case NOINVENTORY:
                                System.out.println("Sorry we are out of coke.");
                                break;
                        }
                    }
                    break;
                    
                case 2:
                    System.out.print("How much product are you adding to the machine");
                    int temp_inven = dot.nextInt();
                    if (MyCokeMachine.incrementInventoryLevel(temp_inven)) 
                    {
                        System.out.println("Your machine has been restocked");
                        System.out.printf("Your inventory level is %d", MyCokeMachine.getInventoryLevel());
                    }

                    else 
                    {
                        System.out.println("You have exceeded your machine's max capacity - no inventory was added");
                        System.out.printf("Your inventory level is %d", MyCokeMachine.getInventoryLevel());
                    }

                    break;
                case 3:
                    System.out.print("How much change are you adding to the machine? ");
                    int temp_chnglvl = dot.nextInt();
                    if (MyCokeMachine.incrementChangeLevel(temp_chnglvl)) 
                    {
                        System.out.println("Your change level has benn updated");
                        System.out.printf("Your change level is %s with a max capcity of %s",displayMoney(MyCokeMachine.getChangeLevel()),displayMoney(MyCokeMachine.getMaxChangeCapacity()));
                    } else 
                    {
                        System.out.println("You exceeded your machine's max change capacity - no change added");
                        System.out.printf("Your change level is %s with a max capcity of %s",displayMoney(MyCokeMachine.getChangeLevel()),displayMoney(MyCokeMachine.getMaxChangeCapacity()));
                    }
                    break;
                case 4:
                    System.out.print(MyCokeMachine);
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

    public static int Cokemenu(String name) 
    {
        System.out.printf("\n%s\n",name);
        System.out.println("\n\n0. Walk Away");
        System.out.println("1. Buy a Coke");
        System.out.println("2. Restock Machine");
        System.out.println("3. Add change");
        System.out.println("4. Display Machine Info");
        Scanner user_in = new Scanner(System.in);
        System.out.print("\n\nChoice : ");
        int choice = -1;
        do {
            try 
            {
                choice = user_in.nextInt();
            } catch (Exception e) 
            {
                choice = 'a';
                user_in.next();
            }
            if (choice < 0 || choice > 5) 
            {
                System.out.print("Invalid choice.  Please reenter ");
            }

        } while (choice < 0 || choice > 5);

        return choice;
    }
}
