import java.util.*;
import java.lang.Math.*;

import static java.lang.Math.pow;

public class Solution {
    //Different items that the carpenter works on
    class Item {
        //Used Long because of the limit defined in question
        long key;

        Item(long x) {
            this.key = x;
        }

        long getKey() {
            return key;
        }

        //Overriding object methods because we do a lot of searching, and also a HashSet is used
        @Override
        public boolean equals(Object o) {
            return (o instanceof Item) && ((Item) o).getKey() == this.getKey();
        }

        @Override
        public int hashCode() {
            return Long.hashCode(key);
        }
    }

    //Each cabinet with different sizes
    class Cabinet {
        int size;

        //Used LinkedList because it is easy to add newest item and remove oldest item
        LinkedList<Item> itemGroup = new LinkedList<>();

        Cabinet(int x) {
            this.size = x;
        }

        //Adds item to a cabinet, if the cabinet is full, returns the oldest item (after removing it), else returns null
        public Item addItem(Item newItem) throws Exception {
            if (itemGroup.size() == this.size) {
                itemGroup.add(newItem);
                return itemGroup.pollFirst();
            } else if (itemGroup.size() < this.size) {
                itemGroup.add(newItem);
                return null;
            } else if (itemGroup.size() > this.size) {
                throw new Exception();
            }
            return null;
        }
    }

    //The carpenter's workshop, which contains all the cabinets, and also "Outside of the Shop" which contains
    //infinite space
    class TheWorkshop {
        int totalCabinets;

        //Used ArrayList for storing all the cabinets, as there is no further modification to the cabinets and it is
        //easier to choose any cabinet from it's index
        ArrayList<Cabinet> cabinetGroup = new ArrayList<>();

        //Used HashSet for storing rest of the items outside the shop, as all the items are unique, and it has infinite
        // storage capacity, so retrieving a single item will be faster
        HashSet<Item> outsideTheShop = new HashSet<>();

        //Initializing the workshop with total number of cabinets, and then inserting each cabinet with the given size
        TheWorkshop(int x, int[] cabinetCapacityArray) {
            totalCabinets = x;
            for (int cabinetSize : cabinetCapacityArray) {
                Cabinet tempCabinet = new Solution().new Cabinet(cabinetSize);
                cabinetGroup.add(tempCabinet);
            }
        }

        //Private method, used internally. Adds an item to the shop. Starts from the first cabinet, if full, adds it to
        //the top and removes the oldest item, and recursively does it until we reach a cabinet with empty space, or
        //we reach the infinite space outside the shop
        private void addItemToShop(Item newItem, int cabinetIndex) throws Exception {
            if (cabinetIndex == totalCabinets) {
                outsideTheShop.add(newItem);
                return;
            }
            Item tempItem = cabinetGroup.get(cabinetIndex).addItem(newItem);
            if (tempItem != null) addItemToShop(tempItem, ++cabinetIndex);
        }

        //Checks if the given item is new or was used previously. Private method, used internally.
        //  Returns -1 if the item is new.
        //  Returns -2 if the item was found outside the shop. Also removes it from there.
        //  Returns with the "index" value (0 to N-1) of the cabinet where item was found, also removes it from there.
        private int isNewItem(Item e) {
            //for (Cabinet eachCabinet : cabinetGroup){
            for (int i = 0; i < cabinetGroup.size(); i++) {
                if (cabinetGroup.get(i).itemGroup.contains(e)) {
                    cabinetGroup.get(i).itemGroup.remove(e);
                    //Found inside the cabinet
                    return i;
                }
            }
            if (outsideTheShop.contains(e)) {
                outsideTheShop.remove(e);
                //Found Outside
                return -2;
            } else {
                //New Item
                return -1;
            }

        }

        //Method that is called in the main function
        //  1. First checks if the item is new by using isNewItem()
        //  2. Adds the item to the shop using addItemToShop()
        //  3. Depending upon the value returned by isNewItem(), returns the appropriate string
        //Named "workOnAnItem", because the carpenter is currently working on the given item
        String workOnAnItem(Item e) throws Exception {
            int returnValue = isNewItem(e);
            if (returnValue == -1) {
                addItemToShop(e, 0);
                return "NEW";
            } else if (returnValue == -2) {
                addItemToShop(e, 0);
                return "OUTSIDE";
            } else if (returnValue >= 0) {
                addItemToShop(e, 0);
                return Integer.toString(returnValue + 1);
            } else {
                return "INPUT_ERROR";
            }
        }
    }

    public static void main(String args[]) throws Exception {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        try {
            Scanner scan = new Scanner(System.in);
            String readFirstLine = scan.nextLine();
            String[] splitEachNumber = readFirstLine.split(" ");

            //cabinetCapacityArray, where the size of each cabinet is stored
            int[] cabinetCapacityArray = new int[splitEachNumber.length];
            for (int i = 0; i < splitEachNumber.length; i++) {
                cabinetCapacityArray[i] = Integer.parseInt(splitEachNumber[i]);
                //Checking Cabinet Size, if it is in the limits defined according to the problem statement
                if (cabinetCapacityArray[i] <= 0 || cabinetCapacityArray[i] >= 1024) throw new Exception();
            }

            //Using long because of the limits defined in the problem statement
            long inputItemCount = scan.nextInt(); //K
            if ((inputItemCount <= 0) || (inputItemCount >= (long) pow(2, 32))) throw new Exception();

            //inputSequence has the sequence of item-id's given as input
            ArrayList<Long> inputSequence = new ArrayList<>();


            //cabinetCount contains the total number of cabinets
            int cabinetCount = cabinetCapacityArray.length; //N
            //Checking total number of cabinets, if it is in the limits as defined in the problem statement
            if ((cabinetCount <= 0) || (cabinetCount >= 64)) throw new Exception();

            //Initializing the workshop named "thisWorkshop" that contains all the cabinets, outside space, etc.
            TheWorkshop thisWorkshop = new Solution().new TheWorkshop(cabinetCount, cabinetCapacityArray);

            String returnString = "";
            for (long i = 0; i < inputItemCount; i++) {
                long temp = scan.nextLong();
                inputSequence.add(temp);
                //Checking the limits according to what is defined in the problem statement
                if ((temp <= 0) || (temp >= (long) pow(2, 32))) throw new Exception();
            }
            //Creating the item, and adding it it in the workshop, according to what is defined in workOnAnItem()
            for (long itemID : inputSequence) {
                Item newItem = new Solution().new Item(itemID);
                //the value returnString changes in every loop, but that's okay, since we only need the value that
                //is returned for the last item
                returnString = thisWorkshop.workOnAnItem(newItem);
            }
            //Solution
            System.out.println(returnString);
        } catch (Exception e) {
            //Print for any type of exception
            System.out.println("INPUT_ERROR");
        }
    }
}
