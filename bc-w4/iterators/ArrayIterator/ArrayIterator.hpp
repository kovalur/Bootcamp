class ArrayIterator {
    private:
        int limit;
        int* array;
        int current;
    public:
        ArrayIterator(int array[], int size);
        
        void next();
        int value();
        bool over();
        void operator++();
        void operator++(int);
        int operator*();
};
