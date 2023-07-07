#include <iostream>
 
// every object of type struct_float will be aligned to alignof(float) boundary
// (usually 4):
struct alignas(float) struct_float
{
    // your definition here
};
 
// every object of type sse_t will be aligned to 32-byte boundary:
struct alignas(4) sse_t_4
{
    float sse_data;
};

// every object of type sse_t will be aligned to 32-byte boundary:
struct alignas(32) sse_t_32
{
    float sse_data[4];
};
 
 // every object of type sse_t2 will be aligned to 64-byte boundary:
struct alignas(64) sse_t_64
{
    float sse_data[4];
};

// the array "cacheline" will be aligned to 64-byte boundary:
alignas(64) char cacheline[64];
 
int main()
{
    float t;
    struct default_aligned_16
    {
        float data[4];  // 4byte * 4 = 16 byte
    };  // => 16 byte address gap
    struct default_aligned_8
    {
        float data[2];  // 4byte * 2 = 8 byte
    };  // => 8 byte address gap
    struct default_aligned_4
    {
        float data[1];  // 4byte * 1 = 4 byte
    };  // => 4 byte address gap

    default_aligned_4 a, b, c;
    default_aligned_8 d, e, f;
    default_aligned_16 g, h, i;
        
    sse_t_4 x0, y0, z0; // => 4 byte align

    sse_t_32 x1, y1, z1;  // => 32 byte align
    sse_t_64 x2, y2, z2;  // => 64 byte align

    alignas(64) bool b1, b2;
 
    std::cout
        << "alignof(struct_float) = " << alignof(struct_float) << '\n'
        << "sizeof(sse_t) = " << sizeof(sse_t_32) << '\n'
        << "alignof(sse_t) = " << alignof(sse_t_32) << '\n'
        << "alignof(cacheline) = " << alignof(alignas(64) char[64]) << '\n'
        << std::hex << std::showbase
        << "&cacheline: " << &cacheline << '\n'
        
        << "&a: " << &a << '\n'
        << "&b: " << &b << " [4byte gap from prev]" <<'\n'
        << "&c: " << &c << " [4byte gap from prev]" <<'\n'
        << "&d: " << &d << '\n'
        << "&e: " << &e << " [8byte gap from prev]" <<'\n'
        << "&f: " << &f << " [8byte gap from prev]" <<'\n'
        << "&g: " << &g << '\n'
        << "&h: " << &h << " [16byte gap from prev]" <<'\n'
        << "&i: " << &i << " [16byte gap from prev]" <<'\n'

        << "&x0: " << &x0 << '\n'
        << "&y0: " << &y0 << " [4byte gap from prev]" <<'\n'
        << "&z0: " << &z0 << " [4byte gap from prev]" <<'\n'
        << "&x1: " << &x1 << '\n'
        << "&y1: " << &y1 << " [32byte gap from prev]" <<'\n'
        << "&z1: " << &z1 << " [32byte gap from prev]" <<'\n'
        << "&x2: " << &x2 << '\n'
        << "&y2: " << &y2 << " [64byte gap from prev]" <<'\n'
        << "&z2: " << &z2 << " [64byte gap from prev]" <<'\n'
        
        << "&b1: " << &b1 << '\n'
        << "&b2: " << &b2 << " [64byte gap from prev]" <<'\n';
}