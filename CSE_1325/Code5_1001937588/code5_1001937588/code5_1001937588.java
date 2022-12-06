/*
Name : Hasnain Bharmal
ID : 1001937588
*/

package code5_1001937588;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


public class code5_1001937588 
{
    public static void main(String[] args) 
    {
        if (args.length != 3) 
        {
            System.out.println("Missing command line parameters – - Usage :INPUTFILENAME= OUTPUTFILENAME=");
            System.exit(0);
        }
        String trickortreat_file = args[0];
        String houses_file = args[1];
        String candy_file = args[2];
        char equal = '=';
        String tot = trickortreat_file.substring(trickortreat_file.indexOf(equal) + 1);
        String houses = houses_file.substring(houses_file.indexOf(equal) + 1);
        String candy = candy_file.substring(candy_file.indexOf(equal) + 1);

        HashMap<String, Integer> Map = new HashMap<>();
        ArrayList<House> Houses = new ArrayList<>();
        ArrayList<TrickOrTreater> TOT = new ArrayList<>();

        CreateCandyList(candy, Map);
        String House_heading= CreateHouses(houses, Houses,Map);
        CreateTots(tot,Houses,TOT);

        ExecutorService executorService = Executors.newCachedThreadPool();
        for(TrickOrTreater it : TOT)
        {
            executorService.execute(it); 
        }
        TextAreaFrame TAF = new TextAreaFrame();
        TAF.setVisible(true);
        while (TrickOrTreater.ImDone != TOT.size() )
        {

            String ScreenOutput = String.format("%s\n", House_heading);
            for(TrickOrTreater it : TOT)
            {
                ScreenOutput += String.format("%s%s\n", it.getPath(), it.getName());
            }
            TAF.textArea.setText(ScreenOutput);
        }
        executorService.shutdown();
        String BucketContets = "Candy!!\n\n";
        for(TrickOrTreater it : TOT)
        {
            BucketContets = BucketContets+it.printBucket();
        }    
        TAF.textArea.setText(BucketContets);
  
    }

    public static void CreateCandyList(String candyFilename, HashMap<String, Integer> myMap) 
    {
        File fileIn = new File(candyFilename);
        Scanner inFileRead = null;
        try 
        {
            inFileRead = new Scanner(fileIn);
        } catch (Exception e) 
        {
            System.out.printf("%s file name does not exist...exiting", candyFilename);
            System.exit(0);
        }
        while (inFileRead.hasNextLine()) 
        {
            String line1 = inFileRead.nextLine();
            String line1_split[] = line1.split("\\|");
            String name = line1_split[0];
            Integer num = Integer.parseInt(line1_split[1]);
            myMap.put(name, num);
        }
        inFileRead.close();
    }

    public static String CreateHouses(String houseFilename, ArrayList<House> Houses,HashMap<String, Integer> CandyList ) 
    {

        ArrayList<String> CandyHouse = new ArrayList<>();
        ArrayList<String> ToothbrushHouse = new ArrayList<>();
        Random rand = new Random();
        String HouseHeading = "         ";
        File fileIn = new File(houseFilename);
        Scanner inFileRead = null;
        try 
        {
            inFileRead = new Scanner(fileIn);
        } 
        catch (Exception e) 
        {
            System.out.printf("%s file name does not exist...exiting", houseFilename);
            System.exit(0);
        }
        while (inFileRead.hasNextLine()) 
        {
            String line = inFileRead.nextLine();
            HouseHeading = HouseHeading + line;
            for (int i = 0; i < 11 - line.length(); i++) 
            {
                HouseHeading += " ";
            }

        
            int rand_gen = rand.nextInt(3);
            if (rand_gen == 0) 
            {
                Houses.add(new CandyHouse(HouseHeading,CandyList));
            } 
            else 
            {
                Houses.add(new ToothbrushHouse(HouseHeading,CandyList));
            }
        }
        inFileRead.close();
        return HouseHeading;
    }

    public static void CreateTots(String totfilename, ArrayList<House> Houses, ArrayList<TrickOrTreater> TrickorTreater) 
    {
        File fileIn = new File(totfilename);
        Scanner inFileRead = null;
        try 
        {
            inFileRead = new Scanner(fileIn);
        } 
        catch (Exception e) 
        {
            System.out.printf("%s file name does not exist...exiting", totfilename);
            System.exit(0);
        }
        while (inFileRead.hasNextLine()) 
        {
            String line = inFileRead.nextLine();
            TrickorTreater.add(new TrickOrTreater(line, Houses));
        }
        inFileRead.close();
    }

}