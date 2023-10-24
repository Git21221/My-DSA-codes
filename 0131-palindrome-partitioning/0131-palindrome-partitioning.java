class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        List<String> help = new ArrayList<>();
        solving(0, s, res, help);
        return res;
    }
    private boolean isPalindrome(String s, int start, int end) {
        while(start <= end) {
            if(s.charAt(start++) != s.charAt(end--)) return false;
        }
        return true;
    }
    private void solving(int ind, String s, List<List<String>> res, List<String> help) {
        // base case -->
        if(ind == s.length()) {
            res.add(new ArrayList<>(help));
            return;
        }

        for(int i = ind; i < s.length(); i++) {
            if(isPalindrome(s, ind, i)) {
                help.add(s.substring(ind, i+1));
                solving(i+1, s, res, help);
                help.remove(help.size() - 1);
            }
        }
    }
}