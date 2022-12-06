//Name: Hasnain Bharmal
//ID: 1001937588
package code3_1001937588;

enum ACTION 
{
    DISPENSECHANGE, INSUFFICIENTCHANGE, INSUFFICIENTFUNDS, EXACTPAYMENT, NOINVENTORY;
}

public class CokeMachine 
{
    private String machineName;
    private int changeLevel;
    private int maxChangeCapacity = 5000;
    private int inventoryLevel;
    private int maxInventoryCapacity = 100;
    private int CokePrice;
    private int changeDispensed;
    private static int numberOfCokesSold = 0;

    public CokeMachine(String name, int cost, int change, int inventory) 
    {
        machineName = name;
        CokePrice = cost;
        changeLevel = change;
        inventoryLevel = inventory;
    }

    //@Override
    public String toString() 
    {
        return String.format("Machine Name \t\t %s\nCurrent Inventory Level  %d\nCurrent Change Level     %d\nLast Change Dispensed \t %d\nInventory Capacity\t %d\nChange Capacity \t %d\nCoke Price\t\t %d\nCokes Sold \t\t %d",machineName, inventoryLevel, changeLevel, changeDispensed, maxInventoryCapacity, maxChangeCapacity,CokePrice, numberOfCokesSold);
    }

    public String getMachineName() 
    {
        return machineName;
    }

    public int getChangeLevel() 
    {
        return changeLevel;
    }

    public int getMaxChangeCapacity() 
    {
        return maxChangeCapacity;
    }

    public int getInventoryLevel() 
    {
        return inventoryLevel;

    }

    public int getMaxInventoryLevel() 
    {
        return maxInventoryCapacity;
    }

    public int getCokePrice() 
    {
        return CokePrice;
    }

    public int getChangeDispensed() 
    {
        return changeDispensed;
    }

    public int getNumberOfCokesSold() 
    {
        return numberOfCokesSold;
    }

    public boolean incrementInventoryLevel(int amountToAdd) 
    {
        if (amountToAdd + inventoryLevel > maxInventoryCapacity) 
        {
            return false;
        } else 
        {
            inventoryLevel += amountToAdd;
            return true;
        }
    }

    public boolean incrementChangeLevel(int amountToAdd) 
    {
        if (amountToAdd + changeLevel > maxChangeCapacity) 
        {
            return false;
        } else {
            changeLevel += amountToAdd;
            return true;
        }

    }

    public ACTION buyACoke(int payment) 
    {
        int chng_back = payment - CokePrice;
        ACTION c = ACTION.EXACTPAYMENT;
        if (payment > CokePrice && chng_back < changeLevel) 
        {
            changeDispensed = chng_back;
            changeLevel -= chng_back;
            changeLevel += CokePrice;
            inventoryLevel--;
            numberOfCokesSold++;
            return ACTION.DISPENSECHANGE;

        } else if ((payment - CokePrice) > changeLevel) 
        {
            return ACTION.INSUFFICIENTCHANGE;

        } else if (payment < CokePrice) 
        {
            return ACTION.INSUFFICIENTFUNDS;

        } else if (inventoryLevel == 0) 
        {
            return ACTION.NOINVENTORY;
        } else if (payment == CokePrice) 
        {
            changeLevel += payment;
            inventoryLevel--;
            numberOfCokesSold++;
            return ACTION.EXACTPAYMENT;
        }

        return c;
    }

}