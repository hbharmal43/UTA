/*
Name : Hasnain Bharmal
ID : 1001937588
*/

package code5_1001937588;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class TrickOrTreater implements Runnable 
{
    public static int ImDone;
    private String name;
    private ArrayList<House> ListOfHouses = new ArrayList<>();
    private HashMap<String, Integer> Bucket = new HashMap<>();
    private String path = ".";

    public String getName() 
    {
        return name;
    }

    public String getPath() 
    {
        return path;
    }

    public TrickOrTreater(String name, ArrayList<House> ListOfHouses)
    {
        this.name = name;
        this.ListOfHouses= ListOfHouses;
    }

    public void addToPath(String add)
    {
        path=path+add;
 
    }

    private void Walk(int speed)
    {
        for(int i =0;i<10;i++)
        {
            path=path+".";
            try 
            {
                Thread.sleep(speed);
            } 
            catch (InterruptedException e) 
            {
                e.getMessage();
            }
        }
    }

    public String printBucket()
    {
        String Candy;
        String BucketContents;
        int CandyCount = 0; 
        BucketContents = String.format("%-10s - ", name);
        for (Map.Entry<String,Integer> bucketElement : Bucket.entrySet())
        {
            Candy = (String)bucketElement.getKey();
            CandyCount = (int)bucketElement.getValue();
            BucketContents += String.format("%15s %d ", Candy, CandyCount);
        }
        BucketContents += "\n";
        return BucketContents;
    }

    @Override
    public void run() 
    {
    
        int speed =0;
        int count =0;
        String Candy;
        Random rn =new Random();

        for(House it:ListOfHouses)
        {
            speed = rn.nextInt(1501)+1;
            
            Walk(speed);
            Candy = it.ringDoorbell(this);
            if(Bucket.containsKey(Candy))
            {
                count = (int)Bucket.get(Candy);
                count++;
                Bucket.put(Candy, count);    
            }
            else
            {
                Bucket.put(Candy,1);
            }

        }
        
        synchronized(this)
        {
            ImDone++;
        }
    } 
}
