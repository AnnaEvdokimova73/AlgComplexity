#include <iostream>

int getCount(int* arr, int size, int target)
{
    int left = 0;
    int right = size - 1;
    int index;

    while (left < right)
    {
        int mid;
        mid = (left + right) / 2;
        if (arr[size - 1] < target)
        {
            index = size;
            break;
        }

        if (right - left == 2)
        {
            if (arr[left] > target)
            {
                index = 0;
                break;
            }
            else if (arr[right] < target)
            {
                index = right;
                break;
            }
            index = mid;
            break;
        }

        if (right - left == 1)
        {
            if (arr[left] > target)
            {
                index = 0;
                break;
            }
            else if (arr[right] <= target)
            {
                index = right + 1;
                break;
            }
        }

        if (arr[mid] > target)
        {
            right = mid + 1;
        }
        else if (arr[mid] < target)
        {
            left = mid - 1;
        }
        else
        {
            left = mid;
        }
    }

    int num = size - index;
    return num;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size = sizeof(arr) / sizeof(int);
    int targetNum;

    for (;;)
    {
        std::cout << "Введите точку отсчета: ";
        std::cin >> targetNum;
        std::cout << "Количество элеметов в массиве больших, чем " << targetNum << ": ";
        std::cout << getCount(arr, size, targetNum);
        std::cout << std::endl;
    }
}