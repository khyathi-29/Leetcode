class Solution {
    static Map<Integer, String> numberToWordMap;
    static {
        numberToWordMap = new HashMap<>();
      
        // Single digits (1-9)
        numberToWordMap.put(1, "One");
        numberToWordMap.put(2, "Two");
        numberToWordMap.put(3, "Three");
        numberToWordMap.put(4, "Four");
        numberToWordMap.put(5, "Five");
        numberToWordMap.put(6, "Six");
        numberToWordMap.put(7, "Seven");
        numberToWordMap.put(8, "Eight");
        numberToWordMap.put(9, "Nine");
      
        // Special cases (10-19)
        numberToWordMap.put(10, "Ten");
        numberToWordMap.put(11, "Eleven");
        numberToWordMap.put(12, "Twelve");
        numberToWordMap.put(13, "Thirteen");
        numberToWordMap.put(14, "Fourteen");
        numberToWordMap.put(15, "Fifteen");
        numberToWordMap.put(16, "Sixteen");
        numberToWordMap.put(17, "Seventeen");
        numberToWordMap.put(18, "Eighteen");
        numberToWordMap.put(19, "Nineteen");
      
        // Tens (20-90)
        numberToWordMap.put(20, "Twenty");
        numberToWordMap.put(30, "Thirty");
        numberToWordMap.put(40, "Forty");
        numberToWordMap.put(50, "Fifty");
        numberToWordMap.put(60, "Sixty");
        numberToWordMap.put(70, "Seventy");
        numberToWordMap.put(80, "Eighty");
        numberToWordMap.put(90, "Ninety");
      
        // Scale units
        numberToWordMap.put(100, "Hundred");
        numberToWordMap.put(1000, "Thousand");
        numberToWordMap.put(1000000, "Million");
        numberToWordMap.put(1000000000, "Billion");
    }

    public String numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        StringBuilder sb = new StringBuilder("");
        for(int scale = 1000_000_000; scale>=1000; scale = scale/1000)
        {
            if(num>=scale){
                   sb.append(' ')
                    .append(convertThreeDigits(num / scale))
                      .append(' ')
                      .append(numberToWordMap.get(scale));
                num %= scale;
            }
        }
        if(num>0){
            sb.append(' ').append(convertThreeDigits(num));
        }
        return sb.substring(1);
    }
    String convertThreeDigits(int num)
    {
        StringBuilder sb = new StringBuilder();
        if(num>=100)
        {
          sb.append(' ').append(numberToWordMap.get(num/100))
                      .append(' ')
                      .append(numberToWordMap.get(100));
                num = num%100;
        }
        if(num>0){
            if(num<=19 || num%10==0){
                     sb.append(' ')
                      .append(numberToWordMap.get(num));
            }
            else{
                 sb.append(' ')
                      .append(numberToWordMap.get(num/10*10))
                      .append(' ')
                      .append(numberToWordMap.get(num%10));
            }
        }
        return sb.substring(1);
    }
}