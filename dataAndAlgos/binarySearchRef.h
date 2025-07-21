#include <vector>

int binarySearchExample(std::vector<int> nums, int target) {
	int l{ 0 }, r{ static_cast<int>(nums.size()) - 1 };

	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] == target) {
			return mid;
		}

		if (nums[mid] > target) { r = mid - 1; }
		else { l = mid + 1; }
	}
	return -1;
}