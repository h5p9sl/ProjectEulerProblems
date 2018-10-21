#include <iostream>
#include <vector>
#include <cinttypes>

// 20/10/2018
// This one took a while to figure out how to solve

class PascalTriangle
{
private:
    std::vector<uint64_t> b;
    const uint32_t width = 0;
    const uint32_t height = 0;
public:
    PascalTriangle(unsigned w, unsigned h)
        : width(w + 1), height(h + 1)
    {
        b.reserve(this->width * this->height);
        for (unsigned i = 0; i < b.capacity(); i++) b.push_back(0);
        for (unsigned i = 0; i < this->width; i++) b.at(i) = 1;
        for (unsigned i = 0; i < this->width*this->height; i += this->width) b.at(i) = 1;
        for (unsigned y = 1; y < this->height; y++) {
            for (unsigned x = 1; x < this->width; x++) {
                b.at(y * this->width + x) = b.at((y - 1) * this->width + x) + b.at(y * this->width + (x - 1));
            }
        }
    }
    std::vector<uint64_t>& getTriangle() { return this->b; }
    uint64_t& getValueAtCoords(unsigned x, unsigned y) { return this->b.at(y * this->width + x); }
};

int main()
{
    PascalTriangle foo(20, 20);
    std::cout << foo.getValueAtCoords(20, 20) << std::endl;
    return 0;
}