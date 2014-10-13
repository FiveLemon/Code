namespace QCQ
{
    template<class T>
    void Reverse(T* begin, T* end)
    {
        while (begin < end)
        {
            swap(*begin, * end);
            begin++;
            end--;
        }
    }
    template<class T>
    void Reverse(T begin, T end)
    {
        while (begin < end)
        {
            swap(*begin, * end);
            begin++;
            end--;
        }
    }
}