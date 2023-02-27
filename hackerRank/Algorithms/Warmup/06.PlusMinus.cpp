void plusMinus(vector<int> arr) {
    double total = arr.size();
    int positive, negative, zeros;
    positive = negative = zeros = 0;
    
    for (int num : arr) {
        if (num == 0)
        {
            zeros++;
        }
        else if (num > 0)
        {
            positive++;
        }
        else if (num < 0)
        {
            negative++;    
        }
    }
    
    float positiveRatio = float(positive) / total;
    float negativeRatio = float(negative) / total;
    float zerosRatio = float(zeros) / total;
    
    cout << fixed << setprecision(6) 
    << positiveRatio << endl
    << negativeRatio << endl
    << zerosRatio << endl;
}