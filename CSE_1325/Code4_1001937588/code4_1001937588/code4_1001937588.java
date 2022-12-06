//Name: Hasnain Bharmal
//ID: 1001937588
package code4_1001937588;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class code4_1001937588 
{
    public static void main(String[] args) throws FileNotFoundException 
    {
        if(args.length != 2)
        {
            System.out.println("Missing command line parameters – - Usage :INPUTFILENAME= OUTPUTFILENAME=");
            System.exit(0);
        }
        String temp_filename = args[0];
        String temp_output = args[1];
        char equal = '=';
        String inputFileName = temp_filename.substring(temp_filename.indexOf(equal) +1);
        String outputfile = temp_output.substring(temp_output.indexOf(equal) +1);
        Scanner dot = new Scanner(System.in);
        ArrayList<CokeMachine> SetOfCokeMachines = new ArrayList<>();
        ReadFile(SetOfCokeMachines, inputFileName);
        int choice = -1;
        int wassup_choice = -1;
        CokeMachine MyCokeMachine = SetOfCokeMachines.get(2);
        do 
        {
            wassup_choice = machinemenu(SetOfCokeMachines);
            if (wassup_choice == SetOfCokeMachines.size() + 1) 
            {

                SetOfCokeMachines.add(new CokeMachine());
                OutFile(outputfile, SetOfCokeMachines);
            } 
            else if (wassup_choice != 0) 
            {
                MyCokeMachine = SetOfCokeMachines.get(wassup_choice - 1);
                do 
                {
                    choice = Cokemenu(MyCokeMachine.getMachineName());
                    switch (choice) 
                    {
                        case 0:
                        // if (MyCokeMachine.getNumberOfCokesSold() == 0) 
                        // {
                        //     System.out.println("Are you sure you aren't really THIRSTY and need a coke");
                        // } else 
                        // {
                        //     System.out.println("Thanks for buying coke");
                        // }
                            break;
                        case 1:
                            System.out.printf("A coke costs %s\n", displayMoney(MyCokeMachine.getCokePrice()));
                            System.out.print("Insert Payment ");
                            int Coke_payment = dot.nextInt();
                            if (MyCokeMachine.getChangeLevel() == MyCokeMachine.getMaxChangeCapacity()) 
                            {
                                System.out.println(
                                        "Unable to sell a Coke -  call 1800 WE DONT CARE to register a complaint...returning your payment");
                                break;
                            } 
                            else 
                            {
                                switch (MyCokeMachine.buyACoke(Coke_payment)) 
                                {
                                    case DISPENSECHANGE:
                                        System.out.printf("Here's your Coke and your change of %s\n\n",
                                                displayMoney(MyCokeMachine.getChangeDispensed()));
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
                        case 5:
                            System.out.print("\nEnter a new Machine name ");
                            String new_machine_name = dot.nextLine();
                            MyCokeMachine.setMachineName(new_machine_name);
                            System.out.print("Machine name has been updated");
                            break;
                        case 6:
                            System.out.print("Enter a new Coke Price: ");
                            int new_coke_price = dot.nextInt();
                            MyCokeMachine.setCokePrice(new_coke_price);
                            System.out.println("Coke price has ben updated");
                            break;
                    }
                } 
                while (choice != 0);
            }
            OutFile(outputfile, SetOfCokeMachines);
        } 
        while (wassup_choice != 0);
        System.out.printf("%d Coke(s) were sold today!\n", MyCokeMachine.getNumberOfCokesSold());
    }

    public static String displayMoney(int cash) 
    {
        int Dollar = cash / 100;
        int cents = cash % 100;
        String in = "$" + String.valueOf(Dollar) + "." + String.valueOf(cents);
        return in;
    }

    public static int machinemenu(ArrayList<CokeMachine> machine) 
    {
        System.out.println("\nPick a Coke Machine\n\n");
        System.out.println("0.Exit");
        for (int i = 0; i < machine.size(); i++) 
        {
            System.out.printf("%d.%s\n", i + 1, machine.get(i).getMachineName());
        }
        System.out.printf("%d Add new machine", machine.size() + 1);
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
            if (choice < 0 || choice > machine.size() + 1) 
            {
                System.out.print("Invalid choice.  Please reenter ");
            }

        } 
        while (choice < 0 || choice > machine.size() + 1);

        return choice;
    }

    public static int Cokemenu(String name) 
    {
        System.out.printf("\n%s\n", name);
        System.out.println("\n\n0. Walk Away");
        System.out.println("1. Buy a Coke");
        System.out.println("2. Restock Machine");
        System.out.println("3. Add change");
        System.out.println("4. Display Machine Info");
        System.out.println("5. Update Machine Name");
        System.out.println("6. Update Coke Price");
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
            if (choice < 0 || choice > 7) 
            {
                System.out.print("Invalid choice.  Please reenter ");
            }

        } 
        while (choice < 0 || choice > 7);
        return choice;
    }

    public static void OutFile(String output_name, ArrayList<CokeMachine> machine) throws FileNotFoundException 
    {
        PrintWriter out = null;
        try 
        {
            out = new PrintWriter(output_name);
        } catch (Exception e) {
            System.out.println("Unable to write output file");
            System.out.println(e.getMessage());
            throw new FileNotFoundException();
        }

        for (CokeMachine write : machine) 
        {
            out.printf("%s\n", write.getMachineName());
        }
        out.close();

    }

    public static void ReadFile(ArrayList<CokeMachine> name, String file_name) 
    {
        File fileIn = new File(file_name);
        Scanner inFileRead = null;
        try 
        {
            inFileRead = new Scanner(fileIn);
        } 
        catch (Exception e) 
        {
            System.out.printf("%s file name does not exist...exiting", file_name);

            System.exit(0);
        }

        while (inFileRead.hasNextLine()) 
        {
            String line1 = inFileRead.nextLine();
            String line1_split[] = line1.split("\\|");
            name.add(new CokeMachine(line1_split[0], Integer.parseInt(line1_split[1]), Integer.parseInt(line1_split[2]),Integer.parseInt(line1_split[3])));
        }
        inFileRead.close();
    }
}
