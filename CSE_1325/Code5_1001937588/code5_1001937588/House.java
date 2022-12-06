/*
Name : Hasnain Bharmal
ID : 1001937588
*/

package code5_1001937588;

import java.util.HashMap;

abstract class House 
{
    private String houseName;
    HashMap<String, Integer> CandyList;
    
    public House(String houseName, HashMap<String, Integer> candyList) 
    {
        this.houseName = houseName;
        CandyList = candyList;
    }
    abstract String ringDoorbell(TrickOrTreater TOT);
}
    

    

