/*
Name : Hasnain Bharmal
ID : 1001937588
*/

package code5_1001937588;

import java.util.HashMap;

public class ToothbrushHouse extends House 
{

    public ToothbrushHouse(String houseName, HashMap<String, Integer> candyList) 
    {
        super(houseName, candyList);
    }

    @Override
    public synchronized String ringDoorbell(TrickOrTreater TOT) 
    {
        TOT.addToPath("-");
        try 
        {
            Thread.sleep(3000);
        } 
        catch (InterruptedException e) 
        {
            e.getMessage();
        }
        return "Toothbrush";
    }
    
}
