class Solution {
    private Map<String, String> parent;
    private Map<String, Double> weight;

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        parent = new HashMap<>();
        weight = new HashMap<>();
        double[] ans = new double[queries.size()];
        for (int i = 0; i < equations.size(); i++) {
            String a = equations.get(i).get(0);
            String b = equations.get(i).get(1);
            double val = values[i];

            if (!parent.containsKey(a)) {
                parent.put(a, a);
                weight.put(a, 1.0);
            }
            if (!parent.containsKey(b)) {
                parent.put(b, b);
                weight.put(b, 1.0);
            }

            String rootA = Uparent(a);
            String rootB = Uparent(b);

            if (!rootA.equals(rootB)) {
                parent.put(rootB, rootA);
                 weight.put(rootB, weight.get(a) / (weight.get(b) * val));
            }
        }
        int j =0;
        for(List<String> t: queries)
        {
            String a = t.get(0);
    String b = t.get(1);

    if (!parent.containsKey(a) || !parent.containsKey(b)) {
        ans[j++] = -1.0;
        continue;
    }

    String rootA = Uparent(a);
    String rootB = Uparent(b);

    if (!rootA.equals(rootB)) {
        ans[j++] = -1.0;
    } else {
        ans[j++] = weight.get(a) / weight.get(b);
    }
        }
        return ans;
    }
    String Uparent(String a)
    {
        if(!parent.get(a).equals(a))
        {
            String origParent = parent.get(a);
            String p = Uparent(parent.get(a));
            parent.put(a,p);
            weight.put(a,weight.get(a)*weight.get(origParent));
            //need to do it with orig parent only
            return p;

        }
        return a;
    }
}