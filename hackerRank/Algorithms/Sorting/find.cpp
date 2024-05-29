int find(const std::vector<int>& arr, int target) {
    auto it = arr.begin();
    while (it != arr.end()) {
        if (*it == target) {
            return distance(arr.begin(), it);
        }
        ++it;
    }
    return -1;
}