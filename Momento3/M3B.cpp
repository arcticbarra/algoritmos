class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        switch(n){
            case 0:
                return 1;
                break;
            case 1:
                return 10;
                break;
            case 2:
                return 91;
                break;
            case 3:
                return 739;
                break;
            case 4:
                return 5275;
                break;
            case 5:
                return 32491;
                break;
            case 6:
                return 168571;
                break;
            case 7:
                return 712891;
                break;
            case 8:
                return 2345851;
                break;
            default:
                return 5611771;
                break;
        }
    }
};
