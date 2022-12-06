/*
Name : Hasnain Bharmal
ID : 1001937588
*/

package code5_1001937588;

import java.util.HashMap;
import java.util.Random;

public class CandyHouse extends House 
{

    public CandyHouse(String houseName, HashMap<String, Integer> candyList) {
        super(houseName, candyList);
    }

    @Override
    public synchronized String ringDoorbell(TrickOrTreater TOT) 
    {
        String Candy="Hello";
        TOT.addToPath("+");
        try 
        {
            Thread.sleep(3000);
        } 
        catch (InterruptedException e) 
        {
            e.getMessage();
        }
        Random rn = new Random();
        int rnum = rn.nextInt(CandyList.size())+1;
        for (HashMap.Entry mapElement : CandyList.entrySet()) 
        {
            int value = (int) mapElement.getValue();
            if(value == rnum) 
            {
                Candy = (String) mapElement.getKey();
            }

        }
        return Candy;

    }
}
