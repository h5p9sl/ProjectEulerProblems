#include <stdio.h>
#include <cinttypes>
#include <cstring>
#include <vector>

// 05/10/2018

struct ANum;

bool isPalindrome(ANum a);
unsigned long LargestPalindrome();

struct ANum
{
    uint8_t* DigitArray;
    size_t ArraySize;

    ANum(unsigned i)
    {
        this->ConvertTo(i);
    }

    void ConvertTo(unsigned num)
    {
        std::vector<uint8_t>* temp = new std::vector<uint8_t>;

        // Split integer into digits
        // Note: The integer is stored in reverse here
        if (num == 0)
            temp->push_back(0);
        else {
            while (num > 0) {
                #ifdef _DEBUG
                printf("[->] Pushed \"%i\".\n", num % 10);
                #endif
                temp->push_back(num % 10);
                num /= 10;
            }
        }

        // Reverse & Store digits
        this->DigitArray = new uint8_t[temp->size()];
        this->ArraySize = temp->size();

        for (unsigned i = 0; i < this->ArraySize; i++) {
            #ifdef _DEBUG
            printf("[<-] Stored \"%i\".\n", temp->back());
            #endif
            this->DigitArray[i] = temp->back();
            temp->pop_back();
        }

        #ifdef _DEBUG
        this->Print();
        #endif

        delete temp;
    }

    void Print()
    {
        for (unsigned i = 0; i < ArraySize; i++)
        {
            printf("%i", DigitArray[i]);
        }
        printf("\n");
    }


};

// Not exactly an elegant solution, but it gets the job done.
bool isPalindrome(ANum a)
{
    bool ret = false;
    if (a.ArraySize % 2 == 0)
    {
        size_t HalfSize = a.ArraySize/2;        // Number of digits / 2
        uint8_t* x = &a.DigitArray[0];            // Pointer to 1st half of integer
        uint8_t* y = &a.DigitArray[HalfSize];    // Pointer to 2nd half of integer
        uint8_t* z = new uint8_t[HalfSize];     // Buffer for storing the reversed version of x

        // Reverse x and place it into z
        for (unsigned i = 0; i < HalfSize; i++)
        {
            z[i] = x[HalfSize - i - 1];
        }

        // Compare digits
        if (memcmp(y, z, HalfSize) == 0)
        {
            #ifdef _DEBUG
            a.Print();
            puts("[^] This number is a palindrome.");
            #endif
            ret = true;
        }

        delete[] z;
    }
    return ret;
}

unsigned long LargestPalindrome()
{
    // Brute force method
    unsigned long result;


    for (unsigned i = 100; i <= 999; i++)
    {
        for (unsigned j = 100; j <= 999; j++)
        {
            if (i*j > result) {
                ANum temp = i*j;
                if (isPalindrome(temp))
                {
                    result = i*j;
                }
            }
        }
    }

    return result;
}

int main()
{
    printf("%i is the largest Palindrome made from two 3-digit factors.\n", LargestPalindrome());
    return 0;
}