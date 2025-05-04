class Solution {
    public boolean isRobotBounded(String instructions) {
        int[] distance = new int[4];
        Arrays.fill(distance,0);
        int dir = 0;//dir 0-N, 1- E, 2-S, 3-W
        for(char c : instructions.toCharArray()){
            if(c=='L'){
                dir = (dir-1+4)%4;
            }
            else if(c=='R'){
                dir = (dir+1)%4;
            }
            else {
                distance[dir]+=1;
            }
        }
        if((distance[0]==distance[2]&&distance[1]==distance[3])||dir!=0) return true;
        else return false;
    }
}