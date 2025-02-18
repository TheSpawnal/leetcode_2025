

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;

class RandomizedSet{
    private ArrayList<Integer> nums;
    private HashMap<Integer, Integer> valToIndex;
    private Random rand;

    public RandomizedSet(){
        nums = new ArrayList<>();
        valToIndex = new HashMap<>();
        rand = new Random();
    }

    public boolean insert(int val){
        if(valToIndex.containsKey(val)){
            return false;
        }
        valToIndex.put(val, nums.size());
        nums.add(val);
        return true; 
    }

    public boolean remove(int val){
        if(!valToIndex.containsKey(val)){
            return false;
        }
        int index = valToIndex.get(val);
        int lastElement = nums.get(nums.size()-1);

        nums.set(index, lastElement);
        valToIndex.put(lastElement, index);
        nums.remove(nums.size()-1);
        valToIndex.remove(val);
        return true;
    }
    public getRandom(){
        return nums.get(rand.nextInt(nums.size()));
    }
}